#ifndef DLDL_OOPSYNTAX_AST_VISITOR_DEAMER_VISITOR_H
#define DLDL_OOPSYNTAX_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
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

namespace DLDL_OOPSYNTAX { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_OOPSYNTAX::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_OOPSYNTAX::ast::Type::ARROW:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::ARROW*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::LEFT_BRACKET:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::RIGHT_BRACKET:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::DOT:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::DOT*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::EQ:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::EQ*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::STAR:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::STAR*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::VARNAME:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::VARNAME*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::NUMBER:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::NUMBER*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::COMMENT:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::COMMENT*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::ESCAPE_CHAR:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::program:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::program*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__stmt__:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::stmt:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::stmt*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::nonterminal_conversion:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::nonterminal_conversion*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_69:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::production_rule_conversion:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::production_rule_conversion*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::numbered_pr_convert:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::numbered_pr_convert*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_72:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::property_assignment:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::property_assignment*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::direct_property_assignment:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::direct_property_assignment*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_arrow__property__:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_76:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_arrow__terminal_name__:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_80:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::direct_any_property_assignment:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::embedded_assignment:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::embedded_assignment*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::nonterminal_name:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::nonterminal_name*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::oop_type:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::oop_type*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::property:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::property*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::extended_property:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::extended_property*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::extended_terminal_access:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::extended_terminal_access*>(node));
				break;
			}
			case DLDL_OOPSYNTAX::ast::Type::terminal_name:
			{
				Visit(static_cast<const DLDL_OOPSYNTAX::ast::node::terminal_name*>(node));
				break;
			}
			}
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::ARROW* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::DOT* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::EQ* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::STAR* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::VARNAME* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::NUMBER* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::COMMENT* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR* node)
		{
		}

		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::program* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::stmt* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::nonterminal_conversion* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::production_rule_conversion* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::numbered_pr_convert* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::property_assignment* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::direct_property_assignment* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::embedded_assignment* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::nonterminal_name* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::oop_type* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::property* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::extended_property* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::extended_terminal_access* node)
		{
		}
		virtual void Visit(const DLDL_OOPSYNTAX::ast::node::terminal_name* node)
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_VISITOR_DEAMER_VISITOR_H
