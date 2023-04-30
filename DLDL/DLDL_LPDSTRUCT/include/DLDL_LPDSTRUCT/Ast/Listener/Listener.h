#ifndef DLDL_LPDSTRUCT_AST_LISTENER_DEAMER_LISTENER_H
#define DLDL_LPDSTRUCT_AST_LISTENER_DEAMER_LISTENER_H

#include <Deamer/External/Cpp/Ast/Listener.h>
#include "DLDL_LPDSTRUCT/Ast/Node/DLDL_LPDSTRUCT.h"
#include "DLDL_LPDSTRUCT/Ast/Enum/Type.h"
#include "DLDL_LPDSTRUCT/Ast/Node/COLON.h"
#include "DLDL_LPDSTRUCT/Ast/Node/LEFT_ANGLE_BRACKET.h"
#include "DLDL_LPDSTRUCT/Ast/Node/RIGHT_ANGLE_BRACKET.h"
#include "DLDL_LPDSTRUCT/Ast/Node/VARNAME.h"
#include "DLDL_LPDSTRUCT/Ast/Node/VARNAME_EXT.h"
#include "DLDL_LPDSTRUCT/Ast/Node/INDENTED_VALUE.h"
#include "DLDL_LPDSTRUCT/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_LPDSTRUCT/Ast/Node/program.h"
#include "DLDL_LPDSTRUCT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDSTRUCT/Ast/Node/stmt.h"
#include "DLDL_LPDSTRUCT/Ast/Node/argument.h"
#include "DLDL_LPDSTRUCT/Ast/Node/argument_name.h"
#include "DLDL_LPDSTRUCT/Ast/Node/argument_block.h"
#include "DLDL_LPDSTRUCT/Ast/Node/deamerreserved_long_60.h"
#include "DLDL_LPDSTRUCT/Ast/Node/deamerreserved_long_63.h"
#include "DLDL_LPDSTRUCT/Ast/Node/deamerreserved_long_66.h"

namespace DLDL_LPDSTRUCT { namespace ast { namespace listener { 

	class Listener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		Listener() = default;
		~Listener() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_LPDSTRUCT::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_LPDSTRUCT::ast::Type::COLON:
			{
				Listen(static_cast<const DLDL_LPDSTRUCT::ast::node::COLON*>(node));
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::LEFT_ANGLE_BRACKET:
			{
				Listen(static_cast<const DLDL_LPDSTRUCT::ast::node::LEFT_ANGLE_BRACKET*>(node));
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::RIGHT_ANGLE_BRACKET:
			{
				Listen(static_cast<const DLDL_LPDSTRUCT::ast::node::RIGHT_ANGLE_BRACKET*>(node));
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::VARNAME:
			{
				Listen(static_cast<const DLDL_LPDSTRUCT::ast::node::VARNAME*>(node));
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::VARNAME_EXT:
			{
				Listen(static_cast<const DLDL_LPDSTRUCT::ast::node::VARNAME_EXT*>(node));
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::INDENTED_VALUE:
			{
				Listen(static_cast<const DLDL_LPDSTRUCT::ast::node::INDENTED_VALUE*>(node));
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::ESCAPE_CHARS:
			{
				Listen(static_cast<const DLDL_LPDSTRUCT::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::program:
			{
				Listen(static_cast<const DLDL_LPDSTRUCT::ast::node::program*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__stmt__:
			{
				Listen(static_cast<const DLDL_LPDSTRUCT::ast::node::deamerreserved_star__stmt__*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::stmt:
			{
				Listen(static_cast<const DLDL_LPDSTRUCT::ast::node::stmt*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::argument:
			{
				Listen(static_cast<const DLDL_LPDSTRUCT::ast::node::argument*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::argument_name:
			{
				Listen(static_cast<const DLDL_LPDSTRUCT::ast::node::argument_name*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::argument_block:
			{
				Listen(static_cast<const DLDL_LPDSTRUCT::ast::node::argument_block*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_60:
			{
				Listen(static_cast<const DLDL_LPDSTRUCT::ast::node::deamerreserved_long_60*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_63:
			{
				Listen(static_cast<const DLDL_LPDSTRUCT::ast::node::deamerreserved_long_63*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_66:
			{
				Listen(static_cast<const DLDL_LPDSTRUCT::ast::node::deamerreserved_long_66*>(node));
				DefaultAction(node);
				break;
			}
			}
		}
		virtual void Listen(const DLDL_LPDSTRUCT::ast::node::COLON* node)
		{
		}
		virtual void Listen(const DLDL_LPDSTRUCT::ast::node::LEFT_ANGLE_BRACKET* node)
		{
		}
		virtual void Listen(const DLDL_LPDSTRUCT::ast::node::RIGHT_ANGLE_BRACKET* node)
		{
		}
		virtual void Listen(const DLDL_LPDSTRUCT::ast::node::VARNAME* node)
		{
		}
		virtual void Listen(const DLDL_LPDSTRUCT::ast::node::VARNAME_EXT* node)
		{
		}
		virtual void Listen(const DLDL_LPDSTRUCT::ast::node::INDENTED_VALUE* node)
		{
		}
		virtual void Listen(const DLDL_LPDSTRUCT::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Listen(const DLDL_LPDSTRUCT::ast::node::program* node)
		{
		}
		virtual void Listen(const DLDL_LPDSTRUCT::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Listen(const DLDL_LPDSTRUCT::ast::node::stmt* node)
		{
		}
		virtual void Listen(const DLDL_LPDSTRUCT::ast::node::argument* node)
		{
		}
		virtual void Listen(const DLDL_LPDSTRUCT::ast::node::argument_name* node)
		{
		}
		virtual void Listen(const DLDL_LPDSTRUCT::ast::node::argument_block* node)
		{
		}
		virtual void Listen(const DLDL_LPDSTRUCT::ast::node::deamerreserved_long_60* node)
		{
		}
		virtual void Listen(const DLDL_LPDSTRUCT::ast::node::deamerreserved_long_63* node)
		{
		}
		virtual void Listen(const DLDL_LPDSTRUCT::ast::node::deamerreserved_long_66* node)
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

#endif // DLDL_LPDSTRUCT_AST_LISTENER_DEAMER_LISTENER_H
