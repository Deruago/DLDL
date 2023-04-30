#ifndef DLDL_ARGUMENT_AST_LISTENER_DEAMER_LISTENER_H
#define DLDL_ARGUMENT_AST_LISTENER_DEAMER_LISTENER_H

#include <Deamer/External/Cpp/Ast/Listener.h>
#include "DLDL_ARGUMENT/Ast/Node/DLDL_ARGUMENT.h"
#include "DLDL_ARGUMENT/Ast/Enum/Type.h"
#include "DLDL_ARGUMENT/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_ARGUMENT/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_ARGUMENT/Ast/Node/TEXT.h"
#include "DLDL_ARGUMENT/Ast/Node/VARNAME.h"
#include "DLDL_ARGUMENT/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_ARGUMENT/Ast/Node/program.h"

namespace DLDL_ARGUMENT { namespace ast { namespace listener { 

	class Listener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		Listener() = default;
		~Listener() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_ARGUMENT::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_ARGUMENT::ast::Type::SINGLE_COMMENT:
			{
				Listen(static_cast<const DLDL_ARGUMENT::ast::node::SINGLE_COMMENT*>(node));
				break;
			}
			case DLDL_ARGUMENT::ast::Type::MULTI_COMMENT:
			{
				Listen(static_cast<const DLDL_ARGUMENT::ast::node::MULTI_COMMENT*>(node));
				break;
			}
			case DLDL_ARGUMENT::ast::Type::TEXT:
			{
				Listen(static_cast<const DLDL_ARGUMENT::ast::node::TEXT*>(node));
				break;
			}
			case DLDL_ARGUMENT::ast::Type::VARNAME:
			{
				Listen(static_cast<const DLDL_ARGUMENT::ast::node::VARNAME*>(node));
				break;
			}
			case DLDL_ARGUMENT::ast::Type::ESCAPE_CHARS:
			{
				Listen(static_cast<const DLDL_ARGUMENT::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_ARGUMENT::ast::Type::program:
			{
				Listen(static_cast<const DLDL_ARGUMENT::ast::node::program*>(node));
				DefaultAction(node);
				break;
			}
			}
		}
		virtual void Listen(const DLDL_ARGUMENT::ast::node::SINGLE_COMMENT* node)
		{
		}
		virtual void Listen(const DLDL_ARGUMENT::ast::node::MULTI_COMMENT* node)
		{
		}
		virtual void Listen(const DLDL_ARGUMENT::ast::node::TEXT* node)
		{
		}
		virtual void Listen(const DLDL_ARGUMENT::ast::node::VARNAME* node)
		{
		}
		virtual void Listen(const DLDL_ARGUMENT::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Listen(const DLDL_ARGUMENT::ast::node::program* node)
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

#endif // DLDL_ARGUMENT_AST_LISTENER_DEAMER_LISTENER_H
