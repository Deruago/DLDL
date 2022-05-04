#ifndef DLDL_LDOSTRUCT_AST_RELATION_NODEISINLINED_H
#define DLDL_LDOSTRUCT_AST_RELATION_NODEISINLINED_H

#include "DLDL_LDOSTRUCT/Ast/Enum/Type.h"

namespace DLDL_LDOSTRUCT { namespace ast { namespace relation { 

	constexpr static bool NodeIsInlined(::DLDL_LDOSTRUCT::ast::Type t)
	{
		
		if (t == ::DLDL_LDOSTRUCT::ast::Type::program)
		{
			return false;
		}

		if (t == ::DLDL_LDOSTRUCT::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::DLDL_LDOSTRUCT::ast::Type::stmt)
		{
			return false;
		}

		if (t == ::DLDL_LDOSTRUCT::ast::Type::argument)
		{
			return false;
		}

		if (t == ::DLDL_LDOSTRUCT::ast::Type::argument_name)
		{
			return false;
		}

		if (t == ::DLDL_LDOSTRUCT::ast::Type::argument_block)
		{
			return false;
		}

		if (t == ::DLDL_LDOSTRUCT::ast::Type::deamerreserved_star__argument_stmt__)
		{
			return true;
		}

		if (t == ::DLDL_LDOSTRUCT::ast::Type::argument_stmt)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_LDOSTRUCT_AST_RELATION_NODEISINLINED_H