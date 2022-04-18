#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_UTILITY_CREATENODE_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_UTILITY_CREATENODE_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Enum/Type.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ENDING_USELESS_SYMBOLS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/VERTICAL_SLASH.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/QUESTION_MARK.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/EXCLAMATION_MARK.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ARROW.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/STAR.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/PLUS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/MINUS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/VALUE.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/NUMBER.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/SINGLE_LINE_COMMENT.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/MULTI_LINE_COMMENT.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/SYMBOLS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ESCAPE_CHARS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/program.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/stmts.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/stmt.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/nested_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/optional_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/zero_or_more_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/one_or_more_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/or_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/min_max_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/extension_group.h"


#include <Deamer/External/Cpp/Ast/Node.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <string>
#include <vector>

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace utility { 

	struct CreateNode
	{
	private:
		std::string nodeValue;
		std::size_t nodeType = 0;
		
		std::vector<::deamer::external::cpp::ast::Node*> nodes;
		std::vector<std::size_t> baseValues;

		int lineNumber = -1;
		int columnNumber = -1;

		std::size_t productionRuleId = 0;
		::deamer::external::cpp::ast::ProductionRuleType productionRuleType =
					::deamer::external::cpp::ast::ProductionRuleType::unknown;
	
	public:
		CreateNode() = default;
		~CreateNode() = default;

	public:
		CreateNode& Node(const ::deamer::external::cpp::lexer::TerminalObject* terminalObject)
		{
			nodeValue = terminalObject->GetValue();
			nodeType = terminalObject->GetType();
			
			lineNumber = terminalObject->GetLineNumber();
			columnNumber = terminalObject->GetColumnNumber();

			return *this;
		}

		CreateNode& Node(std::size_t nodeType_)
		{
			nodeType = nodeType_;

			return *this;
		}

		CreateNode& ProductionRule(std::size_t productionRuleId_,
			::deamer::external::cpp::ast::ProductionRuleType productionRuleType_ = ::deamer::external::cpp::ast::ProductionRuleType::user)
		{
			productionRuleId = productionRuleId_;
			productionRuleType = productionRuleType_;

			return *this;
		}

		CreateNode& SubNode(::deamer::external::cpp::lexer::TerminalObject* terminalObject)
		{
			CreateNode tmp{};
			
			tmp.Node(terminalObject);
			nodes.push_back(tmp.GetNode());

			return *this;
		}

		CreateNode& SubNode(::deamer::external::cpp::ast::Node* subNode_)
		{
			nodes.push_back(subNode_);
			return *this;
		}

		::deamer::external::cpp::ast::Node* GetNode()
		{
			switch(static_cast<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type>(nodeType))
			{
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::deamerreserved_unknown: {
				return new ::deamer::external::cpp::ast::Node(
					deamer::external::cpp::ast::NodeInformation{
						nodeType, deamer::external::cpp::ast::NodeValue::terminal, nodeValue,
						lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ENDING_USELESS_SYMBOLS: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VERTICAL_SLASH: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_PARANTHESIS: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_PARANTHESIS: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_BRACKET: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_BRACKET: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_SQUARE_BRACKET: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_SQUARE_BRACKET: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::QUESTION_MARK: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::EXCLAMATION_MARK: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ARROW: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::STAR: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::PLUS: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MINUS: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VALUE: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::NUMBER: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SINGLE_LINE_COMMENT: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MULTI_LINE_COMMENT: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SYMBOLS: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ESCAPE_CHARS: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::program: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmts: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmt: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::nested_group: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::optional_group: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::zero_or_more_group: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::one_or_more_group: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::or_group: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::min_max_group: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::extension_group: {
				return new ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}

			}

			return nullptr;
		}
	};

}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_UTILITY_CREATENODE_H