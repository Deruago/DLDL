%define parse.error verbose
%define parse.lac full

%{
#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <Deamer/External/Cpp/Ast/Node.h>
#include "DLDL_LPDDEF_EF/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/DLDL_LPDDEF_EF_lexer.h"
#undef YY_NO_UNISTD_H
#include "DLDL_LPDDEF_EF/Ast/Enum/Type.h"
#include "DLDL_LPDDEF_EF/Ast/Node/COMMENT.h"
#include "DLDL_LPDDEF_EF/Ast/Node/VARNAME.h"
#include "DLDL_LPDDEF_EF/Ast/Node/NUMBER.h"
#include "DLDL_LPDDEF_EF/Ast/Node/COLON.h"
#include "DLDL_LPDDEF_EF/Ast/Node/SEMICOLON.h"
#include "DLDL_LPDDEF_EF/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_LPDDEF_EF/Ast/Node/program.h"
#include "DLDL_LPDDEF_EF/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDDEF_EF/Ast/Node/stmt.h"
#include "DLDL_LPDDEF_EF/Ast/Node/comment_line.h"
#include "DLDL_LPDDEF_EF/Ast/Node/standard_variant.h"
#include "DLDL_LPDDEF_EF/Ast/Node/standard_variant_specific_number.h"
#include "DLDL_LPDDEF_EF/Ast/Node/value.h"
#include "DLDL_LPDDEF_EF/Ast/Node/enum_name.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDL_LPDDEF_EFnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDL_LPDDEF_EFlloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE

void DLDL_LPDDEF_EFerror(const char* s);
int DLDL_LPDDEF_EFlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;
%}

%token<Terminal> COMMENT
%token<Terminal> VARNAME
%token<Terminal> NUMBER
%token<Terminal> COLON
%token<Terminal> SEMICOLON
%token<Terminal> ESCAPE_CHARS


%nterm<DLDL_LPDDEF_EF_program> program
%nterm<DLDL_LPDDEF_EF_deamerreserved_star__stmt__> deamerreserved_star__stmt__
%nterm<DLDL_LPDDEF_EF_stmt> stmt
%nterm<DLDL_LPDDEF_EF_comment_line> comment_line
%nterm<DLDL_LPDDEF_EF_standard_variant> standard_variant
%nterm<DLDL_LPDDEF_EF_standard_variant_specific_number> standard_variant_specific_number
%nterm<DLDL_LPDDEF_EF_value> value
%nterm<DLDL_LPDDEF_EF_enum_name> enum_name


%union{
	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_LPDDEF_EF::ast::node::COMMENT* DLDL_LPDDEF_EF_COMMENT;
	::DLDL_LPDDEF_EF::ast::node::VARNAME* DLDL_LPDDEF_EF_VARNAME;
	::DLDL_LPDDEF_EF::ast::node::NUMBER* DLDL_LPDDEF_EF_NUMBER;
	::DLDL_LPDDEF_EF::ast::node::COLON* DLDL_LPDDEF_EF_COLON;
	::DLDL_LPDDEF_EF::ast::node::SEMICOLON* DLDL_LPDDEF_EF_SEMICOLON;
	::DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS* DLDL_LPDDEF_EF_ESCAPE_CHARS;
	::DLDL_LPDDEF_EF::ast::node::program* DLDL_LPDDEF_EF_program;
	::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__* DLDL_LPDDEF_EF_deamerreserved_star__stmt__;
	::DLDL_LPDDEF_EF::ast::node::stmt* DLDL_LPDDEF_EF_stmt;
	::DLDL_LPDDEF_EF::ast::node::comment_line* DLDL_LPDDEF_EF_comment_line;
	::DLDL_LPDDEF_EF::ast::node::standard_variant* DLDL_LPDDEF_EF_standard_variant;
	::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number* DLDL_LPDDEF_EF_standard_variant_specific_number;
	::DLDL_LPDDEF_EF::ast::node::value* DLDL_LPDDEF_EF_value;
	::DLDL_LPDDEF_EF::ast::node::enum_name* DLDL_LPDDEF_EF_enum_name;

}

%%


program:
	deamerreserved_star__stmt__  {
		auto* const newNode = new DLDL_LPDDEF_EF::ast::node::program({::DLDL_LPDDEF_EF::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;


deamerreserved_star__stmt__:
	stmt deamerreserved_star__stmt__  {
		auto* const newNode = new DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__({::DLDL_LPDDEF_EF::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__({::DLDL_LPDDEF_EF::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


stmt:
	comment_line  {
		auto* const newNode = new DLDL_LPDDEF_EF::ast::node::stmt({::DLDL_LPDDEF_EF::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| standard_variant_specific_number  {
		auto* const newNode = new DLDL_LPDDEF_EF::ast::node::stmt({::DLDL_LPDDEF_EF::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| standard_variant  {
		auto* const newNode = new DLDL_LPDDEF_EF::ast::node::stmt({::DLDL_LPDDEF_EF::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


comment_line:
	COMMENT  {
		auto* const newNode = new DLDL_LPDDEF_EF::ast::node::comment_line({::DLDL_LPDDEF_EF::ast::Type::comment_line, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_EF::ast::node::COMMENT({::DLDL_LPDDEF_EF::ast::Type::COMMENT, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


standard_variant:
	enum_name  {
		auto* const newNode = new DLDL_LPDDEF_EF::ast::node::standard_variant({::DLDL_LPDDEF_EF::ast::Type::standard_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


standard_variant_specific_number:
	enum_name value  {
		auto* const newNode = new DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number({::DLDL_LPDDEF_EF::ast::Type::standard_variant_specific_number, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


value:
	NUMBER  {
		auto* const newNode = new DLDL_LPDDEF_EF::ast::node::value({::DLDL_LPDDEF_EF::ast::Type::value, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_EF::ast::node::NUMBER({::DLDL_LPDDEF_EF::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


enum_name:
	VARNAME  {
		auto* const newNode = new DLDL_LPDDEF_EF::ast::node::enum_name({::DLDL_LPDDEF_EF::ast::Type::enum_name, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_EF::ast::node::VARNAME({::DLDL_LPDDEF_EF::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;



%%

void DLDL_LPDDEF_EFerror(const char* s)
{
	std::cout << "Syntax error on line: " << s << '\n';
}

deamer::external::cpp::ast::Tree* DLDL_LPDDEF_EF::parser::Parser::Parse(const std::string& text) const
{
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_LPDDEF_EF_scan_string(text.c_str());
	DLDL_LPDDEF_EFparse();
	DLDL_LPDDEF_EF_delete_buffer(buf);
	DLDL_LPDDEF_EFlex_destroy();

	return outputTree;
}
