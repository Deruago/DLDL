#ifndef DLDL_LPDDEF_DF_AST_VISITOR_DEAMER_VISITOR_H
#define DLDL_LPDDEF_DF_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include "DLDL_LPDDEF_DF/Ast/Enum/Type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/LAB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RAB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/LSB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RSB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/EQ.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COLON.h"
#include "DLDL_LPDDEF_DF/Ast/Node/LB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COMMA.h"
#include "DLDL_LPDDEF_DF/Ast/Node/OPTIONAL.h"
#include "DLDL_LPDDEF_DF/Ast/Node/VECTOR.h"
#include "DLDL_LPDDEF_DF/Ast/Node/DEAMER_VARNAME.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COMMENT.h"
#include "DLDL_LPDDEF_DF/Ast/Node/VARNAME.h"
#include "DLDL_LPDDEF_DF/Ast/Node/NUMBER.h"
#include "DLDL_LPDDEF_DF/Ast/Node/STRING.h"
#include "DLDL_LPDDEF_DF/Ast/Node/SEMICOLON.h"
#include "DLDL_LPDDEF_DF/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_LPDDEF_DF/Ast/Node/program.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/stmt.h"
#include "DLDL_LPDDEF_DF/Ast/Node/comment_line.h"
#include "DLDL_LPDDEF_DF/Ast/Node/vector_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/optional_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value_part.h"
#include "DLDL_LPDDEF_DF/Ast/Node/standard_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value_type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_arrow__value_type__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__COMMA__value_type__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/var_type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_arrow__VARNAME__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__COLON__VARNAME__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/var_name.h"

namespace DLDL_LPDDEF_DF { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_LPDDEF_DF::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_LPDDEF_DF::ast::Type::LAB:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::LAB*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::RAB:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::RAB*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::LSB:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::LSB*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::RSB:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::RSB*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::EQ:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::EQ*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::COLON:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::COLON*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::LB:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::LB*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::RB:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::RB*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::COMMA:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::COMMA*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::OPTIONAL:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::OPTIONAL*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::VECTOR:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::VECTOR*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::DEAMER_VARNAME:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::COMMENT:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::COMMENT*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::VARNAME:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::VARNAME*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::NUMBER:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::NUMBER*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::STRING:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::STRING*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::SEMICOLON:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::SEMICOLON*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::ESCAPE_CHARS:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::program:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::program*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__stmt__:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::stmt:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::stmt*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::comment_line:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::comment_line*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::vector_variant:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::vector_variant*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::optional_variant:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::optional_variant*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::value_part:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::value_part*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::standard_variant:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::standard_variant*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::value:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::value*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::value_type:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::value_type*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__value_type__:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COMMA__value_type__:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::var_type:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::var_type*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__VARNAME__:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COLON__VARNAME__:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::var_name:
			{
				Visit(static_cast<const DLDL_LPDDEF_DF::ast::node::var_name*>(node));
				break;
			}
			}
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::LAB* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::RAB* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::LSB* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::RSB* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::EQ* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::COLON* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::LB* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::RB* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::COMMA* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::OPTIONAL* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::VECTOR* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::COMMENT* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::VARNAME* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::NUMBER* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::STRING* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::SEMICOLON* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::program* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::stmt* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::comment_line* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::vector_variant* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::optional_variant* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::value_part* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::standard_variant* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::value* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::value_type* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::var_type* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__* node)
		{
		}
		virtual void Visit(const DLDL_LPDDEF_DF::ast::node::var_name* node)
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_VISITOR_DEAMER_VISITOR_H
