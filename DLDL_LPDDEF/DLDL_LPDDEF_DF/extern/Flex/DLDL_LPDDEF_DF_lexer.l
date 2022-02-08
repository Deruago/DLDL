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
#include "DLDL_LPDDEF_DF/Ast/Node/optional_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value_part.h"
#include "DLDL_LPDDEF_DF/Ast/Node/standard_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value_type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_arrow__value_type__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__COMMA__value_type__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/var_type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_arrow__VARNAME__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__COLON__VARNAME__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/var_name.h"
#include "Bison/DLDL_LPDDEF_DF_parser.tab.h"
void showError();
extern int DLDL_LPDDEF_DFlex();

static bool local_store = false;
static int column = 0;
static int handleColumn(const std::string& text);
static void store(const deamer::external::cpp::lexer::TerminalObject* const newObject);
static std::vector<const deamer::external::cpp::lexer::TerminalObject*> local_objects;
#ifndef yyval
#define yyval yytext
#endif //yyval
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
DEAMER_VARNAME	(deamer([:][:][a-zA-Z_][a-zA-Z_0-9])+)
COMMENT	([/]+[^\n]*[\n])
VARNAME	([a-zA-Z_][a-zA-Z_0-9]*)
NUMBER	([-]*[0-9]+)
STRING	(["][^"]*["])
SEMICOLON	([;])
ESCAPE_CHARS	([\n\t\r\b\v\a ])

%%

{LAB}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(1)));else DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(1));;handleColumn(yyval);if (!local_store) return (LAB);;}
{RAB}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(2)));else DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(2));;handleColumn(yyval);if (!local_store) return (RAB);;}
{LSB}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(3)));else DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(3));;handleColumn(yyval);if (!local_store) return (LSB);;}
{RSB}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(4)));else DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(4));;handleColumn(yyval);if (!local_store) return (RSB);;}
{EQ}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(5)));else DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, column, std::size_t(5));;handleColumn(yyval);if (!local_store) return (EQ);;}
{COLON}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(6)));else DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(6));;handleColumn(yyval);if (!local_store) return (COLON);;}
{LB}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(7)));else DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(7));;handleColumn(yyval);if (!local_store) return (LB);;}
{RB}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(8)));else DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(8));;handleColumn(yyval);if (!local_store) return (RB);;}
{COMMA}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(9)));else DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(9));;handleColumn(yyval);if (!local_store) return (COMMA);;}
{OPTIONAL}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(10)));else DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(10));;handleColumn(yyval);if (!local_store) return (OPTIONAL);;}
{VECTOR}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(11)));else DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(11));;handleColumn(yyval);if (!local_store) return (VECTOR);;}
{DEAMER_VARNAME}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(12)));else DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(12));;handleColumn(yyval);if (!local_store) return (DEAMER_VARNAME);;}
{COMMENT}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(13)));else DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(13));;handleColumn(yyval);if (!local_store) return (COMMENT);;}
{VARNAME}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(14)));else DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(14));;handleColumn(yyval);if (!local_store) return (VARNAME);;}
{NUMBER}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(15)));else DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(15));;handleColumn(yyval);if (!local_store) return (NUMBER);;}
{STRING}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(16)));else DLDL_LPDDEF_DFlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(16));;handleColumn(yyval);if (!local_store) return (STRING);;}
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

std::vector<const deamer::external::cpp::lexer::TerminalObject*> DLDL_LPDDEF_DF::lexer::Lexer::Tokenize(const std::string& text) const
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


