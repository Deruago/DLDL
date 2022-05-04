%define parse.error verbose
%define parse.lac full


%{
#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <Deamer/External/Cpp/Ast/Node.h>
#include "DLDL_LPDDEF_DF/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/DLDL_LPDDEF_DF_lexer.h"
#undef YY_NO_UNISTD_H
#include "DLDL_LPDDEF_DF/Ast/Enum/Type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/LAB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RAB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/LSB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RSB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/EQ.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COLON.h"
#include "DLDL_LPDDEF_DF/Ast/Node/LB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COMMA.h"
#include "DLDL_LPDDEF_DF/Ast/Node/OPTIONAL.h"
#include "DLDL_LPDDEF_DF/Ast/Node/VECTOR.h"
#include "DLDL_LPDDEF_DF/Ast/Node/DEAMER_VARNAME.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COMMENT.h"
#include "DLDL_LPDDEF_DF/Ast/Node/VARNAME.h"
#include "DLDL_LPDDEF_DF/Ast/Node/NUMBER.h"
#include "DLDL_LPDDEF_DF/Ast/Node/STRING.h"
#include "DLDL_LPDDEF_DF/Ast/Node/SEMICOLON.h"
#include "DLDL_LPDDEF_DF/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_LPDDEF_DF/Ast/Node/program.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/stmt.h"
#include "DLDL_LPDDEF_DF/Ast/Node/comment_line.h"
#include "DLDL_LPDDEF_DF/Ast/Node/vector_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/optional_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value_part.h"
#include "DLDL_LPDDEF_DF/Ast/Node/standard_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value_type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_arrow__value_type__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__COMMA__value_type__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/var_type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_arrow__VARNAME__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__COLON__VARNAME__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/var_name.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDL_LPDDEF_DFnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDL_LPDDEF_DFlloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE

void DLDL_LPDDEF_DFerror(const char* s);
int DLDL_LPDDEF_DFlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;
%}

%token<Terminal> LAB
%token<Terminal> RAB
%token<Terminal> LSB
%token<Terminal> RSB
%token<Terminal> EQ
%token<Terminal> COLON
%token<Terminal> LB
%token<Terminal> RB
%token<Terminal> COMMA
%token<Terminal> OPTIONAL
%token<Terminal> VECTOR
%token<Terminal> DEAMER_VARNAME
%token<Terminal> COMMENT
%token<Terminal> VARNAME
%token<Terminal> NUMBER
%token<Terminal> STRING
%token<Terminal> SEMICOLON
%token<Terminal> ESCAPE_CHARS


%nterm<DLDL_LPDDEF_DF_program> program
%nterm<DLDL_LPDDEF_DF_deamerreserved_star__stmt__> deamerreserved_star__stmt__
%nterm<DLDL_LPDDEF_DF_stmt> stmt
%nterm<DLDL_LPDDEF_DF_comment_line> comment_line
%nterm<DLDL_LPDDEF_DF_vector_variant> vector_variant
%nterm<DLDL_LPDDEF_DF_optional_variant> optional_variant
%nterm<DLDL_LPDDEF_DF_value_part> value_part
%nterm<DLDL_LPDDEF_DF_standard_variant> standard_variant
%nterm<DLDL_LPDDEF_DF_value> value
%nterm<DLDL_LPDDEF_DF_value_type> value_type
%nterm<DLDL_LPDDEF_DF_deamerreserved_arrow__value_type__> deamerreserved_arrow__value_type__
%nterm<DLDL_LPDDEF_DF_deamerreserved_star__COMMA__value_type__> deamerreserved_star__COMMA__value_type__
%nterm<DLDL_LPDDEF_DF_var_type> var_type
%nterm<DLDL_LPDDEF_DF_deamerreserved_arrow__VARNAME__> deamerreserved_arrow__VARNAME__
%nterm<DLDL_LPDDEF_DF_deamerreserved_star__COLON__VARNAME__> deamerreserved_star__COLON__VARNAME__
%nterm<DLDL_LPDDEF_DF_var_name> var_name


%union{
	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_LPDDEF_DF::ast::node::LAB* DLDL_LPDDEF_DF_LAB;
	::DLDL_LPDDEF_DF::ast::node::RAB* DLDL_LPDDEF_DF_RAB;
	::DLDL_LPDDEF_DF::ast::node::LSB* DLDL_LPDDEF_DF_LSB;
	::DLDL_LPDDEF_DF::ast::node::RSB* DLDL_LPDDEF_DF_RSB;
	::DLDL_LPDDEF_DF::ast::node::EQ* DLDL_LPDDEF_DF_EQ;
	::DLDL_LPDDEF_DF::ast::node::COLON* DLDL_LPDDEF_DF_COLON;
	::DLDL_LPDDEF_DF::ast::node::LB* DLDL_LPDDEF_DF_LB;
	::DLDL_LPDDEF_DF::ast::node::RB* DLDL_LPDDEF_DF_RB;
	::DLDL_LPDDEF_DF::ast::node::COMMA* DLDL_LPDDEF_DF_COMMA;
	::DLDL_LPDDEF_DF::ast::node::OPTIONAL* DLDL_LPDDEF_DF_OPTIONAL;
	::DLDL_LPDDEF_DF::ast::node::VECTOR* DLDL_LPDDEF_DF_VECTOR;
	::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME* DLDL_LPDDEF_DF_DEAMER_VARNAME;
	::DLDL_LPDDEF_DF::ast::node::COMMENT* DLDL_LPDDEF_DF_COMMENT;
	::DLDL_LPDDEF_DF::ast::node::VARNAME* DLDL_LPDDEF_DF_VARNAME;
	::DLDL_LPDDEF_DF::ast::node::NUMBER* DLDL_LPDDEF_DF_NUMBER;
	::DLDL_LPDDEF_DF::ast::node::STRING* DLDL_LPDDEF_DF_STRING;
	::DLDL_LPDDEF_DF::ast::node::SEMICOLON* DLDL_LPDDEF_DF_SEMICOLON;
	::DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS* DLDL_LPDDEF_DF_ESCAPE_CHARS;
	::DLDL_LPDDEF_DF::ast::node::program* DLDL_LPDDEF_DF_program;
	::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__* DLDL_LPDDEF_DF_deamerreserved_star__stmt__;
	::DLDL_LPDDEF_DF::ast::node::stmt* DLDL_LPDDEF_DF_stmt;
	::DLDL_LPDDEF_DF::ast::node::comment_line* DLDL_LPDDEF_DF_comment_line;
	::DLDL_LPDDEF_DF::ast::node::vector_variant* DLDL_LPDDEF_DF_vector_variant;
	::DLDL_LPDDEF_DF::ast::node::optional_variant* DLDL_LPDDEF_DF_optional_variant;
	::DLDL_LPDDEF_DF::ast::node::value_part* DLDL_LPDDEF_DF_value_part;
	::DLDL_LPDDEF_DF::ast::node::standard_variant* DLDL_LPDDEF_DF_standard_variant;
	::DLDL_LPDDEF_DF::ast::node::value* DLDL_LPDDEF_DF_value;
	::DLDL_LPDDEF_DF::ast::node::value_type* DLDL_LPDDEF_DF_value_type;
	::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__* DLDL_LPDDEF_DF_deamerreserved_arrow__value_type__;
	::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__* DLDL_LPDDEF_DF_deamerreserved_star__COMMA__value_type__;
	::DLDL_LPDDEF_DF::ast::node::var_type* DLDL_LPDDEF_DF_var_type;
	::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__* DLDL_LPDDEF_DF_deamerreserved_arrow__VARNAME__;
	::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__* DLDL_LPDDEF_DF_deamerreserved_star__COLON__VARNAME__;
	::DLDL_LPDDEF_DF::ast::node::var_name* DLDL_LPDDEF_DF_var_name;

}

%%


program:
	deamerreserved_star__stmt__  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::program({::DLDL_LPDDEF_DF::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;


deamerreserved_star__stmt__:
	stmt deamerreserved_star__stmt__  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__({::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__({::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


stmt:
	comment_line  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::stmt({::DLDL_LPDDEF_DF::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| vector_variant  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::stmt({::DLDL_LPDDEF_DF::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| optional_variant  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::stmt({::DLDL_LPDDEF_DF::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| standard_variant  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::stmt({::DLDL_LPDDEF_DF::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


comment_line:
	COMMENT  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::comment_line({::DLDL_LPDDEF_DF::ast::Type::comment_line, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::COMMENT({::DLDL_LPDDEF_DF::ast::Type::COMMENT, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


vector_variant:
	VECTOR LAB var_type RAB var_name value_part  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::vector_variant({::DLDL_LPDDEF_DF::ast::Type::vector_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::VECTOR({::DLDL_LPDDEF_DF::ast::Type::VECTOR, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $3, $5, $6 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
		delete $4;
	}
	| VECTOR LAB var_type RAB var_name  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::vector_variant({::DLDL_LPDDEF_DF::ast::Type::vector_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::VECTOR({::DLDL_LPDDEF_DF::ast::Type::VECTOR, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $3, $5 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
		delete $4;
	}
	| VECTOR LSB var_type RSB var_name value_part  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::vector_variant({::DLDL_LPDDEF_DF::ast::Type::vector_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::VECTOR({::DLDL_LPDDEF_DF::ast::Type::VECTOR, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $3, $5, $6 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
		delete $4;
	}
	| VECTOR LSB var_type RSB var_name  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::vector_variant({::DLDL_LPDDEF_DF::ast::Type::vector_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::VECTOR({::DLDL_LPDDEF_DF::ast::Type::VECTOR, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $3, $5 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
		delete $4;
	}
;


optional_variant:
	OPTIONAL LAB var_type RAB var_name value_part  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::optional_variant({::DLDL_LPDDEF_DF::ast::Type::optional_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::OPTIONAL({::DLDL_LPDDEF_DF::ast::Type::OPTIONAL, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $3, $5, $6 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
		delete $4;
	}
	| OPTIONAL LAB var_type RAB var_name  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::optional_variant({::DLDL_LPDDEF_DF::ast::Type::optional_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::OPTIONAL({::DLDL_LPDDEF_DF::ast::Type::OPTIONAL, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $3, $5 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
		delete $4;
	}
	| OPTIONAL LSB var_type RSB var_name value_part  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::optional_variant({::DLDL_LPDDEF_DF::ast::Type::optional_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::OPTIONAL({::DLDL_LPDDEF_DF::ast::Type::OPTIONAL, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $3, $5, $6 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
		delete $4;
	}
	| OPTIONAL LSB var_type RSB var_name  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::optional_variant({::DLDL_LPDDEF_DF::ast::Type::optional_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::OPTIONAL({::DLDL_LPDDEF_DF::ast::Type::OPTIONAL, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $3, $5 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $2;
		delete $4;
	}
;


value_part:
	EQ value  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::value_part({::DLDL_LPDDEF_DF::ast::Type::value_part, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		delete $1;
	}
;


standard_variant:
	var_type var_name value_part  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::standard_variant({::DLDL_LPDDEF_DF::ast::Type::standard_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2, $3 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| var_type var_name  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::standard_variant({::DLDL_LPDDEF_DF::ast::Type::standard_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


value:
	value_type  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::value({::DLDL_LPDDEF_DF::ast::Type::value, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


value_type:
	VARNAME  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::value_type({::DLDL_LPDDEF_DF::ast::Type::value_type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::VARNAME({::DLDL_LPDDEF_DF::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| VARNAME COLON COLON VARNAME  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::value_type({::DLDL_LPDDEF_DF::ast::Type::value_type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::VARNAME({::DLDL_LPDDEF_DF::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), new DLDL_LPDDEF_DF::ast::node::COLON({::DLDL_LPDDEF_DF::ast::Type::COLON, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), new DLDL_LPDDEF_DF::ast::node::COLON({::DLDL_LPDDEF_DF::ast::Type::COLON, ::deamer::external::cpp::ast::NodeValue::terminal, $3 }), new DLDL_LPDDEF_DF::ast::node::VARNAME({::DLDL_LPDDEF_DF::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $4 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| DEAMER_VARNAME  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::value_type({::DLDL_LPDDEF_DF::ast::Type::value_type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME({::DLDL_LPDDEF_DF::ast::Type::DEAMER_VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| NUMBER  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::value_type({::DLDL_LPDDEF_DF::ast::Type::value_type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::NUMBER({::DLDL_LPDDEF_DF::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| STRING  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::value_type({::DLDL_LPDDEF_DF::ast::Type::value_type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::STRING({::DLDL_LPDDEF_DF::ast::Type::STRING, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| LB deamerreserved_arrow__value_type__ RB  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::value_type({::DLDL_LPDDEF_DF::ast::Type::value_type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::LB({::DLDL_LPDDEF_DF::ast::Type::LB, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2, new DLDL_LPDDEF_DF::ast::node::RB({::DLDL_LPDDEF_DF::ast::Type::RB, ::deamer::external::cpp::ast::NodeValue::terminal, $3 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| LB RB  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::value_type({::DLDL_LPDDEF_DF::ast::Type::value_type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 6, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::LB({::DLDL_LPDDEF_DF::ast::Type::LB, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), new DLDL_LPDDEF_DF::ast::node::RB({::DLDL_LPDDEF_DF::ast::Type::RB, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_arrow__value_type__:
	value_type deamerreserved_star__COMMA__value_type__  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__({::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__value_type__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_star__COMMA__value_type__:
	COMMA value_type deamerreserved_star__COMMA__value_type__  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__({::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COMMA__value_type__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new DLDL_LPDDEF_DF::ast::node::COMMA({::DLDL_LPDDEF_DF::ast::Type::COMMA, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2, $3 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__({::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COMMA__value_type__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


var_type:
	DEAMER_VARNAME  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::var_type({::DLDL_LPDDEF_DF::ast::Type::var_type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME({::DLDL_LPDDEF_DF::ast::Type::DEAMER_VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| deamerreserved_arrow__VARNAME__  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::var_type({::DLDL_LPDDEF_DF::ast::Type::var_type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_arrow__VARNAME__:
	VARNAME deamerreserved_star__COLON__VARNAME__  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__({::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__VARNAME__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new DLDL_LPDDEF_DF::ast::node::VARNAME({::DLDL_LPDDEF_DF::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_star__COLON__VARNAME__:
	COLON VARNAME deamerreserved_star__COLON__VARNAME__  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__({::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COLON__VARNAME__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new DLDL_LPDDEF_DF::ast::node::COLON({::DLDL_LPDDEF_DF::ast::Type::COLON, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), new DLDL_LPDDEF_DF::ast::node::VARNAME({::DLDL_LPDDEF_DF::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__({::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COLON__VARNAME__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


var_name:
	VARNAME  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::var_name({::DLDL_LPDDEF_DF::ast::Type::var_name, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::VARNAME({::DLDL_LPDDEF_DF::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;



%%

void DLDL_LPDDEF_DFerror(const char* s)
{
	std::cout << "Syntax error on line: " << s << '\n';
}

deamer::external::cpp::ast::Tree* DLDL_LPDDEF_DF::bison::parser::Parser::Parse(const std::string& text) const
{
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_LPDDEF_DF_scan_string(text.c_str());
	DLDL_LPDDEF_DFparse();
	DLDL_LPDDEF_DF_delete_buffer(buf);
	DLDL_LPDDEF_DFlex_destroy();

	return outputTree;
}
