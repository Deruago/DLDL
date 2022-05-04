#ifndef DLDL_LPDDEF_AST_NODE_argument_H
#define DLDL_LPDDEF_AST_NODE_argument_H

#include "DLDL_LPDDEF/Ast/Node/DLDL_LPDDEF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF { namespace ast { namespace node { 

	class argument : public DLDL_LPDDEF<argument>
	{
	private:
	public:
		argument(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LPDDEF<argument>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_AST_NODE_argument_H
