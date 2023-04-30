#ifndef DLDL_GENERATION_AST_NODE_type_H
#define DLDL_GENERATION_AST_NODE_type_H

#include "DLDL_GENERATION/Ast/Node/DLDL_GENERATION.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GENERATION { namespace ast { namespace node { 

	class type : public DLDL_GENERATION<type>
	{
	private:
	public:
		type(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_GENERATION<type>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_GENERATION_AST_NODE_type_H
