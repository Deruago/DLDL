#ifndef DLDL_VALUE_AST_NODE_MULTI_COMMENT_H
#define DLDL_VALUE_AST_NODE_MULTI_COMMENT_H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node {

	class MULTI_COMMENT : public DLDL_VALUE<MULTI_COMMENT>
	{
	private:
	public:
		MULTI_COMMENT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_VALUE<MULTI_COMMENT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_MULTI_COMMENT_H
