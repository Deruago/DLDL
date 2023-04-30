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
#include "DLDL_IMPORT/Flex/Lexer.h"

#include "DLDL_IMPORT/Ast/Enum/Type.h"

#include "DLDL_IMPORT/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_IMPORT/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_IMPORT/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_IMPORT/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_IMPORT/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_IMPORT/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_IMPORT/Ast/Node/COLON.h"
#include "DLDL_IMPORT/Ast/Node/DOT.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT_FILE.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT_MODULE.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT.h"
#include "DLDL_IMPORT/Ast/Node/TEXT.h"
#include "DLDL_IMPORT/Ast/Node/VARNAME.h"
#include "DLDL_IMPORT/Ast/Node/ESCAPE_CHARS.h"
#include "DLDL_IMPORT/Ast/Node/program.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_IMPORT/Ast/Node/stmt.h"
#include "DLDL_IMPORT/Ast/Node/import_declaration.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_arrow__import_context__.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_long_40.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_long_43.h"
#include "DLDL_IMPORT/Ast/Node/specialization.h"
#include "DLDL_IMPORT/Ast/Node/import_abstraction.h"
#include "DLDL_IMPORT/Ast/Node/value.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_optional__VARNAME__.h"
#include "DLDL_IMPORT/Ast/Node/abstraction.h"
#include "DLDL_IMPORT/Ast/Node/import_context.h"
#include "DLDL_IMPORT/Ast/Node/import_rule_name.h"


#include "Bison/DLDL_IMPORT_parser.tab.h"
void showError();
extern int DLDL_IMPORTlex();

static bool local_store     = false;
static bool include_deleted = false;

int DLDL_IMPORT_column    = 1;
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

SINGLE_COMMENT	([/][^\n\r]*[\n\r]{0,1})
MULTI_COMMENT	([/][*][^*]*[*][/]{0,1})
LEFT_PARANTHESIS	([(])
RIGHT_PARANTHESIS	([)])
LEFT_SQUARE_BRACKET	([\[])
RIGHT_SQUARE_BRACKET	([\]])
COLON	([:])
DOT	([\.])
IMPORT_FILE	([Ii][Mm][Pp][Oo][Rr][Tt][ 	]*[Ff][Ii][Ll][Ee])
IMPORT_MODULE	([Ii][Mm][Pp][Oo][Rr][Tt][ 	]*[Mm][Oo][Dd][Uu][Ll][Ee])
IMPORT	([Ii][Mm][Pp][Oo][Rr][Tt])
TEXT	(((["][^"]*["])|(['][^']*['])|([@]['][^']*['][@])|([@]["][^"]*["][@])))
VARNAME	([a-zA-Z_][a-zA-Z_0-9]*)
ESCAPE_CHARS	([ \n\r\t])

DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH	(.)

%%

{SINGLE_COMMENT}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(1))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(1))); else if (local_store && true); else if (!true || include_deleted) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(1)); else if (false) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(1)); if ((!local_store && false) || (!local_store && include_deleted)) return (SINGLE_COMMENT); }
{MULTI_COMMENT}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(2))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(2))); else if (local_store && true); else if (!true || include_deleted) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(2)); else if (false) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(2)); if ((!local_store && false) || (!local_store && include_deleted)) return (MULTI_COMMENT); }
{LEFT_PARANTHESIS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(3))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(3))); else if (local_store && true); else if (!true || include_deleted) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(3)); else if (true) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(3)); if ((!local_store && true) || (!local_store && include_deleted)) return (LEFT_PARANTHESIS); }
{RIGHT_PARANTHESIS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(4))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(4))); else if (local_store && true); else if (!true || include_deleted) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(4)); else if (true) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(4)); if ((!local_store && true) || (!local_store && include_deleted)) return (RIGHT_PARANTHESIS); }
{LEFT_SQUARE_BRACKET}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(5))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(5))); else if (local_store && true); else if (!true || include_deleted) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(5)); else if (true) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(5)); if ((!local_store && true) || (!local_store && include_deleted)) return (LEFT_SQUARE_BRACKET); }
{RIGHT_SQUARE_BRACKET}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(6))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(6))); else if (local_store && true); else if (!true || include_deleted) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(6)); else if (true) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(6)); if ((!local_store && true) || (!local_store && include_deleted)) return (RIGHT_SQUARE_BRACKET); }
{COLON}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(7))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(7))); else if (local_store && true); else if (!true || include_deleted) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(7)); else if (true) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(7)); if ((!local_store && true) || (!local_store && include_deleted)) return (COLON); }
{DOT}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(8))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(8))); else if (local_store && true); else if (!true || include_deleted) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(8)); else if (true) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(8)); if ((!local_store && true) || (!local_store && include_deleted)) return (DOT); }
{IMPORT_FILE}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(9))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(9))); else if (local_store && true); else if (!true || include_deleted) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(9)); else if (true) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(9)); if ((!local_store && true) || (!local_store && include_deleted)) return (IMPORT_FILE); }
{IMPORT_MODULE}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(10))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(10))); else if (local_store && true); else if (!true || include_deleted) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(10)); else if (true) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(10)); if ((!local_store && true) || (!local_store && include_deleted)) return (IMPORT_MODULE); }
{IMPORT}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(11))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(11))); else if (local_store && true); else if (!true || include_deleted) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(11)); else if (true) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(11)); if ((!local_store && true) || (!local_store && include_deleted)) return (IMPORT); }
{TEXT}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(12))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(12))); else if (local_store && false); else if (!false || include_deleted) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(12)); else if (true) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(12)); if ((!local_store && true) || (!local_store && include_deleted)) return (TEXT); }
{VARNAME}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(13))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(13))); else if (local_store && false); else if (!false || include_deleted) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(13)); else if (true) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(13)); if ((!local_store && true) || (!local_store && include_deleted)) return (VARNAME); }
{ESCAPE_CHARS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(14))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(14))); else if (local_store && true); else if (!true || include_deleted) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(14)); else if (false) DLDL_IMPORTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_IMPORT_column, std::size_t(14)); if ((!local_store && false) || (!local_store && include_deleted)) return (ESCAPE_CHARS); }

{DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH} { if (local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_IMPORT_column, std::size_t(0))); }

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
	DLDL_IMPORT_column = next_column;

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

std::vector<const ::deamer::external::cpp::lexer::TerminalObject*> DLDL_IMPORT::flex::lexer::Lexer::Tokenize(const std::string& text, ::deamer::external::cpp::lexer::TerminalConstructionPolicy constructionPolicy) const
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
	DLDL_IMPORT_column = 0;

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