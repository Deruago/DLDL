#ifndef DLDL_GRAMMAR_AST_UTILITY_CREATENODE_H
#define DLDL_GRAMMAR_AST_UTILITY_CREATENODE_H

#include "DLDL_GRAMMAR/Ast/Enum/Type.h"
#include "DLDL_GRAMMAR/Ast/Node/COMMENT.h"
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


#include <Deamer/External/Cpp/Ast/Node.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <string>
#include <vector>

namespace DLDL_GRAMMAR { namespace ast { namespace utility { 

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
			switch(static_cast<::DLDL_GRAMMAR::ast::Type>(nodeType))
			{
			case ::DLDL_GRAMMAR::ast::Type::deamerreserved_unknown: {
				return new ::deamer::external::cpp::ast::Node(
					deamer::external::cpp::ast::NodeInformation{
						nodeType, deamer::external::cpp::ast::NodeValue::terminal, nodeValue,
						lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR::ast::Type::COMMENT: {
				return new ::DLDL_GRAMMAR::ast::node::COMMENT({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR::ast::Type::START_ABSTRACTION: {
				return new ::DLDL_GRAMMAR::ast::node::START_ABSTRACTION({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR::ast::Type::GROUP_ABSTRACTION: {
				return new ::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR::ast::Type::INLINE_ABSTRACTION: {
				return new ::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR::ast::Type::INLINE_GROUP_ABSTRACTION: {
				return new ::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR::ast::Type::UNKNOWN_ABSTRACTION: {
				return new ::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR::ast::Type::NONTERMINAL: {
				return new ::DLDL_GRAMMAR::ast::node::NONTERMINAL({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR::ast::Type::PRODUCTION_RULE: {
				return new ::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR::ast::Type::ESCAPE_CHARS: {
				return new ::DLDL_GRAMMAR::ast::node::ESCAPE_CHARS({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_GRAMMAR::ast::Type::program: {
				return new ::DLDL_GRAMMAR::ast::node::program({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_GRAMMAR::ast::Type::stmts: {
				return new ::DLDL_GRAMMAR::ast::node::stmts({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_GRAMMAR::ast::Type::stmt: {
				return new ::DLDL_GRAMMAR::ast::node::stmt({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_GRAMMAR::ast::Type::abstraction_declaration: {
				return new ::DLDL_GRAMMAR::ast::node::abstraction_declaration({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_GRAMMAR::ast::Type::abstraction: {
				return new ::DLDL_GRAMMAR::ast::node::abstraction({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_GRAMMAR::ast::Type::definition: {
				return new ::DLDL_GRAMMAR::ast::node::definition({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_GRAMMAR::ast::Type::production_rules: {
				return new ::DLDL_GRAMMAR::ast::node::production_rules({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}

			}

			return nullptr;
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_UTILITY_CREATENODE_H