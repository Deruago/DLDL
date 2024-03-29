#ifndef DLDL_OOPSYNTAX_AST_RELATION_NODEISINLINED_H
#define DLDL_OOPSYNTAX_AST_RELATION_NODEISINLINED_H

#include "DLDL_OOPSYNTAX/Ast/Enum/Type.h"

namespace DLDL_OOPSYNTAX { namespace ast { namespace relation { 

	constexpr static bool NodeIsInlined(::DLDL_OOPSYNTAX::ast::Type t)
	{
		
		if (t == ::DLDL_OOPSYNTAX::ast::Type::program)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::stmt)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::nonterminal_conversion)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_69)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::production_rule_conversion)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::numbered_pr_convert)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_72)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::property_assignment)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::direct_property_assignment)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_arrow__property__)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_76)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_arrow__terminal_name__)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_80)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::direct_any_property_assignment)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::embedded_assignment)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::nonterminal_name)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::oop_type)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::property)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::extended_property)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::extended_terminal_access)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::terminal_name)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_OOPSYNTAX_AST_RELATION_NODEISINLINED_H