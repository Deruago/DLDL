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
#include "DLDL_IMPORT/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/DLDL_IMPORT_lexer.h"
#undef YY_NO_UNISTD_H
#include "DLDL_IMPORT/Ast/Enum/Type.h"
#include "DLDL_IMPORT/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_IMPORT/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_IMPORT/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_IMPORT/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_IMPORT/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_IMPORT/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_IMPORT/Ast/Node/COLON.h"
#include "DLDL_IMPORT/Ast/Node/DOT.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT_FILE.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT_MODULE.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT.h"
#include "DLDL_IMPORT/Ast/Node/TEXT.h"
#include "DLDL_IMPORT/Ast/Node/VARNAME.h"
#include "DLDL_IMPORT/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_IMPORT/Ast/Node/program.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_IMPORT/Ast/Node/stmt.h"
#include "DLDL_IMPORT/Ast/Node/import_declaration.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_arrow__import_context__.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_long_40.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_long_43.h"
#include "DLDL_IMPORT/Ast/Node/specialization.h"
#include "DLDL_IMPORT/Ast/Node/import_abstraction.h"
#include "DLDL_IMPORT/Ast/Node/value.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_optional__VARNAME__.h"
#include "DLDL_IMPORT/Ast/Node/abstraction.h"
#include "DLDL_IMPORT/Ast/Node/import_context.h"
#include "DLDL_IMPORT/Ast/Node/import_rule_name.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDL_IMPORTnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDL_IMPORTlloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE 1



void DLDL_IMPORTerror(const char* s);
int DLDL_IMPORTlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;

extern int DLDL_IMPORTlineno;
extern int DLDL_IMPORT_column;

static const std::string* DLDL_IMPORT_input_text = nullptr;
%}

%token<Terminal> SINGLE_COMMENT
%token<Terminal> MULTI_COMMENT
%token<Terminal> LEFT_PARANTHESIS
%token<Terminal> RIGHT_PARANTHESIS
%token<Terminal> LEFT_SQUARE_BRACKET
%token<Terminal> RIGHT_SQUARE_BRACKET
%token<Terminal> COLON
%token<Terminal> DOT
%token<Terminal> IMPORT_FILE
%token<Terminal> IMPORT_MODULE
%token<Terminal> IMPORT
%token<Terminal> TEXT
%token<Terminal> VARNAME
%token<Terminal> ESCAPE_CHARS


%nterm<DLDL_IMPORT_program> program
%nterm<DLDL_IMPORT_deamerreserved_star__stmt__> deamerreserved_star__stmt__
%nterm<DLDL_IMPORT_stmt> stmt
%nterm<DLDL_IMPORT_import_declaration> import_declaration
%nterm<DLDL_IMPORT_deamerreserved_arrow__import_context__> deamerreserved_arrow__import_context__
%nterm<DLDL_IMPORT_deamerreserved_long_40> deamerreserved_long_40
%nterm<DLDL_IMPORT_deamerreserved_long_43> deamerreserved_long_43
%nterm<DLDL_IMPORT_specialization> specialization
%nterm<DLDL_IMPORT_import_abstraction> import_abstraction
%nterm<DLDL_IMPORT_value> value
%nterm<DLDL_IMPORT_deamerreserved_optional__VARNAME__> deamerreserved_optional__VARNAME__
%nterm<DLDL_IMPORT_abstraction> abstraction
%nterm<DLDL_IMPORT_import_context> import_context
%nterm<DLDL_IMPORT_import_rule_name> import_rule_name


%union{
	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_IMPORT::ast::node::SINGLE_COMMENT* DLDL_IMPORT_SINGLE_COMMENT;
	::DLDL_IMPORT::ast::node::MULTI_COMMENT* DLDL_IMPORT_MULTI_COMMENT;
	::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS* DLDL_IMPORT_LEFT_PARANTHESIS;
	::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS* DLDL_IMPORT_RIGHT_PARANTHESIS;
	::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET* DLDL_IMPORT_LEFT_SQUARE_BRACKET;
	::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET* DLDL_IMPORT_RIGHT_SQUARE_BRACKET;
	::DLDL_IMPORT::ast::node::COLON* DLDL_IMPORT_COLON;
	::DLDL_IMPORT::ast::node::DOT* DLDL_IMPORT_DOT;
	::DLDL_IMPORT::ast::node::IMPORT_FILE* DLDL_IMPORT_IMPORT_FILE;
	::DLDL_IMPORT::ast::node::IMPORT_MODULE* DLDL_IMPORT_IMPORT_MODULE;
	::DLDL_IMPORT::ast::node::IMPORT* DLDL_IMPORT_IMPORT;
	::DLDL_IMPORT::ast::node::TEXT* DLDL_IMPORT_TEXT;
	::DLDL_IMPORT::ast::node::VARNAME* DLDL_IMPORT_VARNAME;
	::DLDL_IMPORT::ast::node::ESCAPE_CHARS* DLDL_IMPORT_ESCAPE_CHARS;
	::DLDL_IMPORT::ast::node::program* DLDL_IMPORT_program;
	::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__* DLDL_IMPORT_deamerreserved_star__stmt__;
	::DLDL_IMPORT::ast::node::stmt* DLDL_IMPORT_stmt;
	::DLDL_IMPORT::ast::node::import_declaration* DLDL_IMPORT_import_declaration;
	::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__* DLDL_IMPORT_deamerreserved_arrow__import_context__;
	::DLDL_IMPORT::ast::node::deamerreserved_long_40* DLDL_IMPORT_deamerreserved_long_40;
	::DLDL_IMPORT::ast::node::deamerreserved_long_43* DLDL_IMPORT_deamerreserved_long_43;
	::DLDL_IMPORT::ast::node::specialization* DLDL_IMPORT_specialization;
	::DLDL_IMPORT::ast::node::import_abstraction* DLDL_IMPORT_import_abstraction;
	::DLDL_IMPORT::ast::node::value* DLDL_IMPORT_value;
	::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__* DLDL_IMPORT_deamerreserved_optional__VARNAME__;
	::DLDL_IMPORT::ast::node::abstraction* DLDL_IMPORT_abstraction;
	::DLDL_IMPORT::ast::node::import_context* DLDL_IMPORT_import_context;
	::DLDL_IMPORT::ast::node::import_rule_name* DLDL_IMPORT_import_rule_name;

}

%%


program:
	deamerreserved_star__stmt__  {
		auto* const newNode = new DLDL_IMPORT::ast::node::program({::DLDL_IMPORT::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;


deamerreserved_star__stmt__:
	stmt deamerreserved_star__stmt__  {
		auto* const newNode = new DLDL_IMPORT::ast::node::deamerreserved_star__stmt__({::DLDL_IMPORT::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_IMPORT::ast::node::deamerreserved_star__stmt__({::DLDL_IMPORT::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


stmt:
	import_declaration  {
		auto* const newNode = new DLDL_IMPORT::ast::node::stmt({::DLDL_IMPORT::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


import_declaration:
	specialization import_rule_name LEFT_PARANTHESIS deamerreserved_arrow__import_context__ RIGHT_PARANTHESIS LEFT_SQUARE_BRACKET deamerreserved_long_43 RIGHT_SQUARE_BRACKET  {
		auto* const newNode = new DLDL_IMPORT::ast::node::import_declaration({::DLDL_IMPORT::ast::Type::import_declaration, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2, new DLDL_IMPORT::ast::node::LEFT_PARANTHESIS({::DLDL_IMPORT::ast::Type::LEFT_PARANTHESIS, ::deamer::external::cpp::ast::NodeValue::terminal, $3 }), $4, new DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS({::DLDL_IMPORT::ast::Type::RIGHT_PARANTHESIS, ::deamer::external::cpp::ast::NodeValue::terminal, $5 }), new DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET({::DLDL_IMPORT::ast::Type::LEFT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $6 }), $7, new DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET({::DLDL_IMPORT::ast::Type::RIGHT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $8 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_arrow__import_context__:
	import_context deamerreserved_long_40  {
		auto* const newNode = new DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__({::DLDL_IMPORT::ast::Type::deamerreserved_arrow__import_context__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_long_40:
	DOT import_context deamerreserved_long_40  {
		auto* const newNode = new DLDL_IMPORT::ast::node::deamerreserved_long_40({::DLDL_IMPORT::ast::Type::deamerreserved_long_40, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new DLDL_IMPORT::ast::node::DOT({::DLDL_IMPORT::ast::Type::DOT, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2, $3 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_IMPORT::ast::node::deamerreserved_long_40({::DLDL_IMPORT::ast::Type::deamerreserved_long_40, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_long_43:
	import_abstraction deamerreserved_long_43  {
		auto* const newNode = new DLDL_IMPORT::ast::node::deamerreserved_long_43({::DLDL_IMPORT::ast::Type::deamerreserved_long_43, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_IMPORT::ast::node::deamerreserved_long_43({::DLDL_IMPORT::ast::Type::deamerreserved_long_43, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


specialization:
	IMPORT  {
		auto* const newNode = new DLDL_IMPORT::ast::node::specialization({::DLDL_IMPORT::ast::Type::specialization, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_IMPORT::ast::node::IMPORT({::DLDL_IMPORT::ast::Type::IMPORT, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| IMPORT_FILE  {
		auto* const newNode = new DLDL_IMPORT::ast::node::specialization({::DLDL_IMPORT::ast::Type::specialization, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_IMPORT::ast::node::IMPORT_FILE({::DLDL_IMPORT::ast::Type::IMPORT_FILE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| IMPORT_MODULE  {
		auto* const newNode = new DLDL_IMPORT::ast::node::specialization({::DLDL_IMPORT::ast::Type::specialization, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_IMPORT::ast::node::IMPORT_MODULE({::DLDL_IMPORT::ast::Type::IMPORT_MODULE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


import_abstraction:
	abstraction COLON value  {
		auto* const newNode = new DLDL_IMPORT::ast::node::import_abstraction({::DLDL_IMPORT::ast::Type::import_abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new DLDL_IMPORT::ast::node::COLON({::DLDL_IMPORT::ast::Type::COLON, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


value:
	TEXT  {
		auto* const newNode = new DLDL_IMPORT::ast::node::value({::DLDL_IMPORT::ast::Type::value, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_IMPORT::ast::node::TEXT({::DLDL_IMPORT::ast::Type::TEXT, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| VARNAME  {
		auto* const newNode = new DLDL_IMPORT::ast::node::value({::DLDL_IMPORT::ast::Type::value, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_IMPORT::ast::node::VARNAME({::DLDL_IMPORT::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| deamerreserved_optional__VARNAME__ LEFT_SQUARE_BRACKET deamerreserved_long_43 RIGHT_SQUARE_BRACKET  {
		auto* const newNode = new DLDL_IMPORT::ast::node::value({::DLDL_IMPORT::ast::Type::value, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET({::DLDL_IMPORT::ast::Type::LEFT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3, new DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET({::DLDL_IMPORT::ast::Type::RIGHT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $4 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_optional__VARNAME__:
	VARNAME  {
		auto* const newNode = new DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__({::DLDL_IMPORT::ast::Type::deamerreserved_optional__VARNAME__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new DLDL_IMPORT::ast::node::VARNAME({::DLDL_IMPORT::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__({::DLDL_IMPORT::ast::Type::deamerreserved_optional__VARNAME__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


abstraction:
	VARNAME  {
		auto* const newNode = new DLDL_IMPORT::ast::node::abstraction({::DLDL_IMPORT::ast::Type::abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_IMPORT::ast::node::VARNAME({::DLDL_IMPORT::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


import_context:
	VARNAME  {
		auto* const newNode = new DLDL_IMPORT::ast::node::import_context({::DLDL_IMPORT::ast::Type::import_context, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_IMPORT::ast::node::VARNAME({::DLDL_IMPORT::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


import_rule_name:
	VARNAME  {
		auto* const newNode = new DLDL_IMPORT::ast::node::import_rule_name({::DLDL_IMPORT::ast::Type::import_rule_name, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_IMPORT::ast::node::VARNAME({::DLDL_IMPORT::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;



%%

void DLDL_IMPORTerror(const char* s)
{
	std::cout << "Error: " << s << "\n";
	std::cout << "In line: " << DLDL_IMPORTlineno << ", Column: " << DLDL_IMPORT_column << '\n';

	std::size_t currentLineCount = 1;
	auto index = 0;
	static constexpr auto offsetShow = 2;

	while (index < DLDL_IMPORT_input_text->size())
	{
		if ((*DLDL_IMPORT_input_text)[index] == '\n')
		{
			currentLineCount += 1;
		}
		index++;

		if (currentLineCount + offsetShow >= DLDL_IMPORTlineno)
		{
			break;
		}

	}

	bool donePreShow = false;
	while (!donePreShow && offsetShow > 0)
	{
		if ((*DLDL_IMPORT_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_IMPORT_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_IMPORT_input_text)[index];
		}

		if ((*DLDL_IMPORT_input_text)[index] == '\n')
		{
			if (currentLineCount + 1 == DLDL_IMPORTlineno)
			{
				donePreShow = true;
			}
			currentLineCount += 1;
		}

		index++;
	}
	
	bool endLine = false;
	while (!endLine && index < DLDL_IMPORT_input_text->size())
	{
		if ((*DLDL_IMPORT_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_IMPORT_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_IMPORT_input_text)[index];
		}
		
		if ((*DLDL_IMPORT_input_text)[index] == '\n')
		{
			endLine = true;
		}
		
		index++;
	}

    for(int i = 0; i < DLDL_IMPORT_column - 1; i++)
	{
		std::cout << "_";
	}
	std::cout << "^\n";
}

deamer::external::cpp::ast::Tree* DLDL_IMPORT::bison::parser::Parser::Parse(const std::string& text) const
{
	DLDL_IMPORT_input_text = &text;
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_IMPORT_scan_string(text.c_str());
	DLDL_IMPORTparse();
	DLDL_IMPORT_delete_buffer(buf);
	DLDL_IMPORTlex_destroy();

	return outputTree;
}
