%{
  #include <stdio.h>
  #include <assert.h>
  #include <string.h>
  #include "cgen.h"
  #include "project_parser.tab.h"


  int line_num = 1;


  int mactable_size = 0;
  #define MAXMACRO 32
  char* mactable[MAXMACRO][2];
  /* Return 1 on success, 0 on failure (macro table full) */
  int set_macro(char* name, char* def);

  /* Return def for macro, or NULL if no such macro is defined. */
  char* get_macro(char* name);
  int def_fix = 0;



%}

DIGIT          [0-9]
IDENT          [a-zA-Z][{0-9a-zA-Z_]*
INT            {DIGIT}{DIGIT}*
REAL           ("."{INT})|({INT}("."{INT}?)?)([eE][+-]?{INT})?
STRING         (['](.)*['])|(["](.)*["])


%x comments
%x macro

%%

@defmacro[ \r\t]+       BEGIN(macro);
<macro>{IDENT}  {
                /* Store macro name */
                char* name = strdup(yytext);
                char* def = NULL;
                size_t deflen = 0;
                char c;

                FILE* deff = open_memstream(&def, &deflen);

                while((c=input())!='\n')
                  if (c != '(' && c != ')')
                    fputc(c, deff);
                fclose(deff);

                if(!set_macro(name, def))
                  printf("lexer error: failed to define macro '%s'\n", name);
                BEGIN(INITIAL);
};




and             { printf("token KW_AND: %s in line num %d\n", yytext, line_num);
                  return TK_AND; }
array           { printf("token KW_ARRAY: %s in line num %d\n", yytext, line_num);
                  return KW_ARRAY; }
boolean         { printf("token KW_BOOLEAN: %s in line num %d\n", yytext, line_num);
                  yylval.crepr = strdup(yytext);
                  return KW_BOOLEAN; }
char            { printf("token KW_CHAR: %s in line num %d\n", yytext, line_num);
                  yylval.crepr = strdup(yytext);
                  return KW_CHAR; }
begin           { printf("token KW_BEGIN: %s in line num %d\n", yytext, line_num);
                  return KW_BEGIN; }
div             { printf("token KW_DIV: %s in line num %d\n", yytext, line_num);
                  return TK_DIV; }
do              { printf("token KW_DO: %s in line num %d\n", yytext, line_num);
                  return KW_DO; }
else            { printf("token KW_ELSE: %s in line num %d\n", yytext, line_num);
                  return KW_ELSE; }
for             { printf("token KW_FOR: %s in line num %d\n", yytext, line_num);
                  return KW_FOR; }
end             { printf("token KW_END: %s in line num %d\n", yytext, line_num);
                  return KW_END; }
function        { printf("token KW_FUNCTION: %s in line num %d\n", yytext, line_num);
                  return KW_FUNCTION; }
goto            { printf("token KW_GOTO: %s in line num %d\n", yytext, line_num);
                  return KW_GOTO; }
if              { printf("token KW_IF: %s in line num %d\n", yytext, line_num);
                  return KW_IF; }
integer         { printf("token KW_INTEGER: %s in line num %d\n", yytext, line_num);
                  yylval.crepr = strdup(yytext);
                  return KW_INTEGER; }
var             { printf("token KW_VAR: %s in line num %d\n", yytext, line_num);
                  yylval.crepr = strdup(yytext);
                  return KW_VAR; }
mod             { printf("token KW_MOD: %s in line num %d\n", yytext, line_num);
                  return TK_MOD; }
not             { printf("token KW_NOT: %s in line num %d\n", yytext, line_num);
                  return TK_NOT; }
or              { printf("token TK_OR: %s in line num %d\n", yytext, line_num);
                  return TK_OR; }
of              { printf("token KW_OF: %s in line num %d\n", yytext, line_num);
                  return KW_OF; }
while           { printf("token KW_WHILE: %s in line num %d\n", yytext, line_num);
                  return KW_WHILE; }
procedure       { printf("token KW_PROCEDURE: %s in line num %d\n", yytext, line_num);
                  return KW_PROCEDURE; }
program         { printf("token KW_PROGRAM: %s in line num %d\n", yytext, line_num);
                  return KW_PROGRAM; }
real            { printf("token KW_REAL: %s in line num %d\n", yytext, line_num);
                  yylval.crepr = strdup(yytext);
                  return KW_REAL; }
repeat          { printf("token KW_REPEAT: %s in line num %d\n", yytext, line_num);
                  return KW_REPEAT; }
to              { printf("token KW_TO: %s in line num %d\n", yytext, line_num);
                  return KW_TO; }
result          { printf("token KW_RESULT: %s in line num %d\n", yytext, line_num);
                  return KW_RESULT; }
return          { printf("token KW_RETURN: %s in line num %d\n", yytext, line_num);
                  return KW_RETURN; }
then            { printf("token KW_THEN: %s in line num %d\n", yytext, line_num);
                  return KW_THEN; }
until           { printf("token KW_UNTIL: %s in line num %d\n", yytext, line_num);
                  return KW_UNTIL; }
downto          { printf("token KW_DOWNTO: %s in line num %d\n", yytext, line_num);
                  return KW_DOWNTO; }
true            { printf("token TK_BOOL_TRUE: %s in line num %d\n", yytext, line_num);
                  return TK_BOOL_TRUE; }
false           { printf("token TK_BOOL_FALSE: %s in line num %d\n", yytext, line_num);
                  return TK_BOOL_FALSE; }
type            { printf("token KW_TYPE: %s in line num %d\n", yytext, line_num);
                  return KW_TYPE; }
readString      { printf("token KW_READSTRING: %s in line num %d\n", yytext, line_num);
                  return KW_READSTRING; }
readInteger     { printf("token KW_READINTEGER: %s in line num %d\n", yytext, line_num);
                  return KW_READINTEGER; }
readReal        { printf("token KW_READREAL: %s in line num %d\n", yytext, line_num);
                  return KW_READREAL; }
writeString     { printf("token KW_WRITESTRING: %s in line num %d\n", yytext, line_num);
                  return KW_WRITESTRING; }
writeInteger    { printf("token KW_WRITEINTEGER: %s in line num %d\n", yytext, line_num);
                  return KW_WRITEINTEGER; }
writeReal       { printf("token KW_WRITEREAL: %s in line num %d\n", yytext, line_num);
                  return KW_WRITEREAL; }




{IDENT}     { printf("token TK_IDENT: %s in line num %d\n", yytext, line_num);
              yylval.crepr = strdup(yytext);
              return TK_IDENT; }
{INT}       { printf("token TK_INT: %s in line num %d\n", yytext, line_num);
              yylval.crepr = strdup(yytext);
              return TK_INT; }
{REAL}      { printf("token TK_REAL: %s in line num %d\n", yytext, line_num);
              yylval.crepr = strdup(yytext);
              return TK_REAL; }
{STRING}    { printf("token TK_STRING: %s in line num %d\n", yytext, line_num);
              yylval.crepr = strdup(yytext);
              return TK_STRING; }



"+"         { printf("token +: %s in line num %d\n", yytext, line_num);
              return TK_PLUS;}
"-"         { printf("token -: %s in line num %d\n", yytext, line_num);
              return TK_MINUS;}
"*"         { printf("token *: %s in line num %d\n", yytext, line_num);
              return TK_MULTIPLY;}
"/"         { printf("token /: %s in line num %d\n", yytext, line_num);
              return TK_DIVIDE;}
"="	        { printf("token =: %s in line num %d\n", yytext, line_num);
              return TK_EQUAL;}
"<>"        { printf("token TK_UNEQUAL: %s in line num %d\n", yytext, line_num);
              return TK_NOTEQUAL;}
"<"	        { printf("token <: %s in line num %d\n", yytext, line_num);
              return TK_SMALLER;}
">"	        { printf("token >: %s in line num %d\n", yytext, line_num);
              return TK_GREATER;}
"<="	      { printf("token TK_SMAAALLLER: %s in line num %d\n", yytext, line_num);
              return TK_SMALLEREQUAL;}
">="	      { printf("token TK_GREATER_EQUAL: %s in line num %d\n", yytext, line_num);
              return TK_GREATER_EQUAL;}
"&&"	      { printf("token TK_AND: %s in line num %d\n", yytext, line_num);
              return TK_AND;}
"||"	      { printf("token TK_OR: %s in line num %d\n", yytext, line_num);
              return TK_OR;}
"!"	        { printf("token !: %s in line num %d\n", yytext, line_num);
              return TK_NOT;}


"("	  { printf("token (: %s in line num %d\n", yytext, line_num);
  	    return TK_LPAR;}
")"		{ printf("token ): %s in line num %d\n", yytext, line_num);
        return TK_RPAR;}
";"		{ printf("token ;: %s in line num %d\n", yytext, line_num);
        return TK_SEMICOLON;}
","		{ printf("token ,: %s in line num %d\n", yytext, line_num);
        return TK_COMMA;}
"["		{ printf("token [: %s in line num %d\n", yytext, line_num);
        return TK_LBRACKET;}
"]"		{ printf("token ]: %s in line num %d\n", yytext, line_num);
        return TK_RBRACKET;}
":"   { printf("token :: %s in line num %d\n", yytext, line_num);
        return TK_COLON;}
"."   { printf("token .: %s in line num %d\n", yytext, line_num);
        return TK_POINT;}



"(*"                  BEGIN(comments);

<comments>[^*\n]*
<comments>"*"+[^*)\n]*
<comments>\n          ++line_num;
<comments>"*"+")"     BEGIN(INITIAL);



"//"[^\n]*  				/* eat line comments */



[ \r\t]+		/* eat whitespace */
\n 			 ++line_num;

":="        { printf("token TK_ASSIGN: %s in line num %d\n", yytext, line_num);
              return TK_ASSIGN ;}
.           { printf("Line %d Lexical Error: Unrecognized literal %s\n", line_num, yytext); }
<<EOF>>     return EOF;

%%



int set_macro(char* name, char* def)
{
	/* Check to see if macro already defined, and redefine it. */
	int i;
	for(i=0; i<mactable_size; i++) {
		if(strcmp(mactable[i][0], name)==0) {
			/* found ! */
			free(name);
			free(mactable[i][1]);
			mactable[i][1] = def;
			break;
		}
	}
	if(i<mactable_size)
		return 1;
	else if(mactable_size < MAXMACRO) {
		/* new entry */
		/*assert(i==mactable_size);*/
		mactable[i][0] = name;
		mactable[i][1] = def;
		mactable_size++;
		return 1;
	}
	else
		return 0;
}

char* get_macro(char* name)
{
  def_fix = 1;
	int i;
	for(i=0; i<mactable_size; i++) {
		if(strcmp(mactable[i][0], name)==0)
			return mactable[i][1];
	}
	return NULL;
}
