#ifndef DLDL_COMMENT_AST_NODE_END_H
#define DLDL_COMMENT_AST_NODE_END_H

#include "DLDL_COMMENT/Ast/Node/DLDL_COMMENT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_COMMENT { namespace ast { namespace node {

	class END : public DLDL_COMMENT<END>
	{
	private:
	public:
		END(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_COMMENT<END>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_COMMENT_AST_NODE_END_H
