#ifndef DLDL_ASSOCIATIVITY_AST_VISITOR_DEAMER_VISITOR_H
#define DLDL_ASSOCIATIVITY_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
#include "DLDL_ASSOCIATIVITY/Ast/Node/DLDL_ASSOCIATIVITY.h"
#include "DLDL_ASSOCIATIVITY/Ast/Enum/Type.h"
#include "DLDL_ASSOCIATIVITY/Ast/Node/ASSOCIATIVITY.h"

#include "DLDL_ASSOCIATIVITY/Ast/Node/program.h"
#include "DLDL_ASSOCIATIVITY/Ast/Node/stmts.h"
#include "DLDL_ASSOCIATIVITY/Ast/Node/stmt.h"

namespace DLDL_ASSOCIATIVITY { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_ASSOCIATIVITY::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_ASSOCIATIVITY::ast::Type::ASSOCIATIVITY:
			{
				Visit(static_cast<const DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY*>(node));
				break;
			}

			case DLDL_ASSOCIATIVITY::ast::Type::program:
			{
				Visit(static_cast<const DLDL_ASSOCIATIVITY::ast::node::program*>(node));
				break;
			}
			case DLDL_ASSOCIATIVITY::ast::Type::stmts:
			{
				Visit(static_cast<const DLDL_ASSOCIATIVITY::ast::node::stmts*>(node));
				break;
			}
			case DLDL_ASSOCIATIVITY::ast::Type::stmt:
			{
				Visit(static_cast<const DLDL_ASSOCIATIVITY::ast::node::stmt*>(node));
				break;
			}
			}
		}
		virtual void Visit(const DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY* node)
		{
		}

		virtual void Visit(const DLDL_ASSOCIATIVITY::ast::node::program* node)
		{
		}
		virtual void Visit(const DLDL_ASSOCIATIVITY::ast::node::stmts* node)
		{
		}
		virtual void Visit(const DLDL_ASSOCIATIVITY::ast::node::stmt* node)
		{
		}
	};

}}}

#endif // DLDL_ASSOCIATIVITY_AST_VISITOR_DEAMER_VISITOR_H
