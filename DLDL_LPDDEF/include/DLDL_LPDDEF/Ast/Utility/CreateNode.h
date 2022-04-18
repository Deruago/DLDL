#ifndef DLDL_LPDDEF_AST_UTILITY_CREATENODE_H
#define DLDL_LPDDEF_AST_UTILITY_CREATENODE_H

#include "DLDL_LPDDEF/Ast/Enum/Type.h"
#include "DLDL_LPDDEF/Ast/Node/COLON.h"
#include "DLDL_LPDDEF/Ast/Node/LEFT_ANGLE_BRACKET.h"
#include "DLDL_LPDDEF/Ast/Node/RIGHT_ANGLE_BRACKET.h"
#include "DLDL_LPDDEF/Ast/Node/VARNAME.h"
#include "DLDL_LPDDEF/Ast/Node/INDENTED_VALUE.h"
#include "DLDL_LPDDEF/Ast/Node/ESCAPE_CHARS.h"
#include "DLDL_LPDDEF/Ast/Node/program.h"
#include "DLDL_LPDDEF/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDDEF/Ast/Node/stmt.h"
#include "DLDL_LPDDEF/Ast/Node/argument.h"
#include "DLDL_LPDDEF/Ast/Node/argument_name.h"
#include "DLDL_LPDDEF/Ast/Node/argument_block.h"
#include "DLDL_LPDDEF/Ast/Node/deamerreserved_star__argument_stmt__.h"
#include "DLDL_LPDDEF/Ast/Node/argument_stmt.h"


#include <Deamer/External/Cpp/Ast/Node.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <string>
#include <vector>

namespace DLDL_LPDDEF { namespace ast { namespace utility { 

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
			switch(static_cast<::DLDL_LPDDEF::ast::Type>(nodeType))
			{
			case ::DLDL_LPDDEF::ast::Type::deamerreserved_unknown: {
				return new ::deamer::external::cpp::ast::Node(
					deamer::external::cpp::ast::NodeInformation{
						nodeType, deamer::external::cpp::ast::NodeValue::terminal, nodeValue,
						lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF::ast::Type::COLON: {
				return new ::DLDL_LPDDEF::ast::node::COLON({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF::ast::Type::LEFT_ANGLE_BRACKET: {
				return new ::DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF::ast::Type::RIGHT_ANGLE_BRACKET: {
				return new ::DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF::ast::Type::VARNAME: {
				return new ::DLDL_LPDDEF::ast::node::VARNAME({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF::ast::Type::INDENTED_VALUE: {
				return new ::DLDL_LPDDEF::ast::node::INDENTED_VALUE({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF::ast::Type::ESCAPE_CHARS: {
				return new ::DLDL_LPDDEF::ast::node::ESCAPE_CHARS({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF::ast::Type::program: {
				return new ::DLDL_LPDDEF::ast::node::program({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF::ast::Type::deamerreserved_star__stmt__: {
				return new ::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF::ast::Type::stmt: {
				return new ::DLDL_LPDDEF::ast::node::stmt({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF::ast::Type::argument: {
				return new ::DLDL_LPDDEF::ast::node::argument({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF::ast::Type::argument_name: {
				return new ::DLDL_LPDDEF::ast::node::argument_name({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF::ast::Type::argument_block: {
				return new ::DLDL_LPDDEF::ast::node::argument_block({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF::ast::Type::deamerreserved_star__argument_stmt__: {
				return new ::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF::ast::Type::argument_stmt: {
				return new ::DLDL_LPDDEF::ast::node::argument_stmt({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}

			}

			return nullptr;
		}
	};

}}}

#endif // DLDL_LPDDEF_AST_UTILITY_CREATENODE_H