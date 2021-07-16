#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_ENUMTOTYPE_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_ENUMTOTYPE_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Enum/Type.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ARROW.h"

namespace DLDL_GRAMMAR_PRODUCTION_RULE::ast::relation
{
	template<DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type T>
	class EnumToType
	{
	public:
		constexpr static auto value = T;
		using type = void;
	};

	/*!
	 *	\see deamer::language::convertor::definition::ObjectEnumToType
	 */
	template<>
	class EnumToType<DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ARROW>
	{
	public:
		constexpr static auto value = DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ARROW;
		using type = DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW;
	};
}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_ENUMTOTYPE_H