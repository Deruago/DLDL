#ifndef DLDL_COMMENT_AST_NODE_LEFT_SQUARE_BRACKET_H
#define DLDL_COMMENT_AST_NODE_LEFT_SQUARE_BRACKET_H

#include "DLDL_COMMENT/Ast/Node/DLDL_COMMENT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_COMMENT { namespace ast { namespace node {

	class LEFT_SQUARE_BRACKET : public DLDL_COMMENT<LEFT_SQUARE_BRACKET>
	{
	private:
	public:
		LEFT_SQUARE_BRACKET(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_COMMENT<LEFT_SQUARE_BRACKET>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_COMMENT_AST_NODE_LEFT_SQUARE_BRACKET_H
