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
#define YYERROR_VERBOSE 1



void DLDL_ASSOCIATIVITYerror(const char* s);
int DLDL_ASSOCIATIVITYlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;

extern int DLDL_ASSOCIATIVITYlineno;
extern int DLDL_ASSOCIATIVITY_column;

static const std::string* DLDL_ASSOCIATIVITY_input_text = nullptr;
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
	std::cout << "Error: " << s << "\n";
	std::cout << "In line: " << DLDL_ASSOCIATIVITYlineno << ", Column: " << DLDL_ASSOCIATIVITY_column << '\n';

	std::size_t currentLineCount = 1;
	auto index = 0;
	static constexpr auto offsetShow = 2;

	while (index < DLDL_ASSOCIATIVITY_input_text->size())
	{
		if ((*DLDL_ASSOCIATIVITY_input_text)[index] == '\n')
		{
			currentLineCount += 1;
		}
		index++;

		if (currentLineCount + offsetShow >= DLDL_ASSOCIATIVITYlineno)
		{
			break;
		}

	}

	bool donePreShow = false;
	while (!donePreShow && offsetShow > 0)
	{
		if ((*DLDL_ASSOCIATIVITY_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_ASSOCIATIVITY_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_ASSOCIATIVITY_input_text)[index];
		}

		if ((*DLDL_ASSOCIATIVITY_input_text)[index] == '\n')
		{
			if (currentLineCount + 1 == DLDL_ASSOCIATIVITYlineno)
			{
				donePreShow = true;
			}
			currentLineCount += 1;
		}

		index++;
	}
	
	bool endLine = false;
	while (!endLine && index < DLDL_ASSOCIATIVITY_input_text->size())
	{
		if ((*DLDL_ASSOCIATIVITY_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_ASSOCIATIVITY_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_ASSOCIATIVITY_input_text)[index];
		}
		
		if ((*DLDL_ASSOCIATIVITY_input_text)[index] == '\n')
		{
			endLine = true;
		}
		
		index++;
	}

    for(int i = 0; i < DLDL_ASSOCIATIVITY_column - 1; i++)
	{
		std::cout << "_";
	}
	std::cout << "^\n";
}

deamer::external::cpp::ast::Tree* DLDL_ASSOCIATIVITY::bison::parser::Parser::Parse(const std::string& text) const
{
	DLDL_ASSOCIATIVITY_input_text = &text;
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_ASSOCIATIVITY_scan_string(text.c_str());
	DLDL_ASSOCIATIVITYparse();
	DLDL_ASSOCIATIVITY_delete_buffer(buf);
	DLDL_ASSOCIATIVITYlex_destroy();

	return outputTree;
}
