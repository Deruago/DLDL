%define parse.error verbose
%define parse.lac full


%{
#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <Deamer/External/Cpp/Ast/Node.h>
#include "DLDL/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/DLDL_lexer.h"
#undef YY_NO_UNISTD_H
#include "DLDL/Ast/Enum/Type.h"
#include "DLDL/Ast/Node/ANY.h"


#include "DLDL/Ast/Node/program.h"
#include "DLDL/Ast/Node/stmts.h"
#include "DLDL/Ast/Node/stmt.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDLnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDLlloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE

void DLDLerror(const char* s);
int DLDLlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;
%}

%token<Terminal> ANY


%nterm<DLDL_program> program
%nterm<DLDL_stmts> stmts
%nterm<DLDL_stmt> stmt


%union{
	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL::ast::node::ANY* DLDL_ANY;
	::DLDL::ast::node::program* DLDL_program;
	::DLDL::ast::node::stmts* DLDL_stmts;
	::DLDL::ast::node::stmt* DLDL_stmt;

}

%%


program:
	stmts  {
		auto* const newNode = new DLDL::ast::node::program({::DLDL::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;


stmts:
	stmt stmts  {
		auto* const newNode = new DLDL::ast::node::stmts({::DLDL::ast::Type::stmts, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL::ast::node::stmts({::DLDL::ast::Type::stmts, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


stmt:
	ANY  {
		auto* const newNode = new DLDL::ast::node::stmt({::DLDL::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL::ast::node::ANY({::DLDL::ast::Type::ANY, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;



%%

void DLDLerror(const char* s)
{
	std::cout << "Syntax error on line: " << s << '\n';
}

deamer::external::cpp::ast::Tree* DLDL::bison::parser::Parser::Parse(const std::string& text) const
{
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_scan_string(text.c_str());
	DLDLparse();
	DLDL_delete_buffer(buf);
	DLDLlex_destroy();

	return outputTree;
}
