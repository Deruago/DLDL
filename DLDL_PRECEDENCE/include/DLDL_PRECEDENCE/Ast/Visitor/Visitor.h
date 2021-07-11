#ifndef DLDL_PRECEDENCE_AST_VISITOR_DEAMER_VISITOR_H
#define DLDL_PRECEDENCE_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
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

namespace DLDL_PRECEDENCE { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_PRECEDENCE::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_PRECEDENCE::ast::Type::PRECEDENCE:
			{
				Visit(static_cast<const DLDL_PRECEDENCE::ast::node::PRECEDENCE*>(node));
				break;
			}
			case DLDL_PRECEDENCE::ast::Type::NUMBER:
			{
				Visit(static_cast<const DLDL_PRECEDENCE::ast::node::NUMBER*>(node));
				break;
			}
			case DLDL_PRECEDENCE::ast::Type::TERMINAL:
			{
				Visit(static_cast<const DLDL_PRECEDENCE::ast::node::TERMINAL*>(node));
				break;
			}
			case DLDL_PRECEDENCE::ast::Type::SYMBOLS:
			{
				Visit(static_cast<const DLDL_PRECEDENCE::ast::node::SYMBOLS*>(node));
				break;
			}
			case DLDL_PRECEDENCE::ast::Type::ESCAPE_CHARS:
			{
				Visit(static_cast<const DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::program:
			{
				Visit(static_cast<const DLDL_PRECEDENCE::ast::node::program*>(node));
				break;
			}
			case DLDL_PRECEDENCE::ast::Type::stmts:
			{
				Visit(static_cast<const DLDL_PRECEDENCE::ast::node::stmts*>(node));
				break;
			}
			case DLDL_PRECEDENCE::ast::Type::stmt:
			{
				Visit(static_cast<const DLDL_PRECEDENCE::ast::node::stmt*>(node));
				break;
			}
			case DLDL_PRECEDENCE::ast::Type::localized_precedence:
			{
				Visit(static_cast<const DLDL_PRECEDENCE::ast::node::localized_precedence*>(node));
				break;
			}
			case DLDL_PRECEDENCE::ast::Type::specific_precedence:
			{
				Visit(static_cast<const DLDL_PRECEDENCE::ast::node::specific_precedence*>(node));
				break;
			}
			case DLDL_PRECEDENCE::ast::Type::terminal_one_or_more:
			{
				Visit(static_cast<const DLDL_PRECEDENCE::ast::node::terminal_one_or_more*>(node));
				break;
			}
			}
		}
		virtual void Visit(const DLDL_PRECEDENCE::ast::node::PRECEDENCE* node)
		{
		}
		virtual void Visit(const DLDL_PRECEDENCE::ast::node::NUMBER* node)
		{
		}
		virtual void Visit(const DLDL_PRECEDENCE::ast::node::TERMINAL* node)
		{
		}
		virtual void Visit(const DLDL_PRECEDENCE::ast::node::SYMBOLS* node)
		{
		}
		virtual void Visit(const DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Visit(const DLDL_PRECEDENCE::ast::node::program* node)
		{
		}
		virtual void Visit(const DLDL_PRECEDENCE::ast::node::stmts* node)
		{
		}
		virtual void Visit(const DLDL_PRECEDENCE::ast::node::stmt* node)
		{
		}
		virtual void Visit(const DLDL_PRECEDENCE::ast::node::localized_precedence* node)
		{
		}
		virtual void Visit(const DLDL_PRECEDENCE::ast::node::specific_precedence* node)
		{
		}
		virtual void Visit(const DLDL_PRECEDENCE::ast::node::terminal_one_or_more* node)
		{
		}
	};

}}}

#endif // DLDL_PRECEDENCE_AST_VISITOR_DEAMER_VISITOR_H
