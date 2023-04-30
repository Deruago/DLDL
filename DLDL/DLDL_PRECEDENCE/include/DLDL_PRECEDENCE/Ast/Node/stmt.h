#ifndef DLDL_PRECEDENCE_AST_NODE_stmt_H
#define DLDL_PRECEDENCE_AST_NODE_stmt_H

#include "DLDL_PRECEDENCE/Ast/Node/DLDL_PRECEDENCE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_PRECEDENCE { namespace ast { namespace node { 

	class stmt : public DLDL_PRECEDENCE<stmt>
	{
	private:
	public:
		stmt(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_PRECEDENCE<stmt>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_PRECEDENCE_AST_NODE_stmt_H
