#ifndef DLDL_IDENTITY_AST_VISITOR_DEAMER_VISITOR_H
#define DLDL_IDENTITY_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
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

namespace DLDL_IDENTITY { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_IDENTITY::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_IDENTITY::ast::Type::NAME:
			{
				Visit(static_cast<const DLDL_IDENTITY::ast::node::NAME*>(node));
				break;
			}
			case DLDL_IDENTITY::ast::Type::VALUE:
			{
				Visit(static_cast<const DLDL_IDENTITY::ast::node::VALUE*>(node));
				break;
			}
			case DLDL_IDENTITY::ast::Type::SYMBOLS:
			{
				Visit(static_cast<const DLDL_IDENTITY::ast::node::SYMBOLS*>(node));
				break;
			}
			case DLDL_IDENTITY::ast::Type::ESCAPE_CHARS:
			{
				Visit(static_cast<const DLDL_IDENTITY::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_IDENTITY::ast::Type::program:
			{
				Visit(static_cast<const DLDL_IDENTITY::ast::node::program*>(node));
				break;
			}
			case DLDL_IDENTITY::ast::Type::stmts:
			{
				Visit(static_cast<const DLDL_IDENTITY::ast::node::stmts*>(node));
				break;
			}
			case DLDL_IDENTITY::ast::Type::stmt:
			{
				Visit(static_cast<const DLDL_IDENTITY::ast::node::stmt*>(node));
				break;
			}
			case DLDL_IDENTITY::ast::Type::name_declaration:
			{
				Visit(static_cast<const DLDL_IDENTITY::ast::node::name_declaration*>(node));
				break;
			}
			}
		}
		virtual void Visit(const DLDL_IDENTITY::ast::node::NAME* node)
		{
		}
		virtual void Visit(const DLDL_IDENTITY::ast::node::VALUE* node)
		{
		}
		virtual void Visit(const DLDL_IDENTITY::ast::node::SYMBOLS* node)
		{
		}
		virtual void Visit(const DLDL_IDENTITY::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Visit(const DLDL_IDENTITY::ast::node::program* node)
		{
		}
		virtual void Visit(const DLDL_IDENTITY::ast::node::stmts* node)
		{
		}
		virtual void Visit(const DLDL_IDENTITY::ast::node::stmt* node)
		{
		}
		virtual void Visit(const DLDL_IDENTITY::ast::node::name_declaration* node)
		{
		}
	};

}}}

#endif // DLDL_IDENTITY_AST_VISITOR_DEAMER_VISITOR_H
