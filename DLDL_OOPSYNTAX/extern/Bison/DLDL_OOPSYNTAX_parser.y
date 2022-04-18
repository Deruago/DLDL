%define parse.error verbose
%define parse.lac full


%{
#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <Deamer/External/Cpp/Ast/Node.h>
#include "DLDL_OOPSYNTAX/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/DLDL_OOPSYNTAX_lexer.h"
#undef YY_NO_UNISTD_H
#include "DLDL_OOPSYNTAX/Ast/Enum/Type.h"
#include "DLDL_OOPSYNTAX/Ast/Node/ARROW.h"
#include "DLDL_OOPSYNTAX/Ast/Node/LEFT_BRACKET.h"
#include "DLDL_OOPSYNTAX/Ast/Node/RIGHT_BRACKET.h"
#include "DLDL_OOPSYNTAX/Ast/Node/DOT.h"
#include "DLDL_OOPSYNTAX/Ast/Node/EQ.h"
#include "DLDL_OOPSYNTAX/Ast/Node/STAR.h"
#include "DLDL_OOPSYNTAX/Ast/Node/VARNAME.h"
#include "DLDL_OOPSYNTAX/Ast/Node/NUMBER.h"
#include "DLDL_OOPSYNTAX/Ast/Node/COMMENT.h"
#include "DLDL_OOPSYNTAX/Ast/Node/ESCAPE_CHAR.h"


#include "DLDL_OOPSYNTAX/Ast/Node/program.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_OOPSYNTAX/Ast/Node/stmt.h"
#include "DLDL_OOPSYNTAX/Ast/Node/nonterminal_conversion.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_star__production_rule_conversion__.h"
#include "DLDL_OOPSYNTAX/Ast/Node/production_rule_conversion.h"
#include "DLDL_OOPSYNTAX/Ast/Node/numbered_pr_convert.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_star__property_assignment__.h"
#include "DLDL_OOPSYNTAX/Ast/Node/property_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/direct_property_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/direct_any_property_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/embedded_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/nonterminal_name.h"
#include "DLDL_OOPSYNTAX/Ast/Node/oop_type.h"
#include "DLDL_OOPSYNTAX/Ast/Node/property.h"
#include "DLDL_OOPSYNTAX/Ast/Node/terminal_name.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDL_OOPSYNTAXnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDL_OOPSYNTAXlloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE

void DLDL_OOPSYNTAXerror(const char* s);
int DLDL_OOPSYNTAXlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;
%}

%token<Terminal> ARROW
%token<Terminal> LEFT_BRACKET
%token<Terminal> RIGHT_BRACKET
%token<Terminal> DOT
%token<Terminal> EQ
%token<Terminal> STAR
%token<Terminal> VARNAME
%token<Terminal> NUMBER
%token<Terminal> COMMENT
%token<Terminal> ESCAPE_CHAR


%nterm<DLDL_OOPSYNTAX_program> program
%nterm<DLDL_OOPSYNTAX_deamerreserved_star__stmt__> deamerreserved_star__stmt__
%nterm<DLDL_OOPSYNTAX_stmt> stmt
%nterm<DLDL_OOPSYNTAX_nonterminal_conversion> nonterminal_conversion
%nterm<DLDL_OOPSYNTAX_deamerreserved_star__production_rule_conversion__> deamerreserved_star__production_rule_conversion__
%nterm<DLDL_OOPSYNTAX_production_rule_conversion> production_rule_conversion
%nterm<DLDL_OOPSYNTAX_numbered_pr_convert> numbered_pr_convert
%nterm<DLDL_OOPSYNTAX_deamerreserved_star__property_assignment__> deamerreserved_star__property_assignment__
%nterm<DLDL_OOPSYNTAX_property_assignment> property_assignment
%nterm<DLDL_OOPSYNTAX_direct_property_assignment> direct_property_assignment
%nterm<DLDL_OOPSYNTAX_direct_any_property_assignment> direct_any_property_assignment
%nterm<DLDL_OOPSYNTAX_embedded_assignment> embedded_assignment
%nterm<DLDL_OOPSYNTAX_nonterminal_name> nonterminal_name
%nterm<DLDL_OOPSYNTAX_oop_type> oop_type
%nterm<DLDL_OOPSYNTAX_property> property
%nterm<DLDL_OOPSYNTAX_terminal_name> terminal_name


%union{
	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_OOPSYNTAX::ast::node::ARROW* DLDL_OOPSYNTAX_ARROW;
	::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET* DLDL_OOPSYNTAX_LEFT_BRACKET;
	::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET* DLDL_OOPSYNTAX_RIGHT_BRACKET;
	::DLDL_OOPSYNTAX::ast::node::DOT* DLDL_OOPSYNTAX_DOT;
	::DLDL_OOPSYNTAX::ast::node::EQ* DLDL_OOPSYNTAX_EQ;
	::DLDL_OOPSYNTAX::ast::node::STAR* DLDL_OOPSYNTAX_STAR;
	::DLDL_OOPSYNTAX::ast::node::VARNAME* DLDL_OOPSYNTAX_VARNAME;
	::DLDL_OOPSYNTAX::ast::node::NUMBER* DLDL_OOPSYNTAX_NUMBER;
	::DLDL_OOPSYNTAX::ast::node::COMMENT* DLDL_OOPSYNTAX_COMMENT;
	::DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR* DLDL_OOPSYNTAX_ESCAPE_CHAR;
	::DLDL_OOPSYNTAX::ast::node::program* DLDL_OOPSYNTAX_program;
	::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__* DLDL_OOPSYNTAX_deamerreserved_star__stmt__;
	::DLDL_OOPSYNTAX::ast::node::stmt* DLDL_OOPSYNTAX_stmt;
	::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion* DLDL_OOPSYNTAX_nonterminal_conversion;
	::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__production_rule_conversion__* DLDL_OOPSYNTAX_deamerreserved_star__production_rule_conversion__;
	::DLDL_OOPSYNTAX::ast::node::production_rule_conversion* DLDL_OOPSYNTAX_production_rule_conversion;
	::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert* DLDL_OOPSYNTAX_numbered_pr_convert;
	::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__property_assignment__* DLDL_OOPSYNTAX_deamerreserved_star__property_assignment__;
	::DLDL_OOPSYNTAX::ast::node::property_assignment* DLDL_OOPSYNTAX_property_assignment;
	::DLDL_OOPSYNTAX::ast::node::direct_property_assignment* DLDL_OOPSYNTAX_direct_property_assignment;
	::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment* DLDL_OOPSYNTAX_direct_any_property_assignment;
	::DLDL_OOPSYNTAX::ast::node::embedded_assignment* DLDL_OOPSYNTAX_embedded_assignment;
	::DLDL_OOPSYNTAX::ast::node::nonterminal_name* DLDL_OOPSYNTAX_nonterminal_name;
	::DLDL_OOPSYNTAX::ast::node::oop_type* DLDL_OOPSYNTAX_oop_type;
	::DLDL_OOPSYNTAX::ast::node::property* DLDL_OOPSYNTAX_property;
	::DLDL_OOPSYNTAX::ast::node::terminal_name* DLDL_OOPSYNTAX_terminal_name;

}

%%


program:
	deamerreserved_star__stmt__  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::program({::DLDL_OOPSYNTAX::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;


deamerreserved_star__stmt__:
	stmt deamerreserved_star__stmt__  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__({::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__({::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


stmt:
	nonterminal_conversion  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::stmt({::DLDL_OOPSYNTAX::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


nonterminal_conversion:
	nonterminal_name ARROW oop_type LEFT_BRACKET deamerreserved_star__production_rule_conversion__ RIGHT_BRACKET  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::nonterminal_conversion({::DLDL_OOPSYNTAX::ast::Type::nonterminal_conversion, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $3, $5 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
		delete $4;
		delete $6;
	}
;


deamerreserved_star__production_rule_conversion__:
	production_rule_conversion deamerreserved_star__production_rule_conversion__  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::deamerreserved_star__production_rule_conversion__({::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__production_rule_conversion__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::deamerreserved_star__production_rule_conversion__({::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__production_rule_conversion__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


production_rule_conversion:
	numbered_pr_convert  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::production_rule_conversion({::DLDL_OOPSYNTAX::ast::Type::production_rule_conversion, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


numbered_pr_convert:
	NUMBER ARROW LEFT_BRACKET deamerreserved_star__property_assignment__ RIGHT_BRACKET  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::numbered_pr_convert({::DLDL_OOPSYNTAX::ast::Type::numbered_pr_convert, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_OOPSYNTAX::ast::node::NUMBER({::DLDL_OOPSYNTAX::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $4 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
		delete $3;
		delete $5;
	}
;


deamerreserved_star__property_assignment__:
	property_assignment deamerreserved_star__property_assignment__  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::deamerreserved_star__property_assignment__({::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__property_assignment__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::deamerreserved_star__property_assignment__({::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__property_assignment__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


property_assignment:
	direct_property_assignment  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::property_assignment({::DLDL_OOPSYNTAX::ast::Type::property_assignment, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| direct_any_property_assignment  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::property_assignment({::DLDL_OOPSYNTAX::ast::Type::property_assignment, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| embedded_assignment  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::property_assignment({::DLDL_OOPSYNTAX::ast::Type::property_assignment, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


direct_property_assignment:
	oop_type DOT property EQ DOT terminal_name  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::direct_property_assignment({::DLDL_OOPSYNTAX::ast::Type::direct_property_assignment, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $3, $6 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
		delete $4;
		delete $5;
	}
;


direct_any_property_assignment:
	STAR DOT property EQ DOT terminal_name  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment({::DLDL_OOPSYNTAX::ast::Type::direct_any_property_assignment, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $3, $6 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $1;
		delete $2;
		delete $4;
		delete $5;
	}
;


embedded_assignment:
	DOT nonterminal_name ARROW oop_type LEFT_BRACKET deamerreserved_star__production_rule_conversion__ RIGHT_BRACKET  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::embedded_assignment({::DLDL_OOPSYNTAX::ast::Type::embedded_assignment, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $2, $4, $6 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $1;
		delete $3;
		delete $5;
		delete $7;
	}
;


nonterminal_name:
	VARNAME  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::nonterminal_name({::DLDL_OOPSYNTAX::ast::Type::nonterminal_name, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_OOPSYNTAX::ast::node::VARNAME({::DLDL_OOPSYNTAX::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


oop_type:
	VARNAME  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::oop_type({::DLDL_OOPSYNTAX::ast::Type::oop_type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_OOPSYNTAX::ast::node::VARNAME({::DLDL_OOPSYNTAX::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


property:
	VARNAME  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::property({::DLDL_OOPSYNTAX::ast::Type::property, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_OOPSYNTAX::ast::node::VARNAME({::DLDL_OOPSYNTAX::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


terminal_name:
	VARNAME  {
		auto* const newNode = new DLDL_OOPSYNTAX::ast::node::terminal_name({::DLDL_OOPSYNTAX::ast::Type::terminal_name, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_OOPSYNTAX::ast::node::VARNAME({::DLDL_OOPSYNTAX::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;



%%

void DLDL_OOPSYNTAXerror(const char* s)
{
	std::cout << "Syntax error on line: " << s << '\n';
}

deamer::external::cpp::ast::Tree* DLDL_OOPSYNTAX::bison::parser::Parser::Parse(const std::string& text) const
{
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_OOPSYNTAX_scan_string(text.c_str());
	DLDL_OOPSYNTAXparse();
	DLDL_OOPSYNTAX_delete_buffer(buf);
	DLDL_OOPSYNTAXlex_destroy();

	return outputTree;
}
