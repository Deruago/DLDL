#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODEISDELETED_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODEISDELETED_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Enum/Type.h"

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace relation { 

	constexpr static bool NodeIsDeleted(::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type t)
	{
		
		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ENDING_USELESS_SYMBOLS)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VERTICAL_SLASH)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_PARANTHESIS)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_PARANTHESIS)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_BRACKET)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_BRACKET)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_SQUARE_BRACKET)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_SQUARE_BRACKET)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::QUESTION_MARK)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::EXCLAMATION_MARK)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ARROW)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::STAR)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::PLUS)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MINUS)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VALUE)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::NUMBER)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SINGLE_LINE_COMMENT)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MULTI_LINE_COMMENT)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SYMBOLS)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ESCAPE_CHARS)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODEISDELETED_H