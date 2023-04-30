#ifndef DLDL_COMMENT_AST_NODE_TEXT_H
#define DLDL_COMMENT_AST_NODE_TEXT_H

#include "DLDL_COMMENT/Ast/Node/DLDL_COMMENT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_COMMENT { namespace ast { namespace node {

	class TEXT : public DLDL_COMMENT<TEXT>
	{
	private:
	public:
		TEXT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_COMMENT<TEXT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_COMMENT_AST_NODE_TEXT_H
