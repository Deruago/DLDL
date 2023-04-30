#ifndef DLDL_VALUE_AST_NODE_LEFT_PARANTHESIS_H
#define DLDL_VALUE_AST_NODE_LEFT_PARANTHESIS_H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node {

	class LEFT_PARANTHESIS : public DLDL_VALUE<LEFT_PARANTHESIS>
	{
	private:
	public:
		LEFT_PARANTHESIS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_VALUE<LEFT_PARANTHESIS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_LEFT_PARANTHESIS_H
