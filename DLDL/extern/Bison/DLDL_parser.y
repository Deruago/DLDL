%define parse.error verbose
%define parse.lac full


%{
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <Deamer/External/Cpp/Ast/Node.h>
#include "DLDL/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/DLDL_lexer.h"
#undef YY_NO_UNISTD_H
#include "DLDL/Ast/Enum/Type.h"
#include "DLDL/Ast/Node/ANY.h"


#include "DLDL/Ast/Node/program.h"
#include "DLDL/Ast/Node/stmts.h"
#include "DLDL/Ast/Node/stmt.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDLnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDLlloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE 1



void DLDLerror(const char* s);
int DLDLlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;

extern int DLDLlineno;
extern int DLDL_column;

static const std::string* DLDL_input_text = nullptr;
%}

%token<Terminal> ANY


%nterm<DLDL_program> program
%nterm<DLDL_stmts> stmts
%nterm<DLDL_stmt> stmt


%union{
	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL::ast::node::ANY* DLDL_ANY;
	::DLDL::ast::node::program* DLDL_program;
	::DLDL::ast::node::stmts* DLDL_stmts;
	::DLDL::ast::node::stmt* DLDL_stmt;

}

%%


program:
	stmts  {
		auto* const newNode = new DLDL::ast::node::program({::DLDL::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;


stmts:
	stmt stmts  {
		auto* const newNode = new DLDL::ast::node::stmts({::DLDL::ast::Type::stmts, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL::ast::node::stmts({::DLDL::ast::Type::stmts, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


stmt:
	ANY  {
		auto* const newNode = new DLDL::ast::node::stmt({::DLDL::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL::ast::node::ANY({::DLDL::ast::Type::ANY, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;



%%

void DLDLerror(const char* s)
{
	std::cout << "Error: " << s << "\n";
	std::cout << "In line: " << DLDLlineno << ", Column: " << DLDL_column << '\n';

	std::size_t currentLineCount = 1;
	auto index = 0;
	static constexpr auto offsetShow = 2;

	while (index < DLDL_input_text->size())
	{
		if ((*DLDL_input_text)[index] == '\n')
		{
			currentLineCount += 1;
		}
		index++;

		if (currentLineCount + offsetShow >= DLDLlineno)
		{
			break;
		}

	}

	bool donePreShow = false;
	while (!donePreShow && offsetShow > 0)
	{
		if ((*DLDL_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_input_text)[index];
		}

		if ((*DLDL_input_text)[index] == '\n')
		{
			if (currentLineCount + 1 == DLDLlineno)
			{
				donePreShow = true;
			}
			currentLineCount += 1;
		}

		index++;
	}
	
	bool endLine = false;
	while (!endLine && index < DLDL_input_text->size())
	{
		if ((*DLDL_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_input_text)[index];
		}
		
		if ((*DLDL_input_text)[index] == '\n')
		{
			endLine = true;
		}
		
		index++;
	}

    for(int i = 0; i < DLDL_column - 1; i++)
	{
		std::cout << "_";
	}
	std::cout << "^\n";
}

deamer::external::cpp::ast::Tree* DLDL::bison::parser::Parser::Parse(const std::string& text) const
{
	DLDL_input_text = &text;
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_scan_string(text.c_str());
	DLDLparse();
	DLDL_delete_buffer(buf);
	DLDLlex_destroy();

	return outputTree;
}
