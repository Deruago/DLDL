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
#include "DLDL_LEXER/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/DLDL_LEXER_lexer.h"
#undef YY_NO_UNISTD_H
#include "DLDL_LEXER/Ast/Enum/Type.h"
#include "DLDL_LEXER/Ast/Node/DELETE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/IGNORE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/NOVALUE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/CRASH_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/STANDARD_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/UNKNOWN_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/TERMINAL.h"
#include "DLDL_LEXER/Ast/Node/REGEX.h"
#include "DLDL_LEXER/Ast/Node/ESCAPE_CHARS.h"
#include "DLDL_LEXER/Ast/Node/COMMENT.h"


#include "DLDL_LEXER/Ast/Node/program.h"
#include "DLDL_LEXER/Ast/Node/stmts.h"
#include "DLDL_LEXER/Ast/Node/stmt.h"
#include "DLDL_LEXER/Ast/Node/tokendeclaration.h"
#include "DLDL_LEXER/Ast/Node/abstraction.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDL_LEXERnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDL_LEXERlloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE 1



void DLDL_LEXERerror(const char* s);
int DLDL_LEXERlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;

extern int DLDL_LEXERlineno;
extern int DLDL_LEXER_column;

static const std::string* DLDL_LEXER_input_text = nullptr;
%}

%token<Terminal> DELETE_ABSTRACTION
%token<Terminal> IGNORE_ABSTRACTION
%token<Terminal> NOVALUE_ABSTRACTION
%token<Terminal> CRASH_ABSTRACTION
%token<Terminal> STANDARD_ABSTRACTION
%token<Terminal> UNKNOWN_ABSTRACTION
%token<Terminal> TERMINAL
%token<Terminal> REGEX
%token<Terminal> ESCAPE_CHARS
%token<Terminal> COMMENT


%nterm<DLDL_LEXER_program> program
%nterm<DLDL_LEXER_stmts> stmts
%nterm<DLDL_LEXER_stmt> stmt
%nterm<DLDL_LEXER_tokendeclaration> tokendeclaration
%nterm<DLDL_LEXER_abstraction> abstraction


%union{
	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_LEXER::ast::node::DELETE_ABSTRACTION* DLDL_LEXER_DELETE_ABSTRACTION;
	::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION* DLDL_LEXER_IGNORE_ABSTRACTION;
	::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION* DLDL_LEXER_NOVALUE_ABSTRACTION;
	::DLDL_LEXER::ast::node::CRASH_ABSTRACTION* DLDL_LEXER_CRASH_ABSTRACTION;
	::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION* DLDL_LEXER_STANDARD_ABSTRACTION;
	::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION* DLDL_LEXER_UNKNOWN_ABSTRACTION;
	::DLDL_LEXER::ast::node::TERMINAL* DLDL_LEXER_TERMINAL;
	::DLDL_LEXER::ast::node::REGEX* DLDL_LEXER_REGEX;
	::DLDL_LEXER::ast::node::ESCAPE_CHARS* DLDL_LEXER_ESCAPE_CHARS;
	::DLDL_LEXER::ast::node::COMMENT* DLDL_LEXER_COMMENT;
	::DLDL_LEXER::ast::node::program* DLDL_LEXER_program;
	::DLDL_LEXER::ast::node::stmts* DLDL_LEXER_stmts;
	::DLDL_LEXER::ast::node::stmt* DLDL_LEXER_stmt;
	::DLDL_LEXER::ast::node::tokendeclaration* DLDL_LEXER_tokendeclaration;
	::DLDL_LEXER::ast::node::abstraction* DLDL_LEXER_abstraction;

}

%%


program:
	stmts  {
		auto* const newNode = new DLDL_LEXER::ast::node::program({::DLDL_LEXER::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;


stmts:
	stmt stmts  {
		auto* const newNode = new DLDL_LEXER::ast::node::stmts({::DLDL_LEXER::ast::Type::stmts, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_LEXER::ast::node::stmts({::DLDL_LEXER::ast::Type::stmts, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


stmt:
	tokendeclaration  {
		auto* const newNode = new DLDL_LEXER::ast::node::stmt({::DLDL_LEXER::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


tokendeclaration:
	abstraction TERMINAL REGEX  {
		auto* const newNode = new DLDL_LEXER::ast::node::tokendeclaration({::DLDL_LEXER::ast::Type::tokendeclaration, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new DLDL_LEXER::ast::node::TERMINAL({::DLDL_LEXER::ast::Type::TERMINAL, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), new DLDL_LEXER::ast::node::REGEX({::DLDL_LEXER::ast::Type::REGEX, ::deamer::external::cpp::ast::NodeValue::terminal, $3 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| TERMINAL REGEX  {
		auto* const newNode = new DLDL_LEXER::ast::node::tokendeclaration({::DLDL_LEXER::ast::Type::tokendeclaration, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LEXER::ast::node::TERMINAL({::DLDL_LEXER::ast::Type::TERMINAL, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), new DLDL_LEXER::ast::node::REGEX({::DLDL_LEXER::ast::Type::REGEX, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


abstraction:
	DELETE_ABSTRACTION  {
		auto* const newNode = new DLDL_LEXER::ast::node::abstraction({::DLDL_LEXER::ast::Type::abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LEXER::ast::node::DELETE_ABSTRACTION({::DLDL_LEXER::ast::Type::DELETE_ABSTRACTION, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| IGNORE_ABSTRACTION  {
		auto* const newNode = new DLDL_LEXER::ast::node::abstraction({::DLDL_LEXER::ast::Type::abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LEXER::ast::node::IGNORE_ABSTRACTION({::DLDL_LEXER::ast::Type::IGNORE_ABSTRACTION, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| CRASH_ABSTRACTION  {
		auto* const newNode = new DLDL_LEXER::ast::node::abstraction({::DLDL_LEXER::ast::Type::abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LEXER::ast::node::CRASH_ABSTRACTION({::DLDL_LEXER::ast::Type::CRASH_ABSTRACTION, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| NOVALUE_ABSTRACTION  {
		auto* const newNode = new DLDL_LEXER::ast::node::abstraction({::DLDL_LEXER::ast::Type::abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION({::DLDL_LEXER::ast::Type::NOVALUE_ABSTRACTION, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| STANDARD_ABSTRACTION  {
		auto* const newNode = new DLDL_LEXER::ast::node::abstraction({::DLDL_LEXER::ast::Type::abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LEXER::ast::node::STANDARD_ABSTRACTION({::DLDL_LEXER::ast::Type::STANDARD_ABSTRACTION, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| UNKNOWN_ABSTRACTION  {
		auto* const newNode = new DLDL_LEXER::ast::node::abstraction({::DLDL_LEXER::ast::Type::abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION({::DLDL_LEXER::ast::Type::UNKNOWN_ABSTRACTION, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;



%%

void DLDL_LEXERerror(const char* s)
{
	std::cout << "Error: " << s << "\n";
	std::cout << "In line: " << DLDL_LEXERlineno << ", Column: " << DLDL_LEXER_column << '\n';

	std::size_t currentLineCount = 1;
	auto index = 0;
	static constexpr auto offsetShow = 2;

	while (index < DLDL_LEXER_input_text->size())
	{
		if ((*DLDL_LEXER_input_text)[index] == '\n')
		{
			currentLineCount += 1;
		}
		index++;

		if (currentLineCount + offsetShow >= DLDL_LEXERlineno)
		{
			break;
		}

	}

	bool donePreShow = false;
	while (!donePreShow && offsetShow > 0)
	{
		if ((*DLDL_LEXER_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_LEXER_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_LEXER_input_text)[index];
		}

		if ((*DLDL_LEXER_input_text)[index] == '\n')
		{
			if (currentLineCount + 1 == DLDL_LEXERlineno)
			{
				donePreShow = true;
			}
			currentLineCount += 1;
		}

		index++;
	}
	
	bool endLine = false;
	while (!endLine && index < DLDL_LEXER_input_text->size())
	{
		if ((*DLDL_LEXER_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_LEXER_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_LEXER_input_text)[index];
		}
		
		if ((*DLDL_LEXER_input_text)[index] == '\n')
		{
			endLine = true;
		}
		
		index++;
	}

    for(int i = 0; i < DLDL_LEXER_column - 1; i++)
	{
		std::cout << "_";
	}
	std::cout << "^\n";
}

deamer::external::cpp::ast::Tree* DLDL_LEXER::bison::parser::Parser::Parse(const std::string& text) const
{
	DLDL_LEXER_input_text = &text;
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_LEXER_scan_string(text.c_str());
	DLDL_LEXERparse();
	DLDL_LEXER_delete_buffer(buf);
	DLDL_LEXERlex_destroy();

	return outputTree;
}
