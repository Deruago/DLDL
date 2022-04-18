#ifndef DLDL_LPDDEF_DF_AST_UTILITY_CREATENODE_H
#define DLDL_LPDDEF_DF_AST_UTILITY_CREATENODE_H

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


#include <Deamer/External/Cpp/Ast/Node.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <string>
#include <vector>

namespace DLDL_LPDDEF_DF { namespace ast { namespace utility { 

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
			switch(static_cast<::DLDL_LPDDEF_DF::ast::Type>(nodeType))
			{
			case ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_unknown: {
				return new ::deamer::external::cpp::ast::Node(
					deamer::external::cpp::ast::NodeInformation{
						nodeType, deamer::external::cpp::ast::NodeValue::terminal, nodeValue,
						lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_DF::ast::Type::LAB: {
				return new ::DLDL_LPDDEF_DF::ast::node::LAB({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_DF::ast::Type::RAB: {
				return new ::DLDL_LPDDEF_DF::ast::node::RAB({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_DF::ast::Type::LSB: {
				return new ::DLDL_LPDDEF_DF::ast::node::LSB({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_DF::ast::Type::RSB: {
				return new ::DLDL_LPDDEF_DF::ast::node::RSB({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_DF::ast::Type::EQ: {
				return new ::DLDL_LPDDEF_DF::ast::node::EQ({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_DF::ast::Type::COLON: {
				return new ::DLDL_LPDDEF_DF::ast::node::COLON({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_DF::ast::Type::LB: {
				return new ::DLDL_LPDDEF_DF::ast::node::LB({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_DF::ast::Type::RB: {
				return new ::DLDL_LPDDEF_DF::ast::node::RB({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_DF::ast::Type::COMMA: {
				return new ::DLDL_LPDDEF_DF::ast::node::COMMA({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_DF::ast::Type::OPTIONAL: {
				return new ::DLDL_LPDDEF_DF::ast::node::OPTIONAL({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_DF::ast::Type::VECTOR: {
				return new ::DLDL_LPDDEF_DF::ast::node::VECTOR({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_DF::ast::Type::DEAMER_VARNAME: {
				return new ::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_DF::ast::Type::COMMENT: {
				return new ::DLDL_LPDDEF_DF::ast::node::COMMENT({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_DF::ast::Type::VARNAME: {
				return new ::DLDL_LPDDEF_DF::ast::node::VARNAME({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_DF::ast::Type::NUMBER: {
				return new ::DLDL_LPDDEF_DF::ast::node::NUMBER({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_DF::ast::Type::STRING: {
				return new ::DLDL_LPDDEF_DF::ast::node::STRING({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_DF::ast::Type::SEMICOLON: {
				return new ::DLDL_LPDDEF_DF::ast::node::SEMICOLON({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_DF::ast::Type::ESCAPE_CHARS: {
				return new ::DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::DLDL_LPDDEF_DF::ast::Type::program: {
				return new ::DLDL_LPDDEF_DF::ast::node::program({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__stmt__: {
				return new ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_DF::ast::Type::stmt: {
				return new ::DLDL_LPDDEF_DF::ast::node::stmt({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_DF::ast::Type::comment_line: {
				return new ::DLDL_LPDDEF_DF::ast::node::comment_line({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_DF::ast::Type::vector_variant: {
				return new ::DLDL_LPDDEF_DF::ast::node::vector_variant({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_DF::ast::Type::optional_variant: {
				return new ::DLDL_LPDDEF_DF::ast::node::optional_variant({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_DF::ast::Type::value_part: {
				return new ::DLDL_LPDDEF_DF::ast::node::value_part({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_DF::ast::Type::standard_variant: {
				return new ::DLDL_LPDDEF_DF::ast::node::standard_variant({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_DF::ast::Type::value: {
				return new ::DLDL_LPDDEF_DF::ast::node::value({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_DF::ast::Type::value_type: {
				return new ::DLDL_LPDDEF_DF::ast::node::value_type({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__value_type__: {
				return new ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COMMA__value_type__: {
				return new ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_DF::ast::Type::var_type: {
				return new ::DLDL_LPDDEF_DF::ast::node::var_type({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__VARNAME__: {
				return new ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COLON__VARNAME__: {
				return new ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::DLDL_LPDDEF_DF::ast::Type::var_name: {
				return new ::DLDL_LPDDEF_DF::ast::node::var_name({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}

			}

			return nullptr;
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_UTILITY_CREATENODE_H