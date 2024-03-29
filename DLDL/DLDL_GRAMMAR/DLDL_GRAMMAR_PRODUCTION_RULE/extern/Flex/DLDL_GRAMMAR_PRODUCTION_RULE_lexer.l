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
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/TILDE.h"
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
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/not_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/one_or_more_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/or_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/min_max_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/extension_group.h"


#include "Bison/DLDL_GRAMMAR_PRODUCTION_RULE_parser.tab.h"
void showError();
extern int DLDL_GRAMMAR_PRODUCTION_RULElex();

static bool local_store     = false;
static bool include_deleted = false;

int DLDL_GRAMMAR_PRODUCTION_RULE_column    = 1;
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
TILDE	([~])
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

{ENDING_USELESS_SYMBOLS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(1))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(1))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(1)); else if (false) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(1)); if ((!local_store && false) || (!local_store && include_deleted)) return (ENDING_USELESS_SYMBOLS); }
{VERTICAL_SLASH}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(2))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(2))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(2)); else if (true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(2)); if ((!local_store && true) || (!local_store && include_deleted)) return (VERTICAL_SLASH); }
{LEFT_PARANTHESIS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(3))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(3))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(3)); else if (true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(3)); if ((!local_store && true) || (!local_store && include_deleted)) return (LEFT_PARANTHESIS); }
{RIGHT_PARANTHESIS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(4))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(4))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(4)); else if (true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(4)); if ((!local_store && true) || (!local_store && include_deleted)) return (RIGHT_PARANTHESIS); }
{LEFT_BRACKET}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(5))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(5))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(5)); else if (true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(5)); if ((!local_store && true) || (!local_store && include_deleted)) return (LEFT_BRACKET); }
{RIGHT_BRACKET}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(6))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(6))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(6)); else if (true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(6)); if ((!local_store && true) || (!local_store && include_deleted)) return (RIGHT_BRACKET); }
{LEFT_SQUARE_BRACKET}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(7))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(7))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(7)); else if (true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(7)); if ((!local_store && true) || (!local_store && include_deleted)) return (LEFT_SQUARE_BRACKET); }
{RIGHT_SQUARE_BRACKET}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(8))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(8))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(8)); else if (true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(8)); if ((!local_store && true) || (!local_store && include_deleted)) return (RIGHT_SQUARE_BRACKET); }
{QUESTION_MARK}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(9))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(9))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(9)); else if (true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(9)); if ((!local_store && true) || (!local_store && include_deleted)) return (QUESTION_MARK); }
{EXCLAMATION_MARK}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(10))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(10))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(10)); else if (true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(10)); if ((!local_store && true) || (!local_store && include_deleted)) return (EXCLAMATION_MARK); }
{TILDE}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(11))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(11))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(11)); else if (true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(11)); if ((!local_store && true) || (!local_store && include_deleted)) return (TILDE); }
{ARROW}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(12))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(12))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(12)); else if (true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(12)); if ((!local_store && true) || (!local_store && include_deleted)) return (ARROW); }
{STAR}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(13))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(13))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(13)); else if (true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(13)); if ((!local_store && true) || (!local_store && include_deleted)) return (STAR); }
{PLUS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(14))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(14))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(14)); else if (true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(14)); if ((!local_store && true) || (!local_store && include_deleted)) return (PLUS); }
{MINUS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(15))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(15))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(15)); else if (true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(15)); if ((!local_store && true) || (!local_store && include_deleted)) return (MINUS); }
{VALUE}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(16))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(16))); else if (local_store && false); else if (!false || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(16)); else if (true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(16)); if ((!local_store && true) || (!local_store && include_deleted)) return (VALUE); }
{NUMBER}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(17))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(17))); else if (local_store && false); else if (!false || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(17)); else if (true) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(17)); if ((!local_store && true) || (!local_store && include_deleted)) return (NUMBER); }
{SINGLE_LINE_COMMENT}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(18))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(18))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(18)); else if (false) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(18)); if ((!local_store && false) || (!local_store && include_deleted)) return (SINGLE_LINE_COMMENT); }
{MULTI_LINE_COMMENT}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(19))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(19))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(19)); else if (false) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(19)); if ((!local_store && false) || (!local_store && include_deleted)) return (MULTI_LINE_COMMENT); }
{SYMBOLS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(20))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(20))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(20)); else if (false) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(20)); if ((!local_store && false) || (!local_store && include_deleted)) return (SYMBOLS); }
{ESCAPE_CHARS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(21))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(21))); else if (local_store && true); else if (!true || include_deleted) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(21)); else if (false) DLDL_GRAMMAR_PRODUCTION_RULElval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(21)); if ((!local_store && false) || (!local_store && include_deleted)) return (ESCAPE_CHARS); }

{DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH} { if (local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, DLDL_GRAMMAR_PRODUCTION_RULE_column, std::size_t(0))); }

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
	DLDL_GRAMMAR_PRODUCTION_RULE_column = next_column;

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
	DLDL_GRAMMAR_PRODUCTION_RULE_column = 0;

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