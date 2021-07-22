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
static int column = 0;
static int handleColumn(const std::string& text);
static void store(const deamer::external::cpp::lexer::TerminalObject* const newObject);
static std::vector<const deamer::external::cpp::lexer::TerminalObject*> local_objects;
#ifndef yyval
#define yyval yytext
#endif //yyval
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

%%

{ENDING_USELESS_SYMBOLS}	{handleColumn(yyval);if (!local_store) ;}
{VERTICAL_SLASH}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (VERTICAL_SLASH);;}
{LEFT_PARANTHESIS}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (LEFT_PARANTHESIS);;}
{RIGHT_PARANTHESIS}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (RIGHT_PARANTHESIS);;}
{LEFT_BRACKET}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (LEFT_BRACKET);;}
{RIGHT_BRACKET}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (RIGHT_BRACKET);;}
{LEFT_SQUARE_BRACKET}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (LEFT_SQUARE_BRACKET);;}
{RIGHT_SQUARE_BRACKET}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (RIGHT_SQUARE_BRACKET);;}
{QUESTION_MARK}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (QUESTION_MARK);;}
{EXCLAMATION_MARK}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (EXCLAMATION_MARK);;}
{ARROW}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (ARROW);;}
{STAR}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (STAR);;}
{PLUS}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (PLUS);;}
{MINUS}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (MINUS);;}
{VALUE}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column));else DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column);;handleColumn(yyval);if (!local_store) return (VALUE);;}
{NUMBER}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column));else DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column);;handleColumn(yyval);if (!local_store) return (NUMBER);;}
{SINGLE_LINE_COMMENT}	{handleColumn(yyval);if (!local_store) ;}
{MULTI_LINE_COMMENT}	{handleColumn(yyval);if (!local_store) ;}
{SYMBOLS}	{handleColumn(yyval);if (!local_store) ;}
{ESCAPE_CHARS}	{handleColumn(yyval);if (!local_store) ;}

%%
static void store(const deamer::external::cpp::lexer::TerminalObject* const newObject)
{
	local_objects.push_back(newObject);
}

static void clear()
{
	local_objects.clear();
}

static int handleColumn(const std::string& text)
{
	int currentColumn = column;
	currentColumn += text.size();
	for (auto character : text)
	{
		if (character == '\n')
		{
			currentColumn = 0;
			break;
		}
	}
	
	return currentColumn;
}

std::vector<const deamer::external::cpp::lexer::TerminalObject*> DLDL_GRAMMAR_PRODUCTION_RULE::lexer::Lexer::Tokenize(const std::string& text) const
{
	local_store = true;
	column = 0;

	YY_BUFFER_STATE buf;
	buf = yy_scan_string(text.c_str());
	yylex();
	yy_delete_buffer(buf);
	yylex_destroy();

	local_store = false;

	auto local_objects_copy = local_objects;
	clear();

	return local_objects_copy;
}


