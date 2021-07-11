#ifndef DLDL_GRAMMAR_AST_NODE_NONTERMINAL_H
#define DLDL_GRAMMAR_AST_NODE_NONTERMINAL_H

#include "DLDL_GRAMMAR/Ast/Node/DLDL_GRAMMAR.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR { namespace ast { namespace node {

	class NONTERMINAL : public DLDL_GRAMMAR<NONTERMINAL>
	{
	private:
	public:
		NONTERMINAL(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GRAMMAR<NONTERMINAL>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_NODE_NONTERMINAL_H
