#ifndef DLDL_AST_NODE_stmts_H
#define DLDL_AST_NODE_stmts_H

#include "DLDL/Ast/Node/DLDL.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL { namespace ast { namespace node { 

	class stmts : public DLDL<stmts>
	{
	private:
	public:
		stmts(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL<stmts>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_AST_NODE_stmts_H
