#ifndef DLDL_PRECEDENCE_AST_NODE_ANY_H
#define DLDL_PRECEDENCE_AST_NODE_ANY_H

#include "DLDL_PRECEDENCE/Ast/Node/DLDL_PRECEDENCE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_PRECEDENCE { namespace ast { namespace node {

	class ANY : public DLDL_PRECEDENCE<ANY>
	{
	private:
	public:
		ANY(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_PRECEDENCE<ANY>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_PRECEDENCE_AST_NODE_ANY_H
