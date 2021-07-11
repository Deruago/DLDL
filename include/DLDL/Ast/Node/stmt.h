#ifndef DLDL_AST_NODE_stmt_H
#define DLDL_AST_NODE_stmt_H

#include "DLDL/Ast/Node/DLDL.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL { namespace ast { namespace node { 

	class stmt : public DLDL<stmt>
	{
	private:
	public:
		stmt(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL<stmt>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_AST_NODE_stmt_H
