#ifndef DLDL_IMPORT_AST_VISITOR_DEAMER_VISITOR_H
#define DLDL_IMPORT_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include "DLDL_IMPORT/Ast/Enum/Type.h"
#include "DLDL_IMPORT/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_IMPORT/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_IMPORT/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_IMPORT/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_IMPORT/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_IMPORT/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_IMPORT/Ast/Node/COLON.h"
#include "DLDL_IMPORT/Ast/Node/DOT.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT_FILE.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT_MODULE.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT.h"
#include "DLDL_IMPORT/Ast/Node/TEXT.h"
#include "DLDL_IMPORT/Ast/Node/VARNAME.h"
#include "DLDL_IMPORT/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_IMPORT/Ast/Node/program.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_IMPORT/Ast/Node/stmt.h"
#include "DLDL_IMPORT/Ast/Node/import_declaration.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_arrow__import_context__.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_long_40.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_long_43.h"
#include "DLDL_IMPORT/Ast/Node/specialization.h"
#include "DLDL_IMPORT/Ast/Node/import_abstraction.h"
#include "DLDL_IMPORT/Ast/Node/value.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_optional__VARNAME__.h"
#include "DLDL_IMPORT/Ast/Node/abstraction.h"
#include "DLDL_IMPORT/Ast/Node/import_context.h"
#include "DLDL_IMPORT/Ast/Node/import_rule_name.h"

namespace DLDL_IMPORT { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_IMPORT::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_IMPORT::ast::Type::SINGLE_COMMENT:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::SINGLE_COMMENT*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::MULTI_COMMENT:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::MULTI_COMMENT*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::LEFT_PARANTHESIS:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::LEFT_PARANTHESIS*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::RIGHT_PARANTHESIS:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::LEFT_SQUARE_BRACKET:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::COLON:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::COLON*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::DOT:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::DOT*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::IMPORT_FILE:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::IMPORT_FILE*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::IMPORT_MODULE:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::IMPORT_MODULE*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::IMPORT:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::IMPORT*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::TEXT:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::TEXT*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::VARNAME:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::VARNAME*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::ESCAPE_CHARS:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::program:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::program*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::deamerreserved_star__stmt__:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::stmt:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::stmt*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::import_declaration:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::import_declaration*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::deamerreserved_arrow__import_context__:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::deamerreserved_long_40:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_long_40*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::deamerreserved_long_43:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_long_43*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::specialization:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::specialization*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::import_abstraction:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::import_abstraction*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::value:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::value*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::deamerreserved_optional__VARNAME__:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::abstraction:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::abstraction*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::import_context:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::import_context*>(node));
				break;
			}
			case DLDL_IMPORT::ast::Type::import_rule_name:
			{
				Visit(static_cast<const DLDL_IMPORT::ast::node::import_rule_name*>(node));
				break;
			}
			}
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::SINGLE_COMMENT* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::MULTI_COMMENT* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::LEFT_PARANTHESIS* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::COLON* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::DOT* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::IMPORT_FILE* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::IMPORT_MODULE* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::IMPORT* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::TEXT* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::VARNAME* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Visit(const DLDL_IMPORT::ast::node::program* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::stmt* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::import_declaration* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::deamerreserved_long_40* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::deamerreserved_long_43* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::specialization* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::import_abstraction* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::value* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::abstraction* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::import_context* node)
		{
		}
		virtual void Visit(const DLDL_IMPORT::ast::node::import_rule_name* node)
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_VISITOR_DEAMER_VISITOR_H
