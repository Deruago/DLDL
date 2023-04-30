#ifndef DLDL_VALUE_AST_NODE_LEFT_BRACKET_H
#define DLDL_VALUE_AST_NODE_LEFT_BRACKET_H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node {

	class LEFT_BRACKET : public DLDL_VALUE<LEFT_BRACKET>
	{
	private:
	public:
		LEFT_BRACKET(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_VALUE<LEFT_BRACKET>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_LEFT_BRACKET_H
