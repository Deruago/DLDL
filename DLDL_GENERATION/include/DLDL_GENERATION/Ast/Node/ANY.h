#ifndef DLDL_GENERATION_AST_NODE_ANY_H
#define DLDL_GENERATION_AST_NODE_ANY_H

#include "DLDL_GENERATION/Ast/Node/DLDL_GENERATION.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GENERATION { namespace ast { namespace node {

	class ANY : public DLDL_GENERATION<ANY>
	{
	private:
	public:
		ANY(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GENERATION<ANY>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GENERATION_AST_NODE_ANY_H
