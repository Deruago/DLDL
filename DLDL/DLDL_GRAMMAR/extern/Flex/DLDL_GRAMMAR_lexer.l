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
#include "DLDL_GRAMMAR/Flex/Lexer.h"

#include "DLDL_GRAMMAR/Ast/Enum/Type.h"

#include "DLDL_GRAMMAR/Ast/Node/COMMENT.h"
#include "DLDL_GRAMMAR/Ast/Node/START_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/GROUP_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/INLINE_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/INLINE_GROUP_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/UNKNOWN_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/NONTERMINAL.h"
#include "DLDL_GRAMMAR/Ast/Node/PRODUCTION_RULE.h"
#include "DLDL_GRAMMAR/Ast/Node/ESCAPE_CHARS.h"
#include "DLDL_GRAMMAR/Ast/Node/program.h"
#include "DLDL_GRAMMAR/Ast/Node/stmts.h"
#include "DLDL_GRAMMAR/Ast/Node/stmt.h"
#include "DLDL_GRAMMAR/Ast/Node/abstraction_declaration.h"
#include "DLDL_GRAMMAR/Ast/Node/abstraction.h"
#include "DLDL_GRAMMAR/Ast/Node/definition.h"
#include "DLDL_GRAMMAR/Ast/Node/production_rules.h"


#include "Bison/DLDL_GRAMMAR_parser.tab.h"
void showError();
extern int DLDL_GRAMMARlex();

static bool local_store     = false;
static bool include_deleted = false;

int DLDL_GRAMMAR_column    = 1;
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

COMMENT	([/][^\n]*)
START_ABSTRACTION	([Ss]tart[:][ \t]*)
GROUP_ABSTRACTION	([Gg]roup[:][ \t]*)
INLINE_ABSTRACTION	([Ii]nline[:][ \t]*)
INLINE_GROUP_ABSTRACTION	((([Ii]nline[ ][Gg]roup)|([Gg]roup[ ][Ii]nline))[:][ \t]*)
UNKNOWN_ABSTRACTION	([a-zA-Z0-9_\\$?!-+=]*[:][ \t]*)
NONTERMINAL	([a-zA-Z_]+[a-zA-Z_0-9]*)
PRODUCTION_RULE	([ \t]+[^\n\r]*)
ESCAPE_CHARS	([\n\r\b\v\a\f\t ])

DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH	(.)

%%

{COMMENT}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_column, std::size_t(1))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_column, std::size_t(1))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_column, std::size_t(1)); else if (false) DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_column, std::size_t(1)); if ((!local_store && false) || (!local_store && include_deleted)) return (COMMENT); }
{START_ABSTRACTION}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_column, std::size_t(2))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_column, std::size_t(2))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_column, std::size_t(2)); else if (true) DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_column, std::size_t(2)); if ((!local_store && true) || (!local_store && include_deleted)) return (START_ABSTRACTION); }
{GROUP_ABSTRACTION}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_column, std::size_t(3))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_column, std::size_t(3))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_column, std::size_t(3)); else if (true) DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_column, std::size_t(3)); if ((!local_store && true) || (!local_store && include_deleted)) return (GROUP_ABSTRACTION); }
{INLINE_ABSTRACTION}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_column, std::size_t(4))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_column, std::size_t(4))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_column, std::size_t(4)); else if (true) DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_column, std::size_t(4)); if ((!local_store && true) || (!local_store && include_deleted)) return (INLINE_ABSTRACTION); }
{INLINE_GROUP_ABSTRACTION}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_column, std::size_t(5))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_column, std::size_t(5))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_column, std::size_t(5)); else if (true) DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_column, std::size_t(5)); if ((!local_store && true) || (!local_store && include_deleted)) return (INLINE_GROUP_ABSTRACTION); }
{UNKNOWN_ABSTRACTION}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_column, std::size_t(6))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_column, std::size_t(6))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_column, std::size_t(6)); else if (true) DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_column, std::size_t(6)); if ((!local_store && true) || (!local_store && include_deleted)) return (UNKNOWN_ABSTRACTION); }
{NONTERMINAL}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_column, std::size_t(7))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_column, std::size_t(7))); else if (local_store && false); else if (!false || include_deleted) DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_column, std::size_t(7)); else if (true) DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_column, std::size_t(7)); if ((!local_store && true) || (!local_store && include_deleted)) return (NONTERMINAL); }
{PRODUCTION_RULE}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_column, std::size_t(8))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_column, std::size_t(8))); else if (local_store && false); else if (!false || include_deleted) DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_column, std::size_t(8)); else if (true) DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_column, std::size_t(8)); if ((!local_store && true) || (!local_store && include_deleted)) return (PRODUCTION_RULE); }
{ESCAPE_CHARS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_column, std::size_t(9))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_column, std::size_t(9))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_column, std::size_t(9)); else if (false) DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_column, std::size_t(9)); if ((!local_store && false) || (!local_store && include_deleted)) return (ESCAPE_CHARS); }

{DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH} { if (local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_column, std::size_t(0))); }

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
	DLDL_GRAMMAR_column = next_column;

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

std::vector<const ::deamer::external::cpp::lexer::TerminalObject*> DLDL_GRAMMAR::flex::lexer::Lexer::Tokenize(const std::string& text, ::deamer::external::cpp::lexer::TerminalConstructionPolicy constructionPolicy) const
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
	DLDL_GRAMMAR_column = 0;

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