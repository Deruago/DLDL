#ifndef DLDL_IMPORT_AST_RELATION_NODETEXTTOENUM_H
#define DLDL_IMPORT_AST_RELATION_NODETEXTTOENUM_H

#include "DLDL_IMPORT/Ast/Enum/Type.h"
#include <string>
#include <map>

namespace DLDL_IMPORT { namespace ast { namespace relation { 

	static constexpr ::DLDL_IMPORT::ast::Type ConvertTextToEnum(const std::string& text)
	{
		static const std::map<std::string, ::DLDL_IMPORT::ast::Type> mapTextWithType = {
			{"", ::DLDL_IMPORT::ast::Type::deamerreserved_unknown },
			
		{ "program", ::DLDL_IMPORT::ast::Type::program },
	

		{ "deamerreserved_star__stmt__", ::DLDL_IMPORT::ast::Type::deamerreserved_star__stmt__ },
	

		{ "stmt", ::DLDL_IMPORT::ast::Type::stmt },
	

		{ "import_declaration", ::DLDL_IMPORT::ast::Type::import_declaration },
	

		{ "deamerreserved_arrow__import_context__", ::DLDL_IMPORT::ast::Type::deamerreserved_arrow__import_context__ },
	

		{ "deamerreserved_long_40", ::DLDL_IMPORT::ast::Type::deamerreserved_long_40 },
	

		{ "deamerreserved_long_43", ::DLDL_IMPORT::ast::Type::deamerreserved_long_43 },
	

		{ "specialization", ::DLDL_IMPORT::ast::Type::specialization },
	

		{ "import_abstraction", ::DLDL_IMPORT::ast::Type::import_abstraction },
	

		{ "value", ::DLDL_IMPORT::ast::Type::value },
	

		{ "deamerreserved_optional__VARNAME__", ::DLDL_IMPORT::ast::Type::deamerreserved_optional__VARNAME__ },
	

		{ "abstraction", ::DLDL_IMPORT::ast::Type::abstraction },
	

		{ "import_context", ::DLDL_IMPORT::ast::Type::import_context },
	

		{ "import_rule_name", ::DLDL_IMPORT::ast::Type::import_rule_name },
	

		{ "SINGLE_COMMENT", ::DLDL_IMPORT::ast::Type::SINGLE_COMMENT },
	

		{ "MULTI_COMMENT", ::DLDL_IMPORT::ast::Type::MULTI_COMMENT },
	

		{ "LEFT_PARANTHESIS", ::DLDL_IMPORT::ast::Type::LEFT_PARANTHESIS },
	

		{ "RIGHT_PARANTHESIS", ::DLDL_IMPORT::ast::Type::RIGHT_PARANTHESIS },
	

		{ "LEFT_SQUARE_BRACKET", ::DLDL_IMPORT::ast::Type::LEFT_SQUARE_BRACKET },
	

		{ "RIGHT_SQUARE_BRACKET", ::DLDL_IMPORT::ast::Type::RIGHT_SQUARE_BRACKET },
	

		{ "COLON", ::DLDL_IMPORT::ast::Type::COLON },
	

		{ "DOT", ::DLDL_IMPORT::ast::Type::DOT },
	

		{ "IMPORT_FILE", ::DLDL_IMPORT::ast::Type::IMPORT_FILE },
	

		{ "IMPORT_MODULE", ::DLDL_IMPORT::ast::Type::IMPORT_MODULE },
	

		{ "IMPORT", ::DLDL_IMPORT::ast::Type::IMPORT },
	

		{ "TEXT", ::DLDL_IMPORT::ast::Type::TEXT },
	

		{ "VARNAME", ::DLDL_IMPORT::ast::Type::VARNAME },
	

		{ "ESCAPE_CHARS", ::DLDL_IMPORT::ast::Type::ESCAPE_CHARS },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DLDL_IMPORT_AST_RELATION_NODETEXTTOENUM_H