#ifndef DLDL_VALUE_AST_RELATION_NODEISINLINED_H
#define DLDL_VALUE_AST_RELATION_NODEISINLINED_H

#include "DLDL_VALUE/Ast/Enum/Type.h"

namespace DLDL_VALUE { namespace ast { namespace relation { 

	constexpr static bool NodeIsInlined(::DLDL_VALUE::ast::Type t)
	{
		
		if (t == ::DLDL_VALUE::ast::Type::program)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::DLDL_VALUE::ast::Type::stmt)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::value_charactersitic_declaration)
		{
			return false;
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
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::deamerreserved_long_91)
		{
			return true;
		}

		if (t == ::DLDL_VALUE::ast::Type::value_characteristic_abstraction)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::value_declaration_abstraction)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::value_abstraction)
		{
			return false;
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
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::syntactic_context)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::abstraction_name)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::value_rule_name)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_VALUE_AST_RELATION_NODEISINLINED_H