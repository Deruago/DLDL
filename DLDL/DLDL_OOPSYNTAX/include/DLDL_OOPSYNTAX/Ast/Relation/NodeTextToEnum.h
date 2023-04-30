#ifndef DLDL_OOPSYNTAX_AST_RELATION_NODETEXTTOENUM_H
#define DLDL_OOPSYNTAX_AST_RELATION_NODETEXTTOENUM_H

#include "DLDL_OOPSYNTAX/Ast/Enum/Type.h"
#include <string>
#include <map>

namespace DLDL_OOPSYNTAX { namespace ast { namespace relation { 

	static constexpr ::DLDL_OOPSYNTAX::ast::Type ConvertTextToEnum(const std::string& text)
	{
		static const std::map<std::string, ::DLDL_OOPSYNTAX::ast::Type> mapTextWithType = {
			{"", ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_unknown },
			
		{ "program", ::DLDL_OOPSYNTAX::ast::Type::program },
	

		{ "deamerreserved_star__stmt__", ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__stmt__ },
	

		{ "stmt", ::DLDL_OOPSYNTAX::ast::Type::stmt },
	

		{ "nonterminal_conversion", ::DLDL_OOPSYNTAX::ast::Type::nonterminal_conversion },
	

		{ "deamerreserved_long_69", ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_69 },
	

		{ "production_rule_conversion", ::DLDL_OOPSYNTAX::ast::Type::production_rule_conversion },
	

		{ "numbered_pr_convert", ::DLDL_OOPSYNTAX::ast::Type::numbered_pr_convert },
	

		{ "deamerreserved_long_72", ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_72 },
	

		{ "property_assignment", ::DLDL_OOPSYNTAX::ast::Type::property_assignment },
	

		{ "direct_property_assignment", ::DLDL_OOPSYNTAX::ast::Type::direct_property_assignment },
	

		{ "deamerreserved_arrow__property__", ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_arrow__property__ },
	

		{ "deamerreserved_long_76", ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_76 },
	

		{ "deamerreserved_arrow__terminal_name__", ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_arrow__terminal_name__ },
	

		{ "deamerreserved_long_80", ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_80 },
	

		{ "direct_any_property_assignment", ::DLDL_OOPSYNTAX::ast::Type::direct_any_property_assignment },
	

		{ "embedded_assignment", ::DLDL_OOPSYNTAX::ast::Type::embedded_assignment },
	

		{ "nonterminal_name", ::DLDL_OOPSYNTAX::ast::Type::nonterminal_name },
	

		{ "oop_type", ::DLDL_OOPSYNTAX::ast::Type::oop_type },
	

		{ "property", ::DLDL_OOPSYNTAX::ast::Type::property },
	

		{ "extended_property", ::DLDL_OOPSYNTAX::ast::Type::extended_property },
	

		{ "extended_terminal_access", ::DLDL_OOPSYNTAX::ast::Type::extended_terminal_access },
	

		{ "terminal_name", ::DLDL_OOPSYNTAX::ast::Type::terminal_name },
	

		{ "ARROW", ::DLDL_OOPSYNTAX::ast::Type::ARROW },
	

		{ "LEFT_BRACKET", ::DLDL_OOPSYNTAX::ast::Type::LEFT_BRACKET },
	

		{ "RIGHT_BRACKET", ::DLDL_OOPSYNTAX::ast::Type::RIGHT_BRACKET },
	

		{ "DOT", ::DLDL_OOPSYNTAX::ast::Type::DOT },
	

		{ "EQ", ::DLDL_OOPSYNTAX::ast::Type::EQ },
	

		{ "STAR", ::DLDL_OOPSYNTAX::ast::Type::STAR },
	

		{ "VARNAME", ::DLDL_OOPSYNTAX::ast::Type::VARNAME },
	

		{ "NUMBER", ::DLDL_OOPSYNTAX::ast::Type::NUMBER },
	

		{ "COMMENT", ::DLDL_OOPSYNTAX::ast::Type::COMMENT },
	

		{ "ESCAPE_CHAR", ::DLDL_OOPSYNTAX::ast::Type::ESCAPE_CHAR },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DLDL_OOPSYNTAX_AST_RELATION_NODETEXTTOENUM_H