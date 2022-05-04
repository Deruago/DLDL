#ifndef DLDL_LPDDEF_AST_VISITOR_DEAMER_VISITOR_H
#define DLDL_LPDDEF_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
#include "DLDL_LPDDEF/Ast/Node/DLDL_LPDDEF.h"
#include "DLDL_LPDDEF/Ast/Enum/Type.h"
#include "DLDL_LPDDEF/Ast/Node/COLON.h"
#include "DLDL_LPDDEF/Ast/Node/LEFT_ANGLE_BRACKET.h"
#include "DLDL_LPDDEF/Ast/Node/RIGHT_ANGLE_BRACKET.h"
#include "DLDL_LPDDEF/Ast/Node/VARNAME.h"
#include "DLDL_LPDDEF/Ast/Node/INDENTED_VALUE.h"
#include "DLDL_LPDDEF/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_LPDDEF/Ast/Node/program.h"
#include "DLDL_LPDDEF/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDDEF/Ast/Node/stmt.h"
#include "DLDL_LPDDEF/Ast/Node/argument.h"
#include "DLDL_LPDDEF/Ast/Node/argument_name.h"
#include "DLDL_LPDDEF/Ast/Node/argument_block.h"
#include "DLDL_LPDDEF/Ast/Node/deamerreserved_star__argument_stmt__.h"
#include "DLDL_LPDDEF/Ast/Node/argument_stmt.h"

namespace DLDL_LPDDEF { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_LPDDEF::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_LPDDEF::ast::Type::COLON:
			{
				Visit(static_cast<const DLDL_LPDDEF::ast::node::COLON*>(node));
				break;
			}
			case DLDL_LPDDEF::ast::Type::LEFT_ANGLE_BRACKET:
			{
				Visit(static_cast<const DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET*>(node));
				break;
			}
			case DLDL_LPDDEF::ast::Type::RIGHT_ANGLE_BRACKET:
			{
				Visit(static_cast<const DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET*>(node));
				break;
			}
			case DLDL_LPDDEF::ast::Type::VARNAME:
			{
				Visit(static_cast<const DLDL_LPDDEF::ast::node::VARNAME*>(node));
				break;
			}
			case DLDL_LPDDEF::ast::Type::INDENTED_VALUE:
			{
				Visit(static_cast<const DLDL_LPDDEF::ast::node::INDENTED_VALUE*>(node));
				break;
			}
			case DLDL_LPDDEF::ast::Type::ESCAPE_CHARS:
			{
				Visit(static_cast<const DLDL_LPDDEF::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_LPDDEF::ast::Type::program:
			{
				Visit(static_cast<const DLDL_LPDDEF::ast::node::program*>(node));
				break;
			}
			case DLDL_LPDDEF::ast::Type::deamerreserved_star__stmt__:
			{
				Visit(static_cast<const DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}
			case DLDL_LPDDEF::ast::Type::stmt:
			{
				Visit(static_cast<const DLDL_LPDDEF::ast::node::stmt*>(node));
				break;
			}
			case DLDL_LPDDEF::ast::Type::argument:
			{
				Visit(static_cast<const DLDL_LPDDEF::ast::node::argument*>(node));
				break;
			}
			case DLDL_LPDDEF::ast::Type::argument_name:
			{
				Visit(static_cast<const DLDL_LPDDEF::ast::node::argument_name*>(node));
				break;
			}
			case DLDL_LPDDEF::ast::Type::argument_block:
			{
				Visit(static_cast<const DLDL_LPDDEF::ast::node::argument_block*>(node));
				break;
			}
			case DLDL_LPDDEF::ast::Type::deamerreserved_star__argument_stmt__:
			{
				Visit(static_cast<const DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__*>(node));
				break;
			}
			case DLDL_LPDDEF::ast::Type::argument_stmt:
			{
				Visit(static_cast<const DLDL_LPDDEF::ast::node::argument_stmt*>(node));
				break;
			}
			}
		}
		virtual void Visit(const DLDL_LPDDEF::ast::node::COLON* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF::ast::node::VARNAME* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF::ast::node::INDENTED_VALUE* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Visit(const DLDL_LPDDEF::ast::node::program* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF::ast::node::stmt* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF::ast::node::argument* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF::ast::node::argument_name* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF::ast::node::argument_block* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF::ast::node::argument_stmt* node)
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_AST_VISITOR_DEAMER_VISITOR_H
