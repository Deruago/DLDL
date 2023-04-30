#ifndef DLDL_PRECEDENCE_AST_NODE_stmts_H
#define DLDL_PRECEDENCE_AST_NODE_stmts_H

#include "DLDL_PRECEDENCE/Ast/Node/DLDL_PRECEDENCE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_PRECEDENCE { namespace ast { namespace node { 

	class stmts : public DLDL_PRECEDENCE<stmts>
	{
	private:
	public:
		stmts(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_PRECEDENCE<stmts>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_PRECEDENCE_AST_NODE_stmts_H
