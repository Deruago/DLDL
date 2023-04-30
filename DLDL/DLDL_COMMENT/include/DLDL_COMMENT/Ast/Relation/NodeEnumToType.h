#ifndef DLDL_COMMENT_AST_RELATION_NODEENUMTOTYPE_H
#define DLDL_COMMENT_AST_RELATION_NODEENUMTOTYPE_H

#include "DLDL_COMMENT/Ast/Enum/Type.h"

#include "DLDL_COMMENT/Ast/Node/program.h"
#include "DLDL_COMMENT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_COMMENT/Ast/Node/stmt.h"
#include "DLDL_COMMENT/Ast/Node/comment_value_declaration.h"
#include "DLDL_COMMENT/Ast/Node/deamerreserved_long_3.h"
#include "DLDL_COMMENT/Ast/Node/deamerreserved_long_6.h"
#include "DLDL_COMMENT/Ast/Node/comment_abstraction.h"
#include "DLDL_COMMENT/Ast/Node/start_abstraction.h"
#include "DLDL_COMMENT/Ast/Node/end_abstraction.h"
#include "DLDL_COMMENT/Ast/Node/start_sequence.h"
#include "DLDL_COMMENT/Ast/Node/end_sequence.h"
#include "DLDL_COMMENT/Ast/Node/sequence.h"
#include "DLDL_COMMENT/Ast/Node/syntactic_reference.h"
#include "DLDL_COMMENT/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_COMMENT/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_COMMENT/Ast/Node/COMMENT_VALUE.h"
#include "DLDL_COMMENT/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_COMMENT/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_COMMENT/Ast/Node/START.h"
#include "DLDL_COMMENT/Ast/Node/END.h"
#include "DLDL_COMMENT/Ast/Node/TEXT.h"
#include "DLDL_COMMENT/Ast/Node/VARNAME.h"
#include "DLDL_COMMENT/Ast/Node/ESCAPE_CHARS.h"


namespace DLDL_COMMENT { namespace ast { namespace relation { 

	template<::DLDL_COMMENT::ast::Type T>
	struct NodeEnumToType
	{
		constexpr static auto value = T;
		using type = void;
	};


	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::program>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::program;
		using type = ::DLDL_COMMENT::ast::node::program;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::deamerreserved_star__stmt__>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::deamerreserved_star__stmt__;
		using type = ::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::stmt>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::stmt;
		using type = ::DLDL_COMMENT::ast::node::stmt;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::comment_value_declaration>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::comment_value_declaration;
		using type = ::DLDL_COMMENT::ast::node::comment_value_declaration;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::deamerreserved_long_3>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::deamerreserved_long_3;
		using type = ::DLDL_COMMENT::ast::node::deamerreserved_long_3;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::deamerreserved_long_6>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::deamerreserved_long_6;
		using type = ::DLDL_COMMENT::ast::node::deamerreserved_long_6;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::comment_abstraction>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::comment_abstraction;
		using type = ::DLDL_COMMENT::ast::node::comment_abstraction;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::start_abstraction>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::start_abstraction;
		using type = ::DLDL_COMMENT::ast::node::start_abstraction;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::end_abstraction>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::end_abstraction;
		using type = ::DLDL_COMMENT::ast::node::end_abstraction;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::start_sequence>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::start_sequence;
		using type = ::DLDL_COMMENT::ast::node::start_sequence;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::end_sequence>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::end_sequence;
		using type = ::DLDL_COMMENT::ast::node::end_sequence;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::sequence>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::sequence;
		using type = ::DLDL_COMMENT::ast::node::sequence;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::syntactic_reference>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::syntactic_reference;
		using type = ::DLDL_COMMENT::ast::node::syntactic_reference;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::SINGLE_COMMENT>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::SINGLE_COMMENT;
		using type = ::DLDL_COMMENT::ast::node::SINGLE_COMMENT;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::MULTI_COMMENT>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::MULTI_COMMENT;
		using type = ::DLDL_COMMENT::ast::node::MULTI_COMMENT;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::COMMENT_VALUE>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::COMMENT_VALUE;
		using type = ::DLDL_COMMENT::ast::node::COMMENT_VALUE;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::LEFT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::LEFT_SQUARE_BRACKET;
		using type = ::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::RIGHT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::RIGHT_SQUARE_BRACKET;
		using type = ::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::START>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::START;
		using type = ::DLDL_COMMENT::ast::node::START;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::END>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::END;
		using type = ::DLDL_COMMENT::ast::node::END;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::TEXT>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::TEXT;
		using type = ::DLDL_COMMENT::ast::node::TEXT;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::VARNAME>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::VARNAME;
		using type = ::DLDL_COMMENT::ast::node::VARNAME;
	};

	template<>
	struct NodeEnumToType<::DLDL_COMMENT::ast::Type::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_COMMENT::ast::node::ESCAPE_CHARS;
	};


template<::DLDL_COMMENT::ast::Type T>
constexpr static auto NodeEnumToType_v = ::DLDL_COMMENT::ast::relation::NodeEnumToType<T>::value;

template<::DLDL_COMMENT::ast::Type T>
using NodeEnumToType_t = typename ::DLDL_COMMENT::ast::relation::NodeEnumToType<T>::type;

}}}

#endif // DLDL_COMMENT_AST_RELATION_NODEENUMTOTYPE_H