#ifndef DLDL_AST_VISITOR_DEAMER_VISITOR_H
#define DLDL_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
#include "DLDL/Ast/Node/DLDL.h"
#include "DLDL/Ast/Enum/Type.h"
#include "DLDL/Ast/Node/ANY.h"

#include "DLDL/Ast/Node/program.h"
#include "DLDL/Ast/Node/stmts.h"
#include "DLDL/Ast/Node/stmt.h"

namespace DLDL { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL::ast::Type::ANY:
			{
				Visit(static_cast<const DLDL::ast::node::ANY*>(node));
				break;
			}

			case DLDL::ast::Type::program:
			{
				Visit(static_cast<const DLDL::ast::node::program*>(node));
				break;
			}
			case DLDL::ast::Type::stmts:
			{
				Visit(static_cast<const DLDL::ast::node::stmts*>(node));
				break;
			}
			case DLDL::ast::Type::stmt:
			{
				Visit(static_cast<const DLDL::ast::node::stmt*>(node));
				break;
			}
			}
		}
		virtual void Visit(const DLDL::ast::node::ANY* node)
		{
		}

		virtual void Visit(const DLDL::ast::node::program* node)
		{
		}
		virtual void Visit(const DLDL::ast::node::stmts* node)
		{
		}
		virtual void Visit(const DLDL::ast::node::stmt* node)
		{
		}
	};

}}}

#endif // DLDL_AST_VISITOR_DEAMER_VISITOR_H
