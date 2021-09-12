#ifndef DLDL_AST_RELATION_NODEENUMTOTYPE_H
#define DLDL_AST_RELATION_NODEENUMTOTYPE_H

#include "DLDL/Ast/Enum/Type.h"

#include "DLDL/Ast/Node/program.h"
#include "DLDL/Ast/Node/stmts.h"
#include "DLDL/Ast/Node/stmt.h"
#include "DLDL/Ast/Node/ANY.h"


namespace DLDL { namespace ast { namespace relation { 

	template<::DLDL::ast::Type T>
	struct NodeEnumToType
	{
		constexpr static auto value = T;
		using type = void;
	};


	template<>
	struct NodeEnumToType<::DLDL::ast::Type::program>
	{
		constexpr static auto value = ::DLDL::ast::Type::program;
		using type = ::DLDL::ast::node::program;
	};

	template<>
	struct NodeEnumToType<::DLDL::ast::Type::stmts>
	{
		constexpr static auto value = ::DLDL::ast::Type::stmts;
		using type = ::DLDL::ast::node::stmts;
	};

	template<>
	struct NodeEnumToType<::DLDL::ast::Type::stmt>
	{
		constexpr static auto value = ::DLDL::ast::Type::stmt;
		using type = ::DLDL::ast::node::stmt;
	};

	template<>
	struct NodeEnumToType<::DLDL::ast::Type::ANY>
	{
		constexpr static auto value = ::DLDL::ast::Type::ANY;
		using type = ::DLDL::ast::node::ANY;
	};


template<::DLDL::ast::Type T>
constexpr static auto NodeEnumToType_v = ::DLDL::ast::relation::NodeEnumToType<T>::value;

template<::DLDL::ast::Type T>
using NodeEnumToType_t = typename ::DLDL::ast::relation::NodeEnumToType<T>::type;

}}}

#endif // DLDL_AST_RELATION_NODEENUMTOTYPE_H