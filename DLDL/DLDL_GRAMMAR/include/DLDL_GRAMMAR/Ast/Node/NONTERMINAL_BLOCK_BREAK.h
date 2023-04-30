#ifndef DLDL_GRAMMAR_AST_NODE_NONTERMINAL_BLOCK_BREAK_H
#define DLDL_GRAMMAR_AST_NODE_NONTERMINAL_BLOCK_BREAK_H

#include "DLDL_GRAMMAR/Ast/Node/DLDL_GRAMMAR.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR { namespace ast { namespace node {

	class NONTERMINAL_BLOCK_BREAK : public DLDL_GRAMMAR<NONTERMINAL_BLOCK_BREAK>
	{
	private:
	public:
		NONTERMINAL_BLOCK_BREAK(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GRAMMAR<NONTERMINAL_BLOCK_BREAK>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_NODE_NONTERMINAL_BLOCK_BREAK_H
