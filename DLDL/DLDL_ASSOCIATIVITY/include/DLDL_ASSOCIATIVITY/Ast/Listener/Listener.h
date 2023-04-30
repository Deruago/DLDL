#ifndef DLDL_ASSOCIATIVITY_AST_LISTENER_DEAMER_LISTENER_H
#define DLDL_ASSOCIATIVITY_AST_LISTENER_DEAMER_LISTENER_H

#include <Deamer/External/Cpp/Ast/Listener.h>
#include "DLDL_ASSOCIATIVITY/Ast/Node/DLDL_ASSOCIATIVITY.h"
#include "DLDL_ASSOCIATIVITY/Ast/Enum/Type.h"
#include "DLDL_ASSOCIATIVITY/Ast/Node/ASSOCIATIVITY.h"

#include "DLDL_ASSOCIATIVITY/Ast/Node/program.h"
#include "DLDL_ASSOCIATIVITY/Ast/Node/stmts.h"
#include "DLDL_ASSOCIATIVITY/Ast/Node/stmt.h"

namespace DLDL_ASSOCIATIVITY { namespace ast { namespace listener { 

	class Listener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		Listener() = default;
		~Listener() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_ASSOCIATIVITY::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_ASSOCIATIVITY::ast::Type::ASSOCIATIVITY:
			{
				Listen(static_cast<const DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY*>(node));
				break;
			}

			case DLDL_ASSOCIATIVITY::ast::Type::program:
			{
				Listen(static_cast<const DLDL_ASSOCIATIVITY::ast::node::program*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_ASSOCIATIVITY::ast::Type::stmts:
			{
				Listen(static_cast<const DLDL_ASSOCIATIVITY::ast::node::stmts*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_ASSOCIATIVITY::ast::Type::stmt:
			{
				Listen(static_cast<const DLDL_ASSOCIATIVITY::ast::node::stmt*>(node));
				DefaultAction(node);
				break;
			}
			}
		}
		virtual void Listen(const DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY* node)
		{
		}

		virtual void Listen(const DLDL_ASSOCIATIVITY::ast::node::program* node)
		{
		}
		virtual void Listen(const DLDL_ASSOCIATIVITY::ast::node::stmts* node)
		{
		}
		virtual void Listen(const DLDL_ASSOCIATIVITY::ast::node::stmt* node)
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

#endif // DLDL_ASSOCIATIVITY_AST_LISTENER_DEAMER_LISTENER_H
