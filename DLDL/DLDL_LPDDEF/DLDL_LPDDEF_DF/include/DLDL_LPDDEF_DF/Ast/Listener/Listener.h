#ifndef DLDL_LPDDEF_DF_AST_LISTENER_DEAMER_LISTENER_H
#define DLDL_LPDDEF_DF_AST_LISTENER_DEAMER_LISTENER_H

#include <Deamer/External/Cpp/Ast/Listener.h>
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
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_optional__value_part__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/optional_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value_part.h"
#include "DLDL_LPDDEF_DF/Ast/Node/standard_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value_type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_arrow__value_type__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__COMMA__value_type__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_long_54.h"
#include "DLDL_LPDDEF_DF/Ast/Node/var_type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_arrow__VARNAME__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__COLON__VARNAME__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/var_name.h"

namespace DLDL_LPDDEF_DF { namespace ast { namespace listener { 

	class Listener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		Listener() = default;
		~Listener() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_LPDDEF_DF::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_LPDDEF_DF::ast::Type::LAB:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::LAB*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::RAB:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::RAB*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::LSB:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::LSB*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::RSB:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::RSB*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::EQ:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::EQ*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::COLON:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::COLON*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::LB:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::LB*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::RB:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::RB*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::COMMA:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::COMMA*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::OPTIONAL:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::OPTIONAL*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::VECTOR:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::VECTOR*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::DEAMER_VARNAME:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::COMMENT:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::COMMENT*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::VARNAME:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::VARNAME*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::NUMBER:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::NUMBER*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::STRING:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::STRING*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::SEMICOLON:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::SEMICOLON*>(node));
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::ESCAPE_CHARS:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::program:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::program*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__stmt__:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::stmt:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::stmt*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::comment_line:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::comment_line*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::vector_variant:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::vector_variant*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_optional__value_part__:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_optional__value_part__*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::optional_variant:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::optional_variant*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::value_part:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::value_part*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::standard_variant:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::standard_variant*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::value:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::value*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::value_type:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::value_type*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__value_type__:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COMMA__value_type__:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_long_54:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_long_54*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::var_type:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::var_type*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__VARNAME__:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COLON__VARNAME__:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_LPDDEF_DF::ast::Type::var_name:
			{
				Listen(static_cast<const DLDL_LPDDEF_DF::ast::node::var_name*>(node));
				DefaultAction(node);
				break;
			}
			}
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::LAB* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::RAB* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::LSB* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::RSB* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::EQ* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::COLON* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::LB* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::RB* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::COMMA* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::OPTIONAL* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::VECTOR* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::COMMENT* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::VARNAME* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::NUMBER* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::STRING* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::SEMICOLON* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::program* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::stmt* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::comment_line* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::vector_variant* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::deamerreserved_optional__value_part__* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::optional_variant* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::value_part* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::standard_variant* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::value* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::value_type* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::deamerreserved_long_54* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::var_type* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__* node)
		{
		}
		virtual void Listen(const DLDL_LPDDEF_DF::ast::node::var_name* node)
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

#endif // DLDL_LPDDEF_DF_AST_LISTENER_DEAMER_LISTENER_H
