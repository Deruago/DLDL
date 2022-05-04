#ifndef DLDL_GRAMMAR_AST_NODE_stmts_H
#define DLDL_GRAMMAR_AST_NODE_stmts_H

#include "DLDL_GRAMMAR/Ast/Node/DLDL_GRAMMAR.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR { namespace ast { namespace node { 

	class stmts : public DLDL_GRAMMAR<stmts>
	{
	private:
	public:
		stmts(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_GRAMMAR<stmts>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_NODE_stmts_H
