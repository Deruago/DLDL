#ifndef DLDL_VALUE_AST_NODE_SINGLE_COMMENT_H
#define DLDL_VALUE_AST_NODE_SINGLE_COMMENT_H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node {

	class SINGLE_COMMENT : public DLDL_VALUE<SINGLE_COMMENT>
	{
	private:
	public:
		SINGLE_COMMENT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_VALUE<SINGLE_COMMENT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_SINGLE_COMMENT_H
