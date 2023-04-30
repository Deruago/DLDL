#ifndef DLDL_ARGUMENT_AST_NODE_MULTI_COMMENT_H
#define DLDL_ARGUMENT_AST_NODE_MULTI_COMMENT_H

#include "DLDL_ARGUMENT/Ast/Node/DLDL_ARGUMENT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_ARGUMENT { namespace ast { namespace node {

	class MULTI_COMMENT : public DLDL_ARGUMENT<MULTI_COMMENT>
	{
	private:
	public:
		MULTI_COMMENT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_ARGUMENT<MULTI_COMMENT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_ARGUMENT_AST_NODE_MULTI_COMMENT_H
