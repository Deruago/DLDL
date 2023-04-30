#ifndef DLDL_IMPORT_AST_RELATION_NODEISINLINED_H
#define DLDL_IMPORT_AST_RELATION_NODEISINLINED_H

#include "DLDL_IMPORT/Ast/Enum/Type.h"

namespace DLDL_IMPORT { namespace ast { namespace relation { 

	constexpr static bool NodeIsInlined(::DLDL_IMPORT::ast::Type t)
	{
		
		if (t == ::DLDL_IMPORT::ast::Type::program)
		{
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::stmt)
		{
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::import_declaration)
		{
			return false;
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
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::import_abstraction)
		{
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::value)
		{
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::deamerreserved_optional__VARNAME__)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::abstraction)
		{
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::import_context)
		{
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::import_rule_name)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_IMPORT_AST_RELATION_NODEISINLINED_H