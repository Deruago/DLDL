#ifndef DLDL_COMMENT_AST_LISTENER_DEAMER_LISTENER_H
#define DLDL_COMMENT_AST_LISTENER_DEAMER_LISTENER_H

#include <Deamer/External/Cpp/Ast/Listener.h>
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

namespace DLDL_COMMENT { namespace ast { namespace listener { 

	class Listener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		Listener() = default;
		~Listener() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_COMMENT::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_COMMENT::ast::Type::SINGLE_COMMENT:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::SINGLE_COMMENT*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::MULTI_COMMENT:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::MULTI_COMMENT*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::COMMENT_VALUE:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::COMMENT_VALUE*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::LEFT_SQUARE_BRACKET:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::START:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::START*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::END:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::END*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::TEXT:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::TEXT*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::VARNAME:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::VARNAME*>(node));
				break;
			}
			case DLDL_COMMENT::ast::Type::ESCAPE_CHARS:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::program:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::program*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_COMMENT::ast::Type::deamerreserved_star__stmt__:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::deamerreserved_star__stmt__*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_COMMENT::ast::Type::stmt:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::stmt*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_COMMENT::ast::Type::comment_value_declaration:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::comment_value_declaration*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_COMMENT::ast::Type::deamerreserved_long_3:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::deamerreserved_long_3*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_COMMENT::ast::Type::deamerreserved_long_6:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::deamerreserved_long_6*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_COMMENT::ast::Type::comment_abstraction:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::comment_abstraction*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_COMMENT::ast::Type::start_abstraction:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::start_abstraction*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_COMMENT::ast::Type::end_abstraction:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::end_abstraction*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_COMMENT::ast::Type::start_sequence:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::start_sequence*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_COMMENT::ast::Type::end_sequence:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::end_sequence*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_COMMENT::ast::Type::sequence:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::sequence*>(node));
				DefaultAction(node);
				break;
			}
			case DLDL_COMMENT::ast::Type::syntactic_reference:
			{
				Listen(static_cast<const DLDL_COMMENT::ast::node::syntactic_reference*>(node));
				DefaultAction(node);
				break;
			}
			}
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::SINGLE_COMMENT* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::MULTI_COMMENT* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::COMMENT_VALUE* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::START* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::END* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::TEXT* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::VARNAME* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Listen(const DLDL_COMMENT::ast::node::program* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::stmt* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::comment_value_declaration* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::deamerreserved_long_3* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::deamerreserved_long_6* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::comment_abstraction* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::start_abstraction* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::end_abstraction* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::start_sequence* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::end_sequence* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::sequence* node)
		{
		}
		virtual void Listen(const DLDL_COMMENT::ast::node::syntactic_reference* node)
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

#endif // DLDL_COMMENT_AST_LISTENER_DEAMER_LISTENER_H
