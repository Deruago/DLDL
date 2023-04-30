#ifndef DLDL_LPDDEF_EF_AST_UTILITY_CREATENODE_H
#define DLDL_LPDDEF_EF_AST_UTILITY_CREATENODE_H

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


#include <Deamer/External/Cpp/Ast/Node.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <string>
#include <vector>

namespace DLDL_LPDDEF_EF { namespace ast { namespace utility { 

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
			switch(static_cast<::DLDL_LPDDEF_EF::ast::Type>(nodeType))
			{
			case ::DLDL_LPDDEF_EF::ast::Type::deamerreserved_unknown: {
				return new ::deamer::external::cpp::ast::Node(
					deamer::external::cpp::ast::NodeInformation{
						nodeType, deamer::external::cpp::ast::NodeValue::terminal, nodeValue,
						lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_EF::ast::Type::COMMENT: {
				return new ::DLDL_LPDDEF_EF::ast::node::COMMENT({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_EF::ast::Type::VARNAME: {
				return new ::DLDL_LPDDEF_EF::ast::node::VARNAME({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_EF::ast::Type::NUMBER: {
				return new ::DLDL_LPDDEF_EF::ast::node::NUMBER({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_EF::ast::Type::COLON: {
				return new ::DLDL_LPDDEF_EF::ast::node::COLON({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_EF::ast::Type::SEMICOLON: {
				return new ::DLDL_LPDDEF_EF::ast::node::SEMICOLON({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_EF::ast::Type::ESCAPE_CHARS: {
				return new ::DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_EF::ast::Type::program: {
				return new ::DLDL_LPDDEF_EF::ast::node::program({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_EF::ast::Type::deamerreserved_star__stmt__: {
				return new ::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_EF::ast::Type::stmt: {
				return new ::DLDL_LPDDEF_EF::ast::node::stmt({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_EF::ast::Type::comment_line: {
				return new ::DLDL_LPDDEF_EF::ast::node::comment_line({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_EF::ast::Type::standard_variant: {
				return new ::DLDL_LPDDEF_EF::ast::node::standard_variant({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_EF::ast::Type::standard_variant_specific_number: {
				return new ::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_EF::ast::Type::value: {
				return new ::DLDL_LPDDEF_EF::ast::node::value({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_EF::ast::Type::enum_name: {
				return new ::DLDL_LPDDEF_EF::ast::node::enum_name({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}

			}

			return nullptr;
		}
	};

}}}

#endif // DLDL_LPDDEF_EF_AST_UTILITY_CREATENODE_H