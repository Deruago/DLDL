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
#include "DLDL_LEXER/Flex/Lexer.h"
#include "DLDL_LEXER/Ast/Enum/Type.h"
#include "DLDL_LEXER/Ast/Node/COMMENT.h"
#include "DLDL_LEXER/Ast/Node/DELETE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/IGNORE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/NOVALUE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/CRASH_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/STANDARD_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/UNKNOWN_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/TERMINAL.h"
#include "DLDL_LEXER/Ast/Node/REGEX.h"
#include "DLDL_LEXER/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_LEXER/Ast/Node/program.h"
#include "DLDL_LEXER/Ast/Node/stmts.h"
#include "DLDL_LEXER/Ast/Node/stmt.h"
#include "DLDL_LEXER/Ast/Node/tokendeclaration.h"
#include "DLDL_LEXER/Ast/Node/abstraction.h"
#include "Bison/DLDL_LEXER_parser.tab.h"
void showError();
extern int DLDL_LEXERlex();

static bool local_store = false;
static void store(const deamer::external::cpp::lexer::TerminalObject* const newObject);
static std::vector<const deamer::external::cpp::lexer::TerminalObject*> local_objects;
#ifndef yyval
#define yyval yytext
#endif //yyval
%}

COMMENT	([/][^\n]*)
DELETE_ABSTRACTION	([Dd]elete[:][ ]*)
IGNORE_ABSTRACTION	([Ii]gnore[:][ ]*)
NOVALUE_ABSTRACTION	((([Nn]o[Vv]alue)|([Vv]alue[Ll]ess))[:][ ]*)
CRASH_ABSTRACTION	([Cc]rash[:][ ]*)
STANDARD_ABSTRACTION	([Ss]tandard[:][ ]*)
UNKNOWN_ABSTRACTION	([a-zA-Z0-9_\\$?!-+=]*[:][ ]*)
TERMINAL	([a-zA-Z_]+)
REGEX	([ \t][^\n]*)
ESCAPE_CHARS	([\n\r\t\f\b\a\v])

%%

{COMMENT}	{if (!local_store) ;}
{DELETE_ABSTRACTION}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno));else DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno);;if (!local_store) return (DELETE_ABSTRACTION);;}
{IGNORE_ABSTRACTION}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno));else DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno);;if (!local_store) return (IGNORE_ABSTRACTION);;}
{NOVALUE_ABSTRACTION}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno));else DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno);;if (!local_store) return (NOVALUE_ABSTRACTION);;}
{CRASH_ABSTRACTION}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno));else DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno);;if (!local_store) return (CRASH_ABSTRACTION);;}
{STANDARD_ABSTRACTION}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno));else DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno);;if (!local_store) return (STANDARD_ABSTRACTION);;}
{UNKNOWN_ABSTRACTION}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno));else DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno);;if (!local_store) return (UNKNOWN_ABSTRACTION);;}
{TERMINAL}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno));else DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno);;if (!local_store) return (TERMINAL);;}
{REGEX}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno));else DLDL_LEXERlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno);;if (!local_store) return (REGEX);;}
{ESCAPE_CHARS}	{if (!local_store) ;}

%%
static void store(const deamer::external::cpp::lexer::TerminalObject* const newObject)
{
	local_objects.push_back(newObject);
}

static void clear()
{
	local_objects.clear();
}

std::vector<const deamer::external::cpp::lexer::TerminalObject*> DLDL_LEXER::lexer::Lexer::Tokenize(const std::string& text) const
{
	local_store = true;

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


