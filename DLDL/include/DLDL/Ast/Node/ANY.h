#ifndef DLDL_AST_NODE_ANY_H
#define DLDL_AST_NODE_ANY_H

#include "DLDL/Ast/Node/DLDL.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL { namespace ast { namespace node {

	class ANY : public DLDL<ANY>
	{
	private:
	public:
		ANY(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL<ANY>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_AST_NODE_ANY_H
