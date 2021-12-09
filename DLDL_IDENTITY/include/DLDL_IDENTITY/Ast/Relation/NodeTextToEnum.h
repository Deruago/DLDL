#ifndef DLDL_IDENTITY_AST_RELATION_NODETEXTTOENUM_H
#define DLDL_IDENTITY_AST_RELATION_NODETEXTTOENUM_H

#include "DLDL_IDENTITY/Ast/Enum/Type.h"

namespace DLDL_IDENTITY { namespace ast { namespace relation { 

	static constexpr ::DLDL_IDENTITY::ast::Type ConvertEnumToText(const std::string& text)
	{
		static const std::map<std::string, ::DLDL_IDENTITY::ast::Type> mapTextWithType = {
			{"", ::DLDL_IDENTITY::ast::Type::deamerreserved_unknown },
			
		{ "program", ::DLDL_IDENTITY::ast::Type::program },
	

		{ "stmts", ::DLDL_IDENTITY::ast::Type::stmts },
	

		{ "stmt", ::DLDL_IDENTITY::ast::Type::stmt },
	

		{ "name_declaration", ::DLDL_IDENTITY::ast::Type::name_declaration },
	

		{ "NAME", ::DLDL_IDENTITY::ast::Type::NAME },
	

		{ "VALUE", ::DLDL_IDENTITY::ast::Type::VALUE },
	

		{ "SYMBOLS", ::DLDL_IDENTITY::ast::Type::SYMBOLS },
	

		{ "ESCAPE_CHARS", ::DLDL_IDENTITY::ast::Type::ESCAPE_CHARS },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DLDL_IDENTITY_AST_RELATION_NODETEXTTOENUM_H