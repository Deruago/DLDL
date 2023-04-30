#ifndef DLDL_IMPORT_AST_UTILITY_CREATENODE_H
#define DLDL_IMPORT_AST_UTILITY_CREATENODE_H

#include "DLDL_IMPORT/Ast/Enum/Type.h"
#include "DLDL_IMPORT/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_IMPORT/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_IMPORT/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_IMPORT/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_IMPORT/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_IMPORT/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_IMPORT/Ast/Node/COLON.h"
#include "DLDL_IMPORT/Ast/Node/DOT.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT_FILE.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT_MODULE.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT.h"
#include "DLDL_IMPORT/Ast/Node/TEXT.h"
#include "DLDL_IMPORT/Ast/Node/VARNAME.h"
#include "DLDL_IMPORT/Ast/Node/ESCAPE_CHARS.h"
#include "DLDL_IMPORT/Ast/Node/program.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_IMPORT/Ast/Node/stmt.h"
#include "DLDL_IMPORT/Ast/Node/import_declaration.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_arrow__import_context__.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_long_40.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_long_43.h"
#include "DLDL_IMPORT/Ast/Node/specialization.h"
#include "DLDL_IMPORT/Ast/Node/import_abstraction.h"
#include "DLDL_IMPORT/Ast/Node/value.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_optional__VARNAME__.h"
#include "DLDL_IMPORT/Ast/Node/abstraction.h"
#include "DLDL_IMPORT/Ast/Node/import_context.h"
#include "DLDL_IMPORT/Ast/Node/import_rule_name.h"


#include <Deamer/External/Cpp/Ast/Node.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <string>
#include <vector>

namespace DLDL_IMPORT { namespace ast { namespace utility { 

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
			switch(static_cast<::DLDL_IMPORT::ast::Type>(nodeType))
			{
			case ::DLDL_IMPORT::ast::Type::deamerreserved_unknown: {
				return new ::deamer::external::cpp::ast::Node(
					deamer::external::cpp::ast::NodeInformation{
						nodeType, deamer::external::cpp::ast::NodeValue::terminal, nodeValue,
						lineNumber, columnNumber});
			}
			case ::DLDL_IMPORT::ast::Type::SINGLE_COMMENT: {
				return new ::DLDL_IMPORT::ast::node::SINGLE_COMMENT({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_IMPORT::ast::Type::MULTI_COMMENT: {
				return new ::DLDL_IMPORT::ast::node::MULTI_COMMENT({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_IMPORT::ast::Type::LEFT_PARANTHESIS: {
				return new ::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_IMPORT::ast::Type::RIGHT_PARANTHESIS: {
				return new ::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_IMPORT::ast::Type::LEFT_SQUARE_BRACKET: {
				return new ::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_IMPORT::ast::Type::RIGHT_SQUARE_BRACKET: {
				return new ::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_IMPORT::ast::Type::COLON: {
				return new ::DLDL_IMPORT::ast::node::COLON({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_IMPORT::ast::Type::DOT: {
				return new ::DLDL_IMPORT::ast::node::DOT({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_IMPORT::ast::Type::IMPORT_FILE: {
				return new ::DLDL_IMPORT::ast::node::IMPORT_FILE({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_IMPORT::ast::Type::IMPORT_MODULE: {
				return new ::DLDL_IMPORT::ast::node::IMPORT_MODULE({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_IMPORT::ast::Type::IMPORT: {
				return new ::DLDL_IMPORT::ast::node::IMPORT({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_IMPORT::ast::Type::TEXT: {
				return new ::DLDL_IMPORT::ast::node::TEXT({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_IMPORT::ast::Type::VARNAME: {
				return new ::DLDL_IMPORT::ast::node::VARNAME({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_IMPORT::ast::Type::ESCAPE_CHARS: {
				return new ::DLDL_IMPORT::ast::node::ESCAPE_CHARS({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_IMPORT::ast::Type::program: {
				return new ::DLDL_IMPORT::ast::node::program({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_IMPORT::ast::Type::deamerreserved_star__stmt__: {
				return new ::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_IMPORT::ast::Type::stmt: {
				return new ::DLDL_IMPORT::ast::node::stmt({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_IMPORT::ast::Type::import_declaration: {
				return new ::DLDL_IMPORT::ast::node::import_declaration({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_IMPORT::ast::Type::deamerreserved_arrow__import_context__: {
				return new ::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_IMPORT::ast::Type::deamerreserved_long_40: {
				return new ::DLDL_IMPORT::ast::node::deamerreserved_long_40({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_IMPORT::ast::Type::deamerreserved_long_43: {
				return new ::DLDL_IMPORT::ast::node::deamerreserved_long_43({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_IMPORT::ast::Type::specialization: {
				return new ::DLDL_IMPORT::ast::node::specialization({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_IMPORT::ast::Type::import_abstraction: {
				return new ::DLDL_IMPORT::ast::node::import_abstraction({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_IMPORT::ast::Type::value: {
				return new ::DLDL_IMPORT::ast::node::value({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_IMPORT::ast::Type::deamerreserved_optional__VARNAME__: {
				return new ::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_IMPORT::ast::Type::abstraction: {
				return new ::DLDL_IMPORT::ast::node::abstraction({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_IMPORT::ast::Type::import_context: {
				return new ::DLDL_IMPORT::ast::node::import_context({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_IMPORT::ast::Type::import_rule_name: {
				return new ::DLDL_IMPORT::ast::node::import_rule_name({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}

			}

			return nullptr;
		}
	};

}}}

#endif // DLDL_IMPORT_AST_UTILITY_CREATENODE_H