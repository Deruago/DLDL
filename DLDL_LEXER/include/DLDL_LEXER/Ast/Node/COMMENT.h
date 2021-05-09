#ifndef DLDL_LEXER_AST_NODE_COMMENT_H
#define DLDL_LEXER_AST_NODE_COMMENT_H

#include "DLDL_LEXER/Ast/Node/DLDL_LEXER.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LEXER { namespace ast { namespace node {

	class COMMENT : public DLDL_LEXER<COMMENT>
	{
	private:
	public:
		COMMENT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LEXER<COMMENT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LEXER_AST_NODE_COMMENT_H
