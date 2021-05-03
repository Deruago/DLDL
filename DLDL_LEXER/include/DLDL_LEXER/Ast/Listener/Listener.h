#ifndef DLDL_LEXER_AST_LISTENER_DEAMER_LISTENER_H
#define DLDL_LEXER_AST_LISTENER_DEAMER_LISTENER_H

#include <Deamer/External/Cpp/Ast/Listener.h>
#include "DLDL_LEXER/Ast/Node/DLDL_LEXER.h"
#include "DLDL_LEXER/Ast/Enum/Type.h"
#include "DLDL_LEXER/Ast/Node/COMMENT.h"
#include "DLDL_LEXER/Ast/Node/DELETE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/IGNORE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/NOVALUE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/CRASH_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/STANDARD_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/UNKNOWN_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/TERMINAL.h"
#include "DLDL_LEXER/Ast/Node/REGEX.h"
#include "DLDL_LEXER/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_LEXER/Ast/Node/program.h"
#include "DLDL_LEXER/Ast/Node/stmts.h"
#include "DLDL_LEXER/Ast/Node/stmt.h"
#include "DLDL_LEXER/Ast/Node/tokendeclaration.h"
#include "DLDL_LEXER/Ast/Node/abstraction.h"

namespace DLDL_LEXER { namespace ast { namespace listener { 

	class Listener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		Listener() = default;
		~Listener() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) const override
		{
			const auto enumeratedValue = static_cast<DLDL_LEXER::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_LEXER::ast::Type::COMMENT:
			{
				Listen(static_cast<const DLDL_LEXER::ast::node::COMMENT*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::DELETE_ABSTRACTION:
			{
				Listen(static_cast<const DLDL_LEXER::ast::node::DELETE_ABSTRACTION*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::IGNORE_ABSTRACTION:
			{
				Listen(static_cast<const DLDL_LEXER::ast::node::IGNORE_ABSTRACTION*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::NOVALUE_ABSTRACTION:
			{
				Listen(static_cast<const DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::CRASH_ABSTRACTION:
			{
				Listen(static_cast<const DLDL_LEXER::ast::node::CRASH_ABSTRACTION*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::STANDARD_ABSTRACTION:
			{
				Listen(static_cast<const DLDL_LEXER::ast::node::STANDARD_ABSTRACTION*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::UNKNOWN_ABSTRACTION:
			{
				Listen(static_cast<const DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::TERMINAL:
			{
				Listen(static_cast<const DLDL_LEXER::ast::node::TERMINAL*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::REGEX:
			{
				Listen(static_cast<const DLDL_LEXER::ast::node::REGEX*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::ESCAPE_CHARS:
			{
				Listen(static_cast<const DLDL_LEXER::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_LEXER::ast::Type::program:
			{
				Listen(static_cast<const DLDL_LEXER::ast::node::program*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LEXER::ast::Type::stmts:
			{
				Listen(static_cast<const DLDL_LEXER::ast::node::stmts*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LEXER::ast::Type::stmt:
			{
				Listen(static_cast<const DLDL_LEXER::ast::node::stmt*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LEXER::ast::Type::tokendeclaration:
			{
				Listen(static_cast<const DLDL_LEXER::ast::node::tokendeclaration*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LEXER::ast::Type::abstraction:
			{
				Listen(static_cast<const DLDL_LEXER::ast::node::abstraction*>(node));
				DefaultAction(node);
				break;
			}
			}
		}
		virtual void Listen(const DLDL_LEXER::ast::node::COMMENT* node) const
		{
		}
		virtual void Listen(const DLDL_LEXER::ast::node::DELETE_ABSTRACTION* node) const
		{
		}
		virtual void Listen(const DLDL_LEXER::ast::node::IGNORE_ABSTRACTION* node) const
		{
		}
		virtual void Listen(const DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION* node) const
		{
		}
		virtual void Listen(const DLDL_LEXER::ast::node::CRASH_ABSTRACTION* node) const
		{
		}
		virtual void Listen(const DLDL_LEXER::ast::node::STANDARD_ABSTRACTION* node) const
		{
		}
		virtual void Listen(const DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION* node) const
		{
		}
		virtual void Listen(const DLDL_LEXER::ast::node::TERMINAL* node) const
		{
		}
		virtual void Listen(const DLDL_LEXER::ast::node::REGEX* node) const
		{
		}
		virtual void Listen(const DLDL_LEXER::ast::node::ESCAPE_CHARS* node) const
		{
		}

		virtual void Listen(const DLDL_LEXER::ast::node::program* node) const
		{
		}
		virtual void Listen(const DLDL_LEXER::ast::node::stmts* node) const
		{
		}
		virtual void Listen(const DLDL_LEXER::ast::node::stmt* node) const
		{
		}
		virtual void Listen(const DLDL_LEXER::ast::node::tokendeclaration* node) const
		{
		}
		virtual void Listen(const DLDL_LEXER::ast::node::abstraction* node) const
		{
		}
	private:
		void DefaultAction(const ::deamer::external::cpp::ast::Node* node) const
		{
			for(const auto* child : node->GetNodes())
			{
				Dispatch(child);
			}
		}
	};

}}}

#endif // DLDL_LEXER_AST_LISTENER_DEAMER_LISTENER_H
