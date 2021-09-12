#ifndef DLDL_IDENTITY_AST_NODE_stmts_H
#define DLDL_IDENTITY_AST_NODE_stmts_H

#include "DLDL_IDENTITY/Ast/Node/DLDL_IDENTITY.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IDENTITY { namespace ast { namespace node { 

	class stmts : public DLDL_IDENTITY<stmts>
	{
	private:
	public:
		stmts(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_IDENTITY<stmts>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_IDENTITY_AST_NODE_stmts_H
