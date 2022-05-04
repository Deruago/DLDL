#ifndef DLDL_LPDDEF_AST_NODE_argument_block_H
#define DLDL_LPDDEF_AST_NODE_argument_block_H

#include "DLDL_LPDDEF/Ast/Node/DLDL_LPDDEF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF { namespace ast { namespace node { 

	class argument_block : public DLDL_LPDDEF<argument_block>
	{
	private:
	public:
		argument_block(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LPDDEF<argument_block>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_AST_NODE_argument_block_H
