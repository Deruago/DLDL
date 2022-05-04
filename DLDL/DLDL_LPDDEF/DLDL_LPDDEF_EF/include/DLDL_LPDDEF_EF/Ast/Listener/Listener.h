#ifndef DLDL_LPDDEF_EF_AST_LISTENER_DEAMER_LISTENER_H
#define DLDL_LPDDEF_EF_AST_LISTENER_DEAMER_LISTENER_H

#include <Deamer/External/Cpp/Ast/Listener.h>
#include "DLDL_LPDDEF_EF/Ast/Node/DLDL_LPDDEF_EF.h"
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

namespace DLDL_LPDDEF_EF { namespace ast { namespace listener { 

	class Listener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		Listener() = default;
		~Listener() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_LPDDEF_EF::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_LPDDEF_EF::ast::Type::COMMENT:
			{
				Listen(static_cast<const DLDL_LPDDEF_EF::ast::node::COMMENT*>(node));
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::VARNAME:
			{
				Listen(static_cast<const DLDL_LPDDEF_EF::ast::node::VARNAME*>(node));
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::NUMBER:
			{
				Listen(static_cast<const DLDL_LPDDEF_EF::ast::node::NUMBER*>(node));
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::COLON:
			{
				Listen(static_cast<const DLDL_LPDDEF_EF::ast::node::COLON*>(node));
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::SEMICOLON:
			{
				Listen(static_cast<const DLDL_LPDDEF_EF::ast::node::SEMICOLON*>(node));
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::ESCAPE_CHARS:
			{
				Listen(static_cast<const DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::program:
			{
				Listen(static_cast<const DLDL_LPDDEF_EF::ast::node::program*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::deamerreserved_star__stmt__:
			{
				Listen(static_cast<const DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::stmt:
			{
				Listen(static_cast<const DLDL_LPDDEF_EF::ast::node::stmt*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::comment_line:
			{
				Listen(static_cast<const DLDL_LPDDEF_EF::ast::node::comment_line*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::standard_variant:
			{
				Listen(static_cast<const DLDL_LPDDEF_EF::ast::node::standard_variant*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::standard_variant_specific_number:
			{
				Listen(static_cast<const DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::value:
			{
				Listen(static_cast<const DLDL_LPDDEF_EF::ast::node::value*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::enum_name:
			{
				Listen(static_cast<const DLDL_LPDDEF_EF::ast::node::enum_name*>(node));
				DefaultAction(node);
				break;
			}
			}
		}
		virtual void Listen(const DLDL_LPDDEF_EF::ast::node::COMMENT* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_EF::ast::node::VARNAME* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_EF::ast::node::NUMBER* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_EF::ast::node::COLON* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_EF::ast::node::SEMICOLON* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Listen(const DLDL_LPDDEF_EF::ast::node::program* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_EF::ast::node::stmt* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_EF::ast::node::comment_line* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_EF::ast::node::standard_variant* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_EF::ast::node::value* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_EF::ast::node::enum_name* node)
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

#endif // DLDL_LPDDEF_EF_AST_LISTENER_DEAMER_LISTENER_H
