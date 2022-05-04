#ifndef DLDL_LPDDEF_AST_LISTENER_DEAMER_LISTENER_H
#define DLDL_LPDDEF_AST_LISTENER_DEAMER_LISTENER_H

#include <Deamer/External/Cpp/Ast/Listener.h>
#include "DLDL_LPDDEF/Ast/Node/DLDL_LPDDEF.h"
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

namespace DLDL_LPDDEF { namespace ast { namespace listener { 

	class Listener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		Listener() = default;
		~Listener() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_LPDDEF::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_LPDDEF::ast::Type::COLON:
			{
				Listen(static_cast<const DLDL_LPDDEF::ast::node::COLON*>(node));
				break;
			}
			case DLDL_LPDDEF::ast::Type::LEFT_ANGLE_BRACKET:
			{
				Listen(static_cast<const DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET*>(node));
				break;
			}
			case DLDL_LPDDEF::ast::Type::RIGHT_ANGLE_BRACKET:
			{
				Listen(static_cast<const DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET*>(node));
				break;
			}
			case DLDL_LPDDEF::ast::Type::VARNAME:
			{
				Listen(static_cast<const DLDL_LPDDEF::ast::node::VARNAME*>(node));
				break;
			}
			case DLDL_LPDDEF::ast::Type::INDENTED_VALUE:
			{
				Listen(static_cast<const DLDL_LPDDEF::ast::node::INDENTED_VALUE*>(node));
				break;
			}
			case DLDL_LPDDEF::ast::Type::ESCAPE_CHARS:
			{
				Listen(static_cast<const DLDL_LPDDEF::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_LPDDEF::ast::Type::program:
			{
				Listen(static_cast<const DLDL_LPDDEF::ast::node::program*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF::ast::Type::deamerreserved_star__stmt__:
			{
				Listen(static_cast<const DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF::ast::Type::stmt:
			{
				Listen(static_cast<const DLDL_LPDDEF::ast::node::stmt*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF::ast::Type::argument:
			{
				Listen(static_cast<const DLDL_LPDDEF::ast::node::argument*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF::ast::Type::argument_name:
			{
				Listen(static_cast<const DLDL_LPDDEF::ast::node::argument_name*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF::ast::Type::argument_block:
			{
				Listen(static_cast<const DLDL_LPDDEF::ast::node::argument_block*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF::ast::Type::deamerreserved_star__argument_stmt__:
			{
				Listen(static_cast<const DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF::ast::Type::argument_stmt:
			{
				Listen(static_cast<const DLDL_LPDDEF::ast::node::argument_stmt*>(node));
				DefaultAction(node);
				break;
			}
			}
		}
		virtual void Listen(const DLDL_LPDDEF::ast::node::COLON* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF::ast::node::VARNAME* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF::ast::node::INDENTED_VALUE* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Listen(const DLDL_LPDDEF::ast::node::program* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF::ast::node::stmt* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF::ast::node::argument* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF::ast::node::argument_name* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF::ast::node::argument_block* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF::ast::node::argument_stmt* node)
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

#endif // DLDL_LPDDEF_AST_LISTENER_DEAMER_LISTENER_H
