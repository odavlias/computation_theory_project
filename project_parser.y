%{
#include <stdarg.h>
#include <stdio.h>
#include "cgen.h"

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







%start input

%type <crepr> program_decl body statements statement_list
%type <crepr> statement proc_call arguments
%type <crepr> arglist expression
%type <crepr> var_decl
%type <crepr> program

%%

input: program {
	/* We have a successful parse!
		Check for any errors and generate output.
	*/
	if(yyerror_count==0) {
		puts(c_prologue);
		printf("/* program  %s */ \n\n", $1);
		printf("int main() %s \n", $2);
	}
};

program:  program_decl body  '.' {};
	| program_decl var_decl body  '.' {};
	| program_decl var_decl program body  '.' {};
	| program_decl program body  '.' {};

program_decl : KW_PROGRAM IDENT ';'  	{ $$ = $2; };
/* help **
 * $$ = template("{\n %s \n }\n", $2); */

/** Commands */

/* commads pattern */
command_pattern: complex_commands TK_SEMCOLUMN 		{ $$ = template("%s", $1); }
								 | assign_command									{ $$ = template("%s", $1); }
								 | special_assign									{ $$ = template("%s", $1); }
								 | if_statement										{ $$ = template("%s", $1); }
								 | for_loop												{ $$ = template("%s", $1); }
								 | while_loop											{ $$ = template("%s", $1); }
								 | label_command									{ $$ = template("%s", $1); }
								 | goto_command										{ $$ = template("%s", $1); }
								 | return_command									{ $$ = template("%s", $1); }
								 | call_function									{ $$ = template("%s", $1); }
								 | TK_SEMCOLUMN complex_commands  { $$ = template("%s", $2); }
								 | TK_SEMCOLUMN assign_command		{ $$ = template("%s", $2); }
								 | TK_SEMCOLUMN special_assign		{ $$ = template("%s", $2); }
								 | TK_SEMCOLUMN if_statement			{ $$ = template("%s", $2); }
								 | TK_SEMCOLUMN for_loop					{ $$ = template("%s", $2); }
								 | TK_SEMCOLUMN while_loop				{ $$ = template("%s", $2); }
								 | TK_SEMCOLUMN label_command			{ $$ = template("%s", $2); }
								 | TK_SEMCOLUMN goto_command			{ $$ = template("%s", $2); }
								 | TK_SEMCOLUMN return_command		{ $$ = template("%s", $2); }
								 | TK_SEMCOLUMN call_function			{ $$ = template("%s", $2); };


/* complex commands */
complex_commands: KW_BEGIN command_list KW_END { $$ = template("%s", $2); };

/* command list */
command_list: 																 						{ $$ = template(""); }
							| command_list assign_command    						{ $$ = template("%s\n%s", $1, $2); }
							| command_list special_assign		 						{ $$ = template("%s\n%s", $1, $2); }
							| command_list if_statement			 						{ $$ = template("%s\n%s", $1, $2); }
							| command_list for_loop					 						{ $$ = template("%s\n%s", $1, $2); }
							| command_list while_loop			   						{ $$ = template("%s\n%s", $1, $2); }
							| command_list label_command		 						{ $$ = template("%s\n%s", $1, $2); }
							| command_list goto_command			 						{ $$ = template("%s\n%s", $1, $2); }
							| command_list return_command    						{ $$ = template("%s\n%s", $1, $2); }
							| command_list call_function		 						{ $$ = template("%s\n%s", $1, $2); }
							| command_list TK_SEMCOLUMN assign_command  { $$ = template("%s\n%s", $1, $3); }
							| command_list TK_SEMCOLUMN special_assign	{ $$ = template("%s\n%s", $1, $3); }
							| command_list TK_SEMCOLUMN if_statement		{ $$ = template("%s\n%s", $1, $3); }
							| command_list TK_SEMCOLUMN for_loop				{ $$ = template("%s\n%s", $1, $3); }
							| command_list TK_SEMCOLUMN while_loop			{ $$ = template("%s\n%s", $1, $3); }
							| command_list TK_SEMCOLUMN label_command		{ $$ = template("%s\n%s", $1, $3); }
							| command_list TK_SEMCOLUMN goto_command		{ $$ = template("%s\n%s", $1, $3); }
							| command_list TK_SEMCOLUMN return_command  { $$ = template("%s\n%s", $1, $3); }
							| command_list TK_SEMCOLUMN call_function		{ $$ = template("%s\n%s", $1, $3); };

/* simple commands implementation */

assign_command: TK_IDENT TK_ASSIGN expression  { $$ = template("%s = %s;", $1, $3); };

special_assign: KW_RESULT TK_ASSIGN expression  { $$ = template("result = %s;", $3); };

if_statement: KW_IF expression KW_THEN command_pattern  { $$ = template("if (%s){\n\t%s}\n", $2, $4); }
						  | if_statement KW_ELSE command_pattern    { $$ = template("else{\n\t%s}\n", $3); };

for_loop: KW_FOR TK_IDENT TK_ASSIGN expression KW_TO expression KW_DO command_pattern 			 { $$ = template("for(%s=%s;%s<=%s;%s++){\n\t%s}\n", $2, $4, $2, $6, $2, $8);}
					| KW_FOR TK_IDENT TK_ASSIGN expression KW_DOWNTO expression KW_DO command_pattern  { $$ = template("for(%s=%s;%s>=%s;%s--){\n\t%s}\n", $2, $4, $2, $6, $2, $8);};

while_loop: KW_WHILE expression KW_DO command_pattern        { $$ = template("while (%s){\n\t%s}\n", $2, $4); }
						| KW_REPEAT command_pattern KW_UNTIL expression  { $$ = template("do{\n\t%s\n} while( %s );", $2, $4); };

label_command: TK_IDENT TK_COLON command_pattern  { $$ = template("%s: %s", $1, $3); };

goto_command: KW_GOTO TK_IDENT  { $$ = template("goto %s;", $2); };

return_command: KW_RETURN  { $$ = template("return;"); };

/* TODO: call_function */


/* Variable declaration
*/


var_decl: KW_VAR var_body {};
				|


var_body: IDENT TK_COLON expression TK_SEMCOLUMN  {};
        | mult_vars TK_COLON expression TK_SEMCOLUMN {};
				| var_body TK_SEMCOLUMN mult_vars TK_COLON expression TK_SEMCOLUMN {};

mult_vars: IDENT
			  |  mult_vars TK_COMMA IDENT





body : KW_BEGIN statements KW_END   	{ $$ = template("{\n %s \n }\n", $2); };
			|









statements: 				        	{ $$ = ""; };
statements: statement_list		   		{ $$ = $1; };

statement_list: statement
	      | statement_list ';' statement  { $$ = template("%s%s", $1, $3); };


statement: proc_call  						{ $$ = template("%s;\n", $1); };

proc_call: IDENT '(' arguments ')' 			{ $$ = template("%s(%s)", $1, $3); };


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


expression: POSINT 							/* Default action: $$ = $1 */
          | REAL
          | STRING 							{ $$ = string_ptuc2c($1); };
					| IDENT							{}
					| TK_BOOL_TRUE			{}
					| TK_BOOL_FALSE			{}
					| TK_CHAR						{}
					| TK_DIGIT					{}
					|
%%

sadf

int main()
{
	yyparse();
}

int yyerror (char *s)
{

  fprintf (stderr, "%s in line: %d\n", s, line_num);
  return 1;
}
