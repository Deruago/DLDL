#ifndef DLDL_GENERATION_AST_RELATION_NODEENUMTOTYPE_H
#define DLDL_GENERATION_AST_RELATION_NODEENUMTOTYPE_H

#include "DLDL_GENERATION/Ast/Enum/Type.h"

#include "DLDL_GENERATION/Ast/Node/program.h"
#include "DLDL_GENERATION/Ast/Node/stmts.h"
#include "DLDL_GENERATION/Ast/Node/stmt.h"
#include "DLDL_GENERATION/Ast/Node/generate_declaration.h"
#include "DLDL_GENERATION/Ast/Node/integrate_declaration.h"
#include "DLDL_GENERATION/Ast/Node/argument_declaration.h"
#include "DLDL_GENERATION/Ast/Node/type.h"
#include "DLDL_GENERATION/Ast/Node/tool.h"
#include "DLDL_GENERATION/Ast/Node/argument_data.h"
#include "DLDL_GENERATION/Ast/Node/GENERATE.h"
#include "DLDL_GENERATION/Ast/Node/INTEGRATE.h"
#include "DLDL_GENERATION/Ast/Node/ARGUMENT.h"
#include "DLDL_GENERATION/Ast/Node/VALUE.h"
#include "DLDL_GENERATION/Ast/Node/SYMBOLS.h"
#include "DLDL_GENERATION/Ast/Node/ESCAPE_CHARS.h"


namespace DLDL_GENERATION { namespace ast { namespace relation { 

	template<::DLDL_GENERATION::ast::Type T>
	struct NodeEnumToType
	{
		constexpr static auto value = T;
		using type = void;
	};


	template<>
	struct NodeEnumToType<::DLDL_GENERATION::ast::Type::program>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::program;
		using type = ::DLDL_GENERATION::ast::node::program;
	};

	template<>
	struct NodeEnumToType<::DLDL_GENERATION::ast::Type::stmts>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::stmts;
		using type = ::DLDL_GENERATION::ast::node::stmts;
	};

	template<>
	struct NodeEnumToType<::DLDL_GENERATION::ast::Type::stmt>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::stmt;
		using type = ::DLDL_GENERATION::ast::node::stmt;
	};

	template<>
	struct NodeEnumToType<::DLDL_GENERATION::ast::Type::generate_declaration>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::generate_declaration;
		using type = ::DLDL_GENERATION::ast::node::generate_declaration;
	};

	template<>
	struct NodeEnumToType<::DLDL_GENERATION::ast::Type::integrate_declaration>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::integrate_declaration;
		using type = ::DLDL_GENERATION::ast::node::integrate_declaration;
	};

	template<>
	struct NodeEnumToType<::DLDL_GENERATION::ast::Type::argument_declaration>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::argument_declaration;
		using type = ::DLDL_GENERATION::ast::node::argument_declaration;
	};

	template<>
	struct NodeEnumToType<::DLDL_GENERATION::ast::Type::type>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::type;
		using type = ::DLDL_GENERATION::ast::node::type;
	};

	template<>
	struct NodeEnumToType<::DLDL_GENERATION::ast::Type::tool>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::tool;
		using type = ::DLDL_GENERATION::ast::node::tool;
	};

	template<>
	struct NodeEnumToType<::DLDL_GENERATION::ast::Type::argument_data>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::argument_data;
		using type = ::DLDL_GENERATION::ast::node::argument_data;
	};

	template<>
	struct NodeEnumToType<::DLDL_GENERATION::ast::Type::GENERATE>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::GENERATE;
		using type = ::DLDL_GENERATION::ast::node::GENERATE;
	};

	template<>
	struct NodeEnumToType<::DLDL_GENERATION::ast::Type::INTEGRATE>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::INTEGRATE;
		using type = ::DLDL_GENERATION::ast::node::INTEGRATE;
	};

	template<>
	struct NodeEnumToType<::DLDL_GENERATION::ast::Type::ARGUMENT>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::ARGUMENT;
		using type = ::DLDL_GENERATION::ast::node::ARGUMENT;
	};

	template<>
	struct NodeEnumToType<::DLDL_GENERATION::ast::Type::VALUE>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::VALUE;
		using type = ::DLDL_GENERATION::ast::node::VALUE;
	};

	template<>
	struct NodeEnumToType<::DLDL_GENERATION::ast::Type::SYMBOLS>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::SYMBOLS;
		using type = ::DLDL_GENERATION::ast::node::SYMBOLS;
	};

	template<>
	struct NodeEnumToType<::DLDL_GENERATION::ast::Type::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_GENERATION::ast::node::ESCAPE_CHARS;
	};


template<::DLDL_GENERATION::ast::Type T>
constexpr static auto NodeEnumToType_v = ::DLDL_GENERATION::ast::relation::NodeEnumToType<T>::value;

template<::DLDL_GENERATION::ast::Type T>
using NodeEnumToType_t = typename ::DLDL_GENERATION::ast::relation::NodeEnumToType<T>::type;

}}}

#endif // DLDL_GENERATION_AST_RELATION_NODEENUMTOTYPE_H