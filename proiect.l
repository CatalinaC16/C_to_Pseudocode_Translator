cif	[0-9]
azAZ	[A-Za-z]
%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
%}

%%
"include <"{azAZ}+"."{azAZ}+">" 	{yylval.str=strdup(yytext);return INCL;} 
"double"				{return DOUBLERESERVE;}
"int"	        			{return INTRESERVE;}
"float"					{return FLOATRESERVE;}
"char"					{return CHARRESERVE;}
"void"  				{yylval.str=strdup(yytext); return VOID;}
"printf" 				{yylval.str=strdup(yytext); return PRTF;}
"scanf" 				{yylval.str=strdup(yytext); return SCNF;}
"if"					{yylval.str=strdup(yytext); return IF;}
"else"					{yylval.str=strdup(yytext); return ELSE;}
"for"   				{yylval.str=strdup(yytext); return FOR;}
"while" 				{yylval.str=strdup(yytext); return WHILE;}
"do" 					{yylval.str=strdup(yytext); return DO;}
"return" 				{yylval.str=strdup(yytext); return RETURN;}
(-)?[0-9]+ 				{yylval.number=atoi(yytext); return INTEGER;}
{cif}+"."{cif}+			        {yylval.doubflt=atof(yytext); return FLOATVAL;}
"'"{azAZ}"'" 				{yylval.str=strdup(yytext); return CHARVAL;}
{azAZ}[\t]*({azAZ}|{cif})* 	        {yylval.str=strdup(yytext); return IDENT;} 
[\"](.*)[\"] 				{return QUOTES;}
\>					{yylval.str=strdup(yytext); return GREATER;}
\<					{yylval.str=strdup(yytext); return LESS;}
\>=					{yylval.str=strdup(yytext); return GREATEREQ;}
\<=					{yylval.str=strdup(yytext); return LESSEQ;}
\==					{yylval.str=strdup(yytext); return EQEQ;}
\+					{return PLUS;}
\+=      				{return PLUSEQ; }
\-					{return MINUS;}
\-=      				{return MINUSEQ; }
\* 					{return MULTIPLICATION;}
\/ 					{return DIVIDE;}
\= 					{return EQ;}
\.      				{return DOT;}
\'      				{return QUOTE;}
\,      				{return COMMA;}
\;					{return SEMICOLON;}
\"					{return DEN;}
\%					{return MODULO;}
\&					{return AND;}
\--  					{return DECREMENT;}
\++    					{return INCREMENT;}
\{      				{return OPENCURL;}
\}	    				{return CLOSECURL;}
\(      				{return OPPARENTH;}
\)      				{return CLPARENTH;}
\n
[ \t]+ 	
%%
