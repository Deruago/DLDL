#ifndef DLDL_LDOSTRUCT_AST_NODE_argument_block_H
#define DLDL_LDOSTRUCT_AST_NODE_argument_block_H

#include "DLDL_LDOSTRUCT/Ast/Node/DLDL_LDOSTRUCT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LDOSTRUCT { namespace ast { namespace node { 

	class argument_block : public DLDL_LDOSTRUCT<argument_block>
	{
	private:
	public:
		argument_block(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LDOSTRUCT<argument_block>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LDOSTRUCT_AST_NODE_argument_block_H
