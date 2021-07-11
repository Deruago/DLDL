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
#include "DLDL_PRECEDENCE/Flex/Lexer.h"
#include "DLDL_PRECEDENCE/Ast/Enum/Type.h"
#include "DLDL_PRECEDENCE/Ast/Node/PRECEDENCE.h"
#include "DLDL_PRECEDENCE/Ast/Node/NUMBER.h"
#include "DLDL_PRECEDENCE/Ast/Node/TERMINAL.h"
#include "DLDL_PRECEDENCE/Ast/Node/SYMBOLS.h"
#include "DLDL_PRECEDENCE/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_PRECEDENCE/Ast/Node/program.h"
#include "DLDL_PRECEDENCE/Ast/Node/stmts.h"
#include "DLDL_PRECEDENCE/Ast/Node/stmt.h"
#include "DLDL_PRECEDENCE/Ast/Node/localized_precedence.h"
#include "DLDL_PRECEDENCE/Ast/Node/specific_precedence.h"
#include "DLDL_PRECEDENCE/Ast/Node/terminal_one_or_more.h"
#include "Bison/DLDL_PRECEDENCE_parser.tab.h"
void showError();
extern int DLDL_PRECEDENCElex();

static bool local_store = false;
static int column = 0;
static int handleColumn(const std::string& text);
static void store(const deamer::external::cpp::lexer::TerminalObject* const newObject);
static std::vector<const deamer::external::cpp::lexer::TerminalObject*> local_objects;
#ifndef yyval
#define yyval yytext
#endif //yyval
%}

PRECEDENCE	(Precedence)
NUMBER	([0-9]+)
TERMINAL	([a-zA-Z_]+)
SYMBOLS	([|&^%$#@!?(){}])
ESCAPE_CHARS	([\n\r\b\v\a\f\t ])

%%

{PRECEDENCE}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column));else DLDL_PRECEDENCElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column);;handleColumn(yyval);if (!local_store) return (PRECEDENCE);;}
{NUMBER}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column));else DLDL_PRECEDENCElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column);;handleColumn(yyval);if (!local_store) return (NUMBER);;}
{TERMINAL}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column));else DLDL_PRECEDENCElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column);;handleColumn(yyval);if (!local_store) return (TERMINAL);;}
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

std::vector<const deamer::external::cpp::lexer::TerminalObject*> DLDL_PRECEDENCE::lexer::Lexer::Tokenize(const std::string& text) const
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


