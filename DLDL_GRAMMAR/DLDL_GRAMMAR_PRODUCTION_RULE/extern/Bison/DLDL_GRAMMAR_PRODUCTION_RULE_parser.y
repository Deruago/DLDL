%define parse.error verbose
%define parse.lac full

%{
#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <Deamer/External/Cpp/Ast/Node.h>
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/DLDL_GRAMMAR_PRODUCTION_RULE_lexer.h"
#undef YY_NO_UNISTD_H
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Enum/Type.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ENDING_USELESS_SYMBOLS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/VERTICAL_SLASH.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/QUESTION_MARK.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/EXCLAMATION_MARK.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ARROW.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/STAR.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/PLUS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/MINUS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/VALUE.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/NUMBER.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/SINGLE_LINE_COMMENT.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/MULTI_LINE_COMMENT.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/SYMBOLS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/program.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/stmts.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/stmt.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/nested_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/optional_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/zero_or_more_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/one_or_more_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/or_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/min_max_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/extension_group.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDL_GRAMMAR_PRODUCTION_RULEnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDL_GRAMMAR_PRODUCTION_RULElloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE

void DLDL_GRAMMAR_PRODUCTION_RULEerror(const char* s);
int DLDL_GRAMMAR_PRODUCTION_RULElex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;
%}

%token<Terminal> ENDING_USELESS_SYMBOLS
%token<Terminal> VERTICAL_SLASH
%token<Terminal> LEFT_PARANTHESIS
%token<Terminal> RIGHT_PARANTHESIS
%token<Terminal> LEFT_BRACKET
%token<Terminal> RIGHT_BRACKET
%token<Terminal> LEFT_SQUARE_BRACKET
%token<Terminal> RIGHT_SQUARE_BRACKET
%token<Terminal> QUESTION_MARK
%token<Terminal> EXCLAMATION_MARK
%token<Terminal> ARROW
%token<Terminal> STAR
%token<Terminal> PLUS
%token<Terminal> MINUS
%token<Terminal> VALUE
%token<Terminal> NUMBER
%token<Terminal> SINGLE_LINE_COMMENT
%token<Terminal> MULTI_LINE_COMMENT
%token<Terminal> SYMBOLS
%token<Terminal> ESCAPE_CHARS


%nterm<DLDL_GRAMMAR_PRODUCTION_RULE_program> program
%nterm<DLDL_GRAMMAR_PRODUCTION_RULE_stmts> stmts
%nterm<DLDL_GRAMMAR_PRODUCTION_RULE_stmt> stmt
%nterm<DLDL_GRAMMAR_PRODUCTION_RULE_group> group
%nterm<DLDL_GRAMMAR_PRODUCTION_RULE_nested_group> nested_group
%nterm<DLDL_GRAMMAR_PRODUCTION_RULE_optional_group> optional_group
%nterm<DLDL_GRAMMAR_PRODUCTION_RULE_zero_or_more_group> zero_or_more_group
%nterm<DLDL_GRAMMAR_PRODUCTION_RULE_one_or_more_group> one_or_more_group
%nterm<DLDL_GRAMMAR_PRODUCTION_RULE_or_group> or_group
%nterm<DLDL_GRAMMAR_PRODUCTION_RULE_min_max_group> min_max_group
%nterm<DLDL_GRAMMAR_PRODUCTION_RULE_extension_group> extension_group


%union{
	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS* DLDL_GRAMMAR_PRODUCTION_RULE_ENDING_USELESS_SYMBOLS;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH* DLDL_GRAMMAR_PRODUCTION_RULE_VERTICAL_SLASH;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS* DLDL_GRAMMAR_PRODUCTION_RULE_LEFT_PARANTHESIS;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS* DLDL_GRAMMAR_PRODUCTION_RULE_RIGHT_PARANTHESIS;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET* DLDL_GRAMMAR_PRODUCTION_RULE_LEFT_BRACKET;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET* DLDL_GRAMMAR_PRODUCTION_RULE_RIGHT_BRACKET;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET* DLDL_GRAMMAR_PRODUCTION_RULE_LEFT_SQUARE_BRACKET;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET* DLDL_GRAMMAR_PRODUCTION_RULE_RIGHT_SQUARE_BRACKET;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK* DLDL_GRAMMAR_PRODUCTION_RULE_QUESTION_MARK;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK* DLDL_GRAMMAR_PRODUCTION_RULE_EXCLAMATION_MARK;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW* DLDL_GRAMMAR_PRODUCTION_RULE_ARROW;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR* DLDL_GRAMMAR_PRODUCTION_RULE_STAR;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS* DLDL_GRAMMAR_PRODUCTION_RULE_PLUS;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS* DLDL_GRAMMAR_PRODUCTION_RULE_MINUS;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE* DLDL_GRAMMAR_PRODUCTION_RULE_VALUE;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER* DLDL_GRAMMAR_PRODUCTION_RULE_NUMBER;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT* DLDL_GRAMMAR_PRODUCTION_RULE_SINGLE_LINE_COMMENT;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT* DLDL_GRAMMAR_PRODUCTION_RULE_MULTI_LINE_COMMENT;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS* DLDL_GRAMMAR_PRODUCTION_RULE_SYMBOLS;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS* DLDL_GRAMMAR_PRODUCTION_RULE_ESCAPE_CHARS;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program* DLDL_GRAMMAR_PRODUCTION_RULE_program;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts* DLDL_GRAMMAR_PRODUCTION_RULE_stmts;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt* DLDL_GRAMMAR_PRODUCTION_RULE_stmt;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group* DLDL_GRAMMAR_PRODUCTION_RULE_group;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group* DLDL_GRAMMAR_PRODUCTION_RULE_nested_group;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group* DLDL_GRAMMAR_PRODUCTION_RULE_optional_group;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group* DLDL_GRAMMAR_PRODUCTION_RULE_zero_or_more_group;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group* DLDL_GRAMMAR_PRODUCTION_RULE_one_or_more_group;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group* DLDL_GRAMMAR_PRODUCTION_RULE_or_group;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group* DLDL_GRAMMAR_PRODUCTION_RULE_min_max_group;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group* DLDL_GRAMMAR_PRODUCTION_RULE_extension_group;

}

%%


program:
	stmts  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;


stmts:
	stmt stmts  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmts, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmts, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


stmt:
	group  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


group:
	nested_group  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| optional_group  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| zero_or_more_group  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| one_or_more_group  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| group MINUS  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
	}
	| or_group  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| min_max_group  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 6, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| extension_group  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 7, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| VALUE  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 8, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VALUE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


nested_group:
	LEFT_PARANTHESIS stmts RIGHT_PARANTHESIS  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::nested_group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $1;
		delete $3;
	}
;


optional_group:
	LEFT_SQUARE_BRACKET stmts RIGHT_SQUARE_BRACKET  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::optional_group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $1;
		delete $3;
	}
	| group QUESTION_MARK  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::optional_group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
	}
;


zero_or_more_group:
	group STAR  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::zero_or_more_group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
	}
;


one_or_more_group:
	group PLUS  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::one_or_more_group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
	}
;


or_group:
	group VERTICAL_SLASH group  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::or_group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $3 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
	}
;


min_max_group:
	group LEFT_BRACKET NUMBER NUMBER RIGHT_BRACKET  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::min_max_group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, $3 }), new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, $4 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
		delete $5;
	}
	| group LEFT_BRACKET NUMBER RIGHT_BRACKET  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::min_max_group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, $3 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
		delete $4;
	}
	| group LEFT_BRACKET NUMBER PLUS RIGHT_BRACKET  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::min_max_group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, $3 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
		delete $4;
		delete $5;
	}
	| group LEFT_BRACKET NUMBER STAR RIGHT_BRACKET  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::min_max_group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, $3 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
		delete $4;
		delete $5;
	}
;


extension_group:
	group ARROW group  {
		auto* const newNode = new DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group({::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::extension_group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $3 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
	}
;



%%

void DLDL_GRAMMAR_PRODUCTION_RULEerror(const char* s)
{
	std::cout << "Syntax error on line: " << s << '\n';
}

deamer::external::cpp::ast::Tree* DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser::Parse(const std::string& text) const
{
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_GRAMMAR_PRODUCTION_RULE_scan_string(text.c_str());
	DLDL_GRAMMAR_PRODUCTION_RULEparse();
	DLDL_GRAMMAR_PRODUCTION_RULE_delete_buffer(buf);
	DLDL_GRAMMAR_PRODUCTION_RULElex_destroy();

	return outputTree;
}
