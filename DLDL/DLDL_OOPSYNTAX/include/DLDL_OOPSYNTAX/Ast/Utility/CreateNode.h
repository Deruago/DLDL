#ifndef DLDL_OOPSYNTAX_AST_UTILITY_CREATENODE_H
#define DLDL_OOPSYNTAX_AST_UTILITY_CREATENODE_H

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


#include <Deamer/External/Cpp/Ast/Node.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <string>
#include <vector>

namespace DLDL_OOPSYNTAX { namespace ast { namespace utility { 

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
			switch(static_cast<::DLDL_OOPSYNTAX::ast::Type>(nodeType))
			{
			case ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_unknown: {
				return new ::deamer::external::cpp::ast::Node(
					deamer::external::cpp::ast::NodeInformation{
						nodeType, deamer::external::cpp::ast::NodeValue::terminal, nodeValue,
						lineNumber, columnNumber});
			}
			case ::DLDL_OOPSYNTAX::ast::Type::ARROW: {
				return new ::DLDL_OOPSYNTAX::ast::node::ARROW({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_OOPSYNTAX::ast::Type::LEFT_BRACKET: {
				return new ::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_OOPSYNTAX::ast::Type::RIGHT_BRACKET: {
				return new ::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_OOPSYNTAX::ast::Type::DOT: {
				return new ::DLDL_OOPSYNTAX::ast::node::DOT({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_OOPSYNTAX::ast::Type::EQ: {
				return new ::DLDL_OOPSYNTAX::ast::node::EQ({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_OOPSYNTAX::ast::Type::STAR: {
				return new ::DLDL_OOPSYNTAX::ast::node::STAR({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_OOPSYNTAX::ast::Type::VARNAME: {
				return new ::DLDL_OOPSYNTAX::ast::node::VARNAME({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_OOPSYNTAX::ast::Type::NUMBER: {
				return new ::DLDL_OOPSYNTAX::ast::node::NUMBER({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_OOPSYNTAX::ast::Type::COMMENT: {
				return new ::DLDL_OOPSYNTAX::ast::node::COMMENT({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_OOPSYNTAX::ast::Type::ESCAPE_CHAR: {
				return new ::DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_OOPSYNTAX::ast::Type::program: {
				return new ::DLDL_OOPSYNTAX::ast::node::program({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__stmt__: {
				return new ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_OOPSYNTAX::ast::Type::stmt: {
				return new ::DLDL_OOPSYNTAX::ast::node::stmt({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_OOPSYNTAX::ast::Type::nonterminal_conversion: {
				return new ::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__production_rule_conversion__: {
				return new ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__production_rule_conversion__({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_OOPSYNTAX::ast::Type::production_rule_conversion: {
				return new ::DLDL_OOPSYNTAX::ast::node::production_rule_conversion({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_OOPSYNTAX::ast::Type::numbered_pr_convert: {
				return new ::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__property_assignment__: {
				return new ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__property_assignment__({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_OOPSYNTAX::ast::Type::property_assignment: {
				return new ::DLDL_OOPSYNTAX::ast::node::property_assignment({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_OOPSYNTAX::ast::Type::direct_property_assignment: {
				return new ::DLDL_OOPSYNTAX::ast::node::direct_property_assignment({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_OOPSYNTAX::ast::Type::direct_any_property_assignment: {
				return new ::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_OOPSYNTAX::ast::Type::embedded_assignment: {
				return new ::DLDL_OOPSYNTAX::ast::node::embedded_assignment({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_OOPSYNTAX::ast::Type::nonterminal_name: {
				return new ::DLDL_OOPSYNTAX::ast::node::nonterminal_name({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_OOPSYNTAX::ast::Type::oop_type: {
				return new ::DLDL_OOPSYNTAX::ast::node::oop_type({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_OOPSYNTAX::ast::Type::property: {
				return new ::DLDL_OOPSYNTAX::ast::node::property({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_OOPSYNTAX::ast::Type::terminal_name: {
				return new ::DLDL_OOPSYNTAX::ast::node::terminal_name({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}

			}

			return nullptr;
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_UTILITY_CREATENODE_H