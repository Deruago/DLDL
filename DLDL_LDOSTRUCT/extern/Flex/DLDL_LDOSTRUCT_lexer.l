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
#include "DLDL_LDOSTRUCT/Flex/Lexer.h"
#include "DLDL_LDOSTRUCT/Ast/Enum/Type.h"
#include "DLDL_LDOSTRUCT/Ast/Node/COLON.h"
#include "DLDL_LDOSTRUCT/Ast/Node/LEFT_ANGLE_BRACKET.h"
#include "DLDL_LDOSTRUCT/Ast/Node/RIGHT_ANGLE_BRACKET.h"
#include "DLDL_LDOSTRUCT/Ast/Node/VARNAME.h"
#include "DLDL_LDOSTRUCT/Ast/Node/VARNAME_EXT.h"
#include "DLDL_LDOSTRUCT/Ast/Node/INDENTED_VALUE.h"
#include "DLDL_LDOSTRUCT/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_LDOSTRUCT/Ast/Node/program.h"
#include "DLDL_LDOSTRUCT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LDOSTRUCT/Ast/Node/stmt.h"
#include "DLDL_LDOSTRUCT/Ast/Node/argument.h"
#include "DLDL_LDOSTRUCT/Ast/Node/argument_name.h"
#include "DLDL_LDOSTRUCT/Ast/Node/argument_block.h"
#include "DLDL_LDOSTRUCT/Ast/Node/deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______.h"
#include "Bison/DLDL_LDOSTRUCT_parser.tab.h"
void showError();
extern int DLDL_LDOSTRUCTlex();

static bool local_store = false;
static int column = 0;
static int handleColumn(const std::string& text);
static void store(const deamer::external::cpp::lexer::TerminalObject* const newObject);
static std::vector<const deamer::external::cpp::lexer::TerminalObject*> local_objects;
#ifndef yyval
#define yyval yytext
#endif //yyval
%}

COLON	([:])
LEFT_ANGLE_BRACKET	([<])
RIGHT_ANGLE_BRACKET	([>])
VARNAME	([a-zA-Z_]+[a-zA-Z_0-9]*)
VARNAME_EXT	(([a-zA-Z_]+[a-zA-Z_0-9]*)|(([a-zA-Z_]+[a-zA-Z_0-9]*)([:]([a-zA-Z_]+[a-zA-Z_0-9]*))+))
INDENTED_VALUE	([\t ]+[^\n\r]*[\r\n])
ESCAPE_CHARS	([\n\t\r\b\v\a ]+)

%%

{COLON}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(1)));else DLDL_LDOSTRUCTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(1));;handleColumn(yyval);if (!local_store) return (COLON);;}
{LEFT_ANGLE_BRACKET}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(2)));else DLDL_LDOSTRUCTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(2));;handleColumn(yyval);if (!local_store) return (LEFT_ANGLE_BRACKET);;}
{RIGHT_ANGLE_BRACKET}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(3)));else DLDL_LDOSTRUCTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(3));;handleColumn(yyval);if (!local_store) return (RIGHT_ANGLE_BRACKET);;}
{VARNAME}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(4)));else DLDL_LDOSTRUCTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(4));;handleColumn(yyval);if (!local_store) return (VARNAME);;}
{VARNAME_EXT}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(5)));else DLDL_LDOSTRUCTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(5));;handleColumn(yyval);if (!local_store) return (VARNAME_EXT);;}
{INDENTED_VALUE}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(6)));else DLDL_LDOSTRUCTlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(6));;handleColumn(yyval);if (!local_store) return (INDENTED_VALUE);;}
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

std::vector<const deamer::external::cpp::lexer::TerminalObject*> DLDL_LDOSTRUCT::lexer::Lexer::Tokenize(const std::string& text) const
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


