#ifndef DLDL_OOPSYNTAX_AST_RELATION_NODEISNONTERMINAL_H
#define DLDL_OOPSYNTAX_AST_RELATION_NODEISNONTERMINAL_H

#include "DLDL_OOPSYNTAX/Ast/Enum/Type.h"

namespace DLDL_OOPSYNTAX { namespace ast { namespace relation { 

	constexpr static bool NodeIsNonTerminal(::DLDL_OOPSYNTAX::ast::Type t)
	{
		
		if (t == ::DLDL_OOPSYNTAX::ast::Type::program)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::stmt)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::nonterminal_conversion)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_69)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::production_rule_conversion)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::numbered_pr_convert)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_72)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::property_assignment)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::direct_property_assignment)
		{
			return true;
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
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::embedded_assignment)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::nonterminal_name)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::oop_type)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::property)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::extended_property)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::extended_terminal_access)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::terminal_name)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_OOPSYNTAX_AST_RELATION_NODEISNONTERMINAL_H