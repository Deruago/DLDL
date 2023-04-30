#ifndef DLDL_COMMENT_AST_NODE_COMMENT_VALUE_H
#define DLDL_COMMENT_AST_NODE_COMMENT_VALUE_H

#include "DLDL_COMMENT/Ast/Node/DLDL_COMMENT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_COMMENT { namespace ast { namespace node {

	class COMMENT_VALUE : public DLDL_COMMENT<COMMENT_VALUE>
	{
	private:
	public:
		COMMENT_VALUE(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_COMMENT<COMMENT_VALUE>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_COMMENT_AST_NODE_COMMENT_VALUE_H
