#ifndef DLDL_IMPORT_AST_RELATION_NODEISNONTERMINAL_H
#define DLDL_IMPORT_AST_RELATION_NODEISNONTERMINAL_H

#include "DLDL_IMPORT/Ast/Enum/Type.h"

namespace DLDL_IMPORT { namespace ast { namespace relation { 

	constexpr static bool NodeIsNonTerminal(::DLDL_IMPORT::ast::Type t)
	{
		
		if (t == ::DLDL_IMPORT::ast::Type::program)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::stmt)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::import_declaration)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::deamerreserved_arrow__import_context__)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::deamerreserved_long_40)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::deamerreserved_long_43)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::specialization)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::import_abstraction)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::value)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::deamerreserved_optional__VARNAME__)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::abstraction)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::import_context)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::import_rule_name)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_IMPORT_AST_RELATION_NODEISNONTERMINAL_H