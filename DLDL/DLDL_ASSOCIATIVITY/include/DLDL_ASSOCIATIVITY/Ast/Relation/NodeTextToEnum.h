#ifndef DLDL_ASSOCIATIVITY_AST_RELATION_NODETEXTTOENUM_H
#define DLDL_ASSOCIATIVITY_AST_RELATION_NODETEXTTOENUM_H

#include "DLDL_ASSOCIATIVITY/Ast/Enum/Type.h"
#include <string>
#include <map>

namespace DLDL_ASSOCIATIVITY { namespace ast { namespace relation { 

	static constexpr ::DLDL_ASSOCIATIVITY::ast::Type ConvertTextToEnum(const std::string& text)
	{
		static const std::map<std::string, ::DLDL_ASSOCIATIVITY::ast::Type> mapTextWithType = {
			{"", ::DLDL_ASSOCIATIVITY::ast::Type::deamerreserved_unknown },
			
		{ "program", ::DLDL_ASSOCIATIVITY::ast::Type::program },
	

		{ "stmts", ::DLDL_ASSOCIATIVITY::ast::Type::stmts },
	

		{ "stmt", ::DLDL_ASSOCIATIVITY::ast::Type::stmt },
	

		{ "ASSOCIATIVITY", ::DLDL_ASSOCIATIVITY::ast::Type::ASSOCIATIVITY },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DLDL_ASSOCIATIVITY_AST_RELATION_NODETEXTTOENUM_H