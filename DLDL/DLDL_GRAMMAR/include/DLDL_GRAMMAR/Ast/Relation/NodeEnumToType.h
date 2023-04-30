#ifndef DLDL_GRAMMAR_AST_RELATION_NODEENUMTOTYPE_H
#define DLDL_GRAMMAR_AST_RELATION_NODEENUMTOTYPE_H

#include "DLDL_GRAMMAR/Ast/Enum/Type.h"

#include "DLDL_GRAMMAR/Ast/Node/program.h"
#include "DLDL_GRAMMAR/Ast/Node/stmts.h"
#include "DLDL_GRAMMAR/Ast/Node/stmt.h"
#include "DLDL_GRAMMAR/Ast/Node/abstraction_declaration.h"
#include "DLDL_GRAMMAR/Ast/Node/abstraction.h"
#include "DLDL_GRAMMAR/Ast/Node/definition.h"
#include "DLDL_GRAMMAR/Ast/Node/production_rules.h"
#include "DLDL_GRAMMAR/Ast/Node/COMMENT.h"
#include "DLDL_GRAMMAR/Ast/Node/START_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/GROUP_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/INLINE_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/INLINE_GROUP_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/UNKNOWN_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/NONTERMINAL.h"
#include "DLDL_GRAMMAR/Ast/Node/PRODUCTION_RULE.h"
#include "DLDL_GRAMMAR/Ast/Node/ESCAPE_CHARS.h"


namespace DLDL_GRAMMAR { namespace ast { namespace relation { 

	template<::DLDL_GRAMMAR::ast::Type T>
	struct NodeEnumToType
	{
		constexpr static auto value = T;
		using type = void;
	};


	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR::ast::Type::program>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::program;
		using type = ::DLDL_GRAMMAR::ast::node::program;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR::ast::Type::stmts>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::stmts;
		using type = ::DLDL_GRAMMAR::ast::node::stmts;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR::ast::Type::stmt>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::stmt;
		using type = ::DLDL_GRAMMAR::ast::node::stmt;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR::ast::Type::abstraction_declaration>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::abstraction_declaration;
		using type = ::DLDL_GRAMMAR::ast::node::abstraction_declaration;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR::ast::Type::abstraction>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::abstraction;
		using type = ::DLDL_GRAMMAR::ast::node::abstraction;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR::ast::Type::definition>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::definition;
		using type = ::DLDL_GRAMMAR::ast::node::definition;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR::ast::Type::production_rules>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::production_rules;
		using type = ::DLDL_GRAMMAR::ast::node::production_rules;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR::ast::Type::COMMENT>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::COMMENT;
		using type = ::DLDL_GRAMMAR::ast::node::COMMENT;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR::ast::Type::START_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::START_ABSTRACTION;
		using type = ::DLDL_GRAMMAR::ast::node::START_ABSTRACTION;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR::ast::Type::GROUP_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::GROUP_ABSTRACTION;
		using type = ::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR::ast::Type::INLINE_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::INLINE_ABSTRACTION;
		using type = ::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR::ast::Type::INLINE_GROUP_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::INLINE_GROUP_ABSTRACTION;
		using type = ::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR::ast::Type::UNKNOWN_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::UNKNOWN_ABSTRACTION;
		using type = ::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR::ast::Type::NONTERMINAL>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::NONTERMINAL;
		using type = ::DLDL_GRAMMAR::ast::node::NONTERMINAL;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR::ast::Type::PRODUCTION_RULE>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::PRODUCTION_RULE;
		using type = ::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR::ast::Type::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_GRAMMAR::ast::node::ESCAPE_CHARS;
	};


template<::DLDL_GRAMMAR::ast::Type T>
constexpr static auto NodeEnumToType_v = ::DLDL_GRAMMAR::ast::relation::NodeEnumToType<T>::value;

template<::DLDL_GRAMMAR::ast::Type T>
using NodeEnumToType_t = typename ::DLDL_GRAMMAR::ast::relation::NodeEnumToType<T>::type;

}}}

#endif // DLDL_GRAMMAR_AST_RELATION_NODEENUMTOTYPE_H