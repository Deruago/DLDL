#ifndef DLDL_ARGUMENT_AST_RELATION_NODEENUMTOTYPE_H
#define DLDL_ARGUMENT_AST_RELATION_NODEENUMTOTYPE_H

#include "DLDL_ARGUMENT/Ast/Enum/Type.h"

#include "DLDL_ARGUMENT/Ast/Node/program.h"
#include "DLDL_ARGUMENT/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_ARGUMENT/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_ARGUMENT/Ast/Node/TEXT.h"
#include "DLDL_ARGUMENT/Ast/Node/VARNAME.h"
#include "DLDL_ARGUMENT/Ast/Node/ESCAPE_CHARS.h"


namespace DLDL_ARGUMENT { namespace ast { namespace relation { 

	template<::DLDL_ARGUMENT::ast::Type T>
	struct NodeEnumToType
	{
		constexpr static auto value = T;
		using type = void;
	};


	template<>
	struct NodeEnumToType<::DLDL_ARGUMENT::ast::Type::program>
	{
		constexpr static auto value = ::DLDL_ARGUMENT::ast::Type::program;
		using type = ::DLDL_ARGUMENT::ast::node::program;
	};

	template<>
	struct NodeEnumToType<::DLDL_ARGUMENT::ast::Type::SINGLE_COMMENT>
	{
		constexpr static auto value = ::DLDL_ARGUMENT::ast::Type::SINGLE_COMMENT;
		using type = ::DLDL_ARGUMENT::ast::node::SINGLE_COMMENT;
	};

	template<>
	struct NodeEnumToType<::DLDL_ARGUMENT::ast::Type::MULTI_COMMENT>
	{
		constexpr static auto value = ::DLDL_ARGUMENT::ast::Type::MULTI_COMMENT;
		using type = ::DLDL_ARGUMENT::ast::node::MULTI_COMMENT;
	};

	template<>
	struct NodeEnumToType<::DLDL_ARGUMENT::ast::Type::TEXT>
	{
		constexpr static auto value = ::DLDL_ARGUMENT::ast::Type::TEXT;
		using type = ::DLDL_ARGUMENT::ast::node::TEXT;
	};

	template<>
	struct NodeEnumToType<::DLDL_ARGUMENT::ast::Type::VARNAME>
	{
		constexpr static auto value = ::DLDL_ARGUMENT::ast::Type::VARNAME;
		using type = ::DLDL_ARGUMENT::ast::node::VARNAME;
	};

	template<>
	struct NodeEnumToType<::DLDL_ARGUMENT::ast::Type::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_ARGUMENT::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_ARGUMENT::ast::node::ESCAPE_CHARS;
	};


template<::DLDL_ARGUMENT::ast::Type T>
constexpr static auto NodeEnumToType_v = ::DLDL_ARGUMENT::ast::relation::NodeEnumToType<T>::value;

template<::DLDL_ARGUMENT::ast::Type T>
using NodeEnumToType_t = typename ::DLDL_ARGUMENT::ast::relation::NodeEnumToType<T>::type;

}}}

#endif // DLDL_ARGUMENT_AST_RELATION_NODEENUMTOTYPE_H