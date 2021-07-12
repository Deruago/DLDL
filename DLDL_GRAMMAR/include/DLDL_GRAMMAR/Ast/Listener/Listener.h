#ifndef DLDL_GRAMMAR_AST_LISTENER_DEAMER_LISTENER_H
#define DLDL_GRAMMAR_AST_LISTENER_DEAMER_LISTENER_H

#include <Deamer/External/Cpp/Ast/Listener.h>
#include "DLDL_GRAMMAR/Ast/Node/DLDL_GRAMMAR.h"
#include "DLDL_GRAMMAR/Ast/Enum/Type.h"
#include "DLDL_GRAMMAR/Ast/Node/COMMENT.h"
#include "DLDL_GRAMMAR/Ast/Node/MULTI_LINE_COMMENT.h"
#include "DLDL_GRAMMAR/Ast/Node/START_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/GROUP_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/INLINE_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/INLINE_GROUP_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/UNKNOWN_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/NONTERMINAL.h"
#include "DLDL_GRAMMAR/Ast/Node/PRODUCTION_RULE.h"
#include "DLDL_GRAMMAR/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_GRAMMAR/Ast/Node/program.h"
#include "DLDL_GRAMMAR/Ast/Node/stmts.h"
#include "DLDL_GRAMMAR/Ast/Node/stmt.h"
#include "DLDL_GRAMMAR/Ast/Node/abstraction_declaration.h"
#include "DLDL_GRAMMAR/Ast/Node/abstraction.h"
#include "DLDL_GRAMMAR/Ast/Node/definition.h"
#include "DLDL_GRAMMAR/Ast/Node/production_rules.h"

namespace DLDL_GRAMMAR { namespace ast { namespace listener { 

	class Listener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		Listener() = default;
		~Listener() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_GRAMMAR::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_GRAMMAR::ast::Type::COMMENT:
			{
				Listen(static_cast<const DLDL_GRAMMAR::ast::node::COMMENT*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::MULTI_LINE_COMMENT:
			{
				Listen(static_cast<const DLDL_GRAMMAR::ast::node::MULTI_LINE_COMMENT*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::START_ABSTRACTION:
			{
				Listen(static_cast<const DLDL_GRAMMAR::ast::node::START_ABSTRACTION*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::GROUP_ABSTRACTION:
			{
				Listen(static_cast<const DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::INLINE_ABSTRACTION:
			{
				Listen(static_cast<const DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::INLINE_GROUP_ABSTRACTION:
			{
				Listen(static_cast<const DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::UNKNOWN_ABSTRACTION:
			{
				Listen(static_cast<const DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::NONTERMINAL:
			{
				Listen(static_cast<const DLDL_GRAMMAR::ast::node::NONTERMINAL*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::PRODUCTION_RULE:
			{
				Listen(static_cast<const DLDL_GRAMMAR::ast::node::PRODUCTION_RULE*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::ESCAPE_CHARS:
			{
				Listen(static_cast<const DLDL_GRAMMAR::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_GRAMMAR::ast::Type::program:
			{
				Listen(static_cast<const DLDL_GRAMMAR::ast::node::program*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_GRAMMAR::ast::Type::stmts:
			{
				Listen(static_cast<const DLDL_GRAMMAR::ast::node::stmts*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_GRAMMAR::ast::Type::stmt:
			{
				Listen(static_cast<const DLDL_GRAMMAR::ast::node::stmt*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_GRAMMAR::ast::Type::abstraction_declaration:
			{
				Listen(static_cast<const DLDL_GRAMMAR::ast::node::abstraction_declaration*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_GRAMMAR::ast::Type::abstraction:
			{
				Listen(static_cast<const DLDL_GRAMMAR::ast::node::abstraction*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_GRAMMAR::ast::Type::definition:
			{
				Listen(static_cast<const DLDL_GRAMMAR::ast::node::definition*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_GRAMMAR::ast::Type::production_rules:
			{
				Listen(static_cast<const DLDL_GRAMMAR::ast::node::production_rules*>(node));
				DefaultAction(node);
				break;
			}
			}
		}
		virtual void Listen(const DLDL_GRAMMAR::ast::node::COMMENT* node)
		{
		}
		virtual void Listen(const DLDL_GRAMMAR::ast::node::MULTI_LINE_COMMENT* node)
		{
		}
		virtual void Listen(const DLDL_GRAMMAR::ast::node::START_ABSTRACTION* node)
		{
		}
		virtual void Listen(const DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION* node)
		{
		}
		virtual void Listen(const DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION* node)
		{
		}
		virtual void Listen(const DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION* node)
		{
		}
		virtual void Listen(const DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION* node)
		{
		}
		virtual void Listen(const DLDL_GRAMMAR::ast::node::NONTERMINAL* node)
		{
		}
		virtual void Listen(const DLDL_GRAMMAR::ast::node::PRODUCTION_RULE* node)
		{
		}
		virtual void Listen(const DLDL_GRAMMAR::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Listen(const DLDL_GRAMMAR::ast::node::program* node)
		{
		}
		virtual void Listen(const DLDL_GRAMMAR::ast::node::stmts* node)
		{
		}
		virtual void Listen(const DLDL_GRAMMAR::ast::node::stmt* node)
		{
		}
		virtual void Listen(const DLDL_GRAMMAR::ast::node::abstraction_declaration* node)
		{
		}
		virtual void Listen(const DLDL_GRAMMAR::ast::node::abstraction* node)
		{
		}
		virtual void Listen(const DLDL_GRAMMAR::ast::node::definition* node)
		{
		}
		virtual void Listen(const DLDL_GRAMMAR::ast::node::production_rules* node)
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

#endif // DLDL_GRAMMAR_AST_LISTENER_DEAMER_LISTENER_H
