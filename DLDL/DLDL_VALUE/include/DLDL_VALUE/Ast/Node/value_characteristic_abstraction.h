#ifndef DLDL_VALUE_AST_NODE_value_characteristic_abstraction_H
#define DLDL_VALUE_AST_NODE_value_characteristic_abstraction_H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node { 

	class value_characteristic_abstraction : public DLDL_VALUE<value_characteristic_abstraction>
	{
	private:
	public:
		value_characteristic_abstraction(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_VALUE<value_characteristic_abstraction>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_value_characteristic_abstraction_H
