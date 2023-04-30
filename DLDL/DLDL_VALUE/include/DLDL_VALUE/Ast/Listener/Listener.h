#ifndef DLDL_VALUE_AST_LISTENER_DEAMER_LISTENER_H
#define DLDL_VALUE_AST_LISTENER_DEAMER_LISTENER_H

#include <Deamer/External/Cpp/Ast/Listener.h>
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

namespace DLDL_VALUE { namespace ast { namespace listener { 

	class Listener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		Listener() = default;
		~Listener() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_VALUE::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_VALUE::ast::Type::SINGLE_COMMENT:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::SINGLE_COMMENT*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::MULTI_COMMENT:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::MULTI_COMMENT*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::LEFT_PARANTHESIS:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::LEFT_PARANTHESIS*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::RIGHT_PARANTHESIS:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::RIGHT_PARANTHESIS*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::LEFT_BRACKET:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::LEFT_BRACKET*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::RIGHT_BRACKET:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::RIGHT_BRACKET*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::LEFT_SQUARE_BRACKET:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::DOT:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::DOT*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::VALUE_CHARACTERISTIC:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::VALUE_RULE:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::VALUE_RULE*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::NUMBER:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::NUMBER*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::TEXT:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::TEXT*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::VARNAME:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::VARNAME*>(node));
				break;
			}
			case DLDL_VALUE::ast::Type::ESCAPE_CHARS:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::program:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::program*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_VALUE::ast::Type::deamerreserved_star__stmt__:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::deamerreserved_star__stmt__*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_VALUE::ast::Type::stmt:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::stmt*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_VALUE::ast::Type::value_charactersitic_declaration:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::value_charactersitic_declaration*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_VALUE::ast::Type::deamerreserved_long_82:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_82*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_VALUE::ast::Type::deamerreserved_long_85:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_85*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_VALUE::ast::Type::deamerreserved_long_88:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_88*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_VALUE::ast::Type::value_declaration:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::value_declaration*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_VALUE::ast::Type::deamerreserved_long_91:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_91*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_VALUE::ast::Type::value_characteristic_abstraction:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::value_characteristic_abstraction*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_VALUE::ast::Type::value_declaration_abstraction:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::value_declaration_abstraction*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_VALUE::ast::Type::value_abstraction:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::value_abstraction*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_VALUE::ast::Type::deamerreserved_star__value_abstraction__:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_VALUE::ast::Type::deamerreserved_long_96:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_96*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_VALUE::ast::Type::value:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::value*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_VALUE::ast::Type::syntactic_context:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::syntactic_context*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_VALUE::ast::Type::abstraction_name:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::abstraction_name*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_VALUE::ast::Type::value_rule_name:
			{
				Listen(static_cast<const DLDL_VALUE::ast::node::value_rule_name*>(node));
				DefaultAction(node);
				break;
			}
			}
		}
		virtual void Listen(const DLDL_VALUE::ast::node::SINGLE_COMMENT* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::MULTI_COMMENT* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::LEFT_PARANTHESIS* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::RIGHT_PARANTHESIS* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::LEFT_BRACKET* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::RIGHT_BRACKET* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::DOT* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::VALUE_RULE* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::NUMBER* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::TEXT* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::VARNAME* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Listen(const DLDL_VALUE::ast::node::program* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::stmt* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::value_charactersitic_declaration* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::deamerreserved_long_82* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::deamerreserved_long_85* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::deamerreserved_long_88* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::value_declaration* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::deamerreserved_long_91* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::value_characteristic_abstraction* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::value_declaration_abstraction* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::value_abstraction* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::deamerreserved_long_96* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::value* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::syntactic_context* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::abstraction_name* node)
		{
		}
		virtual void Listen(const DLDL_VALUE::ast::node::value_rule_name* node)
		{
		}
	private:
		void DefaultAction(const ::deamer::external::cpp::ast::Node* node)
		{
			for(const auto* child : node->GetNodes())
			{
				Dispatch(child);
			}
		}
	};

}}}

#endif // DLDL_VALUE_AST_LISTENER_DEAMER_LISTENER_H
