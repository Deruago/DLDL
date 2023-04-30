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
#include "DLDL_COMMENT/Flex/Lexer.h"

#include "DLDL_COMMENT/Ast/Enum/Type.h"

#include "DLDL_COMMENT/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_COMMENT/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_COMMENT/Ast/Node/COMMENT_VALUE.h"
#include "DLDL_COMMENT/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_COMMENT/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_COMMENT/Ast/Node/START.h"
#include "DLDL_COMMENT/Ast/Node/END.h"
#include "DLDL_COMMENT/Ast/Node/TEXT.h"
#include "DLDL_COMMENT/Ast/Node/VARNAME.h"
#include "DLDL_COMMENT/Ast/Node/ESCAPE_CHARS.h"
#include "DLDL_COMMENT/Ast/Node/program.h"
#include "DLDL_COMMENT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_COMMENT/Ast/Node/stmt.h"
#include "DLDL_COMMENT/Ast/Node/comment_value_declaration.h"
#include "DLDL_COMMENT/Ast/Node/deamerreserved_long_3.h"
#include "DLDL_COMMENT/Ast/Node/deamerreserved_long_6.h"
#include "DLDL_COMMENT/Ast/Node/comment_abstraction.h"
#include "DLDL_COMMENT/Ast/Node/start_abstraction.h"
#include "DLDL_COMMENT/Ast/Node/end_abstraction.h"
#include "DLDL_COMMENT/Ast/Node/start_sequence.h"
#include "DLDL_COMMENT/Ast/Node/end_sequence.h"
#include "DLDL_COMMENT/Ast/Node/sequence.h"
#include "DLDL_COMMENT/Ast/Node/syntactic_reference.h"


#include "Bison/DLDL_COMMENT_parser.tab.h"
void showError();
extern int DLDL_COMMENTlex();

static bool local_store     = false;
static bool include_deleted = false;

int DLDL_COMMENT_column    = 1;
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
COMMENT_VALUE	([Cc][Oo][Mm][Mm][Ee][Nn][Tt])
LEFT_SQUARE_BRACKET	([\[])
RIGHT_SQUARE_BRACKET	([\]])
START	([Ss][Tt][Aa][Rr][Tt])
END	([Ee][Nn][Dd])
TEXT	(["][^"]*["])
VARNAME	([a-zA-Z_][a-zA-Z_0-9]*)
ESCAPE_CHARS	([ \n\r\t])

DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH	(.)

%%

{SINGLE_COMMENT}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(1))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(1))); else if (local_store && true); else if (!true || include_deleted) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(1)); else if (false) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(1)); if ((!local_store && false) || (!local_store && include_deleted)) return (SINGLE_COMMENT); }
{MULTI_COMMENT}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(2))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(2))); else if (local_store && true); else if (!true || include_deleted) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(2)); else if (false) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(2)); if ((!local_store && false) || (!local_store && include_deleted)) return (MULTI_COMMENT); }
{COMMENT_VALUE}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(3))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(3))); else if (local_store && true); else if (!true || include_deleted) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(3)); else if (true) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(3)); if ((!local_store && true) || (!local_store && include_deleted)) return (COMMENT_VALUE); }
{LEFT_SQUARE_BRACKET}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(4))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(4))); else if (local_store && true); else if (!true || include_deleted) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(4)); else if (true) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(4)); if ((!local_store && true) || (!local_store && include_deleted)) return (LEFT_SQUARE_BRACKET); }
{RIGHT_SQUARE_BRACKET}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(5))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(5))); else if (local_store && true); else if (!true || include_deleted) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(5)); else if (true) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(5)); if ((!local_store && true) || (!local_store && include_deleted)) return (RIGHT_SQUARE_BRACKET); }
{START}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(6))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(6))); else if (local_store && true); else if (!true || include_deleted) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(6)); else if (true) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(6)); if ((!local_store && true) || (!local_store && include_deleted)) return (START); }
{END}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(7))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(7))); else if (local_store && true); else if (!true || include_deleted) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(7)); else if (true) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(7)); if ((!local_store && true) || (!local_store && include_deleted)) return (END); }
{TEXT}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(8))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(8))); else if (local_store && false); else if (!false || include_deleted) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(8)); else if (true) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(8)); if ((!local_store && true) || (!local_store && include_deleted)) return (TEXT); }
{VARNAME}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(9))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(9))); else if (local_store && false); else if (!false || include_deleted) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(9)); else if (true) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(9)); if ((!local_store && true) || (!local_store && include_deleted)) return (VARNAME); }
{ESCAPE_CHARS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(10))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(10))); else if (local_store && true); else if (!true || include_deleted) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(10)); else if (false) DLDL_COMMENTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_COMMENT_column, std::size_t(10)); if ((!local_store && false) || (!local_store && include_deleted)) return (ESCAPE_CHARS); }

{DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH} { if (local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_COMMENT_column, std::size_t(0))); }

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
	DLDL_COMMENT_column = next_column;

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

std::vector<const ::deamer::external::cpp::lexer::TerminalObject*> DLDL_COMMENT::flex::lexer::Lexer::Tokenize(const std::string& text, ::deamer::external::cpp::lexer::TerminalConstructionPolicy constructionPolicy) const
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
	DLDL_COMMENT_column = 0;

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