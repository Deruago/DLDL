#ifndef DLDL_LEXER_AST_NODE_NOVALUE_ABSTRACTION_H
#define DLDL_LEXER_AST_NODE_NOVALUE_ABSTRACTION_H

#include "DLDL_LEXER/Ast/Node/DLDL_LEXER.h"
#include "DLDL_LEXER/Ast/Node/abstraction.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LEXER { namespace ast { namespace node {

	class NOVALUE_ABSTRACTION : public DLDL_LEXER<NOVALUE_ABSTRACTION>, public ::DLDL_LEXER::ast::common::node::abstraction
	{
	private:
	public:
		NOVALUE_ABSTRACTION(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LEXER<NOVALUE_ABSTRACTION>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LEXER_AST_NODE_NOVALUE_ABSTRACTION_H
