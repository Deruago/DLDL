#ifndef DLDL_GRAMMAR_AST_NODE_UNKNOWN_ABSTRACTION_H
#define DLDL_GRAMMAR_AST_NODE_UNKNOWN_ABSTRACTION_H

#include "DLDL_GRAMMAR/Ast/Node/DLDL_GRAMMAR.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR { namespace ast { namespace node {

	class UNKNOWN_ABSTRACTION : public DLDL_GRAMMAR<UNKNOWN_ABSTRACTION>
	{
	private:
	public:
		UNKNOWN_ABSTRACTION(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GRAMMAR<UNKNOWN_ABSTRACTION>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_NODE_UNKNOWN_ABSTRACTION_H
