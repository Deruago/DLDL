#ifndef DLDL_LEXER_AST_COMMON_NODE_abstraction_H
#define DLDL_LEXER_AST_COMMON_NODE_abstraction_H

#include <Deamer/External/Cpp/Ast/CommonNodeAPI.h>

namespace DLDL_LEXER { namespace ast { namespace common { namespace node {

	class abstraction : public ::deamer::external::cpp::ast::CommonNodeAPI<abstraction>
	{	private:
	public:
		abstraction() = default;
		virtual ~abstraction() = default;
	public:
	};
}}}}

#endif // DLDL_LEXER_AST_COMMON_NODE_abstraction_H
