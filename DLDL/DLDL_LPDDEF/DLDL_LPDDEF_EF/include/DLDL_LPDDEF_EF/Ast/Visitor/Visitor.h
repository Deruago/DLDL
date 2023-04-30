#ifndef DLDL_LPDDEF_EF_AST_VISITOR_DEAMER_VISITOR_H
#define DLDL_LPDDEF_EF_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
#include "DLDL_LPDDEF_EF/Ast/Node/DLDL_LPDDEF_EF.h"
#include "DLDL_LPDDEF_EF/Ast/Enum/Type.h"
#include "DLDL_LPDDEF_EF/Ast/Node/COMMENT.h"
#include "DLDL_LPDDEF_EF/Ast/Node/VARNAME.h"
#include "DLDL_LPDDEF_EF/Ast/Node/NUMBER.h"
#include "DLDL_LPDDEF_EF/Ast/Node/COLON.h"
#include "DLDL_LPDDEF_EF/Ast/Node/SEMICOLON.h"
#include "DLDL_LPDDEF_EF/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_LPDDEF_EF/Ast/Node/program.h"
#include "DLDL_LPDDEF_EF/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDDEF_EF/Ast/Node/stmt.h"
#include "DLDL_LPDDEF_EF/Ast/Node/comment_line.h"
#include "DLDL_LPDDEF_EF/Ast/Node/standard_variant.h"
#include "DLDL_LPDDEF_EF/Ast/Node/standard_variant_specific_number.h"
#include "DLDL_LPDDEF_EF/Ast/Node/value.h"
#include "DLDL_LPDDEF_EF/Ast/Node/enum_name.h"

namespace DLDL_LPDDEF_EF { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_LPDDEF_EF::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_LPDDEF_EF::ast::Type::COMMENT:
			{
				Visit(static_cast<const DLDL_LPDDEF_EF::ast::node::COMMENT*>(node));
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::VARNAME:
			{
				Visit(static_cast<const DLDL_LPDDEF_EF::ast::node::VARNAME*>(node));
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::NUMBER:
			{
				Visit(static_cast<const DLDL_LPDDEF_EF::ast::node::NUMBER*>(node));
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::COLON:
			{
				Visit(static_cast<const DLDL_LPDDEF_EF::ast::node::COLON*>(node));
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::SEMICOLON:
			{
				Visit(static_cast<const DLDL_LPDDEF_EF::ast::node::SEMICOLON*>(node));
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::ESCAPE_CHARS:
			{
				Visit(static_cast<const DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::program:
			{
				Visit(static_cast<const DLDL_LPDDEF_EF::ast::node::program*>(node));
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::deamerreserved_star__stmt__:
			{
				Visit(static_cast<const DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::stmt:
			{
				Visit(static_cast<const DLDL_LPDDEF_EF::ast::node::stmt*>(node));
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::comment_line:
			{
				Visit(static_cast<const DLDL_LPDDEF_EF::ast::node::comment_line*>(node));
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::standard_variant:
			{
				Visit(static_cast<const DLDL_LPDDEF_EF::ast::node::standard_variant*>(node));
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::standard_variant_specific_number:
			{
				Visit(static_cast<const DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number*>(node));
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::value:
			{
				Visit(static_cast<const DLDL_LPDDEF_EF::ast::node::value*>(node));
				break;
			}
			case DLDL_LPDDEF_EF::ast::Type::enum_name:
			{
				Visit(static_cast<const DLDL_LPDDEF_EF::ast::node::enum_name*>(node));
				break;
			}
			}
		}
		virtual void Visit(const DLDL_LPDDEF_EF::ast::node::COMMENT* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_EF::ast::node::VARNAME* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_EF::ast::node::NUMBER* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_EF::ast::node::COLON* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_EF::ast::node::SEMICOLON* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Visit(const DLDL_LPDDEF_EF::ast::node::program* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_EF::ast::node::stmt* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_EF::ast::node::comment_line* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_EF::ast::node::standard_variant* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_EF::ast::node::value* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_EF::ast::node::enum_name* node)
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_EF_AST_VISITOR_DEAMER_VISITOR_H
