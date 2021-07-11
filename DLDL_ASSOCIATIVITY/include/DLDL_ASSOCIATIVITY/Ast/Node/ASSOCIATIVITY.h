#ifndef DLDL_ASSOCIATIVITY_AST_NODE_ASSOCIATIVITY_H
#define DLDL_ASSOCIATIVITY_AST_NODE_ASSOCIATIVITY_H

#include "DLDL_ASSOCIATIVITY/Ast/Node/DLDL_ASSOCIATIVITY.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_ASSOCIATIVITY { namespace ast { namespace node {

	class ASSOCIATIVITY : public DLDL_ASSOCIATIVITY<ASSOCIATIVITY>
	{
	private:
	public:
		ASSOCIATIVITY(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_ASSOCIATIVITY<ASSOCIATIVITY>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_ASSOCIATIVITY_AST_NODE_ASSOCIATIVITY_H
