#ifndef DLDL_VALUE_AST_NODE_RIGHT_SQUARE_BRACKET_H
#define DLDL_VALUE_AST_NODE_RIGHT_SQUARE_BRACKET_H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node {

	class RIGHT_SQUARE_BRACKET : public DLDL_VALUE<RIGHT_SQUARE_BRACKET>
	{
	private:
	public:
		RIGHT_SQUARE_BRACKET(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_VALUE<RIGHT_SQUARE_BRACKET>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_RIGHT_SQUARE_BRACKET_H
