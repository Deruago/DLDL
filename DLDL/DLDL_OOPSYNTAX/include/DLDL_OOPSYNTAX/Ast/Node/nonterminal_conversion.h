#ifndef DLDL_OOPSYNTAX_AST_NODE_nonterminal_conversion_H
#define DLDL_OOPSYNTAX_AST_NODE_nonterminal_conversion_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node { 

	class nonterminal_conversion : public DLDL_OOPSYNTAX<nonterminal_conversion>
	{
	private:
	public:
		nonterminal_conversion(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_OOPSYNTAX<nonterminal_conversion>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_nonterminal_conversion_H
