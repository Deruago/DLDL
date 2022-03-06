%define parse.error verbose
%define parse.lac full


%{
#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <Deamer/External/Cpp/Ast/Node.h>
#include "DLDL_GENERATION/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/DLDL_GENERATION_lexer.h"
#undef YY_NO_UNISTD_H
#include "DLDL_GENERATION/Ast/Enum/Type.h"
#include "DLDL_GENERATION/Ast/Node/GENERATE.h"
#include "DLDL_GENERATION/Ast/Node/INTEGRATE.h"
#include "DLDL_GENERATION/Ast/Node/ARGUMENT.h"
#include "DLDL_GENERATION/Ast/Node/VALUE.h"
#include "DLDL_GENERATION/Ast/Node/SYMBOLS.h"
#include "DLDL_GENERATION/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_GENERATION/Ast/Node/program.h"
#include "DLDL_GENERATION/Ast/Node/stmts.h"
#include "DLDL_GENERATION/Ast/Node/stmt.h"
#include "DLDL_GENERATION/Ast/Node/generate_declaration.h"
#include "DLDL_GENERATION/Ast/Node/integrate_declaration.h"
#include "DLDL_GENERATION/Ast/Node/argument_declaration.h"
#include "DLDL_GENERATION/Ast/Node/type.h"
#include "DLDL_GENERATION/Ast/Node/tool.h"
#include "DLDL_GENERATION/Ast/Node/argument_data.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDL_GENERATIONnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDL_GENERATIONlloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE

void DLDL_GENERATIONerror(const char* s);
int DLDL_GENERATIONlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;
%}

%token<Terminal> GENERATE
%token<Terminal> INTEGRATE
%token<Terminal> ARGUMENT
%token<Terminal> VALUE
%token<Terminal> SYMBOLS
%token<Terminal> ESCAPE_CHARS


%nterm<DLDL_GENERATION_program> program
%nterm<DLDL_GENERATION_stmts> stmts
%nterm<DLDL_GENERATION_stmt> stmt
%nterm<DLDL_GENERATION_generate_declaration> generate_declaration
%nterm<DLDL_GENERATION_integrate_declaration> integrate_declaration
%nterm<DLDL_GENERATION_argument_declaration> argument_declaration
%nterm<DLDL_GENERATION_type> type
%nterm<DLDL_GENERATION_tool> tool
%nterm<DLDL_GENERATION_argument_data> argument_data


%union{
	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_GENERATION::ast::node::GENERATE* DLDL_GENERATION_GENERATE;
	::DLDL_GENERATION::ast::node::INTEGRATE* DLDL_GENERATION_INTEGRATE;
	::DLDL_GENERATION::ast::node::ARGUMENT* DLDL_GENERATION_ARGUMENT;
	::DLDL_GENERATION::ast::node::VALUE* DLDL_GENERATION_VALUE;
	::DLDL_GENERATION::ast::node::SYMBOLS* DLDL_GENERATION_SYMBOLS;
	::DLDL_GENERATION::ast::node::ESCAPE_CHARS* DLDL_GENERATION_ESCAPE_CHARS;
	::DLDL_GENERATION::ast::node::program* DLDL_GENERATION_program;
	::DLDL_GENERATION::ast::node::stmts* DLDL_GENERATION_stmts;
	::DLDL_GENERATION::ast::node::stmt* DLDL_GENERATION_stmt;
	::DLDL_GENERATION::ast::node::generate_declaration* DLDL_GENERATION_generate_declaration;
	::DLDL_GENERATION::ast::node::integrate_declaration* DLDL_GENERATION_integrate_declaration;
	::DLDL_GENERATION::ast::node::argument_declaration* DLDL_GENERATION_argument_declaration;
	::DLDL_GENERATION::ast::node::type* DLDL_GENERATION_type;
	::DLDL_GENERATION::ast::node::tool* DLDL_GENERATION_tool;
	::DLDL_GENERATION::ast::node::argument_data* DLDL_GENERATION_argument_data;

}

%%


program:
	stmts  {
		auto* const newNode = new DLDL_GENERATION::ast::node::program({::DLDL_GENERATION::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;


stmts:
	stmt stmts  {
		auto* const newNode = new DLDL_GENERATION::ast::node::stmts({::DLDL_GENERATION::ast::Type::stmts, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_GENERATION::ast::node::stmts({::DLDL_GENERATION::ast::Type::stmts, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


stmt:
	generate_declaration  {
		auto* const newNode = new DLDL_GENERATION::ast::node::stmt({::DLDL_GENERATION::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| integrate_declaration  {
		auto* const newNode = new DLDL_GENERATION::ast::node::stmt({::DLDL_GENERATION::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| argument_declaration  {
		auto* const newNode = new DLDL_GENERATION::ast::node::stmt({::DLDL_GENERATION::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


generate_declaration:
	GENERATE type tool  {
		auto* const newNode = new DLDL_GENERATION::ast::node::generate_declaration({::DLDL_GENERATION::ast::Type::generate_declaration, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_GENERATION::ast::node::GENERATE({::DLDL_GENERATION::ast::Type::GENERATE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2, $3 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


integrate_declaration:
	INTEGRATE tool tool  {
		auto* const newNode = new DLDL_GENERATION::ast::node::integrate_declaration({::DLDL_GENERATION::ast::Type::integrate_declaration, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_GENERATION::ast::node::INTEGRATE({::DLDL_GENERATION::ast::Type::INTEGRATE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2, $3 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


argument_declaration:
	ARGUMENT tool argument_data  {
		auto* const newNode = new DLDL_GENERATION::ast::node::argument_declaration({::DLDL_GENERATION::ast::Type::argument_declaration, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_GENERATION::ast::node::ARGUMENT({::DLDL_GENERATION::ast::Type::ARGUMENT, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2, $3 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


type:
	VALUE  {
		auto* const newNode = new DLDL_GENERATION::ast::node::type({::DLDL_GENERATION::ast::Type::type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_GENERATION::ast::node::VALUE({::DLDL_GENERATION::ast::Type::VALUE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


tool:
	VALUE  {
		auto* const newNode = new DLDL_GENERATION::ast::node::tool({::DLDL_GENERATION::ast::Type::tool, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_GENERATION::ast::node::VALUE({::DLDL_GENERATION::ast::Type::VALUE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


argument_data:
	VALUE argument_data  {
		auto* const newNode = new DLDL_GENERATION::ast::node::argument_data({::DLDL_GENERATION::ast::Type::argument_data, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_GENERATION::ast::node::VALUE({::DLDL_GENERATION::ast::Type::VALUE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_GENERATION::ast::node::argument_data({::DLDL_GENERATION::ast::Type::argument_data, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;



%%

void DLDL_GENERATIONerror(const char* s)
{
	std::cout << "Syntax error on line: " << s << '\n';
}

deamer::external::cpp::ast::Tree* DLDL_GENERATION::parser::Parser::Parse(const std::string& text) const
{
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_GENERATION_scan_string(text.c_str());
	DLDL_GENERATIONparse();
	DLDL_GENERATION_delete_buffer(buf);
	DLDL_GENERATIONlex_destroy();

	return outputTree;
}
