#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_VISITOR_DEAMER_VISITOR_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/DLDL_GRAMMAR_PRODUCTION_RULE.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Enum/Type.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ENDING_USELESS_SYMBOLS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/VERTICAL_SLASH.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/QUESTION_MARK.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/EXCLAMATION_MARK.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ARROW.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/STAR.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/PLUS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/MINUS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/VALUE.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/NUMBER.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/SINGLE_LINE_COMMENT.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/MULTI_LINE_COMMENT.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/SYMBOLS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ESCAPE_CHARS.h"

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/program.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/stmts.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/stmt.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/nested_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/optional_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/zero_or_more_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/one_or_more_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/or_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/min_max_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/extension_group.h"

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ENDING_USELESS_SYMBOLS:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VERTICAL_SLASH:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_PARANTHESIS:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_PARANTHESIS:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_BRACKET:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_BRACKET:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_SQUARE_BRACKET:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::QUESTION_MARK:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::EXCLAMATION_MARK:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ARROW:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::STAR:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::PLUS:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MINUS:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VALUE:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::NUMBER:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SINGLE_LINE_COMMENT:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MULTI_LINE_COMMENT:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SYMBOLS:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ESCAPE_CHARS:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::program:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmts:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmt:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::nested_group:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::optional_group:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::zero_or_more_group:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::one_or_more_group:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::or_group:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::min_max_group:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group*>(node));
				break;
			}
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::extension_group:
			{
				Visit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group*>(node));
				break;
			}
			}
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group* node)
		{
		}
		virtual void Visit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group* node)
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_VISITOR_DEAMER_VISITOR_H
