#ifndef DLDL_GENERATION_AST_RELATION_NODETEXTTOENUM_H
#define DLDL_GENERATION_AST_RELATION_NODETEXTTOENUM_H

#include "DLDL_GENERATION/Ast/Enum/Type.h"
#include <string>
#include <map>

namespace DLDL_GENERATION { namespace ast { namespace relation { 

	static constexpr ::DLDL_GENERATION::ast::Type ConvertTextToEnum(const std::string& text)
	{
		static const std::map<std::string, ::DLDL_GENERATION::ast::Type> mapTextWithType = {
			{"", ::DLDL_GENERATION::ast::Type::deamerreserved_unknown },
			
		{ "program", ::DLDL_GENERATION::ast::Type::program },
	

		{ "stmts", ::DLDL_GENERATION::ast::Type::stmts },
	

		{ "stmt", ::DLDL_GENERATION::ast::Type::stmt },
	

		{ "generate_declaration", ::DLDL_GENERATION::ast::Type::generate_declaration },
	

		{ "integrate_declaration", ::DLDL_GENERATION::ast::Type::integrate_declaration },
	

		{ "argument_declaration", ::DLDL_GENERATION::ast::Type::argument_declaration },
	

		{ "type", ::DLDL_GENERATION::ast::Type::type },
	

		{ "tool", ::DLDL_GENERATION::ast::Type::tool },
	

		{ "argument_data", ::DLDL_GENERATION::ast::Type::argument_data },
	

		{ "GENERATE", ::DLDL_GENERATION::ast::Type::GENERATE },
	

		{ "INTEGRATE", ::DLDL_GENERATION::ast::Type::INTEGRATE },
	

		{ "ARGUMENT", ::DLDL_GENERATION::ast::Type::ARGUMENT },
	

		{ "VALUE", ::DLDL_GENERATION::ast::Type::VALUE },
	

		{ "SYMBOLS", ::DLDL_GENERATION::ast::Type::SYMBOLS },
	

		{ "ESCAPE_CHARS", ::DLDL_GENERATION::ast::Type::ESCAPE_CHARS },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DLDL_GENERATION_AST_RELATION_NODETEXTTOENUM_H