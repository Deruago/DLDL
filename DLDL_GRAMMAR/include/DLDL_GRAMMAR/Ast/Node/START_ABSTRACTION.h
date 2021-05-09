#ifndef DLDL_GRAMMAR_AST_NODE_START_ABSTRACTION_H
#define DLDL_GRAMMAR_AST_NODE_START_ABSTRACTION_H

#include "DLDL_GRAMMAR/Ast/Node/DLDL_GRAMMAR.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR { namespace ast { namespace node {

	class START_ABSTRACTION : public DLDL_GRAMMAR<START_ABSTRACTION>
	{
	private:
	public:
		START_ABSTRACTION(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GRAMMAR<START_ABSTRACTION>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_NODE_START_ABSTRACTION_H
