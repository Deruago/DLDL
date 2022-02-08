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
#include "DLDL_LPDDEF_EF/Flex/Lexer.h"
#include "DLDL_LPDDEF_EF/Ast/Enum/Type.h"
#include "DLDL_LPDDEF_EF/Ast/Node/COMMENT.h"
#include "DLDL_LPDDEF_EF/Ast/Node/VARNAME.h"
#include "DLDL_LPDDEF_EF/Ast/Node/NUMBER.h"
#include "DLDL_LPDDEF_EF/Ast/Node/COLON.h"
#include "DLDL_LPDDEF_EF/Ast/Node/SEMICOLON.h"
#include "DLDL_LPDDEF_EF/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_LPDDEF_EF/Ast/Node/program.h"
#include "DLDL_LPDDEF_EF/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDDEF_EF/Ast/Node/stmt.h"
#include "DLDL_LPDDEF_EF/Ast/Node/comment_line.h"
#include "DLDL_LPDDEF_EF/Ast/Node/standard_variant.h"
#include "DLDL_LPDDEF_EF/Ast/Node/standard_variant_specific_number.h"
#include "DLDL_LPDDEF_EF/Ast/Node/value.h"
#include "DLDL_LPDDEF_EF/Ast/Node/enum_name.h"
#include "Bison/DLDL_LPDDEF_EF_parser.tab.h"
void showError();
extern int DLDL_LPDDEF_EFlex();

static bool local_store = false;
static int column = 0;
static int handleColumn(const std::string& text);
static void store(const deamer::external::cpp::lexer::TerminalObject* const newObject);
static std::vector<const deamer::external::cpp::lexer::TerminalObject*> local_objects;
#ifndef yyval
#define yyval yytext
#endif //yyval
%}

COMMENT	([/]+[^\n]*[\n])
VARNAME	([a-zA-Z_]+[a-zA-Z_0-9]*)
NUMBER	([-]*[0-9]+)
COLON	([:])
SEMICOLON	([;])
ESCAPE_CHARS	([\n\t\r\b\v\a ])

%%

{COMMENT}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(1)));else DLDL_LPDDEF_EFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(1));;handleColumn(yyval);if (!local_store) return (COMMENT);;}
{VARNAME}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(2)));else DLDL_LPDDEF_EFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(2));;handleColumn(yyval);if (!local_store) return (VARNAME);;}
{NUMBER}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(3)));else DLDL_LPDDEF_EFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(3));;handleColumn(yyval);if (!local_store) return (NUMBER);;}
{COLON}	{handleColumn(yyval);if (!local_store) ;}
{SEMICOLON}	{handleColumn(yyval);if (!local_store) ;}
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

std::vector<const deamer::external::cpp::lexer::TerminalObject*> DLDL_LPDDEF_EF::lexer::Lexer::Tokenize(const std::string& text) const
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


