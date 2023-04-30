#ifndef DLDL_GENERATION_AST_NODE_stmts_H
#define DLDL_GENERATION_AST_NODE_stmts_H

#include "DLDL_GENERATION/Ast/Node/DLDL_GENERATION.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GENERATION { namespace ast { namespace node { 

	class stmts : public DLDL_GENERATION<stmts>
	{
	private:
	public:
		stmts(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_GENERATION<stmts>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_GENERATION_AST_NODE_stmts_H
