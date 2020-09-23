%{
#include <iostream>
#include <stdio.h>
using namespace std;
	#include <stdlib.h>
	#include <string.h>

	#include "y.tab.h"
	int line = 1;
	extern int scope;

	extern void yyerror(const char *);  

	extern struct node * checksym(char *);
%}


D   		[0-9]
L   		[a-zA-Z_]
A   		[a-zA-Z_0-9]
WS  		[ \t\v\f]


%%

[\n]		{  line++;	}
"//".*["\n"*] {line++;};
"/*"(.|"\n")*"*/"(" "|\n)* {line++;};

int			{   yylval.ival=0; return(INT); 	}
float		{  yylval.ival=1; return(FLOAT); }
char		{  yylval.ival=2; return(CHAR); }
void		{  yylval.ival=3; return(VOID); }

"#"			{  return HASH; }
include		{return INCLUDE; }

"math.h"	{   return MATH; }
"iostream.h"	{  return IOSTREAM; }
"stdlib.h"	{  return STDLIB; }
"string.h"	{  return STRING; }
"time.h"	{  return TIME; }


for			{  return FOR; }
while			{   return WHILE; }
if			{ return IF; }
else			{   return ELSE; }

cout 		{ 	 return COUT; }
return 		{ 	 return RETURN; }


{L}{A}*							{	 
									yylval.ptr = checksym(yytext); 
									return IDENTIFIER;
								}
{D}+\.{D}+                      {
									yylval.fval=atof(yytext);
									return FLOAT_LITERAL;
								}  		
{D}+							{
									yylval.ival=atoi(yytext);
									return INTEGER_LITERAL;
								}	

"'"."'"							{
									yylval.cval= yytext[1];
									return CHARACTER_LITERAL;  
								}

\"{A}+(".h"|".c")\"				{return HEADER_LITERAL;}

\".*\"							{  return STRING_LITERAL; }


"+="		{  return(ADD_ASSIGN); }
"-="		{ return(SUB_ASSIGN); }
"*="		{  return(MUL_ASSIGN); }
"/="		{  return(DIV_ASSIGN); }
"%="		{ return(MOD_ASSIGN); }

"++"		{  return(INC_OP); }
"--"		{ return(DEC_OP); }
"<="		{  return(LE_OP); }
">="		{ return(GE_OP); }
"=="		{  return(EQ_OP); }
"!="		{ return(NE_OP); }

";"			{ return(';'); }
"{"			{ scope++; return('{'); }
"}"			{  return('}'); }
","			{ return(','); }
":"			{  return(':'); }
"="			{  return('='); }
"("			{ return('('); }
")"			{ return(')'); }
("["|"<:")	{ return('['); }
("]"|":>")	{ return(']'); }
"."			{  return('.'); }
"&"			{ return('&'); }
"!"			{ return('!'); }
"~"			{  return('~'); }
"-"			{ return('-'); }
"+"			{  return('+'); }
"*"			{  return('*'); }
"/"			{ return('/'); }
"%"			{  return('%'); }
"<"			{ return('<'); }
">"			{ return('>'); }
"^"			{ return('^'); }
"|"			{  return('|'); }
"?"			{ return('?'); }


{WS}+		{ }


%%

int yywrap(void)
{
	return 1;
}


