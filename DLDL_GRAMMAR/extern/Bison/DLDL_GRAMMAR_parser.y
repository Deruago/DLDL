%{
#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <Deamer/External/Cpp/Ast/Node.h>
#include "DLDL_GRAMMAR/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/DLDL_GRAMMAR_lexer.h"
#undef YY_NO_UNISTD_H
#include "DLDL_GRAMMAR/Ast/Enum/Type.h"
#include "DLDL_GRAMMAR/Ast/Node/COMMENT.h"
#include "DLDL_GRAMMAR/Ast/Node/MULTI_LINE_COMMENT.h"
#include "DLDL_GRAMMAR/Ast/Node/START_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/GROUP_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/INLINE_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/INLINE_GROUP_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/UNKNOWN_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/NONTERMINAL.h"
#include "DLDL_GRAMMAR/Ast/Node/PRODUCTION_RULE.h"
#include "DLDL_GRAMMAR/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_GRAMMAR/Ast/Node/program.h"
#include "DLDL_GRAMMAR/Ast/Node/stmts.h"
#include "DLDL_GRAMMAR/Ast/Node/stmt.h"
#include "DLDL_GRAMMAR/Ast/Node/abstraction_declaration.h"
#include "DLDL_GRAMMAR/Ast/Node/abstraction.h"
#include "DLDL_GRAMMAR/Ast/Node/definition.h"
#include "DLDL_GRAMMAR/Ast/Node/production_rules.h"

#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDL_GRAMMARnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDL_GRAMMARlloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE

void DLDL_GRAMMARerror(const char* s);
int DLDL_GRAMMARlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;
%}

%token<Terminal> START_ABSTRACTION
%token<Terminal> GROUP_ABSTRACTION
%token<Terminal> INLINE_ABSTRACTION
%token<Terminal> INLINE_GROUP_ABSTRACTION
%token<Terminal> UNKNOWN_ABSTRACTION
%token<Terminal> NONTERMINAL
%token<Terminal> PRODUCTION_RULE

%nterm<DLDL_GRAMMAR_program> program
%nterm<DLDL_GRAMMAR_stmts> stmts
%nterm<DLDL_GRAMMAR_stmt> stmt
%nterm<DLDL_GRAMMAR_abstraction_declaration> abstraction_declaration
%nterm<DLDL_GRAMMAR_abstraction> abstraction
%nterm<DLDL_GRAMMAR_definition> definition
%nterm<DLDL_GRAMMAR_production_rules> production_rules



%union{
	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_GRAMMAR::ast::node::COMMENT* DLDL_GRAMMAR_COMMENT;
	::DLDL_GRAMMAR::ast::node::MULTI_LINE_COMMENT* DLDL_GRAMMAR_MULTI_LINE_COMMENT;
	::DLDL_GRAMMAR::ast::node::START_ABSTRACTION* DLDL_GRAMMAR_START_ABSTRACTION;
	::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION* DLDL_GRAMMAR_GROUP_ABSTRACTION;
	::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION* DLDL_GRAMMAR_INLINE_ABSTRACTION;
	::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION* DLDL_GRAMMAR_INLINE_GROUP_ABSTRACTION;
	::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION* DLDL_GRAMMAR_UNKNOWN_ABSTRACTION;
	::DLDL_GRAMMAR::ast::node::NONTERMINAL* DLDL_GRAMMAR_NONTERMINAL;
	::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE* DLDL_GRAMMAR_PRODUCTION_RULE;
	::DLDL_GRAMMAR::ast::node::ESCAPE_CHARS* DLDL_GRAMMAR_ESCAPE_CHARS;
	::DLDL_GRAMMAR::ast::node::program* DLDL_GRAMMAR_program;
	::DLDL_GRAMMAR::ast::node::stmts* DLDL_GRAMMAR_stmts;
	::DLDL_GRAMMAR::ast::node::stmt* DLDL_GRAMMAR_stmt;
	::DLDL_GRAMMAR::ast::node::abstraction_declaration* DLDL_GRAMMAR_abstraction_declaration;
	::DLDL_GRAMMAR::ast::node::abstraction* DLDL_GRAMMAR_abstraction;
	::DLDL_GRAMMAR::ast::node::definition* DLDL_GRAMMAR_definition;
	::DLDL_GRAMMAR::ast::node::production_rules* DLDL_GRAMMAR_production_rules;
}

%%

program:
	stmts {
		auto* const newNode = new DLDL_GRAMMAR::ast::node::program({::DLDL_GRAMMAR::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, {0, ::deamer::external::cpp::ast::ProductionRuleType::user}}, { $1 });
		$$ = newNode;
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;

stmts:
	stmt stmts {
		auto* const newNode = new DLDL_GRAMMAR::ast::node::stmts({::DLDL_GRAMMAR::ast::Type::stmts, ::deamer::external::cpp::ast::NodeValue::nonterminal, {0, ::deamer::external::cpp::ast::ProductionRuleType::user}}, { $1, $2 });
		$$ = newNode;
	}
	| {
		auto* const newNode = new DLDL_GRAMMAR::ast::node::stmts({::DLDL_GRAMMAR::ast::Type::stmts, ::deamer::external::cpp::ast::NodeValue::nonterminal, {1, ::deamer::external::cpp::ast::ProductionRuleType::user}}, {  });
		$$ = newNode;
	}
;

stmt:
	abstraction_declaration {
		auto* const newNode = new DLDL_GRAMMAR::ast::node::stmt({::DLDL_GRAMMAR::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, {0, ::deamer::external::cpp::ast::ProductionRuleType::user}}, { $1 });
		$$ = newNode;
	}
	| definition {
		auto* const newNode = new DLDL_GRAMMAR::ast::node::stmt({::DLDL_GRAMMAR::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, {1, ::deamer::external::cpp::ast::ProductionRuleType::user}}, { $1 });
		$$ = newNode;
	}
;

abstraction_declaration:
	abstraction NONTERMINAL {
		auto* const newNode = new DLDL_GRAMMAR::ast::node::abstraction_declaration({::DLDL_GRAMMAR::ast::Type::abstraction_declaration, ::deamer::external::cpp::ast::NodeValue::nonterminal, {0, ::deamer::external::cpp::ast::ProductionRuleType::user}}, { $1, new DLDL_GRAMMAR::ast::node::NONTERMINAL({::DLDL_GRAMMAR::ast::Type::NONTERMINAL, ::deamer::external::cpp::ast::NodeValue::terminal, $2}) });
		$$ = newNode;
	}
;

abstraction:
	GROUP_ABSTRACTION {
		auto* const newNode = new DLDL_GRAMMAR::ast::node::abstraction({::DLDL_GRAMMAR::ast::Type::abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, {0, ::deamer::external::cpp::ast::ProductionRuleType::user}}, { new DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION({::DLDL_GRAMMAR::ast::Type::GROUP_ABSTRACTION, ::deamer::external::cpp::ast::NodeValue::terminal, $1}) });
		$$ = newNode;
	}
	| INLINE_ABSTRACTION {
		auto* const newNode = new DLDL_GRAMMAR::ast::node::abstraction({::DLDL_GRAMMAR::ast::Type::abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, {1, ::deamer::external::cpp::ast::ProductionRuleType::user}}, { new DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION({::DLDL_GRAMMAR::ast::Type::INLINE_ABSTRACTION, ::deamer::external::cpp::ast::NodeValue::terminal, $1}) });
		$$ = newNode;
	}
	| INLINE_GROUP_ABSTRACTION {
		auto* const newNode = new DLDL_GRAMMAR::ast::node::abstraction({::DLDL_GRAMMAR::ast::Type::abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, {2, ::deamer::external::cpp::ast::ProductionRuleType::user}}, { new DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION({::DLDL_GRAMMAR::ast::Type::INLINE_GROUP_ABSTRACTION, ::deamer::external::cpp::ast::NodeValue::terminal, $1}) });
		$$ = newNode;
	}
	| START_ABSTRACTION {
		auto* const newNode = new DLDL_GRAMMAR::ast::node::abstraction({::DLDL_GRAMMAR::ast::Type::abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, {3, ::deamer::external::cpp::ast::ProductionRuleType::user}}, { new DLDL_GRAMMAR::ast::node::START_ABSTRACTION({::DLDL_GRAMMAR::ast::Type::START_ABSTRACTION, ::deamer::external::cpp::ast::NodeValue::terminal, $1}) });
		$$ = newNode;
	}
	| UNKNOWN_ABSTRACTION {
		auto* const newNode = new DLDL_GRAMMAR::ast::node::abstraction({::DLDL_GRAMMAR::ast::Type::abstraction, ::deamer::external::cpp::ast::NodeValue::nonterminal, {4, ::deamer::external::cpp::ast::ProductionRuleType::user}}, { new DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION({::DLDL_GRAMMAR::ast::Type::UNKNOWN_ABSTRACTION, ::deamer::external::cpp::ast::NodeValue::terminal, $1}) });
		$$ = newNode;
	}
;

definition:
	abstraction NONTERMINAL production_rules {
		auto* const newNode = new DLDL_GRAMMAR::ast::node::definition({::DLDL_GRAMMAR::ast::Type::definition, ::deamer::external::cpp::ast::NodeValue::nonterminal, {0, ::deamer::external::cpp::ast::ProductionRuleType::user}}, { $1, new DLDL_GRAMMAR::ast::node::NONTERMINAL({::DLDL_GRAMMAR::ast::Type::NONTERMINAL, ::deamer::external::cpp::ast::NodeValue::terminal, $2}), $3 });
		$$ = newNode;
	}
	| NONTERMINAL production_rules {
		auto* const newNode = new DLDL_GRAMMAR::ast::node::definition({::DLDL_GRAMMAR::ast::Type::definition, ::deamer::external::cpp::ast::NodeValue::nonterminal, {1, ::deamer::external::cpp::ast::ProductionRuleType::user}}, { new DLDL_GRAMMAR::ast::node::NONTERMINAL({::DLDL_GRAMMAR::ast::Type::NONTERMINAL, ::deamer::external::cpp::ast::NodeValue::terminal, $1}), $2 });
		$$ = newNode;
	}
;

production_rules:
	PRODUCTION_RULE production_rules {
		auto* const newNode = new DLDL_GRAMMAR::ast::node::production_rules({::DLDL_GRAMMAR::ast::Type::production_rules, ::deamer::external::cpp::ast::NodeValue::nonterminal, {0, ::deamer::external::cpp::ast::ProductionRuleType::user}}, { new DLDL_GRAMMAR::ast::node::PRODUCTION_RULE({::DLDL_GRAMMAR::ast::Type::PRODUCTION_RULE, ::deamer::external::cpp::ast::NodeValue::terminal, $1}), $2 });
		$$ = newNode;
	}
	| PRODUCTION_RULE {
		auto* const newNode = new DLDL_GRAMMAR::ast::node::production_rules({::DLDL_GRAMMAR::ast::Type::production_rules, ::deamer::external::cpp::ast::NodeValue::nonterminal, {1, ::deamer::external::cpp::ast::ProductionRuleType::user}}, { new DLDL_GRAMMAR::ast::node::PRODUCTION_RULE({::DLDL_GRAMMAR::ast::Type::PRODUCTION_RULE, ::deamer::external::cpp::ast::NodeValue::terminal, $1}) });
		$$ = newNode;
	}
;

%%

void DLDL_GRAMMARerror(const char* s)
{
	std::cout << "Syntax error on line: " << s << '\n';
}

deamer::external::cpp::ast::Tree* DLDL_GRAMMAR::parser::Parser::Parse(const std::string& text) const
{
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_GRAMMAR_scan_string(text.c_str());
	DLDL_GRAMMARparse();
	DLDL_GRAMMAR_delete_buffer(buf);
	DLDL_GRAMMARlex_destroy();

	return outputTree;
}

