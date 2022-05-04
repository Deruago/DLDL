#ifndef DLDL_GENERATION_AST_NODE_INTEGRATE_H
#define DLDL_GENERATION_AST_NODE_INTEGRATE_H

#include "DLDL_GENERATION/Ast/Node/DLDL_GENERATION.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GENERATION { namespace ast { namespace node {

	class INTEGRATE : public DLDL_GENERATION<INTEGRATE>
	{
	private:
	public:
		INTEGRATE(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GENERATION<INTEGRATE>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GENERATION_AST_NODE_INTEGRATE_H
