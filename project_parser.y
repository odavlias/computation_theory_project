%{
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cgen.h"

#define FILENAME "output.c"

extern int yylex(void);
extern int line_num;

FILE *outputFile;

%}

%union
{
	char* crepr;
}

/* Basic data types tokens */
%token <crepr> TK_IDENT
%token <crepr> TK_INT
%token <crepr> TK_REAL
%token <crepr> TK_STRING
%token TK_BOOL_TRUE
%token TK_BOOL_FALSE

/* Operators */
%left TK_PLUS
%left TK_MINUS
%left TK_MULTIPLY
%left TK_DIVIDE
%left TK_DIV
%left TK_MOD
%left TK_EQUAL
%left TK_NOTEQUAL
%left TK_SMALLER
%left TK_GREATER
%left TK_SMALLEREQUAL
%left TK_GREATER_EQUAL
%left TK_AND
%left TK_OR
%right TK_NOT

/* Delimiters */
%token <crepr> TK_LPAR
%token <crepr> TK_RPAR
%token <crepr> TK_SEMICOLON
%left <crepr> TK_COMMA
%token <crepr> TK_LBRACKET
%token <crepr> TK_RBRACKET
%token <crepr> TK_COLON
%token <crepr> TK_POINT
%token <crepr> TK_DIGIT
%token <crepr> TK_CHAR
%token <crepr> TK_ASSIGN

%token <crepr> KW_ARRAY

/* Keywords */
%token KW_PROGRAM
%token KW_BEGIN
%token KW_END
%token <crepr> KW_BOOLEAN
%token <crepr> KW_CHAR
%token KW_DO
%token KW_ELSE
%token KW_FOR
%token KW_FUNCTION
%token KW_GOTO
%token KW_IF
%token <crepr> KW_INTEGER
%token <crepr> KW_VAR
%token <crepr> KW_OF
%token KW_WHILE
%token KW_PROCEDURE
%token <crepr> KW_REAL
%token KW_REPEAT
%token KW_TO
%token KW_RESULT
%token KW_RETURN
%token KW_THEN
%token KW_UNTIL
%token KW_DOWNTO
%token KW_TYPE
%token KW_READSTRING
%token KW_READINTEGER
%token KW_READREAL
%token KW_WRITESTRING
%token KW_WRITEINTEGER
%token KW_WRITEREAL

%start program

%type <crepr> program_header
%type <crepr> program_declarations
%type <crepr> program_body
%type <crepr> program_end
%type <crepr> types_declaration
%type <crepr> program_types
%type <crepr> variables_declaration
%type <crepr> identifiers
%type <crepr> subroutines
%type <crepr> procedure
%type <crepr> procedure_header
%type <crepr> subroutine_arguments
%type <crepr> procedure_declarations
%type <crepr> procedure_body
%type <crepr> basic_data_type
%type <crepr> data_type
%type <crepr> brackets
%type <crepr> complex_command
%type <crepr> command_list
%type <crepr> command
%type <crepr> commands
%type <crepr> assign_command
%type <crepr> special_assign
%type <crepr> if_statement
%type <crepr> for_loop
%type <crepr> while_loop
%type <crepr> label_command
%type <crepr> goto_command
%type <crepr> return_command
%type <crepr> call_subroutine
%type <crepr> default_subroutine
%type <crepr> call_function
%type <crepr> call_procedure
%type <crepr> call_arguments
%type <crepr> function
%type <crepr> function_header
%type <crepr> expression
%type <crepr> mathematics
%type <crepr> compare
%type <crepr> call_arguments_list
%type <crepr>	variables_declaration_body
%type <crepr> declaring
%type <crepr> complex_command_list
%type <crepr> statement_commands
%type <crepr> subroutine_end

%%

/* Program consists of 4 parts (3 mandatory and 1 optional) *
 * * program header (mandatory)                             *
 * * declarations (optional)                                *
 * * body (mandatory)                                       *
 * * end token                                              *
 ************************************************************/
program: program_header program_declarations program_body program_end  {
	/* We have a successful parse!
		Check for any errors and generate output.
	*/
	if(yyerror_count==0) {
		outputFile = fopen(FILENAME, "a");
		fprintf(outputFile, c_prologue); // include etc
		fprintf(outputFile, "/* program  %s */ \n\n", $1); // program name as comment
		fprintf(outputFile, $2); // declaration part
		fprintf(outputFile, "\nint main() %s \n", $3); // program main
		fclose(outputFile);
	}
};

/* Program header follows the template: program <program_name>;*/
program_header: KW_PROGRAM TK_IDENT TK_SEMICOLON { $$ = template("%s", $2); };

/* program_declarations is optional *
 * it may include:                  *
 * * type(s) declaration(s)         *
 * * variables declarations         *
 * * subroutines                    *
 ************************************/
program_declarations: { $$ = template(""); }
										  | program_declarations declaring  { $$ = template("%s\n%s", $1, $2); }
											| program_declarations subroutines  { $$ = template("%s\n%s", $1, $2); };

declaring: types_declaration { $$ = template("%s", $1); }
					 | variables_declaration  { $$ = template("%s", $1); };
/* */
types_declaration: KW_TYPE program_types  { $$ = template("%s", $2); };

program_types: TK_IDENT TK_EQUAL data_type TK_SEMICOLON  { $$ = template("typedef %s %s;", $3, $1); }
							 | program_types TK_IDENT TK_EQUAL data_type TK_SEMICOLON  { $$ = template("%s\ntypedef %s %s;", $1, $4, $2); };

variables_declaration: KW_VAR variables_declaration_body  { $$ = template("%s", $2); };

variables_declaration_body: identifiers TK_COLON data_type TK_SEMICOLON  { $$ = template("%s %s;", $3, $1); }
														| variables_declaration_body identifiers TK_COLON data_type TK_SEMICOLON  { $$ = template("%s\n%s %s;", $1, $4, $2); };

identifiers: TK_IDENT  { $$ = template("%s", $1); }
						 | identifiers TK_COMMA TK_IDENT  { $$ = template("%s, %s", $1, $3); };

subroutines: function  { $$ = template("%s", $1); }
						 | procedure  { $$ = template("%s", $1); };

function:  function_header procedure_declarations procedure_body  { $$ = template("%s{\n%s\n%s\n}\n", $1, $2, $3); };

function_header: KW_FUNCTION TK_IDENT TK_LPAR subroutine_arguments TK_RPAR TK_COLON data_type TK_SEMICOLON  { $$ = template("%s %s(%s)", $7, $2, $4); };

procedure: procedure_header procedure_declarations procedure_body  { $$ = template("%s{\n%s\n%s\n}\n", $1, $2, $3); };

procedure_header: KW_PROCEDURE TK_IDENT TK_LPAR subroutine_arguments TK_RPAR TK_SEMICOLON  { $$ = template("void %s(%s)", $2, $4); };

subroutine_arguments: { $$ = template(""); }
										 | TK_IDENT TK_COLON data_type { $$ = template("%s %s", $3, $1); }
										 | subroutine_arguments TK_SEMICOLON TK_IDENT TK_COLON data_type { $$ = template("%s, %s %s", $1, $5, $3); };

procedure_declarations: program_declarations  { $$ = template("%s", $1); };

procedure_body: complex_command TK_SEMICOLON { $$ = template("%s", $1); };

program_body: KW_BEGIN commands KW_END  { $$ = template("{\n%s \n}\n", $2); };

program_end: TK_POINT  { $$ = template(""); };

subroutine_end: TK_SEMICOLON  { $$ = template(""); };

basic_data_type: KW_INTEGER  { $$ = template("int"); }
								 | KW_BOOLEAN  { $$ = template("int"); }
								 | KW_CHAR  { $$ = template("char"); }
								 | KW_REAL  { $$ = template("double"); };

data_type: basic_data_type  { $$ = template($1); }
					 | KW_ARRAY brackets KW_OF basic_data_type  { $$ = template("%s [%s]", $4, $2); }
					 | KW_ARRAY KW_OF basic_data_type  { $$ = template("%s*", $3); };

brackets: TK_LBRACKET expression TK_RBRACKET  { $$ = template("[%s]", $2); }
					| brackets TK_LBRACKET expression TK_RBRACKET  { $$ = template("%s [%s]", $1, $3); };

/** Commands */
commands: { $$ = template(""); }
					| commands command_list  { $$ = template("%s%s", $1, $2); };


/* complex command represents a group of commands in between begin and end */
complex_command: KW_BEGIN complex_command_list KW_END { $$ = template("%s", $2); };

/* command list */
command_list: command { $$ = template("%s", $1); }
							| TK_SEMICOLON command { $$ = template("%s\n", $2); }
							| TK_SEMICOLON complex_command  { $$ = template("%s", $2); }
							| complex_command TK_SEMICOLON  { $$ = template("%s", $1); };

command: assign_command  { $$ = template("%s", $1); }
				 | special_assign  { $$ = template("%s", $1); }
				 | if_statement  { $$ = template("%s", $1); }
				 | for_loop  { $$ = template("%s", $1); }
				 | while_loop  { $$ = template("%s", $1); }
				 | label_command  { $$ = template("%s", $1); }
				 | goto_command	 { $$ = template("%s", $1); }
				 | return_command  { $$ = template("%s", $1); }
				 | call_subroutine  { $$ = template("%s", $1); };

complex_command_list: { $$ = template(""); }
											| complex_command_list command  { $$ = template("%s\n%s", $1, $2); }
											| complex_command_list TK_SEMICOLON command  { $$ = template("%s\n%s", $1, $3); };

statement_commands: complex_command  { $$ = template("%s", $1); }
										| special_assign  { $$ = template("%s", $1); };

/* simple commands implementation */

assign_command: TK_IDENT TK_ASSIGN expression  { $$ = template("%s = %s;", $1, $3); }
								| TK_IDENT brackets TK_ASSIGN expression  { $$ = template("%s%s = %s;", $1, $2, $4); };

special_assign: KW_RESULT TK_ASSIGN expression  { $$ = template("result = %s;", $3); };

if_statement: KW_IF expression KW_THEN statement_commands  { $$ = template("if (%s){\n\t%s}\n", $2, $4); }
						  | if_statement KW_ELSE statement_commands  { $$ = template("else{\n\t%s}\n", $3); };

for_loop: KW_FOR TK_IDENT TK_ASSIGN expression KW_TO expression KW_DO statement_commands  { $$ = template("for(%s=%s;%s<=%s;%s++){\n\t%s}\n", $2, $4, $2, $6, $2, $8);}
					| KW_FOR TK_IDENT TK_ASSIGN expression KW_DOWNTO expression KW_DO statement_commands  { $$ = template("for(%s=%s;%s>=%s;%s--){\n\t%s}\n", $2, $4, $2, $6, $2, $8);};

while_loop: KW_WHILE expression KW_DO statement_commands  { $$ = template("while (%s){\n\t%s}\n", $2, $4); }
						| KW_REPEAT statement_commands KW_UNTIL expression  { $$ = template("do{\n\t%s\n} while( %s );", $2, $4); };

label_command: TK_IDENT TK_COLON statement_commands  { $$ = template("%s: %s", $1, $3); };

goto_command: KW_GOTO TK_IDENT  { $$ = template("goto %s;", $2); };

return_command: KW_RETURN  { $$ = template("return result;"); };

/* call_subroutine */
call_subroutine: default_subroutine  { $$ = template("%s", $1); }
								 | call_function  { $$ = template("%s", $1); }
								 | call_procedure  { $$ = template("%s", $1); };

default_subroutine: KW_WRITESTRING TK_LPAR expression TK_RPAR  { $$ = template("writeString(%s);", $3); }
										| KW_WRITEINTEGER TK_LPAR expression TK_RPAR  { $$ = template("writeInteger(%s);", $3); }
										| KW_WRITEREAL TK_LPAR expression TK_RPAR  { $$ = template("writeReal(%s);", $3); }
										| TK_IDENT TK_ASSIGN KW_READSTRING  { $$ = template("%s = readString();", $1); }
										| TK_IDENT TK_ASSIGN KW_READINTEGER  { $$ = template("%s = readInteger();", $1); }
										| TK_IDENT TK_ASSIGN KW_READREAL  { $$ = template("%s = readReal();", $1); };

call_function: TK_IDENT TK_ASSIGN TK_IDENT TK_LPAR call_arguments TK_RPAR  { $$ = template("%s = %s(%s);", $1, $3, $5); }
							 | KW_RESULT TK_ASSIGN TK_IDENT TK_LPAR call_arguments TK_RPAR  { $$ = template("result = %s(%s);", $3, $5); };

call_procedure: TK_IDENT TK_LPAR call_arguments TK_RPAR  { $$ = template("%s(%s);", $1, $3); };


call_arguments: { $$ = template(""); }
								| call_arguments_list  { $$ = template("%s", $1); };

call_arguments_list: TK_IDENT  { $$ = template("%s", $1); }
										 | call_arguments_list TK_COMMA TK_IDENT  { $$ = template("%s, %s", $1, $3); };

expression: TK_INT  { $$ = template( "%s", $1); }
					  | TK_REAL  { $$ = template( "%s", $1); }
					  | TK_STRING  { $$ = template( "%s", $1); }
						| TK_IDENT  { $$ = template( "%s", $1); }
						| TK_BOOL_TRUE  { $$ = template( "1"); }
						| TK_BOOL_FALSE  { $$ = template( "0"); }
						| TK_CHAR  { $$ = template( "%s", $1); }
						| TK_DIGIT  { $$ = template( "%s", $1); }
						| TK_PLUS expression  { $$ = template( "+%s", $2); }
						| TK_MINUS expression  { $$ = template( "-%s", $2); }
						| TK_LPAR expression TK_RPAR  { $$ = template( "(%s)",$2); }
						| TK_LPAR data_type TK_RPAR TK_IDENT  { $$ = template("(%s)%s", $2, $4); }
						| mathematics  { $$ = template( "%s", $1); }
						| compare  { $$ = $1; }
						| TK_IDENT brackets  { $$ = template( "%s%s", $1, $2); };


mathematics:  expression TK_DIVIDE expression  { $$ = template("%s/%s", $1, $3); }
							| expression TK_MOD expression  { $$ = template("%s % %s", $1, $3); }
							| expression TK_PLUS expression  { $$ = template("%s+%s", $1, $3); }
							| expression TK_MINUS expression  { $$ = template("%s-%s", $1, $3); }
							//| expression TK_DIV expression  { $$ = template("div(%s, %s)", $1, $3); }
							| expression TK_MULTIPLY expression  { $$ = template("%s * %s", $1, $3); }
							| expression TK_AND expression  { $$ = template("%s && %s", $1, $3); }
							| expression TK_OR expression  { $$ = template("%s || %s", $1, $3); }
							| TK_NOT expression  { $$ = template("! %s", $2); };


compare: expression TK_GREATER expression  { $$ = template("%s > %s", $1, $3); }
			 	 | expression TK_GREATER_EQUAL expression  { $$ = template("%s >= %s", $1, $3); }
			   | expression TK_EQUAL expression  { $$ = template("%s==%s", $1, $3); }
			   | expression TK_SMALLER expression  { $$ = template("%s < %s", $1, $3); }
			   | expression TK_SMALLEREQUAL expression  { $$ = template("%s <= %s", $1, $3); }
				 | expression TK_NOTEQUAL expression  { $$ = template("%s != %s", $1, $3); };


%%


int main()
{
	yyparse();
}
