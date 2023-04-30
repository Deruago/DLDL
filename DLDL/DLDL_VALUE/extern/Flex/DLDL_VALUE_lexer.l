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
#include "DLDL_VALUE/Flex/Lexer.h"

#include "DLDL_VALUE/Ast/Enum/Type.h"

#include "DLDL_VALUE/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_VALUE/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_VALUE/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_VALUE/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_VALUE/Ast/Node/LEFT_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/RIGHT_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/DOT.h"
#include "DLDL_VALUE/Ast/Node/VALUE_CHARACTERISTIC.h"
#include "DLDL_VALUE/Ast/Node/VALUE_RULE.h"
#include "DLDL_VALUE/Ast/Node/NUMBER.h"
#include "DLDL_VALUE/Ast/Node/TEXT.h"
#include "DLDL_VALUE/Ast/Node/VARNAME.h"
#include "DLDL_VALUE/Ast/Node/ESCAPE_CHARS.h"
#include "DLDL_VALUE/Ast/Node/program.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_VALUE/Ast/Node/stmt.h"
#include "DLDL_VALUE/Ast/Node/value_charactersitic_declaration.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_82.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_85.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_88.h"
#include "DLDL_VALUE/Ast/Node/value_declaration.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_91.h"
#include "DLDL_VALUE/Ast/Node/value_characteristic_abstraction.h"
#include "DLDL_VALUE/Ast/Node/value_declaration_abstraction.h"
#include "DLDL_VALUE/Ast/Node/value_abstraction.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_star__value_abstraction__.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_96.h"
#include "DLDL_VALUE/Ast/Node/value.h"
#include "DLDL_VALUE/Ast/Node/syntactic_context.h"
#include "DLDL_VALUE/Ast/Node/abstraction_name.h"
#include "DLDL_VALUE/Ast/Node/value_rule_name.h"


#include "Bison/DLDL_VALUE_parser.tab.h"
void showError();
extern int DLDL_VALUElex();

static bool local_store     = false;
static bool include_deleted = false;

int DLDL_VALUE_column    = 1;
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
LEFT_BRACKET	([{])
RIGHT_BRACKET	([}])
LEFT_SQUARE_BRACKET	([\[])
RIGHT_SQUARE_BRACKET	([\]])
DOT	([\.])
VALUE_CHARACTERISTIC	(((([Vv][Aa][Ll][Uu][Ee])|([Vv][Aa][Ll]))[ ]*(([Cc][Hh][Aa][Rr][Aa][Cc][Tt][Ee][Rr][Ii][Ss][Tt][Ii][Cc])|([Cc][Hh][Aa][Rr]))[:]))
VALUE_RULE	((([Vv][Aa][Ll][Uu][Ee])|([Vv][Aa][Ll])[:]))
NUMBER	([0-9]+)
TEXT	(((["][^"]*["])|(['][^']*['])|([@]['][^']*['][@])|([@]["][^"]*["][@])))
VARNAME	([a-zA-Z_][a-zA-Z_0-9]*)
ESCAPE_CHARS	([ \n\r\t])

DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH	(.)

%%

{SINGLE_COMMENT}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(1))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(1))); else if (local_store && true); else if (!true || include_deleted) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(1)); else if (false) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(1)); if ((!local_store && false) || (!local_store && include_deleted)) return (SINGLE_COMMENT); }
{MULTI_COMMENT}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(2))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(2))); else if (local_store && true); else if (!true || include_deleted) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(2)); else if (false) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(2)); if ((!local_store && false) || (!local_store && include_deleted)) return (MULTI_COMMENT); }
{LEFT_PARANTHESIS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(3))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(3))); else if (local_store && true); else if (!true || include_deleted) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(3)); else if (true) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(3)); if ((!local_store && true) || (!local_store && include_deleted)) return (LEFT_PARANTHESIS); }
{RIGHT_PARANTHESIS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(4))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(4))); else if (local_store && true); else if (!true || include_deleted) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(4)); else if (true) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(4)); if ((!local_store && true) || (!local_store && include_deleted)) return (RIGHT_PARANTHESIS); }
{LEFT_BRACKET}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(5))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(5))); else if (local_store && true); else if (!true || include_deleted) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(5)); else if (true) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(5)); if ((!local_store && true) || (!local_store && include_deleted)) return (LEFT_BRACKET); }
{RIGHT_BRACKET}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(6))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(6))); else if (local_store && true); else if (!true || include_deleted) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(6)); else if (true) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(6)); if ((!local_store && true) || (!local_store && include_deleted)) return (RIGHT_BRACKET); }
{LEFT_SQUARE_BRACKET}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(7))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(7))); else if (local_store && true); else if (!true || include_deleted) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(7)); else if (true) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(7)); if ((!local_store && true) || (!local_store && include_deleted)) return (LEFT_SQUARE_BRACKET); }
{RIGHT_SQUARE_BRACKET}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(8))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(8))); else if (local_store && true); else if (!true || include_deleted) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(8)); else if (true) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(8)); if ((!local_store && true) || (!local_store && include_deleted)) return (RIGHT_SQUARE_BRACKET); }
{DOT}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(9))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(9))); else if (local_store && true); else if (!true || include_deleted) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(9)); else if (true) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(9)); if ((!local_store && true) || (!local_store && include_deleted)) return (DOT); }
{VALUE_CHARACTERISTIC}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(10))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(10))); else if (local_store && false); else if (!false || include_deleted) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(10)); else if (true) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(10)); if ((!local_store && true) || (!local_store && include_deleted)) return (VALUE_CHARACTERISTIC); }
{VALUE_RULE}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(11))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(11))); else if (local_store && false); else if (!false || include_deleted) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(11)); else if (true) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(11)); if ((!local_store && true) || (!local_store && include_deleted)) return (VALUE_RULE); }
{NUMBER}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(12))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(12))); else if (local_store && false); else if (!false || include_deleted) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(12)); else if (true) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(12)); if ((!local_store && true) || (!local_store && include_deleted)) return (NUMBER); }
{TEXT}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(13))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(13))); else if (local_store && false); else if (!false || include_deleted) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(13)); else if (true) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(13)); if ((!local_store && true) || (!local_store && include_deleted)) return (TEXT); }
{VARNAME}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(14))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(14))); else if (local_store && false); else if (!false || include_deleted) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(14)); else if (true) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(14)); if ((!local_store && true) || (!local_store && include_deleted)) return (VARNAME); }
{ESCAPE_CHARS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(15))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(15))); else if (local_store && true); else if (!true || include_deleted) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(15)); else if (false) DLDL_VALUElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_VALUE_column, std::size_t(15)); if ((!local_store && false) || (!local_store && include_deleted)) return (ESCAPE_CHARS); }

{DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH} { if (local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_VALUE_column, std::size_t(0))); }

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
	DLDL_VALUE_column = next_column;

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

std::vector<const ::deamer::external::cpp::lexer::TerminalObject*> DLDL_VALUE::flex::lexer::Lexer::Tokenize(const std::string& text, ::deamer::external::cpp::lexer::TerminalConstructionPolicy constructionPolicy) const
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
	DLDL_VALUE_column = 0;

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