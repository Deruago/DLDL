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
#include "DLDL_IDENTITY/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/DLDL_IDENTITY_lexer.h"
#undef YY_NO_UNISTD_H
#include "DLDL_IDENTITY/Ast/Enum/Type.h"
#include "DLDL_IDENTITY/Ast/Node/NAME.h"
#include "DLDL_IDENTITY/Ast/Node/VALUE.h"
#include "DLDL_IDENTITY/Ast/Node/SYMBOLS.h"
#include "DLDL_IDENTITY/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_IDENTITY/Ast/Node/program.h"
#include "DLDL_IDENTITY/Ast/Node/stmts.h"
#include "DLDL_IDENTITY/Ast/Node/stmt.h"
#include "DLDL_IDENTITY/Ast/Node/name_declaration.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDL_IDENTITYnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDL_IDENTITYlloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE 1



void DLDL_IDENTITYerror(const char* s);
int DLDL_IDENTITYlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;

extern int DLDL_IDENTITYlineno;
extern int DLDL_IDENTITY_column;

static const std::string* DLDL_IDENTITY_input_text = nullptr;
%}

%token<Terminal> NAME
%token<Terminal> VALUE
%token<Terminal> SYMBOLS
%token<Terminal> ESCAPE_CHARS


%nterm<DLDL_IDENTITY_program> program
%nterm<DLDL_IDENTITY_stmts> stmts
%nterm<DLDL_IDENTITY_stmt> stmt
%nterm<DLDL_IDENTITY_name_declaration> name_declaration


%union{
	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_IDENTITY::ast::node::NAME* DLDL_IDENTITY_NAME;
	::DLDL_IDENTITY::ast::node::VALUE* DLDL_IDENTITY_VALUE;
	::DLDL_IDENTITY::ast::node::SYMBOLS* DLDL_IDENTITY_SYMBOLS;
	::DLDL_IDENTITY::ast::node::ESCAPE_CHARS* DLDL_IDENTITY_ESCAPE_CHARS;
	::DLDL_IDENTITY::ast::node::program* DLDL_IDENTITY_program;
	::DLDL_IDENTITY::ast::node::stmts* DLDL_IDENTITY_stmts;
	::DLDL_IDENTITY::ast::node::stmt* DLDL_IDENTITY_stmt;
	::DLDL_IDENTITY::ast::node::name_declaration* DLDL_IDENTITY_name_declaration;

}

%%


program:
	stmts  {
		auto* const newNode = new DLDL_IDENTITY::ast::node::program({::DLDL_IDENTITY::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;


stmts:
	stmt stmts  {
		auto* const newNode = new DLDL_IDENTITY::ast::node::stmts({::DLDL_IDENTITY::ast::Type::stmts, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_IDENTITY::ast::node::stmts({::DLDL_IDENTITY::ast::Type::stmts, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


stmt:
	name_declaration  {
		auto* const newNode = new DLDL_IDENTITY::ast::node::stmt({::DLDL_IDENTITY::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


name_declaration:
	NAME VALUE  {
		auto* const newNode = new DLDL_IDENTITY::ast::node::name_declaration({::DLDL_IDENTITY::ast::Type::name_declaration, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_IDENTITY::ast::node::NAME({::DLDL_IDENTITY::ast::Type::NAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), new DLDL_IDENTITY::ast::node::VALUE({::DLDL_IDENTITY::ast::Type::VALUE, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;



%%

void DLDL_IDENTITYerror(const char* s)
{
	std::cout << "Error: " << s << "\n";
	std::cout << "In line: " << DLDL_IDENTITYlineno << ", Column: " << DLDL_IDENTITY_column << '\n';

	std::size_t currentLineCount = 1;
	auto index = 0;
	static constexpr auto offsetShow = 2;

	while (index < DLDL_IDENTITY_input_text->size())
	{
		if ((*DLDL_IDENTITY_input_text)[index] == '\n')
		{
			currentLineCount += 1;
		}
		index++;

		if (currentLineCount + offsetShow >= DLDL_IDENTITYlineno)
		{
			break;
		}

	}

	bool donePreShow = false;
	while (!donePreShow && offsetShow > 0)
	{
		if ((*DLDL_IDENTITY_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_IDENTITY_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_IDENTITY_input_text)[index];
		}

		if ((*DLDL_IDENTITY_input_text)[index] == '\n')
		{
			if (currentLineCount + 1 == DLDL_IDENTITYlineno)
			{
				donePreShow = true;
			}
			currentLineCount += 1;
		}

		index++;
	}
	
	bool endLine = false;
	while (!endLine && index < DLDL_IDENTITY_input_text->size())
	{
		if ((*DLDL_IDENTITY_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_IDENTITY_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_IDENTITY_input_text)[index];
		}
		
		if ((*DLDL_IDENTITY_input_text)[index] == '\n')
		{
			endLine = true;
		}
		
		index++;
	}

    for(int i = 0; i < DLDL_IDENTITY_column - 1; i++)
	{
		std::cout << "_";
	}
	std::cout << "^\n";
}

deamer::external::cpp::ast::Tree* DLDL_IDENTITY::bison::parser::Parser::Parse(const std::string& text) const
{
	DLDL_IDENTITY_input_text = &text;
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_IDENTITY_scan_string(text.c_str());
	DLDL_IDENTITYparse();
	DLDL_IDENTITY_delete_buffer(buf);
	DLDL_IDENTITYlex_destroy();

	return outputTree;
}
