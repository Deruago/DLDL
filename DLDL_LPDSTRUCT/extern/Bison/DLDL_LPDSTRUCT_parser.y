%define parse.error verbose
%define parse.lac full

%{
#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <Deamer/External/Cpp/Ast/Node.h>
#include "DLDL_LPDSTRUCT/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/DLDL_LPDSTRUCT_lexer.h"
#undef YY_NO_UNISTD_H
#include "DLDL_LPDSTRUCT/Ast/Enum/Type.h"
#include "DLDL_LPDSTRUCT/Ast/Node/COLON.h"
#include "DLDL_LPDSTRUCT/Ast/Node/LEFT_ANGLE_BRACKET.h"
#include "DLDL_LPDSTRUCT/Ast/Node/RIGHT_ANGLE_BRACKET.h"
#include "DLDL_LPDSTRUCT/Ast/Node/VARNAME.h"
#include "DLDL_LPDSTRUCT/Ast/Node/VARNAME_EXT.h"
#include "DLDL_LPDSTRUCT/Ast/Node/INDENTED_VALUE.h"
#include "DLDL_LPDSTRUCT/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_LPDSTRUCT/Ast/Node/program.h"
#include "DLDL_LPDSTRUCT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDSTRUCT/Ast/Node/stmt.h"
#include "DLDL_LPDSTRUCT/Ast/Node/argument.h"
#include "DLDL_LPDSTRUCT/Ast/Node/argument_name.h"
#include "DLDL_LPDSTRUCT/Ast/Node/argument_block.h"
#include "DLDL_LPDSTRUCT/Ast/Node/deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDL_LPDSTRUCTnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDL_LPDSTRUCTlloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE

void DLDL_LPDSTRUCTerror(const char* s);
int DLDL_LPDSTRUCTlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;
%}

%token<Terminal> COLON
%token<Terminal> LEFT_ANGLE_BRACKET
%token<Terminal> RIGHT_ANGLE_BRACKET
%token<Terminal> VARNAME
%token<Terminal> VARNAME_EXT
%token<Terminal> INDENTED_VALUE
%token<Terminal> ESCAPE_CHARS


%nterm<DLDL_LPDSTRUCT_program> program
%nterm<DLDL_LPDSTRUCT_deamerreserved_star__stmt__> deamerreserved_star__stmt__
%nterm<DLDL_LPDSTRUCT_stmt> stmt
%nterm<DLDL_LPDSTRUCT_argument> argument
%nterm<DLDL_LPDSTRUCT_argument_name> argument_name
%nterm<DLDL_LPDSTRUCT_argument_block> argument_block
%nterm<DLDL_LPDSTRUCT_deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______> deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______


%union{
	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_LPDSTRUCT::ast::node::COLON* DLDL_LPDSTRUCT_COLON;
	::DLDL_LPDSTRUCT::ast::node::LEFT_ANGLE_BRACKET* DLDL_LPDSTRUCT_LEFT_ANGLE_BRACKET;
	::DLDL_LPDSTRUCT::ast::node::RIGHT_ANGLE_BRACKET* DLDL_LPDSTRUCT_RIGHT_ANGLE_BRACKET;
	::DLDL_LPDSTRUCT::ast::node::VARNAME* DLDL_LPDSTRUCT_VARNAME;
	::DLDL_LPDSTRUCT::ast::node::VARNAME_EXT* DLDL_LPDSTRUCT_VARNAME_EXT;
	::DLDL_LPDSTRUCT::ast::node::INDENTED_VALUE* DLDL_LPDSTRUCT_INDENTED_VALUE;
	::DLDL_LPDSTRUCT::ast::node::ESCAPE_CHARS* DLDL_LPDSTRUCT_ESCAPE_CHARS;
	::DLDL_LPDSTRUCT::ast::node::program* DLDL_LPDSTRUCT_program;
	::DLDL_LPDSTRUCT::ast::node::deamerreserved_star__stmt__* DLDL_LPDSTRUCT_deamerreserved_star__stmt__;
	::DLDL_LPDSTRUCT::ast::node::stmt* DLDL_LPDSTRUCT_stmt;
	::DLDL_LPDSTRUCT::ast::node::argument* DLDL_LPDSTRUCT_argument;
	::DLDL_LPDSTRUCT::ast::node::argument_name* DLDL_LPDSTRUCT_argument_name;
	::DLDL_LPDSTRUCT::ast::node::argument_block* DLDL_LPDSTRUCT_argument_block;
	::DLDL_LPDSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______* DLDL_LPDSTRUCT_deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______;

}

%%


program:
	deamerreserved_star__stmt__  {
		auto* const newNode = new DLDL_LPDSTRUCT::ast::node::program({::DLDL_LPDSTRUCT::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;


deamerreserved_star__stmt__:
	stmt deamerreserved_star__stmt__  {
		auto* const newNode = new DLDL_LPDSTRUCT::ast::node::deamerreserved_star__stmt__({::DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_LPDSTRUCT::ast::node::deamerreserved_star__stmt__({::DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


stmt:
	argument  {
		auto* const newNode = new DLDL_LPDSTRUCT::ast::node::stmt({::DLDL_LPDSTRUCT::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


argument:
	argument_name COLON VARNAME_EXT  {
		auto* const newNode = new DLDL_LPDSTRUCT::ast::node::argument({::DLDL_LPDSTRUCT::ast::Type::argument, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new DLDL_LPDSTRUCT::ast::node::VARNAME_EXT({::DLDL_LPDSTRUCT::ast::Type::VARNAME_EXT, ::deamer::external::cpp::ast::NodeValue::terminal, $3 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
	}
	| argument_name COLON argument_block  {
		auto* const newNode = new DLDL_LPDSTRUCT::ast::node::argument({::DLDL_LPDSTRUCT::ast::Type::argument, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $3 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
	}
;


argument_name:
	VARNAME  {
		auto* const newNode = new DLDL_LPDSTRUCT::ast::node::argument_name({::DLDL_LPDSTRUCT::ast::Type::argument_name, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDSTRUCT::ast::node::VARNAME({::DLDL_LPDSTRUCT::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


argument_block:
	LEFT_ANGLE_BRACKET deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______ RIGHT_ANGLE_BRACKET  {
		auto* const newNode = new DLDL_LPDSTRUCT::ast::node::argument_block({::DLDL_LPDSTRUCT::ast::Type::argument_block, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $1;
		delete $3;
	}
;


deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______:
	INDENTED_VALUE deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______  {
		auto* const newNode = new DLDL_LPDSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______({::DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new DLDL_LPDSTRUCT::ast::node::INDENTED_VALUE({::DLDL_LPDSTRUCT::ast::Type::INDENTED_VALUE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| VARNAME_EXT deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______  {
		auto* const newNode = new DLDL_LPDSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______({::DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new DLDL_LPDSTRUCT::ast::node::VARNAME_EXT({::DLDL_LPDSTRUCT::ast::Type::VARNAME_EXT, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| VARNAME deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______  {
		auto* const newNode = new DLDL_LPDSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______({::DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new DLDL_LPDSTRUCT::ast::node::VARNAME({::DLDL_LPDSTRUCT::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_LPDSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______({::DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;



%%

void DLDL_LPDSTRUCTerror(const char* s)
{
	std::cout << "Syntax error on line: " << s << '\n';
}

deamer::external::cpp::ast::Tree* DLDL_LPDSTRUCT::parser::Parser::Parse(const std::string& text) const
{
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_LPDSTRUCT_scan_string(text.c_str());
	DLDL_LPDSTRUCTparse();
	DLDL_LPDSTRUCT_delete_buffer(buf);
	DLDL_LPDSTRUCTlex_destroy();

	return outputTree;
}
