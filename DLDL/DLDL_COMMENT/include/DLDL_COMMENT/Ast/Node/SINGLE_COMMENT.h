#ifndef DLDL_COMMENT_AST_NODE_SINGLE_COMMENT_H
#define DLDL_COMMENT_AST_NODE_SINGLE_COMMENT_H

#include "DLDL_COMMENT/Ast/Node/DLDL_COMMENT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_COMMENT { namespace ast { namespace node {

	class SINGLE_COMMENT : public DLDL_COMMENT<SINGLE_COMMENT>
	{
	private:
	public:
		SINGLE_COMMENT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_COMMENT<SINGLE_COMMENT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_COMMENT_AST_NODE_SINGLE_COMMENT_H
