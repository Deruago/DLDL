#ifndef DLDL_GENERATION_AST_NODE_argument_data_H
#define DLDL_GENERATION_AST_NODE_argument_data_H

#include "DLDL_GENERATION/Ast/Node/DLDL_GENERATION.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GENERATION { namespace ast { namespace node { 

	class argument_data : public DLDL_GENERATION<argument_data>
	{
	private:
	public:
		argument_data(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_GENERATION<argument_data>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_GENERATION_AST_NODE_argument_data_H
