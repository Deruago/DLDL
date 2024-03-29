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
#include "DLDL_LPDDEF_DF/Flex/Lexer.h"

#include "DLDL_LPDDEF_DF/Ast/Enum/Type.h"

#include "DLDL_LPDDEF_DF/Ast/Node/LAB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RAB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/LSB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RSB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/EQ.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COLON.h"
#include "DLDL_LPDDEF_DF/Ast/Node/LB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COMMA.h"
#include "DLDL_LPDDEF_DF/Ast/Node/OPTIONAL.h"
#include "DLDL_LPDDEF_DF/Ast/Node/VECTOR.h"
#include "DLDL_LPDDEF_DF/Ast/Node/DEAMER_VARNAME.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COMMENT.h"
#include "DLDL_LPDDEF_DF/Ast/Node/VARNAME.h"
#include "DLDL_LPDDEF_DF/Ast/Node/NUMBER.h"
#include "DLDL_LPDDEF_DF/Ast/Node/STRING.h"
#include "DLDL_LPDDEF_DF/Ast/Node/SEMICOLON.h"
#include "DLDL_LPDDEF_DF/Ast/Node/ESCAPE_CHARS.h"
#include "DLDL_LPDDEF_DF/Ast/Node/program.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/stmt.h"
#include "DLDL_LPDDEF_DF/Ast/Node/comment_line.h"
#include "DLDL_LPDDEF_DF/Ast/Node/vector_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_optional__value_part__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/optional_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value_part.h"
#include "DLDL_LPDDEF_DF/Ast/Node/standard_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value_type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_arrow__value_type__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__COMMA__value_type__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_long_54.h"
#include "DLDL_LPDDEF_DF/Ast/Node/var_type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_arrow__VARNAME__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__COLON__VARNAME__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/var_name.h"


#include "Bison/DLDL_LPDDEF_DF_parser.tab.h"
void showError();
extern int DLDL_LPDDEF_DFlex();

static bool local_store     = false;
static bool include_deleted = false;

int DLDL_LPDDEF_DF_column    = 1;
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

LAB	([<])
RAB	([>])
LSB	([\[])
RSB	([\]])
EQ	([=])
COLON	([:])
LB	([{])
RB	([}])
COMMA	([,])
OPTIONAL	([Oo][Pp][Tt][Ii][Oo][Nn][Aa][Ll])
VECTOR	([Vv][Ee][Cc][Tt][Oo][Rr])
DEAMER_VARNAME	(deamer([:][:][a-zA-Z_][a-zA-Z_0-9]+)+)
COMMENT	([/]+[^\n]*[\n])
VARNAME	([a-zA-Z_][a-zA-Z_0-9]*)
NUMBER	([-]*[0-9]+)
STRING	(["][^"]*["])
SEMICOLON	([;])
ESCAPE_CHARS	([\n\t\r\b\v\a ])

DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH	(.)

%%

{LAB}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(1))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(1))); else if (local_store && true); else if (!true || include_deleted) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(1)); else if (true) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(1)); if ((!local_store && true) || (!local_store && include_deleted)) return (LAB); }
{RAB}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(2))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(2))); else if (local_store && true); else if (!true || include_deleted) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(2)); else if (true) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(2)); if ((!local_store && true) || (!local_store && include_deleted)) return (RAB); }
{LSB}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(3))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(3))); else if (local_store && true); else if (!true || include_deleted) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(3)); else if (true) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(3)); if ((!local_store && true) || (!local_store && include_deleted)) return (LSB); }
{RSB}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(4))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(4))); else if (local_store && true); else if (!true || include_deleted) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(4)); else if (true) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(4)); if ((!local_store && true) || (!local_store && include_deleted)) return (RSB); }
{EQ}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(5))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(5))); else if (local_store && true); else if (!true || include_deleted) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(5)); else if (true) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(5)); if ((!local_store && true) || (!local_store && include_deleted)) return (EQ); }
{COLON}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(6))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(6))); else if (local_store && false); else if (!false || include_deleted) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(6)); else if (true) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(6)); if ((!local_store && true) || (!local_store && include_deleted)) return (COLON); }
{LB}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(7))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(7))); else if (local_store && false); else if (!false || include_deleted) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(7)); else if (true) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(7)); if ((!local_store && true) || (!local_store && include_deleted)) return (LB); }
{RB}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(8))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(8))); else if (local_store && false); else if (!false || include_deleted) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(8)); else if (true) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(8)); if ((!local_store && true) || (!local_store && include_deleted)) return (RB); }
{COMMA}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(9))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(9))); else if (local_store && false); else if (!false || include_deleted) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(9)); else if (true) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(9)); if ((!local_store && true) || (!local_store && include_deleted)) return (COMMA); }
{OPTIONAL}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(10))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(10))); else if (local_store && false); else if (!false || include_deleted) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(10)); else if (true) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(10)); if ((!local_store && true) || (!local_store && include_deleted)) return (OPTIONAL); }
{VECTOR}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(11))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(11))); else if (local_store && false); else if (!false || include_deleted) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(11)); else if (true) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(11)); if ((!local_store && true) || (!local_store && include_deleted)) return (VECTOR); }
{DEAMER_VARNAME}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(12))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(12))); else if (local_store && false); else if (!false || include_deleted) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(12)); else if (true) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(12)); if ((!local_store && true) || (!local_store && include_deleted)) return (DEAMER_VARNAME); }
{COMMENT}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(13))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(13))); else if (local_store && false); else if (!false || include_deleted) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(13)); else if (true) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(13)); if ((!local_store && true) || (!local_store && include_deleted)) return (COMMENT); }
{VARNAME}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(14))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(14))); else if (local_store && false); else if (!false || include_deleted) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(14)); else if (true) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(14)); if ((!local_store && true) || (!local_store && include_deleted)) return (VARNAME); }
{NUMBER}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(15))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(15))); else if (local_store && false); else if (!false || include_deleted) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(15)); else if (true) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(15)); if ((!local_store && true) || (!local_store && include_deleted)) return (NUMBER); }
{STRING}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(16))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(16))); else if (local_store && false); else if (!false || include_deleted) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(16)); else if (true) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(16)); if ((!local_store && true) || (!local_store && include_deleted)) return (STRING); }
{SEMICOLON}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(17))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(17))); else if (local_store && true); else if (!true || include_deleted) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(17)); else if (false) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(17)); if ((!local_store && false) || (!local_store && include_deleted)) return (SEMICOLON); }
{ESCAPE_CHARS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(18))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(18))); else if (local_store && true); else if (!true || include_deleted) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(18)); else if (false) DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_LPDDEF_DF_column, std::size_t(18)); if ((!local_store && false) || (!local_store && include_deleted)) return (ESCAPE_CHARS); }

{DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH} { if (local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_LPDDEF_DF_column, std::size_t(0))); }

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
	DLDL_LPDDEF_DF_column = next_column;

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

std::vector<const ::deamer::external::cpp::lexer::TerminalObject*> DLDL_LPDDEF_DF::flex::lexer::Lexer::Tokenize(const std::string& text, ::deamer::external::cpp::lexer::TerminalConstructionPolicy constructionPolicy) const
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
	DLDL_LPDDEF_DF_column = 0;

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