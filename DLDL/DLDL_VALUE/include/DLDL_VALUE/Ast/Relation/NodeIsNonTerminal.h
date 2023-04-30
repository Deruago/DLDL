#ifndef DLDL_VALUE_AST_RELATION_NODEISNONTERMINAL_H
#define DLDL_VALUE_AST_RELATION_NODEISNONTERMINAL_H

#include "DLDL_VALUE/Ast/Enum/Type.h"

namespace DLDL_VALUE { namespace ast { namespace relation { 

	constexpr static bool NodeIsNonTerminal(::DLDL_VALUE::ast::Type t)
	{
		
		if (t == ::DLDL_VALUE::ast::Type::program)
		{
			return true;
		}

		if (t == ::DLDL_VALUE::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::DLDL_VALUE::ast::Type::stmt)
		{
			return true;
		}

		if (t == ::DLDL_VALUE::ast::Type::value_charactersitic_declaration)
		{
			return true;
		}

		if (t == ::DLDL_VALUE::ast::Type::deamerreserved_long_82)
		{
			return true;
		}

		if (t == ::DLDL_VALUE::ast::Type::deamerreserved_long_85)
		{
			return true;
		}

		if (t == ::DLDL_VALUE::ast::Type::deamerreserved_long_88)
		{
			return true;
		}

		if (t == ::DLDL_VALUE::ast::Type::value_declaration)
		{
			return true;
		}

		if (t == ::DLDL_VALUE::ast::Type::deamerreserved_long_91)
		{
			return true;
		}

		if (t == ::DLDL_VALUE::ast::Type::value_characteristic_abstraction)
		{
			return true;
		}

		if (t == ::DLDL_VALUE::ast::Type::value_declaration_abstraction)
		{
			return true;
		}

		if (t == ::DLDL_VALUE::ast::Type::value_abstraction)
		{
			return true;
		}

		if (t == ::DLDL_VALUE::ast::Type::deamerreserved_star__value_abstraction__)
		{
			return true;
		}

		if (t == ::DLDL_VALUE::ast::Type::deamerreserved_long_96)
		{
			return true;
		}

		if (t == ::DLDL_VALUE::ast::Type::value)
		{
			return true;
		}

		if (t == ::DLDL_VALUE::ast::Type::syntactic_context)
		{
			return true;
		}

		if (t == ::DLDL_VALUE::ast::Type::abstraction_name)
		{
			return true;
		}

		if (t == ::DLDL_VALUE::ast::Type::value_rule_name)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_VALUE_AST_RELATION_NODEISNONTERMINAL_H