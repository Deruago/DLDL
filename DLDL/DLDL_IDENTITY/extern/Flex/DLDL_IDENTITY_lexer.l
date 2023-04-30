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
#include "DLDL_IDENTITY/Flex/Lexer.h"

#include "DLDL_IDENTITY/Ast/Enum/Type.h"

#include "DLDL_IDENTITY/Ast/Node/NAME.h"
#include "DLDL_IDENTITY/Ast/Node/VALUE.h"
#include "DLDL_IDENTITY/Ast/Node/SYMBOLS.h"
#include "DLDL_IDENTITY/Ast/Node/ESCAPE_CHARS.h"
#include "DLDL_IDENTITY/Ast/Node/program.h"
#include "DLDL_IDENTITY/Ast/Node/stmts.h"
#include "DLDL_IDENTITY/Ast/Node/stmt.h"
#include "DLDL_IDENTITY/Ast/Node/name_declaration.h"


#include "Bison/DLDL_IDENTITY_parser.tab.h"
void showError();
extern int DLDL_IDENTITYlex();

static bool local_store     = false;
static bool include_deleted = false;

int DLDL_IDENTITY_column    = 1;
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

NAME	(Name)
VALUE	([a-zA-Z_]+[a-zA-Z0-9_])
SYMBOLS	([|&^%$#@!?(){}])
ESCAPE_CHARS	([\n\r\b\v\a\f\t ])

DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH	(.)

%%

{NAME}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IDENTITY_column, std::size_t(1))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IDENTITY_column, std::size_t(1))); else if (local_store && true); else if (!true || include_deleted) DLDL_IDENTITYlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IDENTITY_column, std::size_t(1)); else if (true) DLDL_IDENTITYlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IDENTITY_column, std::size_t(1)); if ((!local_store && true) || (!local_store && include_deleted)) return (NAME); }
{VALUE}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IDENTITY_column, std::size_t(2))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IDENTITY_column, std::size_t(2))); else if (local_store && false); else if (!false || include_deleted) DLDL_IDENTITYlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IDENTITY_column, std::size_t(2)); else if (true) DLDL_IDENTITYlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IDENTITY_column, std::size_t(2)); if ((!local_store && true) || (!local_store && include_deleted)) return (VALUE); }
{SYMBOLS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IDENTITY_column, std::size_t(3))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IDENTITY_column, std::size_t(3))); else if (local_store && true); else if (!true || include_deleted) DLDL_IDENTITYlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IDENTITY_column, std::size_t(3)); else if (false) DLDL_IDENTITYlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IDENTITY_column, std::size_t(3)); if ((!local_store && false) || (!local_store && include_deleted)) return (SYMBOLS); }
{ESCAPE_CHARS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IDENTITY_column, std::size_t(4))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IDENTITY_column, std::size_t(4))); else if (local_store && true); else if (!true || include_deleted) DLDL_IDENTITYlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IDENTITY_column, std::size_t(4)); else if (false) DLDL_IDENTITYlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IDENTITY_column, std::size_t(4)); if ((!local_store && false) || (!local_store && include_deleted)) return (ESCAPE_CHARS); }

{DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH} { if (local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IDENTITY_column, std::size_t(0))); }

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
	DLDL_IDENTITY_column = next_column;

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

std::vector<const ::deamer::external::cpp::lexer::TerminalObject*> DLDL_IDENTITY::flex::lexer::Lexer::Tokenize(const std::string& text, ::deamer::external::cpp::lexer::TerminalConstructionPolicy constructionPolicy) const
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
	DLDL_IDENTITY_column = 0;

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