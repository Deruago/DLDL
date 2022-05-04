#ifndef DLDL_GENERATION_AST_NODE_VALUE_H
#define DLDL_GENERATION_AST_NODE_VALUE_H

#include "DLDL_GENERATION/Ast/Node/DLDL_GENERATION.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GENERATION { namespace ast { namespace node {

	class VALUE : public DLDL_GENERATION<VALUE>
	{
	private:
	public:
		VALUE(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GENERATION<VALUE>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GENERATION_AST_NODE_VALUE_H
