#ifndef DLDL_VALUE_AST_NODE_VALUE_CHARACTERISTIC_H
#define DLDL_VALUE_AST_NODE_VALUE_CHARACTERISTIC_H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node {

	class VALUE_CHARACTERISTIC : public DLDL_VALUE<VALUE_CHARACTERISTIC>
	{
	private:
	public:
		VALUE_CHARACTERISTIC(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_VALUE<VALUE_CHARACTERISTIC>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_VALUE_CHARACTERISTIC_H
