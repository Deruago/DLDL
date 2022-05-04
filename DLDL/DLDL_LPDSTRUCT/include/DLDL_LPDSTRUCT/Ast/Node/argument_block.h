#ifndef DLDL_LPDSTRUCT_AST_NODE_argument_block_H
#define DLDL_LPDSTRUCT_AST_NODE_argument_block_H

#include "DLDL_LPDSTRUCT/Ast/Node/DLDL_LPDSTRUCT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDSTRUCT { namespace ast { namespace node { 

	class argument_block : public DLDL_LPDSTRUCT<argument_block>
	{
	private:
	public:
		argument_block(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LPDSTRUCT<argument_block>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LPDSTRUCT_AST_NODE_argument_block_H
