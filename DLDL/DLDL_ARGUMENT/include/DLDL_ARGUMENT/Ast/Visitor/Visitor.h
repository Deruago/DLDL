#ifndef DLDL_ARGUMENT_AST_VISITOR_DEAMER_VISITOR_H
#define DLDL_ARGUMENT_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
#include "DLDL_ARGUMENT/Ast/Node/DLDL_ARGUMENT.h"
#include "DLDL_ARGUMENT/Ast/Enum/Type.h"
#include "DLDL_ARGUMENT/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_ARGUMENT/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_ARGUMENT/Ast/Node/TEXT.h"
#include "DLDL_ARGUMENT/Ast/Node/VARNAME.h"
#include "DLDL_ARGUMENT/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_ARGUMENT/Ast/Node/program.h"

namespace DLDL_ARGUMENT { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_ARGUMENT::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_ARGUMENT::ast::Type::SINGLE_COMMENT:
			{
				Visit(static_cast<const DLDL_ARGUMENT::ast::node::SINGLE_COMMENT*>(node));
				break;
			}
			case DLDL_ARGUMENT::ast::Type::MULTI_COMMENT:
			{
				Visit(static_cast<const DLDL_ARGUMENT::ast::node::MULTI_COMMENT*>(node));
				break;
			}
			case DLDL_ARGUMENT::ast::Type::TEXT:
			{
				Visit(static_cast<const DLDL_ARGUMENT::ast::node::TEXT*>(node));
				break;
			}
			case DLDL_ARGUMENT::ast::Type::VARNAME:
			{
				Visit(static_cast<const DLDL_ARGUMENT::ast::node::VARNAME*>(node));
				break;
			}
			case DLDL_ARGUMENT::ast::Type::ESCAPE_CHARS:
			{
				Visit(static_cast<const DLDL_ARGUMENT::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_ARGUMENT::ast::Type::program:
			{
				Visit(static_cast<const DLDL_ARGUMENT::ast::node::program*>(node));
				break;
			}
			}
		}
		virtual void Visit(const DLDL_ARGUMENT::ast::node::SINGLE_COMMENT* node)
		{
		}
		virtual void Visit(const DLDL_ARGUMENT::ast::node::MULTI_COMMENT* node)
		{
		}
		virtual void Visit(const DLDL_ARGUMENT::ast::node::TEXT* node)
		{
		}
		virtual void Visit(const DLDL_ARGUMENT::ast::node::VARNAME* node)
		{
		}
		virtual void Visit(const DLDL_ARGUMENT::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Visit(const DLDL_ARGUMENT::ast::node::program* node)
		{
		}
	};

}}}

#endif // DLDL_ARGUMENT_AST_VISITOR_DEAMER_VISITOR_H
