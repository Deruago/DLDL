#ifndef DLDL_LPDSTRUCT_AST_VISITOR_DEAMER_VISITOR_H
#define DLDL_LPDSTRUCT_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
#include "DLDL_LPDSTRUCT/Ast/Node/DLDL_LPDSTRUCT.h"
#include "DLDL_LPDSTRUCT/Ast/Enum/Type.h"
#include "DLDL_LPDSTRUCT/Ast/Node/COLON.h"
#include "DLDL_LPDSTRUCT/Ast/Node/LEFT_ANGLE_BRACKET.h"
#include "DLDL_LPDSTRUCT/Ast/Node/RIGHT_ANGLE_BRACKET.h"
#include "DLDL_LPDSTRUCT/Ast/Node/VARNAME.h"
#include "DLDL_LPDSTRUCT/Ast/Node/VARNAME_EXT.h"
#include "DLDL_LPDSTRUCT/Ast/Node/INDENTED_VALUE.h"
#include "DLDL_LPDSTRUCT/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_LPDSTRUCT/Ast/Node/program.h"
#include "DLDL_LPDSTRUCT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDSTRUCT/Ast/Node/stmt.h"
#include "DLDL_LPDSTRUCT/Ast/Node/argument.h"
#include "DLDL_LPDSTRUCT/Ast/Node/argument_name.h"
#include "DLDL_LPDSTRUCT/Ast/Node/argument_block.h"
#include "DLDL_LPDSTRUCT/Ast/Node/deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______.h"

namespace DLDL_LPDSTRUCT { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_LPDSTRUCT::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_LPDSTRUCT::ast::Type::COLON:
			{
				Visit(static_cast<const DLDL_LPDSTRUCT::ast::node::COLON*>(node));
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::LEFT_ANGLE_BRACKET:
			{
				Visit(static_cast<const DLDL_LPDSTRUCT::ast::node::LEFT_ANGLE_BRACKET*>(node));
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::RIGHT_ANGLE_BRACKET:
			{
				Visit(static_cast<const DLDL_LPDSTRUCT::ast::node::RIGHT_ANGLE_BRACKET*>(node));
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::VARNAME:
			{
				Visit(static_cast<const DLDL_LPDSTRUCT::ast::node::VARNAME*>(node));
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::VARNAME_EXT:
			{
				Visit(static_cast<const DLDL_LPDSTRUCT::ast::node::VARNAME_EXT*>(node));
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::INDENTED_VALUE:
			{
				Visit(static_cast<const DLDL_LPDSTRUCT::ast::node::INDENTED_VALUE*>(node));
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::ESCAPE_CHARS:
			{
				Visit(static_cast<const DLDL_LPDSTRUCT::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::program:
			{
				Visit(static_cast<const DLDL_LPDSTRUCT::ast::node::program*>(node));
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__stmt__:
			{
				Visit(static_cast<const DLDL_LPDSTRUCT::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::stmt:
			{
				Visit(static_cast<const DLDL_LPDSTRUCT::ast::node::stmt*>(node));
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::argument:
			{
				Visit(static_cast<const DLDL_LPDSTRUCT::ast::node::argument*>(node));
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::argument_name:
			{
				Visit(static_cast<const DLDL_LPDSTRUCT::ast::node::argument_name*>(node));
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::argument_block:
			{
				Visit(static_cast<const DLDL_LPDSTRUCT::ast::node::argument_block*>(node));
				break;
			}
			case DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______:
			{
				Visit(static_cast<const DLDL_LPDSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______*>(node));
				break;
			}
			}
		}
		virtual void Visit(const DLDL_LPDSTRUCT::ast::node::COLON* node)
		{
		}
		virtual void Visit(const DLDL_LPDSTRUCT::ast::node::LEFT_ANGLE_BRACKET* node)
		{
		}
		virtual void Visit(const DLDL_LPDSTRUCT::ast::node::RIGHT_ANGLE_BRACKET* node)
		{
		}
		virtual void Visit(const DLDL_LPDSTRUCT::ast::node::VARNAME* node)
		{
		}
		virtual void Visit(const DLDL_LPDSTRUCT::ast::node::VARNAME_EXT* node)
		{
		}
		virtual void Visit(const DLDL_LPDSTRUCT::ast::node::INDENTED_VALUE* node)
		{
		}
		virtual void Visit(const DLDL_LPDSTRUCT::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Visit(const DLDL_LPDSTRUCT::ast::node::program* node)
		{
		}
		virtual void Visit(const DLDL_LPDSTRUCT::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Visit(const DLDL_LPDSTRUCT::ast::node::stmt* node)
		{
		}
		virtual void Visit(const DLDL_LPDSTRUCT::ast::node::argument* node)
		{
		}
		virtual void Visit(const DLDL_LPDSTRUCT::ast::node::argument_name* node)
		{
		}
		virtual void Visit(const DLDL_LPDSTRUCT::ast::node::argument_block* node)
		{
		}
		virtual void Visit(const DLDL_LPDSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______* node)
		{
		}
	};

}}}

#endif // DLDL_LPDSTRUCT_AST_VISITOR_DEAMER_VISITOR_H
