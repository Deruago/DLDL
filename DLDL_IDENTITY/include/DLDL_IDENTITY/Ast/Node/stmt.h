#ifndef DLDL_IDENTITY_AST_NODE_stmt_H
#define DLDL_IDENTITY_AST_NODE_stmt_H

#include "DLDL_IDENTITY/Ast/Node/DLDL_IDENTITY.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IDENTITY { namespace ast { namespace node { 

	class stmt : public DLDL_IDENTITY<stmt>
	{
	private:
	public:
		stmt(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_IDENTITY<stmt>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_IDENTITY_AST_NODE_stmt_H
