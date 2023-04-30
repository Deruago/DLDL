#ifndef DLDL_COMMENT_AST_NODE_START_H
#define DLDL_COMMENT_AST_NODE_START_H

#include "DLDL_COMMENT/Ast/Node/DLDL_COMMENT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_COMMENT { namespace ast { namespace node {

	class START : public DLDL_COMMENT<START>
	{
	private:
	public:
		START(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_COMMENT<START>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_COMMENT_AST_NODE_START_H
