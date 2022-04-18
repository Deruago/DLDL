%define parse.error verbose
%define parse.lac full


%{
#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <Deamer/External/Cpp/Ast/Node.h>
#include "DLDL_ASSOCIATIVITY/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/DLDL_ASSOCIATIVITY_lexer.h"
#undef YY_NO_UNISTD_H
#include "DLDL_ASSOCIATIVITY/Ast/Enum/Type.h"
#include "DLDL_ASSOCIATIVITY/Ast/Node/ASSOCIATIVITY.h"


#include "DLDL_ASSOCIATIVITY/Ast/Node/program.h"
#include "DLDL_ASSOCIATIVITY/Ast/Node/stmts.h"
#include "DLDL_ASSOCIATIVITY/Ast/Node/stmt.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDL_ASSOCIATIVITYnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDL_ASSOCIATIVITYlloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE

void DLDL_ASSOCIATIVITYerror(const char* s);
int DLDL_ASSOCIATIVITYlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;
%}

%token<Terminal> ASSOCIATIVITY


%nterm<DLDL_ASSOCIATIVITY_program> program
%nterm<DLDL_ASSOCIATIVITY_stmts> stmts
%nterm<DLDL_ASSOCIATIVITY_stmt> stmt


%union{
	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY* DLDL_ASSOCIATIVITY_ASSOCIATIVITY;
	::DLDL_ASSOCIATIVITY::ast::node::program* DLDL_ASSOCIATIVITY_program;
	::DLDL_ASSOCIATIVITY::ast::node::stmts* DLDL_ASSOCIATIVITY_stmts;
	::DLDL_ASSOCIATIVITY::ast::node::stmt* DLDL_ASSOCIATIVITY_stmt;

}

%%


program:
	stmts  {
		auto* const newNode = new DLDL_ASSOCIATIVITY::ast::node::program({::DLDL_ASSOCIATIVITY::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;


stmts:
	stmt stmts  {
		auto* const newNode = new DLDL_ASSOCIATIVITY::ast::node::stmts({::DLDL_ASSOCIATIVITY::ast::Type::stmts, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_ASSOCIATIVITY::ast::node::stmts({::DLDL_ASSOCIATIVITY::ast::Type::stmts, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


stmt:
	ASSOCIATIVITY  {
		auto* const newNode = new DLDL_ASSOCIATIVITY::ast::node::stmt({::DLDL_ASSOCIATIVITY::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY({::DLDL_ASSOCIATIVITY::ast::Type::ASSOCIATIVITY, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;



%%

void DLDL_ASSOCIATIVITYerror(const char* s)
{
	std::cout << "Syntax error on line: " << s << '\n';
}

deamer::external::cpp::ast::Tree* DLDL_ASSOCIATIVITY::bison::parser::Parser::Parse(const std::string& text) const
{
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_ASSOCIATIVITY_scan_string(text.c_str());
	DLDL_ASSOCIATIVITYparse();
	DLDL_ASSOCIATIVITY_delete_buffer(buf);
	DLDL_ASSOCIATIVITYlex_destroy();

	return outputTree;
}
