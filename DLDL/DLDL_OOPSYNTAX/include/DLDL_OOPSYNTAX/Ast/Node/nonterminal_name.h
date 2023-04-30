#ifndef DLDL_OOPSYNTAX_AST_NODE_nonterminal_name_H
#define DLDL_OOPSYNTAX_AST_NODE_nonterminal_name_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node { 

	class nonterminal_name : public DLDL_OOPSYNTAX<nonterminal_name>
	{
	private:
	public:
		nonterminal_name(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_OOPSYNTAX<nonterminal_name>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_nonterminal_name_H
