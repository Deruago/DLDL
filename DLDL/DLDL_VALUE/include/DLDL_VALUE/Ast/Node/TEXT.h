#ifndef DLDL_VALUE_AST_NODE_TEXT_H
#define DLDL_VALUE_AST_NODE_TEXT_H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node {

	class TEXT : public DLDL_VALUE<TEXT>
	{
	private:
	public:
		TEXT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_VALUE<TEXT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_TEXT_H
