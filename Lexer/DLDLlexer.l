%option yylineno
%option noyywrap

%{
#include <AstNodes.h>
#include <Deamer/AstGen/AstInformation.h>
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstTree.h>
#include <stdio.h>
#include <string.h>
#include "../Parser/DLDLparser.tab.h"
void showError();
extern int DLDLlex();
%}

NEWLINE   ([\n])
SPACES   ([ ]+)
CR   ([\r])
TAB   ([\t])
LEFT_CURLY_BRACKET   ([(])
RIGHT_CURLY_BRACKET   ([)])
LEFT_BRACKET   ([{])
RIGHT_BRACKET   ([}])
LEFT_SQUARE_BRACKET   ([\[])
RIGHT_SQUARE_BRACKET   ([\]])
DELETE   (DELETE[:])
IGNORE   (IGNORE[:])
TERMINAL   (TERMINAL[:])
NONTERMINAL   (NONTERMINAL[:])
GROUP   (GROUP[:])
ALIAS   (ALIAS[:])
START   (START[:])
COMMENT   (COMMENT[:])
UNIQUE   (UNIQUE[:])
TYPE   (TYPE[:])
VARNAME   ((([\[][^\]]+[\] \\a-zA-Z_0-9\}\{\&\#\@\%\$]*[\]](([\{][ ]*[0-9]+[ ]*[,][ ]*[0-9]+[ ]*[\}])|([+*]{0,1}))([\)]*)[|]{0,1})|([\^]{0,1}[\(][^\)]+[\) a-zA-Z_0-9\[\]\}\{\&\#\@\%\$]*[\)][\]]{0,1}(([\{][ ]*[0-9]+[ ]*[,][ ]*[0-9]+[ ]*[\}])|([+*]{0,1}))((([|\)]*))[+*]{0,1}[$]{0,1}))|([a-zA-Z_0-9]+))+)
%%
{NEWLINE}
{SPACES}
{CR}
{TAB}
{LEFT_CURLY_BRACKET}   {DLDLlval.DeamerNode = (deamer::AstInformation*) malloc(sizeof(deamer::AstInformation)); sscanf(yytext, "%s", DLDLlval.DeamerNode->ValueName); DLDLlval.DeamerNode->LineNumber = DLDLlineno; return (LEFT_CURLY_BRACKET);}
{RIGHT_CURLY_BRACKET}   {DLDLlval.DeamerNode = (deamer::AstInformation*) malloc(sizeof(deamer::AstInformation)); sscanf(yytext, "%s", DLDLlval.DeamerNode->ValueName); DLDLlval.DeamerNode->LineNumber = DLDLlineno; return (RIGHT_CURLY_BRACKET);}
{LEFT_BRACKET}   {DLDLlval.DeamerNode = (deamer::AstInformation*) malloc(sizeof(deamer::AstInformation)); sscanf(yytext, "%s", DLDLlval.DeamerNode->ValueName); DLDLlval.DeamerNode->LineNumber = DLDLlineno; return (LEFT_BRACKET);}
{RIGHT_BRACKET}   {DLDLlval.DeamerNode = (deamer::AstInformation*) malloc(sizeof(deamer::AstInformation)); sscanf(yytext, "%s", DLDLlval.DeamerNode->ValueName); DLDLlval.DeamerNode->LineNumber = DLDLlineno; return (RIGHT_BRACKET);}
{LEFT_SQUARE_BRACKET}   {DLDLlval.DeamerNode = (deamer::AstInformation*) malloc(sizeof(deamer::AstInformation)); sscanf(yytext, "%s", DLDLlval.DeamerNode->ValueName); DLDLlval.DeamerNode->LineNumber = DLDLlineno; return (LEFT_SQUARE_BRACKET);}
{RIGHT_SQUARE_BRACKET}   {DLDLlval.DeamerNode = (deamer::AstInformation*) malloc(sizeof(deamer::AstInformation)); sscanf(yytext, "%s", DLDLlval.DeamerNode->ValueName); DLDLlval.DeamerNode->LineNumber = DLDLlineno; return (RIGHT_SQUARE_BRACKET);}
{DELETE}   {DLDLlval.DeamerNode = (deamer::AstInformation*) malloc(sizeof(deamer::AstInformation)); sscanf(yytext, "%s", DLDLlval.DeamerNode->ValueName); DLDLlval.DeamerNode->LineNumber = DLDLlineno; return (DELETE);}
{IGNORE}   {DLDLlval.DeamerNode = (deamer::AstInformation*) malloc(sizeof(deamer::AstInformation)); sscanf(yytext, "%s", DLDLlval.DeamerNode->ValueName); DLDLlval.DeamerNode->LineNumber = DLDLlineno; return (IGNORE);}
{TERMINAL}   {DLDLlval.DeamerNode = (deamer::AstInformation*) malloc(sizeof(deamer::AstInformation)); sscanf(yytext, "%s", DLDLlval.DeamerNode->ValueName); DLDLlval.DeamerNode->LineNumber = DLDLlineno; return (TERMINAL);}
{NONTERMINAL}   {DLDLlval.DeamerNode = (deamer::AstInformation*) malloc(sizeof(deamer::AstInformation)); sscanf(yytext, "%s", DLDLlval.DeamerNode->ValueName); DLDLlval.DeamerNode->LineNumber = DLDLlineno; return (NONTERMINAL);}
{GROUP}   {DLDLlval.DeamerNode = (deamer::AstInformation*) malloc(sizeof(deamer::AstInformation)); sscanf(yytext, "%s", DLDLlval.DeamerNode->ValueName); DLDLlval.DeamerNode->LineNumber = DLDLlineno; return (GROUP);}
{ALIAS}   {DLDLlval.DeamerNode = (deamer::AstInformation*) malloc(sizeof(deamer::AstInformation)); sscanf(yytext, "%s", DLDLlval.DeamerNode->ValueName); DLDLlval.DeamerNode->LineNumber = DLDLlineno; return (ALIAS);}
{START}   {DLDLlval.DeamerNode = (deamer::AstInformation*) malloc(sizeof(deamer::AstInformation)); sscanf(yytext, "%s", DLDLlval.DeamerNode->ValueName); DLDLlval.DeamerNode->LineNumber = DLDLlineno; return (START);}
{COMMENT}   {DLDLlval.DeamerNode = (deamer::AstInformation*) malloc(sizeof(deamer::AstInformation)); sscanf(yytext, "%s", DLDLlval.DeamerNode->ValueName); DLDLlval.DeamerNode->LineNumber = DLDLlineno; return (COMMENT);}
{UNIQUE}   {DLDLlval.DeamerNode = (deamer::AstInformation*) malloc(sizeof(deamer::AstInformation)); sscanf(yytext, "%s", DLDLlval.DeamerNode->ValueName); DLDLlval.DeamerNode->LineNumber = DLDLlineno; return (UNIQUE);}
{TYPE}   {DLDLlval.DeamerNode = (deamer::AstInformation*) malloc(sizeof(deamer::AstInformation)); sscanf(yytext, "%s", DLDLlval.DeamerNode->ValueName); DLDLlval.DeamerNode->LineNumber = DLDLlineno; return (TYPE);}
{VARNAME}   {DLDLlval.DeamerNode = (deamer::AstInformation*) malloc(sizeof(deamer::AstInformation)); sscanf(yytext, "%s", DLDLlval.DeamerNode->ValueName); DLDLlval.DeamerNode->LineNumber = DLDLlineno; return (VARNAME);}

%%

