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
#include "DLDL_LDOSTRUCT/Flex/Lexer.h"

#include "DLDL_LDOSTRUCT/Ast/Enum/Type.h"

#include "DLDL_LDOSTRUCT/Ast/Node/COLON.h"
#include "DLDL_LDOSTRUCT/Ast/Node/LEFT_ANGLE_BRACKET.h"
#include "DLDL_LDOSTRUCT/Ast/Node/RIGHT_ANGLE_BRACKET.h"
#include "DLDL_LDOSTRUCT/Ast/Node/VARNAME.h"
#include "DLDL_LDOSTRUCT/Ast/Node/INDENTED_VALUE.h"
#include "DLDL_LDOSTRUCT/Ast/Node/ESCAPE_CHARS.h"
#include "DLDL_LDOSTRUCT/Ast/Node/program.h"
#include "DLDL_LDOSTRUCT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LDOSTRUCT/Ast/Node/stmt.h"
#include "DLDL_LDOSTRUCT/Ast/Node/argument.h"
#include "DLDL_LDOSTRUCT/Ast/Node/argument_name.h"
#include "DLDL_LDOSTRUCT/Ast/Node/argument_block.h"
#include "DLDL_LDOSTRUCT/Ast/Node/deamerreserved_star__argument_stmt__.h"
#include "DLDL_LDOSTRUCT/Ast/Node/argument_stmt.h"


#include "Bison/DLDL_LDOSTRUCT_parser.tab.h"
void showError();
extern int DLDL_LDOSTRUCTlex();

static bool local_store     = false;
static bool include_deleted = false;

int DLDL_LDOSTRUCT_column    = 1;
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

COLON	([:][ \t]*)
LEFT_ANGLE_BRACKET	([<])
RIGHT_ANGLE_BRACKET	([>])
VARNAME	([a-zA-Z_]+[a-zA-Z_0-9]*)
INDENTED_VALUE	([\t ]+[^\n\r]*[\r\n]+)
ESCAPE_CHARS	([\n\t\r\b\v\a ])

DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH	(.)

%%

{COLON}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LDOSTRUCT_column, std::size_t(1))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LDOSTRUCT_column, std::size_t(1))); else if (local_store && true); else if (!true || include_deleted) DLDL_LDOSTRUCTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LDOSTRUCT_column, std::size_t(1)); else if (true) DLDL_LDOSTRUCTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LDOSTRUCT_column, std::size_t(1)); if ((!local_store && true) || (!local_store && include_deleted)) return (COLON); }
{LEFT_ANGLE_BRACKET}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LDOSTRUCT_column, std::size_t(2))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LDOSTRUCT_column, std::size_t(2))); else if (local_store && true); else if (!true || include_deleted) DLDL_LDOSTRUCTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LDOSTRUCT_column, std::size_t(2)); else if (true) DLDL_LDOSTRUCTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LDOSTRUCT_column, std::size_t(2)); if ((!local_store && true) || (!local_store && include_deleted)) return (LEFT_ANGLE_BRACKET); }
{RIGHT_ANGLE_BRACKET}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LDOSTRUCT_column, std::size_t(3))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LDOSTRUCT_column, std::size_t(3))); else if (local_store && true); else if (!true || include_deleted) DLDL_LDOSTRUCTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LDOSTRUCT_column, std::size_t(3)); else if (true) DLDL_LDOSTRUCTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LDOSTRUCT_column, std::size_t(3)); if ((!local_store && true) || (!local_store && include_deleted)) return (RIGHT_ANGLE_BRACKET); }
{VARNAME}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LDOSTRUCT_column, std::size_t(4))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LDOSTRUCT_column, std::size_t(4))); else if (local_store && false); else if (!false || include_deleted) DLDL_LDOSTRUCTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LDOSTRUCT_column, std::size_t(4)); else if (true) DLDL_LDOSTRUCTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LDOSTRUCT_column, std::size_t(4)); if ((!local_store && true) || (!local_store && include_deleted)) return (VARNAME); }
{INDENTED_VALUE}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LDOSTRUCT_column, std::size_t(5))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LDOSTRUCT_column, std::size_t(5))); else if (local_store && false); else if (!false || include_deleted) DLDL_LDOSTRUCTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LDOSTRUCT_column, std::size_t(5)); else if (true) DLDL_LDOSTRUCTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LDOSTRUCT_column, std::size_t(5)); if ((!local_store && true) || (!local_store && include_deleted)) return (INDENTED_VALUE); }
{ESCAPE_CHARS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LDOSTRUCT_column, std::size_t(6))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LDOSTRUCT_column, std::size_t(6))); else if (local_store && true); else if (!true || include_deleted) DLDL_LDOSTRUCTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LDOSTRUCT_column, std::size_t(6)); else if (false) DLDL_LDOSTRUCTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LDOSTRUCT_column, std::size_t(6)); if ((!local_store && false) || (!local_store && include_deleted)) return (ESCAPE_CHARS); }

{DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH} { if (local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LDOSTRUCT_column, std::size_t(0))); }

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
	DLDL_LDOSTRUCT_column = next_column;

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

std::vector<const ::deamer::external::cpp::lexer::TerminalObject*> DLDL_LDOSTRUCT::flex::lexer::Lexer::Tokenize(const std::string& text, ::deamer::external::cpp::lexer::TerminalConstructionPolicy constructionPolicy) const
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
	DLDL_LDOSTRUCT_column = 0;

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