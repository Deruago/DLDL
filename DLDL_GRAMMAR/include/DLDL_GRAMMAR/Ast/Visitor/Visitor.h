#ifndef DLDL_GRAMMAR_AST_VISITOR_DEAMER_VISITOR_H
#define DLDL_GRAMMAR_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
#include "DLDL_GRAMMAR/Ast/Node/DLDL_GRAMMAR.h"
#include "DLDL_GRAMMAR/Ast/Enum/Type.h"
#include "DLDL_GRAMMAR/Ast/Node/COMMENT.h"
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

namespace DLDL_GRAMMAR { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_GRAMMAR::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_GRAMMAR::ast::Type::COMMENT:
			{
				Visit(static_cast<const DLDL_GRAMMAR::ast::node::COMMENT*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::START_ABSTRACTION:
			{
				Visit(static_cast<const DLDL_GRAMMAR::ast::node::START_ABSTRACTION*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::GROUP_ABSTRACTION:
			{
				Visit(static_cast<const DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::INLINE_ABSTRACTION:
			{
				Visit(static_cast<const DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::INLINE_GROUP_ABSTRACTION:
			{
				Visit(static_cast<const DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::UNKNOWN_ABSTRACTION:
			{
				Visit(static_cast<const DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::NONTERMINAL:
			{
				Visit(static_cast<const DLDL_GRAMMAR::ast::node::NONTERMINAL*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::PRODUCTION_RULE:
			{
				Visit(static_cast<const DLDL_GRAMMAR::ast::node::PRODUCTION_RULE*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::ESCAPE_CHARS:
			{
				Visit(static_cast<const DLDL_GRAMMAR::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_GRAMMAR::ast::Type::program:
			{
				Visit(static_cast<const DLDL_GRAMMAR::ast::node::program*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::stmts:
			{
				Visit(static_cast<const DLDL_GRAMMAR::ast::node::stmts*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::stmt:
			{
				Visit(static_cast<const DLDL_GRAMMAR::ast::node::stmt*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::abstraction_declaration:
			{
				Visit(static_cast<const DLDL_GRAMMAR::ast::node::abstraction_declaration*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::abstraction:
			{
				Visit(static_cast<const DLDL_GRAMMAR::ast::node::abstraction*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::definition:
			{
				Visit(static_cast<const DLDL_GRAMMAR::ast::node::definition*>(node));
				break;
			}
			case DLDL_GRAMMAR::ast::Type::production_rules:
			{
				Visit(static_cast<const DLDL_GRAMMAR::ast::node::production_rules*>(node));
				break;
			}
			}
		}
		virtual void Visit(const DLDL_GRAMMAR::ast::node::COMMENT* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR::ast::node::START_ABSTRACTION* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR::ast::node::NONTERMINAL* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR::ast::node::PRODUCTION_RULE* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Visit(const DLDL_GRAMMAR::ast::node::program* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR::ast::node::stmts* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR::ast::node::stmt* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR::ast::node::abstraction_declaration* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR::ast::node::abstraction* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR::ast::node::definition* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR::ast::node::production_rules* node)
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_VISITOR_DEAMER_VISITOR_H
