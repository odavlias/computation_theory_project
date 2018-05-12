%{
  #define TK_DIGIT 200
  #define TK_IDENTIFIER 201
  #define TK_INT 202
  #define TK_REAL 203
  #define TK_BOOL 204
  #define TK_STRING 205
  #define TK_ASSIGN 206
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

  int lineNum = 1;
%}

DIGIT          [0-9]
ID             [a-zA-Z][{DIGIT}a-zA-Z_]*
INT            {DIGIT}{DIGIT}*
REAL           ("."{INT})|({INT}("."{INT}?)?)([eE][+-]?{INT})?
BOOLEAN        ("true"|"false")
CHAR           (['](.)*("\n")*(.)*['])|(["](.)*("\n")*(.)*["])
%x comments

%%

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




{DIGIT}	    { yylval.str = strdup(yytext); return TK_DIGIT;}
{ID}        { yylval.str = strdup(yytext); return TK_IDENTIFIER; }
{INT}       { yylval.str = strdup(yytext); return TK_INT; }
{REAL}      { yylval.str = strdup(yytext); return TK_REAL; }
{BOOL}	    { yylval.str = strdup(yytext); return TK_BOOL; }
{STRING}    { yylval.str = strdup(yytext); return TK_STRING;}




"+"         return '+';
"-"         return '-';
"*"         return '*';
"/"         return '/';
"="	        return '=';
"<>"        return '<>';

"<"	        return '<';
">"	        return '>';
"<="	      return LESS_EQUAL;
">="	      return GREATER_EQUAL;
"!="	      return NOT_EQUAL;
"&&"	      return AND;
"||"	      return OR;
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
<comments>\n          ++lineNum
<comments>"*"+"/"     BEGIN(0);

"//"[^\n]*  				/* eat line comments */



[ \r\t]+		/* eat whitespace */
\n 			 ++lineNum;

":="        { return TK_ASSIGN ;}
.           { printf("Line %d Lexical Error: Unrecognized literal %s\n", lineNum, yytext); }
<<EOF>>     return TK_EOF;

%%
