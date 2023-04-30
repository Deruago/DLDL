#ifndef DLDL_OOPSYNTAX_AST_LISTENER_DEAMER_LISTENER_H
#define DLDL_OOPSYNTAX_AST_LISTENER_DEAMER_LISTENER_H

#include <Deamer/External/Cpp/Ast/Listener.h>
#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include "DLDL_OOPSYNTAX/Ast/Enum/Type.h"
#include "DLDL_OOPSYNTAX/Ast/Node/ARROW.h"
#include "DLDL_OOPSYNTAX/Ast/Node/LEFT_BRACKET.h"
#include "DLDL_OOPSYNTAX/Ast/Node/RIGHT_BRACKET.h"
#include "DLDL_OOPSYNTAX/Ast/Node/DOT.h"
#include "DLDL_OOPSYNTAX/Ast/Node/EQ.h"
#include "DLDL_OOPSYNTAX/Ast/Node/STAR.h"
#include "DLDL_OOPSYNTAX/Ast/Node/VARNAME.h"
#include "DLDL_OOPSYNTAX/Ast/Node/NUMBER.h"
#include "DLDL_OOPSYNTAX/Ast/Node/COMMENT.h"
#include "DLDL_OOPSYNTAX/Ast/Node/ESCAPE_CHAR.h"

#include "DLDL_OOPSYNTAX/Ast/Node/program.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_OOPSYNTAX/Ast/Node/stmt.h"
#include "DLDL_OOPSYNTAX/Ast/Node/nonterminal_conversion.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_long_69.h"
#include "DLDL_OOPSYNTAX/Ast/Node/production_rule_conversion.h"
#include "DLDL_OOPSYNTAX/Ast/Node/numbered_pr_convert.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_long_72.h"
#include "DLDL_OOPSYNTAX/Ast/Node/property_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/direct_property_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_arrow__property__.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_long_76.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_arrow__terminal_name__.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_long_80.h"
#include "DLDL_OOPSYNTAX/Ast/Node/direct_any_property_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/embedded_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/nonterminal_name.h"
#include "DLDL_OOPSYNTAX/Ast/Node/oop_type.h"
#include "DLDL_OOPSYNTAX/Ast/Node/property.h"
#include "DLDL_OOPSYNTAX/Ast/Node/extended_property.h"
#include "DLDL_OOPSYNTAX/Ast/Node/extended_terminal_access.h"
#include "DLDL_OOPSYNTAX/Ast/Node/terminal_name.h"

namespace DLDL_OOPSYNTAX { namespace ast { namespace listener { 

	class Listener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		Listener() = default;
		~Listener() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_OOPSYNTAX::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_OOPSYNTAX::ast::Type::ARROW:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::ARROW*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::LEFT_BRACKET:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::RIGHT_BRACKET:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::DOT:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::DOT*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::EQ:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::EQ*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::STAR:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::STAR*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::VARNAME:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::VARNAME*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::NUMBER:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::NUMBER*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::COMMENT:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::COMMENT*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::ESCAPE_CHAR:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::program:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::program*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__stmt__:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::stmt:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::stmt*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::nonterminal_conversion:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::nonterminal_conversion*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_69:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::production_rule_conversion:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::production_rule_conversion*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::numbered_pr_convert:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::numbered_pr_convert*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_72:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::property_assignment:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::property_assignment*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::direct_property_assignment:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::direct_property_assignment*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_arrow__property__:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_76:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_arrow__terminal_name__:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_80:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::direct_any_property_assignment:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::embedded_assignment:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::embedded_assignment*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::nonterminal_name:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::nonterminal_name*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::oop_type:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::oop_type*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::property:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::property*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::extended_property:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::extended_property*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::extended_terminal_access:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::extended_terminal_access*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::terminal_name:
			{
				Listen(static_cast<const DLDL_OOPSYNTAX::ast::node::terminal_name*>(node));
				DefaultAction(node);
				break;
			}
			}
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::ARROW* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::DOT* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::EQ* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::STAR* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::VARNAME* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::NUMBER* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::COMMENT* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR* node)
		{
		}

		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::program* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::stmt* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::nonterminal_conversion* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::production_rule_conversion* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::numbered_pr_convert* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::property_assignment* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::direct_property_assignment* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::embedded_assignment* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::nonterminal_name* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::oop_type* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::property* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::extended_property* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::extended_terminal_access* node)
		{
		}
		virtual void Listen(const DLDL_OOPSYNTAX::ast::node::terminal_name* node)
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

#endif // DLDL_OOPSYNTAX_AST_LISTENER_DEAMER_LISTENER_H
