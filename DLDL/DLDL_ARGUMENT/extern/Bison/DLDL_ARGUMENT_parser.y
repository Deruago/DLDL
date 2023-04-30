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
#include "DLDL_ARGUMENT/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/DLDL_ARGUMENT_lexer.h"
#undef YY_NO_UNISTD_H
#include "DLDL_ARGUMENT/Ast/Enum/Type.h"
#include "DLDL_ARGUMENT/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_ARGUMENT/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_ARGUMENT/Ast/Node/TEXT.h"
#include "DLDL_ARGUMENT/Ast/Node/VARNAME.h"
#include "DLDL_ARGUMENT/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_ARGUMENT/Ast/Node/program.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDL_ARGUMENTnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDL_ARGUMENTlloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE 1



void DLDL_ARGUMENTerror(const char* s);
int DLDL_ARGUMENTlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;

extern int DLDL_ARGUMENTlineno;
extern int DLDL_ARGUMENT_column;

static const std::string* DLDL_ARGUMENT_input_text = nullptr;
%}

%token<Terminal> SINGLE_COMMENT
%token<Terminal> MULTI_COMMENT
%token<Terminal> TEXT
%token<Terminal> VARNAME
%token<Terminal> ESCAPE_CHARS


%nterm<DLDL_ARGUMENT_program> program


%union{
	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_ARGUMENT::ast::node::SINGLE_COMMENT* DLDL_ARGUMENT_SINGLE_COMMENT;
	::DLDL_ARGUMENT::ast::node::MULTI_COMMENT* DLDL_ARGUMENT_MULTI_COMMENT;
	::DLDL_ARGUMENT::ast::node::TEXT* DLDL_ARGUMENT_TEXT;
	::DLDL_ARGUMENT::ast::node::VARNAME* DLDL_ARGUMENT_VARNAME;
	::DLDL_ARGUMENT::ast::node::ESCAPE_CHARS* DLDL_ARGUMENT_ESCAPE_CHARS;
	::DLDL_ARGUMENT::ast::node::program* DLDL_ARGUMENT_program;

}

%%


program:
	 {
		auto* const newNode = new DLDL_ARGUMENT::ast::node::program({::DLDL_ARGUMENT::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;



%%

void DLDL_ARGUMENTerror(const char* s)
{
	std::cout << "Error: " << s << "\n";
	std::cout << "In line: " << DLDL_ARGUMENTlineno << ", Column: " << DLDL_ARGUMENT_column << '\n';

	std::size_t currentLineCount = 1;
	auto index = 0;
	static constexpr auto offsetShow = 2;

	while (index < DLDL_ARGUMENT_input_text->size())
	{
		if ((*DLDL_ARGUMENT_input_text)[index] == '\n')
		{
			currentLineCount += 1;
		}
		index++;

		if (currentLineCount + offsetShow >= DLDL_ARGUMENTlineno)
		{
			break;
		}

	}

	bool donePreShow = false;
	while (!donePreShow && offsetShow > 0)
	{
		if ((*DLDL_ARGUMENT_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_ARGUMENT_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_ARGUMENT_input_text)[index];
		}

		if ((*DLDL_ARGUMENT_input_text)[index] == '\n')
		{
			if (currentLineCount + 1 == DLDL_ARGUMENTlineno)
			{
				donePreShow = true;
			}
			currentLineCount += 1;
		}

		index++;
	}
	
	bool endLine = false;
	while (!endLine && index < DLDL_ARGUMENT_input_text->size())
	{
		if ((*DLDL_ARGUMENT_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*DLDL_ARGUMENT_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*DLDL_ARGUMENT_input_text)[index];
		}
		
		if ((*DLDL_ARGUMENT_input_text)[index] == '\n')
		{
			endLine = true;
		}
		
		index++;
	}

    for(int i = 0; i < DLDL_ARGUMENT_column - 1; i++)
	{
		std::cout << "_";
	}
	std::cout << "^\n";
}

deamer::external::cpp::ast::Tree* DLDL_ARGUMENT::bison::parser::Parser::Parse(const std::string& text) const
{
	DLDL_ARGUMENT_input_text = &text;
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_ARGUMENT_scan_string(text.c_str());
	DLDL_ARGUMENTparse();
	DLDL_ARGUMENT_delete_buffer(buf);
	DLDL_ARGUMENTlex_destroy();

	return outputTree;
}
