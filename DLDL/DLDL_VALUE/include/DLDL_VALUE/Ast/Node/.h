#ifndef DLDL_VALUE_AST_NODE__H
#define DLDL_VALUE_AST_NODE__H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node { 

	class  : public DLDL_VALUE<>
	{
	private:
	public:
		(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_VALUE<>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE__H
