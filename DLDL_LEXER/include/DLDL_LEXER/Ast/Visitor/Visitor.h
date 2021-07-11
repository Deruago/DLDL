#ifndef DLDL_LEXER_AST_VISITOR_DEAMER_VISITOR_H
#define DLDL_LEXER_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
#include "DLDL_LEXER/Ast/Node/DLDL_LEXER.h"
#include "DLDL_LEXER/Ast/Enum/Type.h"
#include "DLDL_LEXER/Ast/Node/DELETE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/IGNORE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/NOVALUE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/CRASH_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/STANDARD_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/UNKNOWN_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/TERMINAL.h"
#include "DLDL_LEXER/Ast/Node/REGEX.h"
#include "DLDL_LEXER/Ast/Node/ESCAPE_CHARS.h"
#include "DLDL_LEXER/Ast/Node/COMMENT.h"

#include "DLDL_LEXER/Ast/Node/program.h"
#include "DLDL_LEXER/Ast/Node/stmts.h"
#include "DLDL_LEXER/Ast/Node/stmt.h"
#include "DLDL_LEXER/Ast/Node/tokendeclaration.h"
#include "DLDL_LEXER/Ast/Node/abstraction.h"

namespace DLDL_LEXER { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_LEXER::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_LEXER::ast::Type::DELETE_ABSTRACTION:
			{
				Visit(static_cast<const DLDL_LEXER::ast::node::DELETE_ABSTRACTION*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::IGNORE_ABSTRACTION:
			{
				Visit(static_cast<const DLDL_LEXER::ast::node::IGNORE_ABSTRACTION*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::NOVALUE_ABSTRACTION:
			{
				Visit(static_cast<const DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::CRASH_ABSTRACTION:
			{
				Visit(static_cast<const DLDL_LEXER::ast::node::CRASH_ABSTRACTION*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::STANDARD_ABSTRACTION:
			{
				Visit(static_cast<const DLDL_LEXER::ast::node::STANDARD_ABSTRACTION*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::UNKNOWN_ABSTRACTION:
			{
				Visit(static_cast<const DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::TERMINAL:
			{
				Visit(static_cast<const DLDL_LEXER::ast::node::TERMINAL*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::REGEX:
			{
				Visit(static_cast<const DLDL_LEXER::ast::node::REGEX*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::ESCAPE_CHARS:
			{
				Visit(static_cast<const DLDL_LEXER::ast::node::ESCAPE_CHARS*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::COMMENT:
			{
				Visit(static_cast<const DLDL_LEXER::ast::node::COMMENT*>(node));
				break;
			}

			case DLDL_LEXER::ast::Type::program:
			{
				Visit(static_cast<const DLDL_LEXER::ast::node::program*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::stmts:
			{
				Visit(static_cast<const DLDL_LEXER::ast::node::stmts*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::stmt:
			{
				Visit(static_cast<const DLDL_LEXER::ast::node::stmt*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::tokendeclaration:
			{
				Visit(static_cast<const DLDL_LEXER::ast::node::tokendeclaration*>(node));
				break;
			}
			case DLDL_LEXER::ast::Type::abstraction:
			{
				Visit(static_cast<const DLDL_LEXER::ast::node::abstraction*>(node));
				break;
			}
			}
		}
		virtual void Visit(const DLDL_LEXER::ast::node::DELETE_ABSTRACTION* node)
		{
		}
		virtual void Visit(const DLDL_LEXER::ast::node::IGNORE_ABSTRACTION* node)
		{
		}
		virtual void Visit(const DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION* node)
		{
		}
		virtual void Visit(const DLDL_LEXER::ast::node::CRASH_ABSTRACTION* node)
		{
		}
		virtual void Visit(const DLDL_LEXER::ast::node::STANDARD_ABSTRACTION* node)
		{
		}
		virtual void Visit(const DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION* node)
		{
		}
		virtual void Visit(const DLDL_LEXER::ast::node::TERMINAL* node)
		{
		}
		virtual void Visit(const DLDL_LEXER::ast::node::REGEX* node)
		{
		}
		virtual void Visit(const DLDL_LEXER::ast::node::ESCAPE_CHARS* node)
		{
		}
		virtual void Visit(const DLDL_LEXER::ast::node::COMMENT* node)
		{
		}

		virtual void Visit(const DLDL_LEXER::ast::node::program* node)
		{
		}
		virtual void Visit(const DLDL_LEXER::ast::node::stmts* node)
		{
		}
		virtual void Visit(const DLDL_LEXER::ast::node::stmt* node)
		{
		}
		virtual void Visit(const DLDL_LEXER::ast::node::tokendeclaration* node)
		{
		}
		virtual void Visit(const DLDL_LEXER::ast::node::abstraction* node)
		{
		}
	};

}}}

#endif // DLDL_LEXER_AST_VISITOR_DEAMER_VISITOR_H
