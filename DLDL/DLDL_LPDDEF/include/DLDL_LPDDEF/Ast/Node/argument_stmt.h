#ifndef DLDL_LPDDEF_AST_NODE_argument_stmt_H
#define DLDL_LPDDEF_AST_NODE_argument_stmt_H

#include "DLDL_LPDDEF/Ast/Node/DLDL_LPDDEF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF { namespace ast { namespace node { 

	class argument_stmt : public DLDL_LPDDEF<argument_stmt>
	{
	private:
	public:
		argument_stmt(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LPDDEF<argument_stmt>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_AST_NODE_argument_stmt_H
