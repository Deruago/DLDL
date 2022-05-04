#ifndef DLDL_ASSOCIATIVITY_AST_NODE_ANY_H
#define DLDL_ASSOCIATIVITY_AST_NODE_ANY_H

#include "DLDL_ASSOCIATIVITY/Ast/Node/DLDL_ASSOCIATIVITY.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_ASSOCIATIVITY { namespace ast { namespace node {

	class ANY : public DLDL_ASSOCIATIVITY<ANY>
	{
	private:
	public:
		ANY(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_ASSOCIATIVITY<ANY>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_ASSOCIATIVITY_AST_NODE_ANY_H
