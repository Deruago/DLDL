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
#include "DLDL_OOPSYNTAX/Flex/Lexer.h"

#include "DLDL_OOPSYNTAX/Ast/Enum/Type.h"

#include "DLDL_OOPSYNTAX/Ast/Node/ARROW.h"
#include "DLDL_OOPSYNTAX/Ast/Node/LEFT_BRACKET.h"
#include "DLDL_OOPSYNTAX/Ast/Node/RIGHT_BRACKET.h"
#include "DLDL_OOPSYNTAX/Ast/Node/DOT.h"
#include "DLDL_OOPSYNTAX/Ast/Node/EQ.h"
#include "DLDL_OOPSYNTAX/Ast/Node/STAR.h"
#include "DLDL_OOPSYNTAX/Ast/Node/VARNAME.h"
#include "DLDL_OOPSYNTAX/Ast/Node/NUMBER.h"
#include "DLDL_OOPSYNTAX/Ast/Node/COMMENT.h"
#include "DLDL_OOPSYNTAX/Ast/Node/ESCAPE_CHAR.h"
#include "DLDL_OOPSYNTAX/Ast/Node/program.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_OOPSYNTAX/Ast/Node/stmt.h"
#include "DLDL_OOPSYNTAX/Ast/Node/nonterminal_conversion.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_long_69.h"
#include "DLDL_OOPSYNTAX/Ast/Node/production_rule_conversion.h"
#include "DLDL_OOPSYNTAX/Ast/Node/numbered_pr_convert.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_long_72.h"
#include "DLDL_OOPSYNTAX/Ast/Node/property_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/direct_property_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_arrow__property__.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_long_76.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_arrow__terminal_name__.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_long_80.h"
#include "DLDL_OOPSYNTAX/Ast/Node/direct_any_property_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/embedded_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/nonterminal_name.h"
#include "DLDL_OOPSYNTAX/Ast/Node/oop_type.h"
#include "DLDL_OOPSYNTAX/Ast/Node/property.h"
#include "DLDL_OOPSYNTAX/Ast/Node/extended_property.h"
#include "DLDL_OOPSYNTAX/Ast/Node/extended_terminal_access.h"
#include "DLDL_OOPSYNTAX/Ast/Node/terminal_name.h"


#include "Bison/DLDL_OOPSYNTAX_parser.tab.h"
void showError();
extern int DLDL_OOPSYNTAXlex();

static bool local_store     = false;
static bool include_deleted = false;

int DLDL_OOPSYNTAX_column    = 1;
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

ARROW	([-][>])
LEFT_BRACKET	([{])
RIGHT_BRACKET	([}])
DOT	([\.])
EQ	([=])
STAR	([*])
VARNAME	([a-zA-Z_][a-zA-Z0-9_]*)
NUMBER	([0-9]+)
COMMENT	([/][^\n\r][\n\r])
ESCAPE_CHAR	([\n\t\r\b\v\a ])

DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH	(.)

%%

{ARROW}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(1))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(1))); else if (local_store && true); else if (!true || include_deleted) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(1)); else if (true) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(1)); if ((!local_store && true) || (!local_store && include_deleted)) return (ARROW); }
{LEFT_BRACKET}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(2))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(2))); else if (local_store && true); else if (!true || include_deleted) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(2)); else if (true) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(2)); if ((!local_store && true) || (!local_store && include_deleted)) return (LEFT_BRACKET); }
{RIGHT_BRACKET}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(3))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(3))); else if (local_store && true); else if (!true || include_deleted) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(3)); else if (true) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(3)); if ((!local_store && true) || (!local_store && include_deleted)) return (RIGHT_BRACKET); }
{DOT}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(4))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(4))); else if (local_store && true); else if (!true || include_deleted) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(4)); else if (true) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(4)); if ((!local_store && true) || (!local_store && include_deleted)) return (DOT); }
{EQ}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(5))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(5))); else if (local_store && true); else if (!true || include_deleted) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(5)); else if (true) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(5)); if ((!local_store && true) || (!local_store && include_deleted)) return (EQ); }
{STAR}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(6))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(6))); else if (local_store && true); else if (!true || include_deleted) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(6)); else if (true) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(6)); if ((!local_store && true) || (!local_store && include_deleted)) return (STAR); }
{VARNAME}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(7))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(7))); else if (local_store && false); else if (!false || include_deleted) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(7)); else if (true) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(7)); if ((!local_store && true) || (!local_store && include_deleted)) return (VARNAME); }
{NUMBER}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(8))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(8))); else if (local_store && false); else if (!false || include_deleted) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(8)); else if (true) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(8)); if ((!local_store && true) || (!local_store && include_deleted)) return (NUMBER); }
{COMMENT}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(9))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(9))); else if (local_store && true); else if (!true || include_deleted) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(9)); else if (false) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(9)); if ((!local_store && false) || (!local_store && include_deleted)) return (COMMENT); }
{ESCAPE_CHAR}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(10))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(10))); else if (local_store && true); else if (!true || include_deleted) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(10)); else if (false) DLDL_OOPSYNTAXlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_OOPSYNTAX_column, std::size_t(10)); if ((!local_store && false) || (!local_store && include_deleted)) return (ESCAPE_CHAR); }

{DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH} { if (local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_OOPSYNTAX_column, std::size_t(0))); }

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
	DLDL_OOPSYNTAX_column = next_column;

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

std::vector<const ::deamer::external::cpp::lexer::TerminalObject*> DLDL_OOPSYNTAX::flex::lexer::Lexer::Tokenize(const std::string& text, ::deamer::external::cpp::lexer::TerminalConstructionPolicy constructionPolicy) const
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
	DLDL_OOPSYNTAX_column = 0;

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