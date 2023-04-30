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
#include "DLDL_LPDSTRUCT/Ast/Node/deamerreserved_long_60.h"
#include "DLDL_LPDSTRUCT/Ast/Node/deamerreserved_long_63.h"
#include "DLDL_LPDSTRUCT/Ast/Node/deamerreserved_long_66.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDL_LPDSTRUCTnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDL_LPDSTRUCTlloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE 1



void DLDL_LPDSTRUCTerror(const char* s);
int DLDL_LPDSTRUCTlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;

extern int DLDL_LPDSTRUCTlineno;
extern int DLDL_LPDSTRUCT_column;

static const std::string* DLDL_LPDSTRUCT_input_text = nullptr;
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
%nterm<DLDL_LPDSTRUCT_deamerreserved_long_60> deamerreserved_long_60
%nterm<DLDL_LPDSTRUCT_deamerreserved_long_63> deamerreserved_long_63
%nterm<DLDL_LPDSTRUCT_deamerreserved_long_66> deamerreserved_long_66


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
	::DLDL_LPDSTRUCT::ast::node::deamerreserved_long_60* DLDL_LPDSTRUCT_deamerreserved_long_60;
	::DLDL_LPDSTRUCT::ast::node::deamerreserved_long_63* DLDL_LPDSTRUCT_deamerreserved_long_63;
	::DLDL_LPDSTRUCT::ast::node::deamerreserved_long_66* DLDL_LPDSTRUCT_deamerreserved_long_66;

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
	LEFT_ANGLE_BRACKET deamerreserved_long_66 RIGHT_ANGLE_BRACKET  {
		auto* const newNode = new DLDL_LPDSTRUCT::ast::node::argument_block({::DLDL_LPDSTRUCT::ast::Type::argument_block, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $1;
		delete $3;
	}
;


deamerreserved_long_60:
	VARNAME_EXT  {
		auto* const newNode = new DLDL_LPDSTRUCT::ast::node::deamerreserved_long_60({::DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_60, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new DLDL_LPDSTRUCT::ast::node::VARNAME_EXT({::DLDL_LPDSTRUCT::ast::Type::VARNAME_EXT, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| VARNAME  {
		auto* const newNode = new DLDL_LPDSTRUCT::ast::node::deamerreserved_long_60({::DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_60, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new DLDL_LPDSTRUCT::ast::node::VARNAME({::DLDL_LPDSTRUCT::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_long_63:
	INDENTED_VALUE  {
		auto* const newNode = new DLDL_LPDSTRUCT::ast::node::deamerreserved_long_63({::DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_63, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new DLDL_LPDSTRUCT::ast::node::INDENTED_VALUE({::DLDL_LPDSTRUCT::ast::Type::INDENTED_VALUE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| deamerreserved_long_60  {
		auto* const newNode = new DLDL_LPDSTRUCT::ast::node::deamerreserved_long_63({::DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_63, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_long_66:
	deamerreserved_long_63 deamerreserved_long_66  {
		auto* const newNode = new DLDL_LPDSTRUCT::ast::node::deamerreserved_long_66({::DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_66, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_LPDSTRUCT::ast::node::deamerreserved_long_66({::DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_66, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;



%%

void DLDL_LPDSTRUCTerror(const char* s)
{
	std::cout << "Error: " << s << "\n";
	std::cout << "In line: " << DLDL_LPDSTRUCTlineno << ", Column: " << DLDL_LPDSTRUCT_column << '\n';

	std::size_t currentLineCount = 1;
	auto index = 0;
	static constexpr auto offsetShow = 2;

	while (index < DLDL_LPDSTRUCT_input_text->size())
	{
		if ((*DLDL_LPDSTRUCT_input_text)[index] == '\n')
		{
			currentLineCount += 1;
		}
		index++;

		if (currentLineCount + offsetShow >= DLDL_LPDSTRUCTlineno)
		{
			break;
		}

	}

	bool donePreShow = false;
	while (!donePreShow && offsetShow > 0)
	{
		if ((*DLDL_LPDSTRUCT_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_LPDSTRUCT_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_LPDSTRUCT_input_text)[index];
		}

		if ((*DLDL_LPDSTRUCT_input_text)[index] == '\n')
		{
			if (currentLineCount + 1 == DLDL_LPDSTRUCTlineno)
			{
				donePreShow = true;
			}
			currentLineCount += 1;
		}

		index++;
	}
	
	bool endLine = false;
	while (!endLine && index < DLDL_LPDSTRUCT_input_text->size())
	{
		if ((*DLDL_LPDSTRUCT_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_LPDSTRUCT_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_LPDSTRUCT_input_text)[index];
		}
		
		if ((*DLDL_LPDSTRUCT_input_text)[index] == '\n')
		{
			endLine = true;
		}
		
		index++;
	}

    for(int i = 0; i < DLDL_LPDSTRUCT_column - 1; i++)
	{
		std::cout << "_";
	}
	std::cout << "^\n";
}

deamer::external::cpp::ast::Tree* DLDL_LPDSTRUCT::bison::parser::Parser::Parse(const std::string& text) const
{
	DLDL_LPDSTRUCT_input_text = &text;
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_LPDSTRUCT_scan_string(text.c_str());
	DLDL_LPDSTRUCTparse();
	DLDL_LPDSTRUCT_delete_buffer(buf);
	DLDL_LPDSTRUCTlex_destroy();

	return outputTree;
}
