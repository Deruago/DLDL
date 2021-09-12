#ifndef DLDL_LEXER_AST_NODE_MULTI_LINE_COMMENT_H
#define DLDL_LEXER_AST_NODE_MULTI_LINE_COMMENT_H

#include "DLDL_LEXER/Ast/Node/DLDL_LEXER.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LEXER { namespace ast { namespace node {

	class MULTI_LINE_COMMENT : public DLDL_LEXER<MULTI_LINE_COMMENT>
	{
	private:
	public:
		MULTI_LINE_COMMENT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LEXER<MULTI_LINE_COMMENT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LEXER_AST_NODE_MULTI_LINE_COMMENT_H
