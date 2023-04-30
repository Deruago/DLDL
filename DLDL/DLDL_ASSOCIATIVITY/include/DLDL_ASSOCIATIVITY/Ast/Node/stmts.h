#ifndef DLDL_ASSOCIATIVITY_AST_NODE_stmts_H
#define DLDL_ASSOCIATIVITY_AST_NODE_stmts_H

#include "DLDL_ASSOCIATIVITY/Ast/Node/DLDL_ASSOCIATIVITY.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_ASSOCIATIVITY { namespace ast { namespace node { 

	class stmts : public DLDL_ASSOCIATIVITY<stmts>
	{
	private:
	public:
		stmts(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_ASSOCIATIVITY<stmts>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_ASSOCIATIVITY_AST_NODE_stmts_H
