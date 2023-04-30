#ifndef DLDL_IMPORT_AST_LISTENER_DEAMER_LISTENER_H
#define DLDL_IMPORT_AST_LISTENER_DEAMER_LISTENER_H

#include <Deamer/External/Cpp/Ast/Listener.h>
#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
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

namespace DLDL_IMPORT { namespace ast { namespace listener { 

	class Listener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		Listener() = default;
		~Listener() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_IMPORT::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_IMPORT::ast::Type::SINGLE_COMMENT:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::SINGLE_COMMENT*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::MULTI_COMMENT:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::MULTI_COMMENT*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::LEFT_PARANTHESIS:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::LEFT_PARANTHESIS*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::RIGHT_PARANTHESIS:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::LEFT_SQUARE_BRACKET:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::COLON:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::COLON*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::DOT:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::DOT*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::IMPORT_FILE:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::IMPORT_FILE*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::IMPORT_MODULE:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::IMPORT_MODULE*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::IMPORT:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::IMPORT*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::TEXT:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::TEXT*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::VARNAME:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::VARNAME*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::ESCAPE_CHARS:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::program:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::program*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_IMPORT::ast::Type::deamerreserved_star__stmt__:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_star__stmt__*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_IMPORT::ast::Type::stmt:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::stmt*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_IMPORT::ast::Type::import_declaration:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::import_declaration*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_IMPORT::ast::Type::deamerreserved_arrow__import_context__:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_IMPORT::ast::Type::deamerreserved_long_40:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_long_40*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_IMPORT::ast::Type::deamerreserved_long_43:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_long_43*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_IMPORT::ast::Type::specialization:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::specialization*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_IMPORT::ast::Type::import_abstraction:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::import_abstraction*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_IMPORT::ast::Type::value:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::value*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_IMPORT::ast::Type::deamerreserved_optional__VARNAME__:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_IMPORT::ast::Type::abstraction:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::abstraction*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_IMPORT::ast::Type::import_context:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::import_context*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_IMPORT::ast::Type::import_rule_name:
			{
				Listen(static_cast<const DLDL_IMPORT::ast::node::import_rule_name*>(node));
				DefaultAction(node);
				break;
			}
			}
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::SINGLE_COMMENT* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::MULTI_COMMENT* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::LEFT_PARANTHESIS* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::COLON* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::DOT* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::IMPORT_FILE* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::IMPORT_MODULE* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::IMPORT* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::TEXT* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::VARNAME* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Listen(const DLDL_IMPORT::ast::node::program* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::stmt* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::import_declaration* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::deamerreserved_long_40* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::deamerreserved_long_43* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::specialization* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::import_abstraction* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::value* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::abstraction* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::import_context* node)
		{
		}
		virtual void Listen(const DLDL_IMPORT::ast::node::import_rule_name* node)
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

#endif // DLDL_IMPORT_AST_LISTENER_DEAMER_LISTENER_H
