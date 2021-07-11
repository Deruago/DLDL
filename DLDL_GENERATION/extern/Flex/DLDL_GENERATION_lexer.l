%option yylineno
%option noyywrap
%option never-interactive
%option nounistd

%{
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include "DLDL_GENERATION/Flex/Lexer.h"
#include "DLDL_GENERATION/Ast/Enum/Type.h"
#include "DLDL_GENERATION/Ast/Node/GENERATE.h"
#include "DLDL_GENERATION/Ast/Node/INTEGRATE.h"
#include "DLDL_GENERATION/Ast/Node/ARGUMENT.h"
#include "DLDL_GENERATION/Ast/Node/VALUE.h"
#include "DLDL_GENERATION/Ast/Node/SYMBOLS.h"
#include "DLDL_GENERATION/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_GENERATION/Ast/Node/program.h"
#include "DLDL_GENERATION/Ast/Node/stmts.h"
#include "DLDL_GENERATION/Ast/Node/stmt.h"
#include "DLDL_GENERATION/Ast/Node/generate_declaration.h"
#include "DLDL_GENERATION/Ast/Node/integrate_declaration.h"
#include "DLDL_GENERATION/Ast/Node/argument_declaration.h"
#include "DLDL_GENERATION/Ast/Node/type.h"
#include "DLDL_GENERATION/Ast/Node/tool.h"
#include "DLDL_GENERATION/Ast/Node/argument_data.h"
#include "Bison/DLDL_GENERATION_parser.tab.h"
void showError();
extern int DLDL_GENERATIONlex();

static bool local_store = false;
static int column = 0;
static int handleColumn(const std::string& text);
static void store(const deamer::external::cpp::lexer::TerminalObject* const newObject);
static std::vector<const deamer::external::cpp::lexer::TerminalObject*> local_objects;
#ifndef yyval
#define yyval yytext
#endif //yyval
%}

GENERATE	(Generate[ \t]*[:=]*)
INTEGRATE	(Integrate[ \t]*[:=]*)
ARGUMENT	((Argument|Option)[ \t]*[:=]*)
VALUE	([a-zA-Z_-]+[a-zA-Z_\-0-9=\"'|&^%$#@!?(){}]*)
SYMBOLS	([|&^%$#@!?(){}])
ESCAPE_CHARS	([\n\r\b\v\a\f\t ])

%%

{GENERATE}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GENERATIONlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (GENERATE);;}
{INTEGRATE}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GENERATIONlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (INTEGRATE);;}
{ARGUMENT}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GENERATIONlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (ARGUMENT);;}
{VALUE}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column));else DLDL_GENERATIONlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column);;handleColumn(yyval);if (!local_store) return (VALUE);;}
{SYMBOLS}	{handleColumn(yyval);if (!local_store) ;}
{ESCAPE_CHARS}	{handleColumn(yyval);if (!local_store) ;}

%%
static void store(const deamer::external::cpp::lexer::TerminalObject* const newObject)
{
	local_objects.push_back(newObject);
}

static void clear()
{
	local_objects.clear();
}

static int handleColumn(const std::string& text)
{
	int currentColumn = column;
	currentColumn += text.size();
	for (auto character : text)
	{
		if (character == '\n')
		{
			currentColumn = 0;
			break;
		}
	}
	
	return currentColumn;
}

std::vector<const deamer::external::cpp::lexer::TerminalObject*> DLDL_GENERATION::lexer::Lexer::Tokenize(const std::string& text) const
{
	local_store = true;
	column = 0;

	YY_BUFFER_STATE buf;
	buf = yy_scan_string(text.c_str());
	yylex();
	yy_delete_buffer(buf);
	yylex_destroy();

	local_store = false;

	auto local_objects_copy = local_objects;
	clear();

	return local_objects_copy;
}


