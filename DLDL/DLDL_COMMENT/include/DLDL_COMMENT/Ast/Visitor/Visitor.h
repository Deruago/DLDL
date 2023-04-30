#ifndef DLDL_COMMENT_AST_VISITOR_DEAMER_VISITOR_H
#define DLDL_COMMENT_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
#include "DLDL_COMMENT/Ast/Node/DLDL_COMMENT.h"
#include "DLDL_COMMENT/Ast/Enum/Type.h"
#include "DLDL_COMMENT/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_COMMENT/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_COMMENT/Ast/Node/COMMENT_VALUE.h"
#include "DLDL_COMMENT/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_COMMENT/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_COMMENT/Ast/Node/START.h"
#include "DLDL_COMMENT/Ast/Node/END.h"
#include "DLDL_COMMENT/Ast/Node/TEXT.h"
#include "DLDL_COMMENT/Ast/Node/VARNAME.h"
#include "DLDL_COMMENT/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_COMMENT/Ast/Node/program.h"
#include "DLDL_COMMENT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_COMMENT/Ast/Node/stmt.h"
#include "DLDL_COMMENT/Ast/Node/comment_value_declaration.h"
#include "DLDL_COMMENT/Ast/Node/deamerreserved_long_3.h"
#include "DLDL_COMMENT/Ast/Node/deamerreserved_long_6.h"
#include "DLDL_COMMENT/Ast/Node/comment_abstraction.h"
#include "DLDL_COMMENT/Ast/Node/start_abstraction.h"
#include "DLDL_COMMENT/Ast/Node/end_abstraction.h"
#include "DLDL_COMMENT/Ast/Node/start_sequence.h"
#include "DLDL_COMMENT/Ast/Node/end_sequence.h"
#include "DLDL_COMMENT/Ast/Node/sequence.h"
#include "DLDL_COMMENT/Ast/Node/syntactic_reference.h"

namespace DLDL_COMMENT { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_COMMENT::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_COMMENT::ast::Type::SINGLE_COMMENT:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::SINGLE_COMMENT*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::MULTI_COMMENT:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::MULTI_COMMENT*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::COMMENT_VALUE:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::COMMENT_VALUE*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::LEFT_SQUARE_BRACKET:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::START:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::START*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::END:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::END*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::TEXT:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::TEXT*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::VARNAME:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::VARNAME*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::ESCAPE_CHARS:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::program:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::program*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::deamerreserved_star__stmt__:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::stmt:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::stmt*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::comment_value_declaration:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::comment_value_declaration*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::deamerreserved_long_3:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::deamerreserved_long_3*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::deamerreserved_long_6:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::deamerreserved_long_6*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::comment_abstraction:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::comment_abstraction*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::start_abstraction:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::start_abstraction*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::end_abstraction:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::end_abstraction*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::start_sequence:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::start_sequence*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::end_sequence:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::end_sequence*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::sequence:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::sequence*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::syntactic_reference:
			{
				Visit(static_cast<const DLDL_COMMENT::ast::node::syntactic_reference*>(node));
				break;
			}
			}
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::SINGLE_COMMENT* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::MULTI_COMMENT* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::COMMENT_VALUE* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::START* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::END* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::TEXT* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::VARNAME* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Visit(const DLDL_COMMENT::ast::node::program* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::stmt* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::comment_value_declaration* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::deamerreserved_long_3* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::deamerreserved_long_6* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::comment_abstraction* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::start_abstraction* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::end_abstraction* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::start_sequence* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::end_sequence* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::sequence* node)
		{
		}
		virtual void Visit(const DLDL_COMMENT::ast::node::syntactic_reference* node)
		{
		}
	};

}}}

#endif // DLDL_COMMENT_AST_VISITOR_DEAMER_VISITOR_H
