#ifndef DLDL_VALUE_AST_NODE_abstraction_name_H
#define DLDL_VALUE_AST_NODE_abstraction_name_H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node { 

	class abstraction_name : public DLDL_VALUE<abstraction_name>
	{
	private:
	public:
		abstraction_name(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_VALUE<abstraction_name>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_abstraction_name_H
