%option yylineno
%option noyywrap
%option never-interactive
%option nounistd

%{
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <cwchar>
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

static bool local_store     = false;
static bool include_deleted = false;

int DLDL_LEXER_column    = 1;
static int next_column = 1;

static std::size_t min(std::size_t a, std::size_t b);

static void handleColumn();
static void store(const deamer::external::cpp::lexer::TerminalObject* const newObject);
static std::vector<const deamer::external::cpp::lexer::TerminalObject*> 
local_objects;


#ifndef yyval
#define yyval yytext
#endif // yyval
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

DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH	(.)

%%

{DELETE_ABSTRACTION}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(1))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(1))); else if (local_store && true); else if (!true || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(1)); else if (true) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(1)); if ((!local_store && true) || (!local_store && include_deleted)) return (DELETE_ABSTRACTION); }
{IGNORE_ABSTRACTION}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(2))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(2))); else if (local_store && true); else if (!true || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(2)); else if (true) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(2)); if ((!local_store && true) || (!local_store && include_deleted)) return (IGNORE_ABSTRACTION); }
{NOVALUE_ABSTRACTION}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(3))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(3))); else if (local_store && true); else if (!true || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(3)); else if (true) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(3)); if ((!local_store && true) || (!local_store && include_deleted)) return (NOVALUE_ABSTRACTION); }
{CRASH_ABSTRACTION}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(4))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(4))); else if (local_store && true); else if (!true || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(4)); else if (true) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(4)); if ((!local_store && true) || (!local_store && include_deleted)) return (CRASH_ABSTRACTION); }
{STANDARD_ABSTRACTION}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(5))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(5))); else if (local_store && true); else if (!true || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(5)); else if (true) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(5)); if ((!local_store && true) || (!local_store && include_deleted)) return (STANDARD_ABSTRACTION); }
{UNKNOWN_ABSTRACTION}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(6))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(6))); else if (local_store && true); else if (!true || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(6)); else if (true) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(6)); if ((!local_store && true) || (!local_store && include_deleted)) return (UNKNOWN_ABSTRACTION); }
{TERMINAL}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(7))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(7))); else if (local_store && false); else if (!false || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(7)); else if (true) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(7)); if ((!local_store && true) || (!local_store && include_deleted)) return (TERMINAL); }
{REGEX}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(8))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(8))); else if (local_store && false); else if (!false || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(8)); else if (true) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(8)); if ((!local_store && true) || (!local_store && include_deleted)) return (REGEX); }
{ESCAPE_CHARS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(9))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(9))); else if (local_store && true); else if (!true || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(9)); else if (false) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(9)); if ((!local_store && false) || (!local_store && include_deleted)) return (ESCAPE_CHARS); }
{COMMENT}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(10))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(10))); else if (local_store && true); else if (!true || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(10)); else if (false) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LEXER_column, std::size_t(10)); if ((!local_store && false) || (!local_store && include_deleted)) return (COMMENT); }

{DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH} { if (local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LEXER_column, std::size_t(0))); }

%%

static void store(const deamer::external::cpp::lexer::TerminalObject* const newObject)
{
	local_objects.push_back(newObject);
}

static void clear()
{
	local_objects.clear();
}

static void handleColumn()
{
	const std::string text = yytext;
	DLDL_LEXER_column = next_column;

	for (auto character : text)
	{
		next_column++;
		if (character == '\n')
		{
			next_column = 1;
		}
	}
}

static std::size_t min(std::size_t a, std::size_t b) {
    if (b < a)
	{
		return b;
	}
	else
	{
		return a;
	}
}

std::vector<const ::deamer::external::cpp::lexer::TerminalObject*> DLDL_LEXER::flex::lexer::Lexer::Tokenize(const std::string& text, ::deamer::external::cpp::lexer::TerminalConstructionPolicy constructionPolicy) const
{
	if (constructionPolicy == ::deamer::external::cpp::lexer::TerminalConstructionPolicy::include_deleted_terminals)
	{
		include_deleted = true;
	}
	else
	{
		include_deleted = false;
	}

	local_store = true;
	DLDL_LEXER_column = 0;

	YY_BUFFER_STATE buf;
	buf = yy_scan_string(text.c_str());
	yylex();
	yy_delete_buffer(buf);
	yylex_destroy();

	local_store = false;
	include_deleted = false;

	auto local_objects_copy = local_objects;
	clear();

	return local_objects_copy;
}