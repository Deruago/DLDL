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
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Flex/Lexer.h"

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Enum/Type.h"

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ENDING_USELESS_SYMBOLS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/VERTICAL_SLASH.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/QUESTION_MARK.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/EXCLAMATION_MARK.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ARROW.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/STAR.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/PLUS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/MINUS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/VALUE.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/NUMBER.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/SINGLE_LINE_COMMENT.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/MULTI_LINE_COMMENT.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/SYMBOLS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ESCAPE_CHARS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/program.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/stmts.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/stmt.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/nested_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/optional_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/zero_or_more_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/one_or_more_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/or_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/min_max_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/extension_group.h"


#include "Bison/DLDL_GRAMMAR_PRODUCTION_RULE_parser.tab.h"
void showError();
extern int DLDL_GRAMMAR_PRODUCTION_RULElex();

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

ENDING_USELESS_SYMBOLS	([|;\r\b\v\a\f\t ]+[\n]+)
VERTICAL_SLASH	([|])
LEFT_PARANTHESIS	([(])
RIGHT_PARANTHESIS	([)])
LEFT_BRACKET	([{])
RIGHT_BRACKET	([}])
LEFT_SQUARE_BRACKET	([\[])
RIGHT_SQUARE_BRACKET	([\]])
QUESTION_MARK	([?])
EXCLAMATION_MARK	([!])
ARROW	([\-][>])
STAR	([*])
PLUS	([+])
MINUS	([\-])
VALUE	([a-zA-Z_]+[a-zA-Z_0-9]*)
NUMBER	([0-9]+)
SINGLE_LINE_COMMENT	([/][^\n]*[\n])
MULTI_LINE_COMMENT	([/][*][^*][*][/])
SYMBOLS	([:;="'])
ESCAPE_CHARS	([\n\r\b\v\a\f\t ])

DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH	(.)

%%

{ENDING_USELESS_SYMBOLS}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(1))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(1))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(1)); else if (!true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(1)); handleColumn(yyval); if ((!local_store && false) || (!local_store && include_deleted)) return (ENDING_USELESS_SYMBOLS); }
{VERTICAL_SLASH}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(2))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(2))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(2)); else if (!true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(2)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (VERTICAL_SLASH); }
{LEFT_PARANTHESIS}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(3))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(3))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(3)); else if (!true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(3)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (LEFT_PARANTHESIS); }
{RIGHT_PARANTHESIS}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(4))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(4))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(4)); else if (!true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(4)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (RIGHT_PARANTHESIS); }
{LEFT_BRACKET}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(5))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(5))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(5)); else if (!true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(5)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (LEFT_BRACKET); }
{RIGHT_BRACKET}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(6))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(6))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(6)); else if (!true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(6)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (RIGHT_BRACKET); }
{LEFT_SQUARE_BRACKET}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(7))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(7))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(7)); else if (!true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(7)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (LEFT_SQUARE_BRACKET); }
{RIGHT_SQUARE_BRACKET}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(8))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(8))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(8)); else if (!true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(8)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (RIGHT_SQUARE_BRACKET); }
{QUESTION_MARK}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(9))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(9))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(9)); else if (!true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(9)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (QUESTION_MARK); }
{EXCLAMATION_MARK}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(10))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(10))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(10)); else if (!true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(10)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (EXCLAMATION_MARK); }
{ARROW}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(11))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(11))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(11)); else if (!true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(11)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (ARROW); }
{STAR}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(12))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(12))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(12)); else if (!true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(12)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (STAR); }
{PLUS}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(13))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(13))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(13)); else if (!true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(13)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (PLUS); }
{MINUS}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(14))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(14))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(14)); else if (!true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(14)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (MINUS); }
{VALUE}	{  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(15))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(15))); else if (local_store && false); else if (!false || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(15)); else if (!false) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(15)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (VALUE); }
{NUMBER}	{  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(16))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(16))); else if (local_store && false); else if (!false || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(16)); else if (!false) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(16)); handleColumn(yyval); if ((!local_store && true) || (!local_store && include_deleted)) return (NUMBER); }
{SINGLE_LINE_COMMENT}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(17))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(17))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(17)); else if (!true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(17)); handleColumn(yyval); if ((!local_store && false) || (!local_store && include_deleted)) return (SINGLE_LINE_COMMENT); }
{MULTI_LINE_COMMENT}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(18))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(18))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(18)); else if (!true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(18)); handleColumn(yyval); if ((!local_store && false) || (!local_store && include_deleted)) return (MULTI_LINE_COMMENT); }
{SYMBOLS}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(19))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(19))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(19)); else if (!true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(19)); handleColumn(yyval); if ((!local_store && false) || (!local_store && include_deleted)) return (SYMBOLS); }
{ESCAPE_CHARS}	{  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(20))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(20))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(20)); else if (!true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(20)); handleColumn(yyval); if ((!local_store && false) || (!local_store && include_deleted)) return (ESCAPE_CHARS); }

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

std::vector<const ::deamer::external::cpp::lexer::TerminalObject*> DLDL_GRAMMAR_PRODUCTION_RULE::flex::lexer::Lexer::Tokenize(const std::string& text, ::deamer::external::cpp::lexer::TerminalConstructionPolicy constructionPolicy) const
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