%{
  #define TK_DIGIT 200
  #define TK_ID 201
  #define TK_INT 202
  #define TK_REAL 203
  #define TK_BOOL 204
  #define TK_STRING 205
  #define TK_ASSIGN 206
  #define TK_UNEQUAL 207
  #define TK_SMAAALLLER 208
  #define TK_NOT_EQUAL 209
  #define TK_AND 210
  #define TK_OR 211
  #define TK_GREATER_EQUAL 212
  #define KW_AND 250
  #define KW_ARRAY 251
  #define KW_BOOLEAN 252
  #define KW_CHAR 253
  #define KW_BEGIN 254
  #define KW_DIV 255
  #define KW_DO 256
  #define KW_ELSE 257
  #define KW_FOR 258
  #define KW_END 259
  #define KW_FUNCTION 260
  #define KW_GOTO 261
  #define KW_IF 262
  #define KW_INTEGER 263
  #define KW_VAR 264
  #define KW_MOD 265
  #define KW_NOT 266
  #define KW_OR 267
  #define KW_OF 268
  #define KW_WHILE 269
  #define KW_PROCEDURE 270
  #define KW_PROGRAM 271
  #define KW_REAL 272
  #define KW_REPEAT 273
  #define KW_TO 274
  #define KW_RESULT 275
  #define KW_RETURN 276
  #define KW_THEN 277
  #define KW_UNTIL 278
  #define KW_DOWNTO 279
  #include <stdio.h>
  #include <assert.h>
  #include <string.h>
  #include "cgen.h"
  int lineNum = 1;


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
ID             [a-zA-Z][{DIGIT}a-zA-Z_]*
INT            {DIGIT}{DIGIT}*
REAL           ("."{INT})|({INT}("."{INT}?)?)([eE][+-]?{INT})?
BOOLEAN        ("true"|"false")
STRING         (['](.)*['])|(["](.)*["])


%x comments
%x macro

%%

@defmacro[ \r\t]+       BEGIN(macro);
<macro>{ID}  {
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




and             return KW_AND;
array           return KW_ARRAY;
boolean         return KW_BOOLEAN;
char            return KW_CHAR;
begin           return KW_BEGIN;
div             return KW_DIV;
do              return KW_DO;
else            return KW_ELSE;
for             return KW_FOR;
end             return KW_END;
function        return KW_FUNCTION;
goto            return KW_GOTO;
if              return KW_IF;
integer         return KW_INTEGER;
var             return KW_VAR;
mod             return KW_MOD;
not             return KW_NOT;
or              return KW_OR;
of              return KW_OF;
while           return KW_WHILE;
procedure       return KW_PROCEDURE;
program         return KW_PROGRAM;
real            return KW_REAL;
repeat          return KW_REPEAT;
to              return KW_TO;
result          return KW_RESULT;
return          return KW_RETURN;
then            return KW_THEN;
until           return KW_UNTIL;
downto          return KW_DOWNTO;



{ID}        { return TK_ID; }
{DIGIT}	    { return TK_DIGIT; }
{INT}       { return TK_INT; }
{REAL}      { return TK_REAL; }
{BOOLEAN}	  { return TK_BOOL; }
{STRING}    { return TK_STRING; }



"+"         return '+';
"-"         return '-';
"*"         return '*';
"/"         return '/';
"="	        return '=';
"<>"        return TK_UNEQUAL;

"<"	        return '<';
">"	        return '>';
"<="	      return TK_SMAAALLLER;
">="	      return TK_GREATER_EQUAL;
"!="	      return TK_NOT_EQUAL;
"&&"	      return TK_AND;
"||"	      return TK_OR;
"!"	        return '!';


"("	    	return '(';
")"		return ')';
";"		return ';';
","		return ',';
"["		return '[';
"]"		return ']';



"(*"                  BEGIN(comments);

<comments>[^*\n]*
<comments>"*"+[^*)\n]*
<comments>\n          ++lineNum;
<comments>"*"+")"     BEGIN(INITIAL);



"//"[^\n]*  				/* eat line comments */



[ \r\t]+		/* eat whitespace */
\n 			 ++lineNum;

":="        { return TK_ASSIGN ;}
.           { printf("Line %d Lexical Error: Unrecognized literal %s\n", lineNum, yytext); }
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
