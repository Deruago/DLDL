#ifndef DLDL_COMMENT_AST_RELATION_NODETEXTTOENUM_H
#define DLDL_COMMENT_AST_RELATION_NODETEXTTOENUM_H

#include "DLDL_COMMENT/Ast/Enum/Type.h"
#include <string>
#include <map>

namespace DLDL_COMMENT { namespace ast { namespace relation { 

	static constexpr ::DLDL_COMMENT::ast::Type ConvertTextToEnum(const std::string& text)
	{
		static const std::map<std::string, ::DLDL_COMMENT::ast::Type> mapTextWithType = {
			{"", ::DLDL_COMMENT::ast::Type::deamerreserved_unknown },
			
		{ "program", ::DLDL_COMMENT::ast::Type::program },
	

		{ "deamerreserved_star__stmt__", ::DLDL_COMMENT::ast::Type::deamerreserved_star__stmt__ },
	

		{ "stmt", ::DLDL_COMMENT::ast::Type::stmt },
	

		{ "comment_value_declaration", ::DLDL_COMMENT::ast::Type::comment_value_declaration },
	

		{ "deamerreserved_long_3", ::DLDL_COMMENT::ast::Type::deamerreserved_long_3 },
	

		{ "deamerreserved_long_6", ::DLDL_COMMENT::ast::Type::deamerreserved_long_6 },
	

		{ "comment_abstraction", ::DLDL_COMMENT::ast::Type::comment_abstraction },
	

		{ "start_abstraction", ::DLDL_COMMENT::ast::Type::start_abstraction },
	

		{ "end_abstraction", ::DLDL_COMMENT::ast::Type::end_abstraction },
	

		{ "start_sequence", ::DLDL_COMMENT::ast::Type::start_sequence },
	

		{ "end_sequence", ::DLDL_COMMENT::ast::Type::end_sequence },
	

		{ "sequence", ::DLDL_COMMENT::ast::Type::sequence },
	

		{ "syntactic_reference", ::DLDL_COMMENT::ast::Type::syntactic_reference },
	

		{ "SINGLE_COMMENT", ::DLDL_COMMENT::ast::Type::SINGLE_COMMENT },
	

		{ "MULTI_COMMENT", ::DLDL_COMMENT::ast::Type::MULTI_COMMENT },
	

		{ "COMMENT_VALUE", ::DLDL_COMMENT::ast::Type::COMMENT_VALUE },
	

		{ "LEFT_SQUARE_BRACKET", ::DLDL_COMMENT::ast::Type::LEFT_SQUARE_BRACKET },
	

		{ "RIGHT_SQUARE_BRACKET", ::DLDL_COMMENT::ast::Type::RIGHT_SQUARE_BRACKET },
	

		{ "START", ::DLDL_COMMENT::ast::Type::START },
	

		{ "END", ::DLDL_COMMENT::ast::Type::END },
	

		{ "TEXT", ::DLDL_COMMENT::ast::Type::TEXT },
	

		{ "VARNAME", ::DLDL_COMMENT::ast::Type::VARNAME },
	

		{ "ESCAPE_CHARS", ::DLDL_COMMENT::ast::Type::ESCAPE_CHARS },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DLDL_COMMENT_AST_RELATION_NODETEXTTOENUM_H