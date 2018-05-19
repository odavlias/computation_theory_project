%{
#include <stdarg.h>
#include <stdio.h>
#include "cgen.h"
#include "ptuclib.h"

extern int yylex(void);
extern int line_num;
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
%token TK_PLUS
%token TK_MINUS
%token TK_MULTIPLY
%token TK_DIVIDE
%token TK_MOD
%token TK_EQUAL
%token TK_NOTEQUAL
%token TK_SMALLER
%token TK_GREATER
%token TK_SMALLEREQUAL
%token TK_GREATER_EQUAL
%token TK_AND
%token TK_OR
%token TK_NOT

/* Delimiters */
%token TK_LPAR
%token TK_RPAR
%token TK_SEMCOLUMN
%token TK_COMMA
%token TK_LBRACKET
%token TK_RBRACKET
%token TK_COLON
%token TK_POINT

%token TK_ASSIGN

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
%token KW_END
%token KW_FUNCTION
%token KW_GOTO
%token KW_IF
%token <crepr> KW_INTEGER
%token <crepr> KW_VAR
%token KW_NOT
%token KW_OR
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
%type <crepr> variables_declaration
%type <crepr> subroutines
%type <crepr> function
%type <crepr> procedure
%type <crepr> procedure_header
%type <crepr> procedure_declarations
%type <crepr> procedure_body
%type <crepr> basic_data_type
%type <crepr> data_type
%type <crepr> brackets
%type <crepr> command_pattern
%type <crepr> complex_command
%type <crepr> command_list
%type <crepr> assign_command
%type <crepr> special_assign
%type <crepr> if_statement
%type <crepr> for_loop
%type <crepr> while_loop
%type <crepr> label_command
%type <crepr> goto_command
%type <crepr> return_command
%type <crepr> call_subroutine

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
		puts(c_prologue); // include etc
		printf("/* program  %s */ \n\n", $1); // program name as comment
		printf($2); // declaration part
		printf("void main()\n{\n\t%s}\n", $3); // program main
	}
};

/* Program header follows the template: program <program_name>;*/
program_header: KW_PROGRAM TK_IDENT TK_SEMCOLUMN { $$ = $2 };

/* program_declarations is optional *
 * it may include:                  *
 * * type(s) declaration(s)         *
 * * variables declarations         *
 * * subroutines                    *
 ************************************/
program_declarations: { $$ = template(""); }
										  | program_declarations types_declaration  { $$ = template("%s\n%s", $1, $2); }
											| program_declarations variables_declaration  { $$ = template("%s\n%s", $1, $2); }
											| program_declarations subroutines  { $$ = template("%s\n%s", $1, $2); };

/* */
types_declaration: KW_TYPE program_types  { $$ = template("%s", $2); };

program_types: TK_IDENT TK_EQUAL data_type TK_SEMCOLUMN  { $$ = template("typedef %s %s;", $3, $1); };
							 program_types TK_IDENT TK_EQUAL data_type TK_SEMCOLUMN  { $$ = template("%s\ntypedef %s %s;", $1, $4, $2); };

variables_declaration: { $$ = template(""); };

subroutines: { $$ = template(""); }
						 | subroutines TK_SEMCOLUMN function  { $$ = template("%s\n%s", $1, $3); }
						 | subroutines TK_SEMCOLUMN procedure  { $$ = template("%s\n%s", $1, $3); };

function: KW_FUNCTION procedure_declarations procedure_body TK_COLON TK_IDENT{};

procedure: procedure_header procedure_declarations procedure_body { $$ = template("%s{\n\t%s\n%s}", $1, $2, $3); };

procedure_header: KW_PROCEDURE TK_IDENT TK_LPAR procedure_arguments TK_RPAR TK_SEMCOLUMN  { $$ = template("void %s(%s)", $2, $4); };

procedure_arguments: { $$ = template(""); }
										 | TK_IDENT TK_COLON data_type { $$ = template("%s %s", $3, $1); }
										 | procedure_arguments TK_COMMA TK_IDENT TK_COLON data_type { $$ = template("%s, %s %s", $1, $5, $3); };

procedure_declarations: program_declarations  { $$ = template("%s", $1); };

procedure_body: program_body  { $$ = template("%s", $1); };

program_body: complex_command  { $$ = template("%s", $1); };

program_end: TK_POINT  { $$ = template(""); };

basic_data_type: KW_INTEGER  { $$ = template("int"); }
								 | KW_BOOLEAN  { $$ = template("int"); }
								 | KW_CHAR  { $$ = template("char"); }
								 | KW_REAL  { $$ = template("double"); }

data_type: basic_data_type  { $$ = template($1); }
					 | KW_ARRAY brackets KW_OF basic_data_type  { $$ = template("%s [%s]", $4, $2); }
					 | KW_ARRAY KW_OF basic_data_type  { $$ = template("%s*", $3); };

brackets: TK_LBRACKET expression TK_RBRACKET  { $$ = template("[%s]", $2); }
					brakets TK_LBRACKET expression TK_RBRACKET  { $$ = template("%s [%s]", $1, $3); };

/** Commands */

/* commands pattern
command_pattern: complex_command TK_SEMCOLUMN  { $$ = template("%s", $1); }
								 | assign_command  { $$ = template("%s", $1); }
								 | special_assign  { $$ = template("%s", $1); }
								 | if_statement  { $$ = template("%s", $1); }
								 | for_loop  { $$ = template("%s", $1); }
								 | while_loop  { $$ = template("%s", $1); }
								 | label_command  { $$ = template("%s", $1); }
								 | goto_command  { $$ = template("%s", $1); }
								 | return_command  { $$ = template("%s", $1); }
								 | call_function  { $$ = template("%s", $1); }
								 | TK_SEMCOLUMN complex_command  { $$ = template("%s", $2); }
								 | TK_SEMCOLUMN assign_command  { $$ = template("%s", $2); }
								 | TK_SEMCOLUMN special_assign  { $$ = template("%s", $2); }
								 | TK_SEMCOLUMN if_statement  { $$ = template("%s", $2); }
								 | TK_SEMCOLUMN for_loop  { $$ = template("%s", $2); }
								 | TK_SEMCOLUMN while_loop  { $$ = template("%s", $2); }
								 | TK_SEMCOLUMN label_command  { $$ = template("%s", $2); }
								 | TK_SEMCOLUMN goto_command  { $$ = template("%s", $2); }
								 | TK_SEMCOLUMN return_command  { $$ = template("%s", $2); }
								 | TK_SEMCOLUMN call_function  { $$ = template("%s", $2); };
*/


/* complex command represents a group of commands */
complex_command: KW_BEGIN command_list KW_END { $$ = template("%s", $2); };


/* command list */
command_list: { $$ = template(""); }
							| command { $$ = template("%s", $1); }
							| command_list TK_SEMCOLUMN command { $$ = template("%s\n%s", $1, $2); };

command: assign_command  { $$ = template("%s", $1); }
				 | special_assign  { $$ = template("%s", $1); }
				 | if_statement  { $$ = template("%s", $1); }
				 | for_loop  { $$ = template("%s", $1); }
				 | while_loop  { $$ = template("%s", $1); }
				 | label_command  { $$ = template("%s", $1); }
				 | goto_command	 { $$ = template("%s", $1); }
				 | return_command  { $$ = template("%s", $1); }
				 | call_subroutine  { $$ = template("%s", $1); }

/* simple commands implementation */

assign_command: TK_IDENT TK_ASSIGN expression  { $$ = template("%s = %s;", $1, $3); };

special_assign: KW_RESULT TK_ASSIGN expression  { $$ = template("result = %s;", $3); };

if_statement: KW_IF expression KW_THEN command_list  { $$ = template("if (%s){\n\t%s}\n", $2, $4); }
						  | if_statement KW_ELSE command_list  { $$ = template("else{\n\t%s}\n", $3); };

for_loop: KW_FOR TK_IDENT TK_ASSIGN expression KW_TO expression KW_DO command_list  { $$ = template("for(%s=%s;%s<=%s;%s++){\n\t%s}\n", $2, $4, $2, $6, $2, $8);}
					| KW_FOR TK_IDENT TK_ASSIGN expression KW_DOWNTO expression KW_DO command_list  { $$ = template("for(%s=%s;%s>=%s;%s--){\n\t%s}\n", $2, $4, $2, $6, $2, $8);};

while_loop: KW_WHILE expression KW_DO command_list  { $$ = template("while (%s){\n\t%s}\n", $2, $4); }
						| KW_REPEAT command_list KW_UNTIL expression  { $$ = template("do{\n\t%s\n} while( %s );", $2, $4); };

label_command: TK_IDENT TK_COLON command_list  { $$ = template("%s: %s", $1, $3); };

goto_command: KW_GOTO TK_IDENT  { $$ = template("goto %s;", $2); };

return_command: KW_RETURN  { $$ = template("return result;"); };

/* TODO: call_subroutine */
call_subroutine: default_subroutine  {}
								 | call_function  {}
								 | call_procedure  {};

default_subroutine: KW_WRITESTRING TK_LPAR expression TK_RPAR  { $$ = template("writeString(%s);", $3); }
										| KW_WRITEINTEGER TK_LPAR expression TK_RPAR  { $$ = template("writeInteger(%s);", $3); }
										| KW_WRITEREAL TK_LPAR expression TK_RPAR  { $$ = template("writeReal(%s);", $3); }
										| TK_IDENT TK_ASSIGN KW_READSTRING  { $$ = template("%s = readString();", $1); }
										| TK_IDENT TK_ASSIGN KW_READINTEGER  { $$ = template("%s = readInteger();", $1); }
										| TK_IDENT TK_ASSIGN KW_READREAL  { $$ = template("%s = readReal();", $1); };

/* Variable declaration
*/


var_decl: KW_VAR var_body {};
				|


var_body: IDENT TK_COLON expression TK_SEMCOLUMN  {};
        | mult_vars TK_COLON expression TK_SEMCOLUMN {};
				| var_body TK_SEMCOLUMN mult_vars TK_COLON expression TK_SEMCOLUMN {};

mult_vars: IDENT
			  |  mult_vars TK_COMMA IDENT



/*

statements: 				        	{ $$ = ""; };
statements: statement_list		   		{ $$ = $1; };

statement_list: statement
	      | statement_list ';' statement  { $$ = template("%s%s", $1, $3); };


statement: proc_call  						{ $$ = template("%s;\n", $1); };

proc_call: IDENT '(' arguments ')' 			{ $$ = template("%s(%s)", $1, $3); };

*/


/* Arguments for the win
*/
arguments :									{ $$ = ""; }
	 	  | arglist 						{ $$ = $1; };

arglist: expression							{ $$ = $1; }
       | arglist ',' expression 			{ $$ = template("%s,%s", $1, $3);  };



/* Expressions simple or not here i come
expr:
  POSINT {$$ = template( "%s", $1);}
| REAL {$$ = template( "%s", $1);}
| TK_BOOL {$$ = template( "%s", $1);}
| TK_CHAR {$$ = template( "%s", $1);}
| STRING  {$$ = template( "%s", $1);}
| TK_DIGIT {$$ = template( "%s", $1);}
| TK_DECIMAL {$$ = template( "%s", $1);}
| IDENTIFIER {$$ = template( "%s", $1);}
| KW_TRUE {$$ = template( "1");}
| KW_FALSE {$$ = template( "0");}
| '(' expr ')' {$$ = template( "(%s)",$2);}
| math_expr {$$ = template( "%s", $1);}
| '+' expr {$$ = template( "+%s", $2);}
| '-' expr {$$ = template( "-%s", $2);}
| compare_expr {$$ = $1;}
| IDENTIFIER '(' func_attr ')' {$$ = template( "%s(%s)", $1, $3);}
| IDENTIFIER '('  ')' {$$ = template( "%s()", $1);}
| lib_func1 {$$ = template( "%s", $1);}
| IDENTIFIER hooks {$$ = template( "%s%s", $1, $2);}
;
*/

expression: INT 				{$$ = template( "%s", $1);}
					  | REAL				{$$ = template( "%s", $1);}
					  | STRING 				{$$ = template( "%s", $1);}
						| IDENT				{$$ = template( "%s", $1);}
						| TK_BOOL_TRUE			{$$ = template( "1");}
						| TK_BOOL_FALSE			{$$ = template( "0");}
						| TK_CHAR				{$$ = template( "%s", $1);}
						| TK_DIGIT				{$$ = template( "%s", $1);}
						| TK_PLUS expression 			{$$ = template( "+%s", $2);}
						| TK_MINUS expression 		{$$ = template( "-%s", $2);}
						| TK_LPAR expression TK_RPAR {$$ = template( "(%s)",$2);}
						| mathematics {$$ = template( "%s", $1);}
						| compare {$$ = $1;}
						| IDENT TK_LPAR function TK_RPAR {$$ = template( "%s(%s)", $1, $3);}
						| IDENT TK_LPAR TK_RPAR  {$$ = template( "%s()", $1);}
						| IDENT brackets  {$$ = template( "%s%s", $1, $2);}
										|

%%


int main()
{
	yyparse();
}

int yyerror (char *s)
{

  fprintf (stderr, "%s in line: %d\n", s, line_num);
  return 1;
}
