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
#include "DLDL_GRAMMAR/Flex/Lexer.h"
#include "DLDL_GRAMMAR/Ast/Enum/Type.h"
#include "DLDL_GRAMMAR/Ast/Node/COMMENT.h"
#include "DLDL_GRAMMAR/Ast/Node/MULTI_LINE_COMMENT.h"
#include "DLDL_GRAMMAR/Ast/Node/START_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/GROUP_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/INLINE_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/INLINE_GROUP_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/UNKNOWN_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/NONTERMINAL.h"
#include "DLDL_GRAMMAR/Ast/Node/PRODUCTION_RULE.h"
#include "DLDL_GRAMMAR/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_GRAMMAR/Ast/Node/program.h"
#include "DLDL_GRAMMAR/Ast/Node/stmts.h"
#include "DLDL_GRAMMAR/Ast/Node/stmt.h"
#include "DLDL_GRAMMAR/Ast/Node/abstraction_declaration.h"
#include "DLDL_GRAMMAR/Ast/Node/abstraction.h"
#include "DLDL_GRAMMAR/Ast/Node/definition.h"
#include "DLDL_GRAMMAR/Ast/Node/production_rules.h"
#include "Bison/DLDL_GRAMMAR_parser.tab.h"
void showError();
extern int DLDL_GRAMMARlex();

static bool local_store = false;
static int column = 0;
static int handleColumn(const std::string& text);
static void store(const deamer::external::cpp::lexer::TerminalObject* const newObject);
static std::vector<const deamer::external::cpp::lexer::TerminalObject*> local_objects;
#ifndef yyval
#define yyval yytext
#endif //yyval
%}

COMMENT	([/][^\n]*)
MULTI_LINE_COMMENT	([/][/]([/][^/]|[\\][/]*|[^/])*[/][/])
START_ABSTRACTION	([Ss]tart[:][ \t]*)
GROUP_ABSTRACTION	([Gg]roup[:][ \t]*)
INLINE_ABSTRACTION	([Ii]nline[:][ \t]*)
INLINE_GROUP_ABSTRACTION	((([Ii]nline[ ][Gg]roup)|([Gg]roup[ ][Ii]nline))[:][ \t]*)
UNKNOWN_ABSTRACTION	([a-zA-Z0-9_\\$?!-+=]*[:][ \t]*)
NONTERMINAL	([a-zA-Z_]+)
PRODUCTION_RULE	([ \t]+[^\n\r]*)
ESCAPE_CHARS	([\n\r\b\v\a\f\t ])

%%

{COMMENT}	{handleColumn(yyval);if (!local_store) ;}
{MULTI_LINE_COMMENT}	{handleColumn(yyval);if (!local_store) ;}
{START_ABSTRACTION}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (START_ABSTRACTION);;}
{GROUP_ABSTRACTION}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (GROUP_ABSTRACTION);;}
{INLINE_ABSTRACTION}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (INLINE_ABSTRACTION);;}
{INLINE_GROUP_ABSTRACTION}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (INLINE_GROUP_ABSTRACTION);;}
{UNKNOWN_ABSTRACTION}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column));else DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column);;handleColumn(yyval);if (!local_store) return (UNKNOWN_ABSTRACTION);;}
{NONTERMINAL}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column));else DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column);;handleColumn(yyval);if (!local_store) return (NONTERMINAL);;}
{PRODUCTION_RULE}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column));else DLDL_GRAMMARlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column);;handleColumn(yyval);if (!local_store) return (PRODUCTION_RULE);;}
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

std::vector<const deamer::external::cpp::lexer::TerminalObject*> DLDL_GRAMMAR::lexer::Lexer::Tokenize(const std::string& text) const
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


