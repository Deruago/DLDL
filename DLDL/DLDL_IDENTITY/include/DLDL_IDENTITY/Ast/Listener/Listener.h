#ifndef DLDL_IDENTITY_AST_LISTENER_DEAMER_LISTENER_H
#define DLDL_IDENTITY_AST_LISTENER_DEAMER_LISTENER_H

#include <Deamer/External/Cpp/Ast/Listener.h>
#include "DLDL_IDENTITY/Ast/Node/DLDL_IDENTITY.h"
#include "DLDL_IDENTITY/Ast/Enum/Type.h"
#include "DLDL_IDENTITY/Ast/Node/NAME.h"
#include "DLDL_IDENTITY/Ast/Node/VALUE.h"
#include "DLDL_IDENTITY/Ast/Node/SYMBOLS.h"
#include "DLDL_IDENTITY/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_IDENTITY/Ast/Node/program.h"
#include "DLDL_IDENTITY/Ast/Node/stmts.h"
#include "DLDL_IDENTITY/Ast/Node/stmt.h"
#include "DLDL_IDENTITY/Ast/Node/name_declaration.h"

namespace DLDL_IDENTITY { namespace ast { namespace listener { 

	class Listener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		Listener() = default;
		~Listener() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_IDENTITY::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_IDENTITY::ast::Type::NAME:
			{
				Listen(static_cast<const DLDL_IDENTITY::ast::node::NAME*>(node));
				break;
			}
			case DLDL_IDENTITY::ast::Type::VALUE:
			{
				Listen(static_cast<const DLDL_IDENTITY::ast::node::VALUE*>(node));
				break;
			}
			case DLDL_IDENTITY::ast::Type::SYMBOLS:
			{
				Listen(static_cast<const DLDL_IDENTITY::ast::node::SYMBOLS*>(node));
				break;
			}
			case DLDL_IDENTITY::ast::Type::ESCAPE_CHARS:
			{
				Listen(static_cast<const DLDL_IDENTITY::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_IDENTITY::ast::Type::program:
			{
				Listen(static_cast<const DLDL_IDENTITY::ast::node::program*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_IDENTITY::ast::Type::stmts:
			{
				Listen(static_cast<const DLDL_IDENTITY::ast::node::stmts*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_IDENTITY::ast::Type::stmt:
			{
				Listen(static_cast<const DLDL_IDENTITY::ast::node::stmt*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_IDENTITY::ast::Type::name_declaration:
			{
				Listen(static_cast<const DLDL_IDENTITY::ast::node::name_declaration*>(node));
				DefaultAction(node);
				break;
			}
			}
		}
		virtual void Listen(const DLDL_IDENTITY::ast::node::NAME* node)
		{
		}
		virtual void Listen(const DLDL_IDENTITY::ast::node::VALUE* node)
		{
		}
		virtual void Listen(const DLDL_IDENTITY::ast::node::SYMBOLS* node)
		{
		}
		virtual void Listen(const DLDL_IDENTITY::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Listen(const DLDL_IDENTITY::ast::node::program* node)
		{
		}
		virtual void Listen(const DLDL_IDENTITY::ast::node::stmts* node)
		{
		}
		virtual void Listen(const DLDL_IDENTITY::ast::node::stmt* node)
		{
		}
		virtual void Listen(const DLDL_IDENTITY::ast::node::name_declaration* node)
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

#endif // DLDL_IDENTITY_AST_LISTENER_DEAMER_LISTENER_H
