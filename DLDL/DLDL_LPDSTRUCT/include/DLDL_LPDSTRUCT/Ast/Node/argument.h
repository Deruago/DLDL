#ifndef DLDL_LPDSTRUCT_AST_NODE_argument_H
#define DLDL_LPDSTRUCT_AST_NODE_argument_H

#include "DLDL_LPDSTRUCT/Ast/Node/DLDL_LPDSTRUCT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDSTRUCT { namespace ast { namespace node { 

	class argument : public DLDL_LPDSTRUCT<argument>
	{
	private:
	public:
		argument(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LPDSTRUCT<argument>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LPDSTRUCT_AST_NODE_argument_H
