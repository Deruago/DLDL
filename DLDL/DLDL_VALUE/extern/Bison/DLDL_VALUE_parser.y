%define parse.error verbose

%glr-parser

%{
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <Deamer/External/Cpp/Ast/Node.h>
#include "DLDL_VALUE/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/DLDL_VALUE_lexer.h"
#undef YY_NO_UNISTD_H
#include "DLDL_VALUE/Ast/Enum/Type.h"
#include "DLDL_VALUE/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_VALUE/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_VALUE/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_VALUE/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_VALUE/Ast/Node/LEFT_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/RIGHT_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/DOT.h"
#include "DLDL_VALUE/Ast/Node/VALUE_CHARACTERISTIC.h"
#include "DLDL_VALUE/Ast/Node/VALUE_RULE.h"
#include "DLDL_VALUE/Ast/Node/NUMBER.h"
#include "DLDL_VALUE/Ast/Node/TEXT.h"
#include "DLDL_VALUE/Ast/Node/VARNAME.h"
#include "DLDL_VALUE/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_VALUE/Ast/Node/program.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_VALUE/Ast/Node/stmt.h"
#include "DLDL_VALUE/Ast/Node/value_charactersitic_declaration.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_82.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_85.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_88.h"
#include "DLDL_VALUE/Ast/Node/value_declaration.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_91.h"
#include "DLDL_VALUE/Ast/Node/value_characteristic_abstraction.h"
#include "DLDL_VALUE/Ast/Node/value_declaration_abstraction.h"
#include "DLDL_VALUE/Ast/Node/value_abstraction.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_star__value_abstraction__.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_96.h"
#include "DLDL_VALUE/Ast/Node/value.h"
#include "DLDL_VALUE/Ast/Node/syntactic_context.h"
#include "DLDL_VALUE/Ast/Node/abstraction_name.h"
#include "DLDL_VALUE/Ast/Node/value_rule_name.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDL_VALUEnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDL_VALUElloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE 1



void DLDL_VALUEerror(const char* s);
int DLDL_VALUElex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;

extern int DLDL_VALUElineno;
extern int DLDL_VALUE_column;

static const std::string* DLDL_VALUE_input_text = nullptr;
%}

%token<Terminal> SINGLE_COMMENT
%token<Terminal> MULTI_COMMENT
%token<Terminal> LEFT_PARANTHESIS
%token<Terminal> RIGHT_PARANTHESIS
%token<Terminal> LEFT_BRACKET
%token<Terminal> RIGHT_BRACKET
%token<Terminal> LEFT_SQUARE_BRACKET
%token<Terminal> RIGHT_SQUARE_BRACKET
%token<Terminal> DOT
%token<Terminal> VALUE_CHARACTERISTIC
%token<Terminal> VALUE_RULE
%token<Terminal> NUMBER
%token<Terminal> TEXT
%token<Terminal> VARNAME
%token<Terminal> ESCAPE_CHARS


%nterm<DLDL_VALUE_program> program
%nterm<DLDL_VALUE_deamerreserved_star__stmt__> deamerreserved_star__stmt__
%nterm<DLDL_VALUE_stmt> stmt
%nterm<DLDL_VALUE_value_charactersitic_declaration> value_charactersitic_declaration
%nterm<DLDL_VALUE_deamerreserved_long_82> deamerreserved_long_82
%nterm<DLDL_VALUE_deamerreserved_long_85> deamerreserved_long_85
%nterm<DLDL_VALUE_deamerreserved_long_88> deamerreserved_long_88
%nterm<DLDL_VALUE_value_declaration> value_declaration
%nterm<DLDL_VALUE_deamerreserved_long_91> deamerreserved_long_91
%nterm<DLDL_VALUE_value_characteristic_abstraction> value_characteristic_abstraction
%nterm<DLDL_VALUE_value_declaration_abstraction> value_declaration_abstraction
%nterm<DLDL_VALUE_value_abstraction> value_abstraction
%nterm<DLDL_VALUE_deamerreserved_star__value_abstraction__> deamerreserved_star__value_abstraction__
%nterm<DLDL_VALUE_deamerreserved_long_96> deamerreserved_long_96
%nterm<DLDL_VALUE_value> value
%nterm<DLDL_VALUE_syntactic_context> syntactic_context
%nterm<DLDL_VALUE_abstraction_name> abstraction_name
%nterm<DLDL_VALUE_value_rule_name> value_rule_name


%union{
	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_VALUE::ast::node::SINGLE_COMMENT* DLDL_VALUE_SINGLE_COMMENT;
	::DLDL_VALUE::ast::node::MULTI_COMMENT* DLDL_VALUE_MULTI_COMMENT;
	::DLDL_VALUE::ast::node::LEFT_PARANTHESIS* DLDL_VALUE_LEFT_PARANTHESIS;
	::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS* DLDL_VALUE_RIGHT_PARANTHESIS;
	::DLDL_VALUE::ast::node::LEFT_BRACKET* DLDL_VALUE_LEFT_BRACKET;
	::DLDL_VALUE::ast::node::RIGHT_BRACKET* DLDL_VALUE_RIGHT_BRACKET;
	::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET* DLDL_VALUE_LEFT_SQUARE_BRACKET;
	::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET* DLDL_VALUE_RIGHT_SQUARE_BRACKET;
	::DLDL_VALUE::ast::node::DOT* DLDL_VALUE_DOT;
	::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC* DLDL_VALUE_VALUE_CHARACTERISTIC;
	::DLDL_VALUE::ast::node::VALUE_RULE* DLDL_VALUE_VALUE_RULE;
	::DLDL_VALUE::ast::node::NUMBER* DLDL_VALUE_NUMBER;
	::DLDL_VALUE::ast::node::TEXT* DLDL_VALUE_TEXT;
	::DLDL_VALUE::ast::node::VARNAME* DLDL_VALUE_VARNAME;
	::DLDL_VALUE::ast::node::ESCAPE_CHARS* DLDL_VALUE_ESCAPE_CHARS;
	::DLDL_VALUE::ast::node::program* DLDL_VALUE_program;
	::DLDL_VALUE::ast::node::deamerreserved_star__stmt__* DLDL_VALUE_deamerreserved_star__stmt__;
	::DLDL_VALUE::ast::node::stmt* DLDL_VALUE_stmt;
	::DLDL_VALUE::ast::node::value_charactersitic_declaration* DLDL_VALUE_value_charactersitic_declaration;
	::DLDL_VALUE::ast::node::deamerreserved_long_82* DLDL_VALUE_deamerreserved_long_82;
	::DLDL_VALUE::ast::node::deamerreserved_long_85* DLDL_VALUE_deamerreserved_long_85;
	::DLDL_VALUE::ast::node::deamerreserved_long_88* DLDL_VALUE_deamerreserved_long_88;
	::DLDL_VALUE::ast::node::value_declaration* DLDL_VALUE_value_declaration;
	::DLDL_VALUE::ast::node::deamerreserved_long_91* DLDL_VALUE_deamerreserved_long_91;
	::DLDL_VALUE::ast::node::value_characteristic_abstraction* DLDL_VALUE_value_characteristic_abstraction;
	::DLDL_VALUE::ast::node::value_declaration_abstraction* DLDL_VALUE_value_declaration_abstraction;
	::DLDL_VALUE::ast::node::value_abstraction* DLDL_VALUE_value_abstraction;
	::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__* DLDL_VALUE_deamerreserved_star__value_abstraction__;
	::DLDL_VALUE::ast::node::deamerreserved_long_96* DLDL_VALUE_deamerreserved_long_96;
	::DLDL_VALUE::ast::node::value* DLDL_VALUE_value;
	::DLDL_VALUE::ast::node::syntactic_context* DLDL_VALUE_syntactic_context;
	::DLDL_VALUE::ast::node::abstraction_name* DLDL_VALUE_abstraction_name;
	::DLDL_VALUE::ast::node::value_rule_name* DLDL_VALUE_value_rule_name;

}

%%


program:
	deamerreserved_star__stmt__  {
		auto* const newNode = new DLDL_VALUE::ast::node::program({::DLDL_VALUE::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;


deamerreserved_star__stmt__:
	stmt deamerreserved_star__stmt__  {
		auto* const newNode = new DLDL_VALUE::ast::node::deamerreserved_star__stmt__({::DLDL_VALUE::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_VALUE::ast::node::deamerreserved_star__stmt__({::DLDL_VALUE::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


stmt:
	value_charactersitic_declaration  {
		auto* const newNode = new DLDL_VALUE::ast::node::stmt({::DLDL_VALUE::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| value_declaration  {
		auto* const newNode = new DLDL_VALUE::ast::node::stmt({::DLDL_VALUE::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


value_charactersitic_declaration:
	VALUE_CHARACTERISTIC value_rule_name LEFT_PARANTHESIS deamerreserved_long_82 RIGHT_PARANTHESIS LEFT_SQUARE_BRACKET deamerreserved_long_88 RIGHT_SQUARE_BRACKET  {
		auto* const newNode = new DLDL_VALUE::ast::node::value_charactersitic_declaration({::DLDL_VALUE::ast::Type::value_charactersitic_declaration, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC({::DLDL_VALUE::ast::Type::VALUE_CHARACTERISTIC, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2, new DLDL_VALUE::ast::node::LEFT_PARANTHESIS({::DLDL_VALUE::ast::Type::LEFT_PARANTHESIS, ::deamer::external::cpp::ast::NodeValue::terminal, $3 }), $4, new DLDL_VALUE::ast::node::RIGHT_PARANTHESIS({::DLDL_VALUE::ast::Type::RIGHT_PARANTHESIS, ::deamer::external::cpp::ast::NodeValue::terminal, $5 }), new DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET({::DLDL_VALUE::ast::Type::LEFT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $6 }), $7, new DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET({::DLDL_VALUE::ast::Type::RIGHT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $8 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_long_82:
	syntactic_context deamerreserved_long_85  {
		auto* const newNode = new DLDL_VALUE::ast::node::deamerreserved_long_82({::DLDL_VALUE::ast::Type::deamerreserved_long_82, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_long_85:
	DOT syntactic_context deamerreserved_long_85  {
		auto* const newNode = new DLDL_VALUE::ast::node::deamerreserved_long_85({::DLDL_VALUE::ast::Type::deamerreserved_long_85, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new DLDL_VALUE::ast::node::DOT({::DLDL_VALUE::ast::Type::DOT, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2, $3 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_VALUE::ast::node::deamerreserved_long_85({::DLDL_VALUE::ast::Type::deamerreserved_long_85, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_long_88:
	value_characteristic_abstraction deamerreserved_long_88  {
		auto* const newNode = new DLDL_VALUE::ast::node::deamerreserved_long_88({::DLDL_VALUE::ast::Type::deamerreserved_long_88, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_VALUE::ast::node::deamerreserved_long_88({::DLDL_VALUE::ast::Type::deamerreserved_long_88, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


value_declaration:
	VALUE_RULE value_rule_name LEFT_PARANTHESIS deamerreserved_long_82 RIGHT_PARANTHESIS LEFT_SQUARE_BRACKET deamerreserved_long_91 RIGHT_SQUARE_BRACKET  {
		auto* const newNode = new DLDL_VALUE::ast::node::value_declaration({::DLDL_VALUE::ast::Type::value_declaration, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_VALUE::ast::node::VALUE_RULE({::DLDL_VALUE::ast::Type::VALUE_RULE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2, new DLDL_VALUE::ast::node::LEFT_PARANTHESIS({::DLDL_VALUE::ast::Type::LEFT_PARANTHESIS, ::deamer::external::cpp::ast::NodeValue::terminal, $3 }), $4, new DLDL_VALUE::ast::node::RIGHT_PARANTHESIS({::DLDL_VALUE::ast::Type::RIGHT_PARANTHESIS, ::deamer::external::cpp::ast::NodeValue::terminal, $5 }), new DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET({::DLDL_VALUE::ast::Type::LEFT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $6 }), $7, new DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET({::DLDL_VALUE::ast::Type::RIGHT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $8 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_long_91:
	value_declaration_abstraction deamerreserved_long_91  {
		auto* const newNode = new DLDL_VALUE::ast::node::deamerreserved_long_91({::DLDL_VALUE::ast::Type::deamerreserved_long_91, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_VALUE::ast::node::deamerreserved_long_91({::DLDL_VALUE::ast::Type::deamerreserved_long_91, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


value_characteristic_abstraction:
	value_abstraction  {
		auto* const newNode = new DLDL_VALUE::ast::node::value_characteristic_abstraction({::DLDL_VALUE::ast::Type::value_characteristic_abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


value_declaration_abstraction:
	value_abstraction  {
		auto* const newNode = new DLDL_VALUE::ast::node::value_declaration_abstraction({::DLDL_VALUE::ast::Type::value_declaration_abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


value_abstraction:
	abstraction_name LEFT_PARANTHESIS value RIGHT_PARANTHESIS deamerreserved_long_96  {
		auto* const newNode = new DLDL_VALUE::ast::node::value_abstraction({::DLDL_VALUE::ast::Type::value_abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new DLDL_VALUE::ast::node::LEFT_PARANTHESIS({::DLDL_VALUE::ast::Type::LEFT_PARANTHESIS, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3, new DLDL_VALUE::ast::node::RIGHT_PARANTHESIS({::DLDL_VALUE::ast::Type::RIGHT_PARANTHESIS, ::deamer::external::cpp::ast::NodeValue::terminal, $4 }), $5 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_star__value_abstraction__:
	value_abstraction deamerreserved_star__value_abstraction__  {
		auto* const newNode = new DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__({::DLDL_VALUE::ast::Type::deamerreserved_star__value_abstraction__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__({::DLDL_VALUE::ast::Type::deamerreserved_star__value_abstraction__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_long_96:
	LEFT_SQUARE_BRACKET deamerreserved_star__value_abstraction__ RIGHT_SQUARE_BRACKET  {
		auto* const newNode = new DLDL_VALUE::ast::node::deamerreserved_long_96({::DLDL_VALUE::ast::Type::deamerreserved_long_96, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET({::DLDL_VALUE::ast::Type::LEFT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2, new DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET({::DLDL_VALUE::ast::Type::RIGHT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $3 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_VALUE::ast::node::deamerreserved_long_96({::DLDL_VALUE::ast::Type::deamerreserved_long_96, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


value:
	VARNAME  {
		auto* const newNode = new DLDL_VALUE::ast::node::value({::DLDL_VALUE::ast::Type::value, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_VALUE::ast::node::VARNAME({::DLDL_VALUE::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| TEXT  {
		auto* const newNode = new DLDL_VALUE::ast::node::value({::DLDL_VALUE::ast::Type::value, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_VALUE::ast::node::TEXT({::DLDL_VALUE::ast::Type::TEXT, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| NUMBER  {
		auto* const newNode = new DLDL_VALUE::ast::node::value({::DLDL_VALUE::ast::Type::value, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_VALUE::ast::node::NUMBER({::DLDL_VALUE::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


syntactic_context:
	VARNAME  {
		auto* const newNode = new DLDL_VALUE::ast::node::syntactic_context({::DLDL_VALUE::ast::Type::syntactic_context, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_VALUE::ast::node::VARNAME({::DLDL_VALUE::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


abstraction_name:
	VARNAME  {
		auto* const newNode = new DLDL_VALUE::ast::node::abstraction_name({::DLDL_VALUE::ast::Type::abstraction_name, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_VALUE::ast::node::VARNAME({::DLDL_VALUE::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


value_rule_name:
	VARNAME  {
		auto* const newNode = new DLDL_VALUE::ast::node::value_rule_name({::DLDL_VALUE::ast::Type::value_rule_name, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_VALUE::ast::node::VARNAME({::DLDL_VALUE::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;



%%

void DLDL_VALUEerror(const char* s)
{
	std::cout << "Error: " << s << "\n";
	std::cout << "In line: " << DLDL_VALUElineno << ", Column: " << DLDL_VALUE_column << '\n';

	std::size_t currentLineCount = 1;
	auto index = 0;
	static constexpr auto offsetShow = 2;

	while (index < DLDL_VALUE_input_text->size())
	{
		if ((*DLDL_VALUE_input_text)[index] == '\n')
		{
			currentLineCount += 1;
		}
		index++;

		if (currentLineCount + offsetShow >= DLDL_VALUElineno)
		{
			break;
		}

	}

	bool donePreShow = false;
	while (!donePreShow && offsetShow > 0)
	{
		if ((*DLDL_VALUE_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_VALUE_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_VALUE_input_text)[index];
		}

		if ((*DLDL_VALUE_input_text)[index] == '\n')
		{
			if (currentLineCount + 1 == DLDL_VALUElineno)
			{
				donePreShow = true;
			}
			currentLineCount += 1;
		}

		index++;
	}
	
	bool endLine = false;
	while (!endLine && index < DLDL_VALUE_input_text->size())
	{
		if ((*DLDL_VALUE_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_VALUE_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_VALUE_input_text)[index];
		}
		
		if ((*DLDL_VALUE_input_text)[index] == '\n')
		{
			endLine = true;
		}
		
		index++;
	}

    for(int i = 0; i < DLDL_VALUE_column - 1; i++)
	{
		std::cout << "_";
	}
	std::cout << "^\n";
}

deamer::external::cpp::ast::Tree* DLDL_VALUE::bison::parser::Parser::Parse(const std::string& text) const
{
	DLDL_VALUE_input_text = &text;
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_VALUE_scan_string(text.c_str());
	DLDL_VALUEparse();
	DLDL_VALUE_delete_buffer(buf);
	DLDL_VALUElex_destroy();

	return outputTree;
}
