#ifndef DLDL_IDENTITY_AST_RELATION_NODEENUMTOTYPE_H
#define DLDL_IDENTITY_AST_RELATION_NODEENUMTOTYPE_H

#include "DLDL_IDENTITY/Ast/Enum/Type.h"

#include "DLDL_IDENTITY/Ast/Node/program.h"
#include "DLDL_IDENTITY/Ast/Node/stmts.h"
#include "DLDL_IDENTITY/Ast/Node/stmt.h"
#include "DLDL_IDENTITY/Ast/Node/name_declaration.h"
#include "DLDL_IDENTITY/Ast/Node/NAME.h"
#include "DLDL_IDENTITY/Ast/Node/VALUE.h"
#include "DLDL_IDENTITY/Ast/Node/SYMBOLS.h"
#include "DLDL_IDENTITY/Ast/Node/ESCAPE_CHARS.h"


namespace DLDL_IDENTITY { namespace ast { namespace relation { 

	template<::DLDL_IDENTITY::ast::Type T>
	struct NodeEnumToType
	{
		constexpr static auto value = T;
		using type = void;
	};


	template<>
	struct NodeEnumToType<::DLDL_IDENTITY::ast::Type::program>
	{
		constexpr static auto value = ::DLDL_IDENTITY::ast::Type::program;
		using type = ::DLDL_IDENTITY::ast::node::program;
	};

	template<>
	struct NodeEnumToType<::DLDL_IDENTITY::ast::Type::stmts>
	{
		constexpr static auto value = ::DLDL_IDENTITY::ast::Type::stmts;
		using type = ::DLDL_IDENTITY::ast::node::stmts;
	};

	template<>
	struct NodeEnumToType<::DLDL_IDENTITY::ast::Type::stmt>
	{
		constexpr static auto value = ::DLDL_IDENTITY::ast::Type::stmt;
		using type = ::DLDL_IDENTITY::ast::node::stmt;
	};

	template<>
	struct NodeEnumToType<::DLDL_IDENTITY::ast::Type::name_declaration>
	{
		constexpr static auto value = ::DLDL_IDENTITY::ast::Type::name_declaration;
		using type = ::DLDL_IDENTITY::ast::node::name_declaration;
	};

	template<>
	struct NodeEnumToType<::DLDL_IDENTITY::ast::Type::NAME>
	{
		constexpr static auto value = ::DLDL_IDENTITY::ast::Type::NAME;
		using type = ::DLDL_IDENTITY::ast::node::NAME;
	};

	template<>
	struct NodeEnumToType<::DLDL_IDENTITY::ast::Type::VALUE>
	{
		constexpr static auto value = ::DLDL_IDENTITY::ast::Type::VALUE;
		using type = ::DLDL_IDENTITY::ast::node::VALUE;
	};

	template<>
	struct NodeEnumToType<::DLDL_IDENTITY::ast::Type::SYMBOLS>
	{
		constexpr static auto value = ::DLDL_IDENTITY::ast::Type::SYMBOLS;
		using type = ::DLDL_IDENTITY::ast::node::SYMBOLS;
	};

	template<>
	struct NodeEnumToType<::DLDL_IDENTITY::ast::Type::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_IDENTITY::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_IDENTITY::ast::node::ESCAPE_CHARS;
	};


template<::DLDL_IDENTITY::ast::Type T>
constexpr static auto NodeEnumToType_v = ::DLDL_IDENTITY::ast::relation::NodeEnumToType<T>::value;

template<::DLDL_IDENTITY::ast::Type T>
using NodeEnumToType_t = typename ::DLDL_IDENTITY::ast::relation::NodeEnumToType<T>::type;

}}}

#endif // DLDL_IDENTITY_AST_RELATION_NODEENUMTOTYPE_H