#ifndef DLDL_LEXER_AST_NODE_IGNORE_ABSTRACTION_H
#define DLDL_LEXER_AST_NODE_IGNORE_ABSTRACTION_H

#include "DLDL_LEXER/Ast/Node/DLDL_LEXER.h"
#include "DLDL_LEXER/Ast/Node/abstraction.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LEXER { namespace ast { namespace node {

	class IGNORE_ABSTRACTION : public DLDL_LEXER<IGNORE_ABSTRACTION>, public ::DLDL_LEXER::ast::common::node::abstraction
	{
	private:
	public:
		IGNORE_ABSTRACTION(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LEXER<IGNORE_ABSTRACTION>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LEXER_AST_NODE_IGNORE_ABSTRACTION_H
