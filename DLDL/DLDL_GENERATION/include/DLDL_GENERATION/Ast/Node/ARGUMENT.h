#ifndef DLDL_GENERATION_AST_NODE_ARGUMENT_H
#define DLDL_GENERATION_AST_NODE_ARGUMENT_H

#include "DLDL_GENERATION/Ast/Node/DLDL_GENERATION.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GENERATION { namespace ast { namespace node {

	class ARGUMENT : public DLDL_GENERATION<ARGUMENT>
	{
	private:
	public:
		ARGUMENT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GENERATION<ARGUMENT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GENERATION_AST_NODE_ARGUMENT_H
