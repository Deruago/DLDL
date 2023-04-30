#ifndef DLDL_VALUE_AST_UTILITY_CREATENODE_H
#define DLDL_VALUE_AST_UTILITY_CREATENODE_H

#include "DLDL_VALUE/Ast/Enum/Type.h"
#include "DLDL_VALUE/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_VALUE/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_VALUE/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_VALUE/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_VALUE/Ast/Node/LEFT_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/RIGHT_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/DOT.h"
#include "DLDL_VALUE/Ast/Node/VALUE_CHARACTERISTIC.h"
#include "DLDL_VALUE/Ast/Node/VALUE_RULE.h"
#include "DLDL_VALUE/Ast/Node/NUMBER.h"
#include "DLDL_VALUE/Ast/Node/TEXT.h"
#include "DLDL_VALUE/Ast/Node/VARNAME.h"
#include "DLDL_VALUE/Ast/Node/ESCAPE_CHARS.h"
#include "DLDL_VALUE/Ast/Node/program.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_VALUE/Ast/Node/stmt.h"
#include "DLDL_VALUE/Ast/Node/value_charactersitic_declaration.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_82.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_85.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_88.h"
#include "DLDL_VALUE/Ast/Node/value_declaration.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_91.h"
#include "DLDL_VALUE/Ast/Node/value_characteristic_abstraction.h"
#include "DLDL_VALUE/Ast/Node/value_declaration_abstraction.h"
#include "DLDL_VALUE/Ast/Node/value_abstraction.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_star__value_abstraction__.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_96.h"
#include "DLDL_VALUE/Ast/Node/value.h"
#include "DLDL_VALUE/Ast/Node/syntactic_context.h"
#include "DLDL_VALUE/Ast/Node/abstraction_name.h"
#include "DLDL_VALUE/Ast/Node/value_rule_name.h"


#include <Deamer/External/Cpp/Ast/Node.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <string>
#include <vector>

namespace DLDL_VALUE { namespace ast { namespace utility { 

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
			switch(static_cast<::DLDL_VALUE::ast::Type>(nodeType))
			{
			case ::DLDL_VALUE::ast::Type::deamerreserved_unknown: {
				return new ::deamer::external::cpp::ast::Node(
					deamer::external::cpp::ast::NodeInformation{
						nodeType, deamer::external::cpp::ast::NodeValue::terminal, nodeValue,
						lineNumber, columnNumber});
			}
			case ::DLDL_VALUE::ast::Type::SINGLE_COMMENT: {
				return new ::DLDL_VALUE::ast::node::SINGLE_COMMENT({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_VALUE::ast::Type::MULTI_COMMENT: {
				return new ::DLDL_VALUE::ast::node::MULTI_COMMENT({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_VALUE::ast::Type::LEFT_PARANTHESIS: {
				return new ::DLDL_VALUE::ast::node::LEFT_PARANTHESIS({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_VALUE::ast::Type::RIGHT_PARANTHESIS: {
				return new ::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_VALUE::ast::Type::LEFT_BRACKET: {
				return new ::DLDL_VALUE::ast::node::LEFT_BRACKET({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_VALUE::ast::Type::RIGHT_BRACKET: {
				return new ::DLDL_VALUE::ast::node::RIGHT_BRACKET({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_VALUE::ast::Type::LEFT_SQUARE_BRACKET: {
				return new ::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_VALUE::ast::Type::RIGHT_SQUARE_BRACKET: {
				return new ::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_VALUE::ast::Type::DOT: {
				return new ::DLDL_VALUE::ast::node::DOT({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_VALUE::ast::Type::VALUE_CHARACTERISTIC: {
				return new ::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_VALUE::ast::Type::VALUE_RULE: {
				return new ::DLDL_VALUE::ast::node::VALUE_RULE({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_VALUE::ast::Type::NUMBER: {
				return new ::DLDL_VALUE::ast::node::NUMBER({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_VALUE::ast::Type::TEXT: {
				return new ::DLDL_VALUE::ast::node::TEXT({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_VALUE::ast::Type::VARNAME: {
				return new ::DLDL_VALUE::ast::node::VARNAME({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_VALUE::ast::Type::ESCAPE_CHARS: {
				return new ::DLDL_VALUE::ast::node::ESCAPE_CHARS({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_VALUE::ast::Type::program: {
				return new ::DLDL_VALUE::ast::node::program({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_VALUE::ast::Type::deamerreserved_star__stmt__: {
				return new ::DLDL_VALUE::ast::node::deamerreserved_star__stmt__({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_VALUE::ast::Type::stmt: {
				return new ::DLDL_VALUE::ast::node::stmt({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_VALUE::ast::Type::value_charactersitic_declaration: {
				return new ::DLDL_VALUE::ast::node::value_charactersitic_declaration({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_VALUE::ast::Type::deamerreserved_long_82: {
				return new ::DLDL_VALUE::ast::node::deamerreserved_long_82({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_VALUE::ast::Type::deamerreserved_long_85: {
				return new ::DLDL_VALUE::ast::node::deamerreserved_long_85({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_VALUE::ast::Type::deamerreserved_long_88: {
				return new ::DLDL_VALUE::ast::node::deamerreserved_long_88({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_VALUE::ast::Type::value_declaration: {
				return new ::DLDL_VALUE::ast::node::value_declaration({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_VALUE::ast::Type::deamerreserved_long_91: {
				return new ::DLDL_VALUE::ast::node::deamerreserved_long_91({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_VALUE::ast::Type::value_characteristic_abstraction: {
				return new ::DLDL_VALUE::ast::node::value_characteristic_abstraction({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_VALUE::ast::Type::value_declaration_abstraction: {
				return new ::DLDL_VALUE::ast::node::value_declaration_abstraction({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_VALUE::ast::Type::value_abstraction: {
				return new ::DLDL_VALUE::ast::node::value_abstraction({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_VALUE::ast::Type::deamerreserved_star__value_abstraction__: {
				return new ::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_VALUE::ast::Type::deamerreserved_long_96: {
				return new ::DLDL_VALUE::ast::node::deamerreserved_long_96({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_VALUE::ast::Type::value: {
				return new ::DLDL_VALUE::ast::node::value({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_VALUE::ast::Type::syntactic_context: {
				return new ::DLDL_VALUE::ast::node::syntactic_context({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_VALUE::ast::Type::abstraction_name: {
				return new ::DLDL_VALUE::ast::node::abstraction_name({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_VALUE::ast::Type::value_rule_name: {
				return new ::DLDL_VALUE::ast::node::value_rule_name({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}

			}

			return nullptr;
		}
	};

}}}

#endif // DLDL_VALUE_AST_UTILITY_CREATENODE_H