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
#include "DLDL_COMMENT/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/DLDL_COMMENT_lexer.h"
#undef YY_NO_UNISTD_H
#include "DLDL_COMMENT/Ast/Enum/Type.h"
#include "DLDL_COMMENT/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_COMMENT/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_COMMENT/Ast/Node/COMMENT_VALUE.h"
#include "DLDL_COMMENT/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_COMMENT/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_COMMENT/Ast/Node/START.h"
#include "DLDL_COMMENT/Ast/Node/END.h"
#include "DLDL_COMMENT/Ast/Node/TEXT.h"
#include "DLDL_COMMENT/Ast/Node/VARNAME.h"
#include "DLDL_COMMENT/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_COMMENT/Ast/Node/program.h"
#include "DLDL_COMMENT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_COMMENT/Ast/Node/stmt.h"
#include "DLDL_COMMENT/Ast/Node/comment_value_declaration.h"
#include "DLDL_COMMENT/Ast/Node/deamerreserved_long_3.h"
#include "DLDL_COMMENT/Ast/Node/deamerreserved_long_6.h"
#include "DLDL_COMMENT/Ast/Node/comment_abstraction.h"
#include "DLDL_COMMENT/Ast/Node/start_abstraction.h"
#include "DLDL_COMMENT/Ast/Node/end_abstraction.h"
#include "DLDL_COMMENT/Ast/Node/start_sequence.h"
#include "DLDL_COMMENT/Ast/Node/end_sequence.h"
#include "DLDL_COMMENT/Ast/Node/sequence.h"
#include "DLDL_COMMENT/Ast/Node/syntactic_reference.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDL_COMMENTnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDL_COMMENTlloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE 1



void DLDL_COMMENTerror(const char* s);
int DLDL_COMMENTlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;

extern int DLDL_COMMENTlineno;
extern int DLDL_COMMENT_column;

static const std::string* DLDL_COMMENT_input_text = nullptr;
%}

%token<Terminal> SINGLE_COMMENT
%token<Terminal> MULTI_COMMENT
%token<Terminal> COMMENT_VALUE
%token<Terminal> LEFT_SQUARE_BRACKET
%token<Terminal> RIGHT_SQUARE_BRACKET
%token<Terminal> START
%token<Terminal> END
%token<Terminal> TEXT
%token<Terminal> VARNAME
%token<Terminal> ESCAPE_CHARS


%nterm<DLDL_COMMENT_program> program
%nterm<DLDL_COMMENT_deamerreserved_star__stmt__> deamerreserved_star__stmt__
%nterm<DLDL_COMMENT_stmt> stmt
%nterm<DLDL_COMMENT_comment_value_declaration> comment_value_declaration
%nterm<DLDL_COMMENT_deamerreserved_long_3> deamerreserved_long_3
%nterm<DLDL_COMMENT_deamerreserved_long_6> deamerreserved_long_6
%nterm<DLDL_COMMENT_comment_abstraction> comment_abstraction
%nterm<DLDL_COMMENT_start_abstraction> start_abstraction
%nterm<DLDL_COMMENT_end_abstraction> end_abstraction
%nterm<DLDL_COMMENT_start_sequence> start_sequence
%nterm<DLDL_COMMENT_end_sequence> end_sequence
%nterm<DLDL_COMMENT_sequence> sequence
%nterm<DLDL_COMMENT_syntactic_reference> syntactic_reference


%union{
	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_COMMENT::ast::node::SINGLE_COMMENT* DLDL_COMMENT_SINGLE_COMMENT;
	::DLDL_COMMENT::ast::node::MULTI_COMMENT* DLDL_COMMENT_MULTI_COMMENT;
	::DLDL_COMMENT::ast::node::COMMENT_VALUE* DLDL_COMMENT_COMMENT_VALUE;
	::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET* DLDL_COMMENT_LEFT_SQUARE_BRACKET;
	::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET* DLDL_COMMENT_RIGHT_SQUARE_BRACKET;
	::DLDL_COMMENT::ast::node::START* DLDL_COMMENT_START;
	::DLDL_COMMENT::ast::node::END* DLDL_COMMENT_END;
	::DLDL_COMMENT::ast::node::TEXT* DLDL_COMMENT_TEXT;
	::DLDL_COMMENT::ast::node::VARNAME* DLDL_COMMENT_VARNAME;
	::DLDL_COMMENT::ast::node::ESCAPE_CHARS* DLDL_COMMENT_ESCAPE_CHARS;
	::DLDL_COMMENT::ast::node::program* DLDL_COMMENT_program;
	::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__* DLDL_COMMENT_deamerreserved_star__stmt__;
	::DLDL_COMMENT::ast::node::stmt* DLDL_COMMENT_stmt;
	::DLDL_COMMENT::ast::node::comment_value_declaration* DLDL_COMMENT_comment_value_declaration;
	::DLDL_COMMENT::ast::node::deamerreserved_long_3* DLDL_COMMENT_deamerreserved_long_3;
	::DLDL_COMMENT::ast::node::deamerreserved_long_6* DLDL_COMMENT_deamerreserved_long_6;
	::DLDL_COMMENT::ast::node::comment_abstraction* DLDL_COMMENT_comment_abstraction;
	::DLDL_COMMENT::ast::node::start_abstraction* DLDL_COMMENT_start_abstraction;
	::DLDL_COMMENT::ast::node::end_abstraction* DLDL_COMMENT_end_abstraction;
	::DLDL_COMMENT::ast::node::start_sequence* DLDL_COMMENT_start_sequence;
	::DLDL_COMMENT::ast::node::end_sequence* DLDL_COMMENT_end_sequence;
	::DLDL_COMMENT::ast::node::sequence* DLDL_COMMENT_sequence;
	::DLDL_COMMENT::ast::node::syntactic_reference* DLDL_COMMENT_syntactic_reference;

}

%%


program:
	deamerreserved_star__stmt__  {
		auto* const newNode = new DLDL_COMMENT::ast::node::program({::DLDL_COMMENT::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;


deamerreserved_star__stmt__:
	stmt deamerreserved_star__stmt__  {
		auto* const newNode = new DLDL_COMMENT::ast::node::deamerreserved_star__stmt__({::DLDL_COMMENT::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_COMMENT::ast::node::deamerreserved_star__stmt__({::DLDL_COMMENT::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


stmt:
	comment_value_declaration  {
		auto* const newNode = new DLDL_COMMENT::ast::node::stmt({::DLDL_COMMENT::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


comment_value_declaration:
	COMMENT_VALUE syntactic_reference deamerreserved_long_6  {
		auto* const newNode = new DLDL_COMMENT::ast::node::comment_value_declaration({::DLDL_COMMENT::ast::Type::comment_value_declaration, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_COMMENT::ast::node::COMMENT_VALUE({::DLDL_COMMENT::ast::Type::COMMENT_VALUE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2, $3 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_long_3:
	comment_abstraction deamerreserved_long_3  {
		auto* const newNode = new DLDL_COMMENT::ast::node::deamerreserved_long_3({::DLDL_COMMENT::ast::Type::deamerreserved_long_3, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_COMMENT::ast::node::deamerreserved_long_3({::DLDL_COMMENT::ast::Type::deamerreserved_long_3, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_long_6:
	LEFT_SQUARE_BRACKET deamerreserved_long_3 RIGHT_SQUARE_BRACKET  {
		auto* const newNode = new DLDL_COMMENT::ast::node::deamerreserved_long_6({::DLDL_COMMENT::ast::Type::deamerreserved_long_6, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET({::DLDL_COMMENT::ast::Type::LEFT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2, new DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET({::DLDL_COMMENT::ast::Type::RIGHT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $3 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_COMMENT::ast::node::deamerreserved_long_6({::DLDL_COMMENT::ast::Type::deamerreserved_long_6, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


comment_abstraction:
	start_abstraction  {
		auto* const newNode = new DLDL_COMMENT::ast::node::comment_abstraction({::DLDL_COMMENT::ast::Type::comment_abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| end_abstraction  {
		auto* const newNode = new DLDL_COMMENT::ast::node::comment_abstraction({::DLDL_COMMENT::ast::Type::comment_abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


start_abstraction:
	START start_sequence  {
		auto* const newNode = new DLDL_COMMENT::ast::node::start_abstraction({::DLDL_COMMENT::ast::Type::start_abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_COMMENT::ast::node::START({::DLDL_COMMENT::ast::Type::START, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


end_abstraction:
	END end_sequence  {
		auto* const newNode = new DLDL_COMMENT::ast::node::end_abstraction({::DLDL_COMMENT::ast::Type::end_abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_COMMENT::ast::node::END({::DLDL_COMMENT::ast::Type::END, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


start_sequence:
	sequence  {
		auto* const newNode = new DLDL_COMMENT::ast::node::start_sequence({::DLDL_COMMENT::ast::Type::start_sequence, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


end_sequence:
	sequence  {
		auto* const newNode = new DLDL_COMMENT::ast::node::end_sequence({::DLDL_COMMENT::ast::Type::end_sequence, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


sequence:
	TEXT  {
		auto* const newNode = new DLDL_COMMENT::ast::node::sequence({::DLDL_COMMENT::ast::Type::sequence, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_COMMENT::ast::node::TEXT({::DLDL_COMMENT::ast::Type::TEXT, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


syntactic_reference:
	VARNAME  {
		auto* const newNode = new DLDL_COMMENT::ast::node::syntactic_reference({::DLDL_COMMENT::ast::Type::syntactic_reference, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_COMMENT::ast::node::VARNAME({::DLDL_COMMENT::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;



%%

void DLDL_COMMENTerror(const char* s)
{
	std::cout << "Error: " << s << "\n";
	std::cout << "In line: " << DLDL_COMMENTlineno << ", Column: " << DLDL_COMMENT_column << '\n';

	std::size_t currentLineCount = 1;
	auto index = 0;
	static constexpr auto offsetShow = 2;

	while (index < DLDL_COMMENT_input_text->size())
	{
		if ((*DLDL_COMMENT_input_text)[index] == '\n')
		{
			currentLineCount += 1;
		}
		index++;

		if (currentLineCount + offsetShow >= DLDL_COMMENTlineno)
		{
			break;
		}

	}

	bool donePreShow = false;
	while (!donePreShow && offsetShow > 0)
	{
		if ((*DLDL_COMMENT_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_COMMENT_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_COMMENT_input_text)[index];
		}

		if ((*DLDL_COMMENT_input_text)[index] == '\n')
		{
			if (currentLineCount + 1 == DLDL_COMMENTlineno)
			{
				donePreShow = true;
			}
			currentLineCount += 1;
		}

		index++;
	}
	
	bool endLine = false;
	while (!endLine && index < DLDL_COMMENT_input_text->size())
	{
		if ((*DLDL_COMMENT_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_COMMENT_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_COMMENT_input_text)[index];
		}
		
		if ((*DLDL_COMMENT_input_text)[index] == '\n')
		{
			endLine = true;
		}
		
		index++;
	}

    for(int i = 0; i < DLDL_COMMENT_column - 1; i++)
	{
		std::cout << "_";
	}
	std::cout << "^\n";
}

deamer::external::cpp::ast::Tree* DLDL_COMMENT::bison::parser::Parser::Parse(const std::string& text) const
{
	DLDL_COMMENT_input_text = &text;
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_COMMENT_scan_string(text.c_str());
	DLDL_COMMENTparse();
	DLDL_COMMENT_delete_buffer(buf);
	DLDL_COMMENTlex_destroy();

	return outputTree;
}
