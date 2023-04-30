#ifndef DLDL_VALUE_AST_NODE_NUMBER_H
#define DLDL_VALUE_AST_NODE_NUMBER_H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node {

	class NUMBER : public DLDL_VALUE<NUMBER>
	{
	private:
	public:
		NUMBER(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_VALUE<NUMBER>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_NUMBER_H
