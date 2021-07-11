#ifndef DLDL_GRAMMAR_AST_NODE_SPACES_H
#define DLDL_GRAMMAR_AST_NODE_SPACES_H

#include "DLDL_GRAMMAR/Ast/Node/DLDL_GRAMMAR.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR { namespace ast { namespace node {

	class SPACES : public DLDL_GRAMMAR<SPACES>
	{
	private:
	public:
		SPACES(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GRAMMAR<SPACES>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_NODE_SPACES_H
