#ifndef DLDL_IMPORT_AST_RELATION_NODEENUMTOTYPE_H
#define DLDL_IMPORT_AST_RELATION_NODEENUMTOTYPE_H

#include "DLDL_IMPORT/Ast/Enum/Type.h"

#include "DLDL_IMPORT/Ast/Node/program.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_IMPORT/Ast/Node/stmt.h"
#include "DLDL_IMPORT/Ast/Node/import_declaration.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_arrow__import_context__.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_long_40.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_long_43.h"
#include "DLDL_IMPORT/Ast/Node/specialization.h"
#include "DLDL_IMPORT/Ast/Node/import_abstraction.h"
#include "DLDL_IMPORT/Ast/Node/value.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_optional__VARNAME__.h"
#include "DLDL_IMPORT/Ast/Node/abstraction.h"
#include "DLDL_IMPORT/Ast/Node/import_context.h"
#include "DLDL_IMPORT/Ast/Node/import_rule_name.h"
#include "DLDL_IMPORT/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_IMPORT/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_IMPORT/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_IMPORT/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_IMPORT/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_IMPORT/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_IMPORT/Ast/Node/COLON.h"
#include "DLDL_IMPORT/Ast/Node/DOT.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT_FILE.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT_MODULE.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT.h"
#include "DLDL_IMPORT/Ast/Node/TEXT.h"
#include "DLDL_IMPORT/Ast/Node/VARNAME.h"
#include "DLDL_IMPORT/Ast/Node/ESCAPE_CHARS.h"


namespace DLDL_IMPORT { namespace ast { namespace relation { 

	template<::DLDL_IMPORT::ast::Type T>
	struct NodeEnumToType
	{
		constexpr static auto value = T;
		using type = void;
	};


	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::program>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::program;
		using type = ::DLDL_IMPORT::ast::node::program;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::deamerreserved_star__stmt__>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::deamerreserved_star__stmt__;
		using type = ::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::stmt>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::stmt;
		using type = ::DLDL_IMPORT::ast::node::stmt;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::import_declaration>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::import_declaration;
		using type = ::DLDL_IMPORT::ast::node::import_declaration;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::deamerreserved_arrow__import_context__>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::deamerreserved_arrow__import_context__;
		using type = ::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::deamerreserved_long_40>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::deamerreserved_long_40;
		using type = ::DLDL_IMPORT::ast::node::deamerreserved_long_40;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::deamerreserved_long_43>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::deamerreserved_long_43;
		using type = ::DLDL_IMPORT::ast::node::deamerreserved_long_43;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::specialization>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::specialization;
		using type = ::DLDL_IMPORT::ast::node::specialization;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::import_abstraction>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::import_abstraction;
		using type = ::DLDL_IMPORT::ast::node::import_abstraction;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::value>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::value;
		using type = ::DLDL_IMPORT::ast::node::value;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::deamerreserved_optional__VARNAME__>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::deamerreserved_optional__VARNAME__;
		using type = ::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::abstraction>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::abstraction;
		using type = ::DLDL_IMPORT::ast::node::abstraction;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::import_context>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::import_context;
		using type = ::DLDL_IMPORT::ast::node::import_context;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::import_rule_name>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::import_rule_name;
		using type = ::DLDL_IMPORT::ast::node::import_rule_name;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::SINGLE_COMMENT>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::SINGLE_COMMENT;
		using type = ::DLDL_IMPORT::ast::node::SINGLE_COMMENT;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::MULTI_COMMENT>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::MULTI_COMMENT;
		using type = ::DLDL_IMPORT::ast::node::MULTI_COMMENT;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::LEFT_PARANTHESIS>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::LEFT_PARANTHESIS;
		using type = ::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::RIGHT_PARANTHESIS>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::RIGHT_PARANTHESIS;
		using type = ::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::LEFT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::LEFT_SQUARE_BRACKET;
		using type = ::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::RIGHT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::RIGHT_SQUARE_BRACKET;
		using type = ::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::COLON>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::COLON;
		using type = ::DLDL_IMPORT::ast::node::COLON;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::DOT>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::DOT;
		using type = ::DLDL_IMPORT::ast::node::DOT;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::IMPORT_FILE>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::IMPORT_FILE;
		using type = ::DLDL_IMPORT::ast::node::IMPORT_FILE;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::IMPORT_MODULE>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::IMPORT_MODULE;
		using type = ::DLDL_IMPORT::ast::node::IMPORT_MODULE;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::IMPORT>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::IMPORT;
		using type = ::DLDL_IMPORT::ast::node::IMPORT;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::TEXT>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::TEXT;
		using type = ::DLDL_IMPORT::ast::node::TEXT;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::VARNAME>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::VARNAME;
		using type = ::DLDL_IMPORT::ast::node::VARNAME;
	};

	template<>
	struct NodeEnumToType<::DLDL_IMPORT::ast::Type::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_IMPORT::ast::node::ESCAPE_CHARS;
	};


template<::DLDL_IMPORT::ast::Type T>
constexpr static auto NodeEnumToType_v = ::DLDL_IMPORT::ast::relation::NodeEnumToType<T>::value;

template<::DLDL_IMPORT::ast::Type T>
using NodeEnumToType_t = typename ::DLDL_IMPORT::ast::relation::NodeEnumToType<T>::type;

}}}

#endif // DLDL_IMPORT_AST_RELATION_NODEENUMTOTYPE_H