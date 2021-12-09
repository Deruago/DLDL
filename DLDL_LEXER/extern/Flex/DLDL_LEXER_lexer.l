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
#include "DLDL_LEXER/Flex/Lexer.h"
#include "DLDL_LEXER/Ast/Enum/Type.h"
#include "DLDL_LEXER/Ast/Node/DELETE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/IGNORE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/NOVALUE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/CRASH_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/STANDARD_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/UNKNOWN_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/TERMINAL.h"
#include "DLDL_LEXER/Ast/Node/REGEX.h"
#include "DLDL_LEXER/Ast/Node/ESCAPE_CHARS.h"
#include "DLDL_LEXER/Ast/Node/COMMENT.h"

#include "DLDL_LEXER/Ast/Node/program.h"
#include "DLDL_LEXER/Ast/Node/stmts.h"
#include "DLDL_LEXER/Ast/Node/stmt.h"
#include "DLDL_LEXER/Ast/Node/tokendeclaration.h"
#include "DLDL_LEXER/Ast/Node/abstraction.h"
#include "Bison/DLDL_LEXER_parser.tab.h"
void showError();
extern int DLDL_LEXERlex();

static bool local_store = false;
static int column = 0;
static int handleColumn(const std::string& text);
static void store(const deamer::external::cpp::lexer::TerminalObject* const newObject);
static std::vector<const deamer::external::cpp::lexer::TerminalObject*> local_objects;
#ifndef yyval
#define yyval yytext
#endif //yyval
%}

DELETE_ABSTRACTION	([Dd]elete[:][ \t]*)
IGNORE_ABSTRACTION	([Ii]gnore[:][ \t]*)
NOVALUE_ABSTRACTION	((([Nn]o[Vv]alue)|([Vv]alue[Ll]ess))[:][ \t]*)
CRASH_ABSTRACTION	([Cc]rash[:][ \t]*)
STANDARD_ABSTRACTION	([Ss]tandard[:][ \t]*)
UNKNOWN_ABSTRACTION	([a-zA-Z0-9_\\$?!-+=]*[:][ \t]*)
TERMINAL	([a-zA-Z_]+[a-zA-Z_0-9]*)
REGEX	([ \t][^\n\r]*)
ESCAPE_CHARS	([\n\r\t\f\b\a\v])
COMMENT	([/][^\n]*)

%%

{DELETE_ABSTRACTION}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(1)));else DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(1));;handleColumn(yyval);if (!local_store) return (DELETE_ABSTRACTION);;}
{IGNORE_ABSTRACTION}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(2)));else DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(2));;handleColumn(yyval);if (!local_store) return (IGNORE_ABSTRACTION);;}
{NOVALUE_ABSTRACTION}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(3)));else DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(3));;handleColumn(yyval);if (!local_store) return (NOVALUE_ABSTRACTION);;}
{CRASH_ABSTRACTION}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(4)));else DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(4));;handleColumn(yyval);if (!local_store) return (CRASH_ABSTRACTION);;}
{STANDARD_ABSTRACTION}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(5)));else DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(5));;handleColumn(yyval);if (!local_store) return (STANDARD_ABSTRACTION);;}
{UNKNOWN_ABSTRACTION}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(6)));else DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(6));;handleColumn(yyval);if (!local_store) return (UNKNOWN_ABSTRACTION);;}
{TERMINAL}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(7)));else DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(7));;handleColumn(yyval);if (!local_store) return (TERMINAL);;}
{REGEX}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(8)));else DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(8));;handleColumn(yyval);if (!local_store) return (REGEX);;}
{ESCAPE_CHARS}	{handleColumn(yyval);if (!local_store) ;}
{COMMENT}	{handleColumn(yyval);if (!local_store) ;}

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

std::vector<const deamer::external::cpp::lexer::TerminalObject*> DLDL_LEXER::lexer::Lexer::Tokenize(const std::string& text) const
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


