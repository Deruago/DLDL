#ifndef DLDL_VALUE_AST_VISITOR_DEAMER_VISITOR_H
#define DLDL_VALUE_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
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

namespace DLDL_VALUE { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_VALUE::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_VALUE::ast::Type::SINGLE_COMMENT:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::SINGLE_COMMENT*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::MULTI_COMMENT:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::MULTI_COMMENT*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::LEFT_PARANTHESIS:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::LEFT_PARANTHESIS*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::RIGHT_PARANTHESIS:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::RIGHT_PARANTHESIS*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::LEFT_BRACKET:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::LEFT_BRACKET*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::RIGHT_BRACKET:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::RIGHT_BRACKET*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::LEFT_SQUARE_BRACKET:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::DOT:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::DOT*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::VALUE_CHARACTERISTIC:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::VALUE_RULE:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::VALUE_RULE*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::NUMBER:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::NUMBER*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::TEXT:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::TEXT*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::VARNAME:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::VARNAME*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::ESCAPE_CHARS:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::program:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::program*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::deamerreserved_star__stmt__:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::stmt:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::stmt*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::value_charactersitic_declaration:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::value_charactersitic_declaration*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::deamerreserved_long_82:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_82*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::deamerreserved_long_85:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_85*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::deamerreserved_long_88:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_88*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::value_declaration:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::value_declaration*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::deamerreserved_long_91:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_91*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::value_characteristic_abstraction:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::value_characteristic_abstraction*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::value_declaration_abstraction:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::value_declaration_abstraction*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::value_abstraction:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::value_abstraction*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::deamerreserved_star__value_abstraction__:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::deamerreserved_long_96:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_96*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::value:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::value*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::syntactic_context:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::syntactic_context*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::abstraction_name:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::abstraction_name*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::value_rule_name:
			{
				Visit(static_cast<const DLDL_VALUE::ast::node::value_rule_name*>(node));
				break;
			}
			}
		}
		virtual void Visit(const DLDL_VALUE::ast::node::SINGLE_COMMENT* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::MULTI_COMMENT* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::LEFT_PARANTHESIS* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::RIGHT_PARANTHESIS* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::LEFT_BRACKET* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::RIGHT_BRACKET* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::DOT* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::VALUE_RULE* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::NUMBER* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::TEXT* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::VARNAME* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Visit(const DLDL_VALUE::ast::node::program* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::stmt* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::value_charactersitic_declaration* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::deamerreserved_long_82* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::deamerreserved_long_85* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::deamerreserved_long_88* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::value_declaration* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::deamerreserved_long_91* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::value_characteristic_abstraction* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::value_declaration_abstraction* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::value_abstraction* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::deamerreserved_long_96* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::value* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::syntactic_context* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::abstraction_name* node)
		{
		}
		virtual void Visit(const DLDL_VALUE::ast::node::value_rule_name* node)
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_VISITOR_DEAMER_VISITOR_H
