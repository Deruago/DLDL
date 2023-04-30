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
#include "DLDL_LPDDEF/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/DLDL_LPDDEF_lexer.h"
#undef YY_NO_UNISTD_H
#include "DLDL_LPDDEF/Ast/Enum/Type.h"
#include "DLDL_LPDDEF/Ast/Node/COLON.h"
#include "DLDL_LPDDEF/Ast/Node/LEFT_ANGLE_BRACKET.h"
#include "DLDL_LPDDEF/Ast/Node/RIGHT_ANGLE_BRACKET.h"
#include "DLDL_LPDDEF/Ast/Node/VARNAME.h"
#include "DLDL_LPDDEF/Ast/Node/INDENTED_VALUE.h"
#include "DLDL_LPDDEF/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_LPDDEF/Ast/Node/program.h"
#include "DLDL_LPDDEF/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDDEF/Ast/Node/stmt.h"
#include "DLDL_LPDDEF/Ast/Node/argument.h"
#include "DLDL_LPDDEF/Ast/Node/argument_name.h"
#include "DLDL_LPDDEF/Ast/Node/argument_block.h"
#include "DLDL_LPDDEF/Ast/Node/deamerreserved_star__argument_stmt__.h"
#include "DLDL_LPDDEF/Ast/Node/argument_stmt.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDL_LPDDEFnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDL_LPDDEFlloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE 1



void DLDL_LPDDEFerror(const char* s);
int DLDL_LPDDEFlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;

extern int DLDL_LPDDEFlineno;
extern int DLDL_LPDDEF_column;

static const std::string* DLDL_LPDDEF_input_text = nullptr;
%}

%token<Terminal> COLON
%token<Terminal> LEFT_ANGLE_BRACKET
%token<Terminal> RIGHT_ANGLE_BRACKET
%token<Terminal> VARNAME
%token<Terminal> INDENTED_VALUE
%token<Terminal> ESCAPE_CHARS


%nterm<DLDL_LPDDEF_program> program
%nterm<DLDL_LPDDEF_deamerreserved_star__stmt__> deamerreserved_star__stmt__
%nterm<DLDL_LPDDEF_stmt> stmt
%nterm<DLDL_LPDDEF_argument> argument
%nterm<DLDL_LPDDEF_argument_name> argument_name
%nterm<DLDL_LPDDEF_argument_block> argument_block
%nterm<DLDL_LPDDEF_deamerreserved_star__argument_stmt__> deamerreserved_star__argument_stmt__
%nterm<DLDL_LPDDEF_argument_stmt> argument_stmt


%union{
	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_LPDDEF::ast::node::COLON* DLDL_LPDDEF_COLON;
	::DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET* DLDL_LPDDEF_LEFT_ANGLE_BRACKET;
	::DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET* DLDL_LPDDEF_RIGHT_ANGLE_BRACKET;
	::DLDL_LPDDEF::ast::node::VARNAME* DLDL_LPDDEF_VARNAME;
	::DLDL_LPDDEF::ast::node::INDENTED_VALUE* DLDL_LPDDEF_INDENTED_VALUE;
	::DLDL_LPDDEF::ast::node::ESCAPE_CHARS* DLDL_LPDDEF_ESCAPE_CHARS;
	::DLDL_LPDDEF::ast::node::program* DLDL_LPDDEF_program;
	::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__* DLDL_LPDDEF_deamerreserved_star__stmt__;
	::DLDL_LPDDEF::ast::node::stmt* DLDL_LPDDEF_stmt;
	::DLDL_LPDDEF::ast::node::argument* DLDL_LPDDEF_argument;
	::DLDL_LPDDEF::ast::node::argument_name* DLDL_LPDDEF_argument_name;
	::DLDL_LPDDEF::ast::node::argument_block* DLDL_LPDDEF_argument_block;
	::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__* DLDL_LPDDEF_deamerreserved_star__argument_stmt__;
	::DLDL_LPDDEF::ast::node::argument_stmt* DLDL_LPDDEF_argument_stmt;

}

%%


program:
	deamerreserved_star__stmt__  {
		auto* const newNode = new DLDL_LPDDEF::ast::node::program({::DLDL_LPDDEF::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;


deamerreserved_star__stmt__:
	stmt deamerreserved_star__stmt__  {
		auto* const newNode = new DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__({::DLDL_LPDDEF::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__({::DLDL_LPDDEF::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


stmt:
	argument  {
		auto* const newNode = new DLDL_LPDDEF::ast::node::stmt({::DLDL_LPDDEF::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


argument:
	argument_name COLON VARNAME  {
		auto* const newNode = new DLDL_LPDDEF::ast::node::argument({::DLDL_LPDDEF::ast::Type::argument, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new DLDL_LPDDEF::ast::node::VARNAME({::DLDL_LPDDEF::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $3 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
	}
	| argument_name COLON argument_block  {
		auto* const newNode = new DLDL_LPDDEF::ast::node::argument({::DLDL_LPDDEF::ast::Type::argument, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $3 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
	}
;


argument_name:
	VARNAME  {
		auto* const newNode = new DLDL_LPDDEF::ast::node::argument_name({::DLDL_LPDDEF::ast::Type::argument_name, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF::ast::node::VARNAME({::DLDL_LPDDEF::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


argument_block:
	LEFT_ANGLE_BRACKET deamerreserved_star__argument_stmt__ RIGHT_ANGLE_BRACKET  {
		auto* const newNode = new DLDL_LPDDEF::ast::node::argument_block({::DLDL_LPDDEF::ast::Type::argument_block, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $1;
		delete $3;
	}
;


deamerreserved_star__argument_stmt__:
	argument_stmt deamerreserved_star__argument_stmt__  {
		auto* const newNode = new DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__({::DLDL_LPDDEF::ast::Type::deamerreserved_star__argument_stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__({::DLDL_LPDDEF::ast::Type::deamerreserved_star__argument_stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


argument_stmt:
	INDENTED_VALUE  {
		auto* const newNode = new DLDL_LPDDEF::ast::node::argument_stmt({::DLDL_LPDDEF::ast::Type::argument_stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF::ast::node::INDENTED_VALUE({::DLDL_LPDDEF::ast::Type::INDENTED_VALUE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| VARNAME  {
		auto* const newNode = new DLDL_LPDDEF::ast::node::argument_stmt({::DLDL_LPDDEF::ast::Type::argument_stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF::ast::node::VARNAME({::DLDL_LPDDEF::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;



%%

void DLDL_LPDDEFerror(const char* s)
{
	std::cout << "Error: " << s << "\n";
	std::cout << "In line: " << DLDL_LPDDEFlineno << ", Column: " << DLDL_LPDDEF_column << '\n';

	std::size_t currentLineCount = 1;
	auto index = 0;
	static constexpr auto offsetShow = 2;

	while (index < DLDL_LPDDEF_input_text->size())
	{
		if ((*DLDL_LPDDEF_input_text)[index] == '\n')
		{
			currentLineCount += 1;
		}
		index++;

		if (currentLineCount + offsetShow >= DLDL_LPDDEFlineno)
		{
			break;
		}

	}

	bool donePreShow = false;
	while (!donePreShow && offsetShow > 0)
	{
		if ((*DLDL_LPDDEF_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_LPDDEF_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_LPDDEF_input_text)[index];
		}

		if ((*DLDL_LPDDEF_input_text)[index] == '\n')
		{
			if (currentLineCount + 1 == DLDL_LPDDEFlineno)
			{
				donePreShow = true;
			}
			currentLineCount += 1;
		}

		index++;
	}
	
	bool endLine = false;
	while (!endLine && index < DLDL_LPDDEF_input_text->size())
	{
		if ((*DLDL_LPDDEF_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_LPDDEF_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_LPDDEF_input_text)[index];
		}
		
		if ((*DLDL_LPDDEF_input_text)[index] == '\n')
		{
			endLine = true;
		}
		
		index++;
	}

    for(int i = 0; i < DLDL_LPDDEF_column - 1; i++)
	{
		std::cout << "_";
	}
	std::cout << "^\n";
}

deamer::external::cpp::ast::Tree* DLDL_LPDDEF::bison::parser::Parser::Parse(const std::string& text) const
{
	DLDL_LPDDEF_input_text = &text;
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_LPDDEF_scan_string(text.c_str());
	DLDL_LPDDEFparse();
	DLDL_LPDDEF_delete_buffer(buf);
	DLDL_LPDDEFlex_destroy();

	return outputTree;
}
