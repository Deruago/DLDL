#ifndef DLDL_GENERATION_AST_LISTENER_DEAMER_LISTENER_H
#define DLDL_GENERATION_AST_LISTENER_DEAMER_LISTENER_H

#include <Deamer/External/Cpp/Ast/Listener.h>
#include "DLDL_GENERATION/Ast/Node/DLDL_GENERATION.h"
#include "DLDL_GENERATION/Ast/Enum/Type.h"
#include "DLDL_GENERATION/Ast/Node/GENERATE.h"
#include "DLDL_GENERATION/Ast/Node/INTEGRATE.h"
#include "DLDL_GENERATION/Ast/Node/ARGUMENT.h"
#include "DLDL_GENERATION/Ast/Node/VALUE.h"
#include "DLDL_GENERATION/Ast/Node/SYMBOLS.h"
#include "DLDL_GENERATION/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_GENERATION/Ast/Node/program.h"
#include "DLDL_GENERATION/Ast/Node/stmts.h"
#include "DLDL_GENERATION/Ast/Node/stmt.h"
#include "DLDL_GENERATION/Ast/Node/generate_declaration.h"
#include "DLDL_GENERATION/Ast/Node/integrate_declaration.h"
#include "DLDL_GENERATION/Ast/Node/argument_declaration.h"
#include "DLDL_GENERATION/Ast/Node/type.h"
#include "DLDL_GENERATION/Ast/Node/tool.h"
#include "DLDL_GENERATION/Ast/Node/argument_data.h"

namespace DLDL_GENERATION { namespace ast { namespace listener { 

	class Listener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		Listener() = default;
		~Listener() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_GENERATION::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_GENERATION::ast::Type::GENERATE:
			{
				Listen(static_cast<const DLDL_GENERATION::ast::node::GENERATE*>(node));
				break;
			}
			case DLDL_GENERATION::ast::Type::INTEGRATE:
			{
				Listen(static_cast<const DLDL_GENERATION::ast::node::INTEGRATE*>(node));
				break;
			}
			case DLDL_GENERATION::ast::Type::ARGUMENT:
			{
				Listen(static_cast<const DLDL_GENERATION::ast::node::ARGUMENT*>(node));
				break;
			}
			case DLDL_GENERATION::ast::Type::VALUE:
			{
				Listen(static_cast<const DLDL_GENERATION::ast::node::VALUE*>(node));
				break;
			}
			case DLDL_GENERATION::ast::Type::SYMBOLS:
			{
				Listen(static_cast<const DLDL_GENERATION::ast::node::SYMBOLS*>(node));
				break;
			}
			case DLDL_GENERATION::ast::Type::ESCAPE_CHARS:
			{
				Listen(static_cast<const DLDL_GENERATION::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_GENERATION::ast::Type::program:
			{
				Listen(static_cast<const DLDL_GENERATION::ast::node::program*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_GENERATION::ast::Type::stmts:
			{
				Listen(static_cast<const DLDL_GENERATION::ast::node::stmts*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_GENERATION::ast::Type::stmt:
			{
				Listen(static_cast<const DLDL_GENERATION::ast::node::stmt*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_GENERATION::ast::Type::generate_declaration:
			{
				Listen(static_cast<const DLDL_GENERATION::ast::node::generate_declaration*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_GENERATION::ast::Type::integrate_declaration:
			{
				Listen(static_cast<const DLDL_GENERATION::ast::node::integrate_declaration*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_GENERATION::ast::Type::argument_declaration:
			{
				Listen(static_cast<const DLDL_GENERATION::ast::node::argument_declaration*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_GENERATION::ast::Type::type:
			{
				Listen(static_cast<const DLDL_GENERATION::ast::node::type*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_GENERATION::ast::Type::tool:
			{
				Listen(static_cast<const DLDL_GENERATION::ast::node::tool*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_GENERATION::ast::Type::argument_data:
			{
				Listen(static_cast<const DLDL_GENERATION::ast::node::argument_data*>(node));
				DefaultAction(node);
				break;
			}
			}
		}
		virtual void Listen(const DLDL_GENERATION::ast::node::GENERATE* node)
		{
		}
		virtual void Listen(const DLDL_GENERATION::ast::node::INTEGRATE* node)
		{
		}
		virtual void Listen(const DLDL_GENERATION::ast::node::ARGUMENT* node)
		{
		}
		virtual void Listen(const DLDL_GENERATION::ast::node::VALUE* node)
		{
		}
		virtual void Listen(const DLDL_GENERATION::ast::node::SYMBOLS* node)
		{
		}
		virtual void Listen(const DLDL_GENERATION::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Listen(const DLDL_GENERATION::ast::node::program* node)
		{
		}
		virtual void Listen(const DLDL_GENERATION::ast::node::stmts* node)
		{
		}
		virtual void Listen(const DLDL_GENERATION::ast::node::stmt* node)
		{
		}
		virtual void Listen(const DLDL_GENERATION::ast::node::generate_declaration* node)
		{
		}
		virtual void Listen(const DLDL_GENERATION::ast::node::integrate_declaration* node)
		{
		}
		virtual void Listen(const DLDL_GENERATION::ast::node::argument_declaration* node)
		{
		}
		virtual void Listen(const DLDL_GENERATION::ast::node::type* node)
		{
		}
		virtual void Listen(const DLDL_GENERATION::ast::node::tool* node)
		{
		}
		virtual void Listen(const DLDL_GENERATION::ast::node::argument_data* node)
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

#endif // DLDL_GENERATION_AST_LISTENER_DEAMER_LISTENER_H
