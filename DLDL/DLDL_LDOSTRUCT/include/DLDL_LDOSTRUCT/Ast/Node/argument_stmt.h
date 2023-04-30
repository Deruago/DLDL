#ifndef DLDL_LDOSTRUCT_AST_NODE_argument_stmt_H
#define DLDL_LDOSTRUCT_AST_NODE_argument_stmt_H

#include "DLDL_LDOSTRUCT/Ast/Node/DLDL_LDOSTRUCT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LDOSTRUCT { namespace ast { namespace node { 

	class argument_stmt : public DLDL_LDOSTRUCT<argument_stmt>
	{
	private:
	public:
		argument_stmt(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LDOSTRUCT<argument_stmt>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LDOSTRUCT_AST_NODE_argument_stmt_H
