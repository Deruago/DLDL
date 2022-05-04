#ifndef DLDL_PRECEDENCE_AST_LISTENER_DEAMER_LISTENER_H
#define DLDL_PRECEDENCE_AST_LISTENER_DEAMER_LISTENER_H

#include <Deamer/External/Cpp/Ast/Listener.h>
#include "DLDL_PRECEDENCE/Ast/Node/DLDL_PRECEDENCE.h"
#include "DLDL_PRECEDENCE/Ast/Enum/Type.h"
#include "DLDL_PRECEDENCE/Ast/Node/PRECEDENCE.h"
#include "DLDL_PRECEDENCE/Ast/Node/NUMBER.h"
#include "DLDL_PRECEDENCE/Ast/Node/TERMINAL.h"
#include "DLDL_PRECEDENCE/Ast/Node/SYMBOLS.h"
#include "DLDL_PRECEDENCE/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_PRECEDENCE/Ast/Node/program.h"
#include "DLDL_PRECEDENCE/Ast/Node/stmts.h"
#include "DLDL_PRECEDENCE/Ast/Node/stmt.h"
#include "DLDL_PRECEDENCE/Ast/Node/localized_precedence.h"
#include "DLDL_PRECEDENCE/Ast/Node/specific_precedence.h"
#include "DLDL_PRECEDENCE/Ast/Node/terminal_one_or_more.h"

namespace DLDL_PRECEDENCE { namespace ast { namespace listener { 

	class Listener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		Listener() = default;
		~Listener() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_PRECEDENCE::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_PRECEDENCE::ast::Type::PRECEDENCE:
			{
				Listen(static_cast<const DLDL_PRECEDENCE::ast::node::PRECEDENCE*>(node));
				break;
			}
			case DLDL_PRECEDENCE::ast::Type::NUMBER:
			{
				Listen(static_cast<const DLDL_PRECEDENCE::ast::node::NUMBER*>(node));
				break;
			}
			case DLDL_PRECEDENCE::ast::Type::TERMINAL:
			{
				Listen(static_cast<const DLDL_PRECEDENCE::ast::node::TERMINAL*>(node));
				break;
			}
			case DLDL_PRECEDENCE::ast::Type::SYMBOLS:
			{
				Listen(static_cast<const DLDL_PRECEDENCE::ast::node::SYMBOLS*>(node));
				break;
			}
			case DLDL_PRECEDENCE::ast::Type::ESCAPE_CHARS:
			{
				Listen(static_cast<const DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::program:
			{
				Listen(static_cast<const DLDL_PRECEDENCE::ast::node::program*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_PRECEDENCE::ast::Type::stmts:
			{
				Listen(static_cast<const DLDL_PRECEDENCE::ast::node::stmts*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_PRECEDENCE::ast::Type::stmt:
			{
				Listen(static_cast<const DLDL_PRECEDENCE::ast::node::stmt*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_PRECEDENCE::ast::Type::localized_precedence:
			{
				Listen(static_cast<const DLDL_PRECEDENCE::ast::node::localized_precedence*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_PRECEDENCE::ast::Type::specific_precedence:
			{
				Listen(static_cast<const DLDL_PRECEDENCE::ast::node::specific_precedence*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_PRECEDENCE::ast::Type::terminal_one_or_more:
			{
				Listen(static_cast<const DLDL_PRECEDENCE::ast::node::terminal_one_or_more*>(node));
				DefaultAction(node);
				break;
			}
			}
		}
		virtual void Listen(const DLDL_PRECEDENCE::ast::node::PRECEDENCE* node)
		{
		}
		virtual void Listen(const DLDL_PRECEDENCE::ast::node::NUMBER* node)
		{
		}
		virtual void Listen(const DLDL_PRECEDENCE::ast::node::TERMINAL* node)
		{
		}
		virtual void Listen(const DLDL_PRECEDENCE::ast::node::SYMBOLS* node)
		{
		}
		virtual void Listen(const DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Listen(const DLDL_PRECEDENCE::ast::node::program* node)
		{
		}
		virtual void Listen(const DLDL_PRECEDENCE::ast::node::stmts* node)
		{
		}
		virtual void Listen(const DLDL_PRECEDENCE::ast::node::stmt* node)
		{
		}
		virtual void Listen(const DLDL_PRECEDENCE::ast::node::localized_precedence* node)
		{
		}
		virtual void Listen(const DLDL_PRECEDENCE::ast::node::specific_precedence* node)
		{
		}
		virtual void Listen(const DLDL_PRECEDENCE::ast::node::terminal_one_or_more* node)
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

#endif // DLDL_PRECEDENCE_AST_LISTENER_DEAMER_LISTENER_H
