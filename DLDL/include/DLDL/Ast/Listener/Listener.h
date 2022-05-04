#ifndef DLDL_AST_LISTENER_DEAMER_LISTENER_H
#define DLDL_AST_LISTENER_DEAMER_LISTENER_H

#include <Deamer/External/Cpp/Ast/Listener.h>
#include "DLDL/Ast/Node/DLDL.h"
#include "DLDL/Ast/Enum/Type.h"
#include "DLDL/Ast/Node/ANY.h"

#include "DLDL/Ast/Node/program.h"
#include "DLDL/Ast/Node/stmts.h"
#include "DLDL/Ast/Node/stmt.h"

namespace DLDL { namespace ast { namespace listener { 

	class Listener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		Listener() = default;
		~Listener() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL::ast::Type::ANY:
			{
				Listen(static_cast<const DLDL::ast::node::ANY*>(node));
				break;
			}

			case DLDL::ast::Type::program:
			{
				Listen(static_cast<const DLDL::ast::node::program*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL::ast::Type::stmts:
			{
				Listen(static_cast<const DLDL::ast::node::stmts*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL::ast::Type::stmt:
			{
				Listen(static_cast<const DLDL::ast::node::stmt*>(node));
				DefaultAction(node);
				break;
			}
			}
		}
		virtual void Listen(const DLDL::ast::node::ANY* node)
		{
		}

		virtual void Listen(const DLDL::ast::node::program* node)
		{
		}
		virtual void Listen(const DLDL::ast::node::stmts* node)
		{
		}
		virtual void Listen(const DLDL::ast::node::stmt* node)
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

#endif // DLDL_AST_LISTENER_DEAMER_LISTENER_H
