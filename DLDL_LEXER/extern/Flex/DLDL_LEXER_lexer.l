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
static bool include_deleted = false;
static int column = 0;
static void handleColumn(const std::string& text);
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

{DELETE_ABSTRACTION}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(1))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(1))); else if (local_store && true); else if (!true || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(1)); else if (!true) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(1)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (DELETE_ABSTRACTION); }
{IGNORE_ABSTRACTION}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(2))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(2))); else if (local_store && true); else if (!true || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(2)); else if (!true) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(2)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (IGNORE_ABSTRACTION); }
{NOVALUE_ABSTRACTION}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(3))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(3))); else if (local_store && true); else if (!true || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(3)); else if (!true) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(3)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (NOVALUE_ABSTRACTION); }
{CRASH_ABSTRACTION}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(4))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(4))); else if (local_store && true); else if (!true || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(4)); else if (!true) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(4)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (CRASH_ABSTRACTION); }
{STANDARD_ABSTRACTION}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(5))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(5))); else if (local_store && true); else if (!true || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(5)); else if (!true) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(5)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (STANDARD_ABSTRACTION); }
{UNKNOWN_ABSTRACTION}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(6))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(6))); else if (local_store && true); else if (!true || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(6)); else if (!true) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(6)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (UNKNOWN_ABSTRACTION); }
{TERMINAL}	{  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(7))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(7))); else if (local_store && false); else if (!false || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(7)); else if (!false) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(7)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (TERMINAL); }
{REGEX}	{  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(8))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(8))); else if (local_store && false); else if (!false || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(8)); else if (!false) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(8)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (REGEX); }
{ESCAPE_CHARS}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(9))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(9))); else if (local_store && true); else if (!true || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(9)); else if (!true) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(9)); handleColumn(yyval); if ((!local_store && false) || (!local_store && include_deleted)) return (ESCAPE_CHARS); }
{COMMENT}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(10))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(10))); else if (local_store && true); else if (!true || include_deleted) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(10)); else if (!true) DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(10)); handleColumn(yyval); if ((!local_store && false) || (!local_store && include_deleted)) return (COMMENT); }

{DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH} { if (local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(0))); }

%%

static void store(const deamer::external::cpp::lexer::TerminalObject* const newObject)
{
	local_objects.push_back(newObject);
}

static void clear()
{
	local_objects.clear();
}

static void handleColumn(const std::string& text)
{
	int& currentColumn = column;
	currentColumn += text.size();
	for (auto character : text)
	{
		if (character == '\n')
		{
			currentColumn = 0;
			break;
		}
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
	column = 0;

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