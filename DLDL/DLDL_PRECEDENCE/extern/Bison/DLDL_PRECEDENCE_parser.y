%define parse.error verbose
%define parse.lac full


%{
#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <Deamer/External/Cpp/Ast/Node.h>
#include "DLDL_PRECEDENCE/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/DLDL_PRECEDENCE_lexer.h"
#undef YY_NO_UNISTD_H
#include "DLDL_PRECEDENCE/Ast/Enum/Type.h"
#include "DLDL_PRECEDENCE/Ast/Node/PRECEDENCE.h"
#include "DLDL_PRECEDENCE/Ast/Node/NUMBER.h"
#include "DLDL_PRECEDENCE/Ast/Node/TERMINAL.h"
#include "DLDL_PRECEDENCE/Ast/Node/SYMBOLS.h"
#include "DLDL_PRECEDENCE/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_PRECEDENCE/Ast/Node/program.h"
#include "DLDL_PRECEDENCE/Ast/Node/stmts.h"
#include "DLDL_PRECEDENCE/Ast/Node/stmt.h"
#include "DLDL_PRECEDENCE/Ast/Node/localized_precedence.h"
#include "DLDL_PRECEDENCE/Ast/Node/specific_precedence.h"
#include "DLDL_PRECEDENCE/Ast/Node/terminal_one_or_more.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDL_PRECEDENCEnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDL_PRECEDENCElloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE

void DLDL_PRECEDENCEerror(const char* s);
int DLDL_PRECEDENCElex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;
%}

%token<Terminal> PRECEDENCE
%token<Terminal> NUMBER
%token<Terminal> TERMINAL
%token<Terminal> SYMBOLS
%token<Terminal> ESCAPE_CHARS


%nterm<DLDL_PRECEDENCE_program> program
%nterm<DLDL_PRECEDENCE_stmts> stmts
%nterm<DLDL_PRECEDENCE_stmt> stmt
%nterm<DLDL_PRECEDENCE_localized_precedence> localized_precedence
%nterm<DLDL_PRECEDENCE_specific_precedence> specific_precedence
%nterm<DLDL_PRECEDENCE_terminal_one_or_more> terminal_one_or_more


%union{
	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_PRECEDENCE::ast::node::PRECEDENCE* DLDL_PRECEDENCE_PRECEDENCE;
	::DLDL_PRECEDENCE::ast::node::NUMBER* DLDL_PRECEDENCE_NUMBER;
	::DLDL_PRECEDENCE::ast::node::TERMINAL* DLDL_PRECEDENCE_TERMINAL;
	::DLDL_PRECEDENCE::ast::node::SYMBOLS* DLDL_PRECEDENCE_SYMBOLS;
	::DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS* DLDL_PRECEDENCE_ESCAPE_CHARS;
	::DLDL_PRECEDENCE::ast::node::program* DLDL_PRECEDENCE_program;
	::DLDL_PRECEDENCE::ast::node::stmts* DLDL_PRECEDENCE_stmts;
	::DLDL_PRECEDENCE::ast::node::stmt* DLDL_PRECEDENCE_stmt;
	::DLDL_PRECEDENCE::ast::node::localized_precedence* DLDL_PRECEDENCE_localized_precedence;
	::DLDL_PRECEDENCE::ast::node::specific_precedence* DLDL_PRECEDENCE_specific_precedence;
	::DLDL_PRECEDENCE::ast::node::terminal_one_or_more* DLDL_PRECEDENCE_terminal_one_or_more;

}

%%


program:
	stmts  {
		auto* const newNode = new DLDL_PRECEDENCE::ast::node::program({::DLDL_PRECEDENCE::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;


stmts:
	stmt stmts  {
		auto* const newNode = new DLDL_PRECEDENCE::ast::node::stmts({::DLDL_PRECEDENCE::ast::Type::stmts, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_PRECEDENCE::ast::node::stmts({::DLDL_PRECEDENCE::ast::Type::stmts, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


stmt:
	localized_precedence  {
		auto* const newNode = new DLDL_PRECEDENCE::ast::node::stmt({::DLDL_PRECEDENCE::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| specific_precedence  {
		auto* const newNode = new DLDL_PRECEDENCE::ast::node::stmt({::DLDL_PRECEDENCE::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


localized_precedence:
	PRECEDENCE terminal_one_or_more  {
		auto* const newNode = new DLDL_PRECEDENCE::ast::node::localized_precedence({::DLDL_PRECEDENCE::ast::Type::localized_precedence, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_PRECEDENCE::ast::node::PRECEDENCE({::DLDL_PRECEDENCE::ast::Type::PRECEDENCE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


specific_precedence:
	PRECEDENCE NUMBER terminal_one_or_more  {
		auto* const newNode = new DLDL_PRECEDENCE::ast::node::specific_precedence({::DLDL_PRECEDENCE::ast::Type::specific_precedence, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_PRECEDENCE::ast::node::PRECEDENCE({::DLDL_PRECEDENCE::ast::Type::PRECEDENCE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), new DLDL_PRECEDENCE::ast::node::NUMBER({::DLDL_PRECEDENCE::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


terminal_one_or_more:
	TERMINAL terminal_one_or_more  {
		auto* const newNode = new DLDL_PRECEDENCE::ast::node::terminal_one_or_more({::DLDL_PRECEDENCE::ast::Type::terminal_one_or_more, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_PRECEDENCE::ast::node::TERMINAL({::DLDL_PRECEDENCE::ast::Type::TERMINAL, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| TERMINAL  {
		auto* const newNode = new DLDL_PRECEDENCE::ast::node::terminal_one_or_more({::DLDL_PRECEDENCE::ast::Type::terminal_one_or_more, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_PRECEDENCE::ast::node::TERMINAL({::DLDL_PRECEDENCE::ast::Type::TERMINAL, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;



%%

void DLDL_PRECEDENCEerror(const char* s)
{
	std::cout << "Syntax error on line: " << s << '\n';
}

deamer::external::cpp::ast::Tree* DLDL_PRECEDENCE::bison::parser::Parser::Parse(const std::string& text) const
{
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_PRECEDENCE_scan_string(text.c_str());
	DLDL_PRECEDENCEparse();
	DLDL_PRECEDENCE_delete_buffer(buf);
	DLDL_PRECEDENCElex_destroy();

	return outputTree;
}
