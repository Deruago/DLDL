#ifndef DLDL_AST_RELATION_NODETEXTTOENUM_H
#define DLDL_AST_RELATION_NODETEXTTOENUM_H

#include "DLDL/Ast/Enum/Type.h"

namespace DLDL { namespace ast { namespace relation { 

	static constexpr ::DLDL::ast::Type ConvertEnumToText(const std::string& text)
	{
		static const std::map<std::string, ::DLDL::ast::Type> mapTextWithType = {
			{"", ::DLDL::ast::Type::deamerreserved_unknown },
			
		{ "program", ::DLDL::ast::Type::program },
	

		{ "stmts", ::DLDL::ast::Type::stmts },
	

		{ "stmt", ::DLDL::ast::Type::stmt },
	

		{ "ANY", ::DLDL::ast::Type::ANY },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DLDL_AST_RELATION_NODETEXTTOENUM_H