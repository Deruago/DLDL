#ifndef DLDL_GENERATION_AST_VISITOR_DEAMER_VISITOR_H
#define DLDL_GENERATION_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
#include "DLDL_GENERATION/Ast/Node/DLDL_GENERATION.h"
#include "DLDL_GENERATION/Ast/Enum/Type.h"
#include "DLDL_GENERATION/Ast/Node/GENERATE.h"
#include "DLDL_GENERATION/Ast/Node/INTEGRATE.h"
#include "DLDL_GENERATION/Ast/Node/ARGUMENT.h"
#include "DLDL_GENERATION/Ast/Node/VALUE.h"
#include "DLDL_GENERATION/Ast/Node/SYMBOLS.h"
#include "DLDL_GENERATION/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_GENERATION/Ast/Node/program.h"
#include "DLDL_GENERATION/Ast/Node/stmts.h"
#include "DLDL_GENERATION/Ast/Node/stmt.h"
#include "DLDL_GENERATION/Ast/Node/generate_declaration.h"
#include "DLDL_GENERATION/Ast/Node/integrate_declaration.h"
#include "DLDL_GENERATION/Ast/Node/argument_declaration.h"
#include "DLDL_GENERATION/Ast/Node/type.h"
#include "DLDL_GENERATION/Ast/Node/tool.h"
#include "DLDL_GENERATION/Ast/Node/argument_data.h"

namespace DLDL_GENERATION { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_GENERATION::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_GENERATION::ast::Type::GENERATE:
			{
				Visit(static_cast<const DLDL_GENERATION::ast::node::GENERATE*>(node));
				break;
			}
			case DLDL_GENERATION::ast::Type::INTEGRATE:
			{
				Visit(static_cast<const DLDL_GENERATION::ast::node::INTEGRATE*>(node));
				break;
			}
			case DLDL_GENERATION::ast::Type::ARGUMENT:
			{
				Visit(static_cast<const DLDL_GENERATION::ast::node::ARGUMENT*>(node));
				break;
			}
			case DLDL_GENERATION::ast::Type::VALUE:
			{
				Visit(static_cast<const DLDL_GENERATION::ast::node::VALUE*>(node));
				break;
			}
			case DLDL_GENERATION::ast::Type::SYMBOLS:
			{
				Visit(static_cast<const DLDL_GENERATION::ast::node::SYMBOLS*>(node));
				break;
			}
			case DLDL_GENERATION::ast::Type::ESCAPE_CHARS:
			{
				Visit(static_cast<const DLDL_GENERATION::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_GENERATION::ast::Type::program:
			{
				Visit(static_cast<const DLDL_GENERATION::ast::node::program*>(node));
				break;
			}
			case DLDL_GENERATION::ast::Type::stmts:
			{
				Visit(static_cast<const DLDL_GENERATION::ast::node::stmts*>(node));
				break;
			}
			case DLDL_GENERATION::ast::Type::stmt:
			{
				Visit(static_cast<const DLDL_GENERATION::ast::node::stmt*>(node));
				break;
			}
			case DLDL_GENERATION::ast::Type::generate_declaration:
			{
				Visit(static_cast<const DLDL_GENERATION::ast::node::generate_declaration*>(node));
				break;
			}
			case DLDL_GENERATION::ast::Type::integrate_declaration:
			{
				Visit(static_cast<const DLDL_GENERATION::ast::node::integrate_declaration*>(node));
				break;
			}
			case DLDL_GENERATION::ast::Type::argument_declaration:
			{
				Visit(static_cast<const DLDL_GENERATION::ast::node::argument_declaration*>(node));
				break;
			}
			case DLDL_GENERATION::ast::Type::type:
			{
				Visit(static_cast<const DLDL_GENERATION::ast::node::type*>(node));
				break;
			}
			case DLDL_GENERATION::ast::Type::tool:
			{
				Visit(static_cast<const DLDL_GENERATION::ast::node::tool*>(node));
				break;
			}
			case DLDL_GENERATION::ast::Type::argument_data:
			{
				Visit(static_cast<const DLDL_GENERATION::ast::node::argument_data*>(node));
				break;
			}
			}
		}
		virtual void Visit(const DLDL_GENERATION::ast::node::GENERATE* node)
		{
		}
		virtual void Visit(const DLDL_GENERATION::ast::node::INTEGRATE* node)
		{
		}
		virtual void Visit(const DLDL_GENERATION::ast::node::ARGUMENT* node)
		{
		}
		virtual void Visit(const DLDL_GENERATION::ast::node::VALUE* node)
		{
		}
		virtual void Visit(const DLDL_GENERATION::ast::node::SYMBOLS* node)
		{
		}
		virtual void Visit(const DLDL_GENERATION::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Visit(const DLDL_GENERATION::ast::node::program* node)
		{
		}
		virtual void Visit(const DLDL_GENERATION::ast::node::stmts* node)
		{
		}
		virtual void Visit(const DLDL_GENERATION::ast::node::stmt* node)
		{
		}
		virtual void Visit(const DLDL_GENERATION::ast::node::generate_declaration* node)
		{
		}
		virtual void Visit(const DLDL_GENERATION::ast::node::integrate_declaration* node)
		{
		}
		virtual void Visit(const DLDL_GENERATION::ast::node::argument_declaration* node)
		{
		}
		virtual void Visit(const DLDL_GENERATION::ast::node::type* node)
		{
		}
		virtual void Visit(const DLDL_GENERATION::ast::node::tool* node)
		{
		}
		virtual void Visit(const DLDL_GENERATION::ast::node::argument_data* node)
		{
		}
	};

}}}

#endif // DLDL_GENERATION_AST_VISITOR_DEAMER_VISITOR_H
