#ifndef DLDL_ARGUMENT_AST_RELATION_NODETEXTTOENUM_H
#define DLDL_ARGUMENT_AST_RELATION_NODETEXTTOENUM_H

#include "DLDL_ARGUMENT/Ast/Enum/Type.h"
#include <string>
#include <map>

namespace DLDL_ARGUMENT { namespace ast { namespace relation { 

	static constexpr ::DLDL_ARGUMENT::ast::Type ConvertTextToEnum(const std::string& text)
	{
		static const std::map<std::string, ::DLDL_ARGUMENT::ast::Type> mapTextWithType = {
			{"", ::DLDL_ARGUMENT::ast::Type::deamerreserved_unknown },
			
		{ "program", ::DLDL_ARGUMENT::ast::Type::program },
	

		{ "SINGLE_COMMENT", ::DLDL_ARGUMENT::ast::Type::SINGLE_COMMENT },
	

		{ "MULTI_COMMENT", ::DLDL_ARGUMENT::ast::Type::MULTI_COMMENT },
	

		{ "TEXT", ::DLDL_ARGUMENT::ast::Type::TEXT },
	

		{ "VARNAME", ::DLDL_ARGUMENT::ast::Type::VARNAME },
	

		{ "ESCAPE_CHARS", ::DLDL_ARGUMENT::ast::Type::ESCAPE_CHARS },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DLDL_ARGUMENT_AST_RELATION_NODETEXTTOENUM_H