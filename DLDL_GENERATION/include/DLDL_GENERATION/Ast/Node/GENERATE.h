#ifndef DLDL_GENERATION_AST_NODE_GENERATE_H
#define DLDL_GENERATION_AST_NODE_GENERATE_H

#include "DLDL_GENERATION/Ast/Node/DLDL_GENERATION.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GENERATION { namespace ast { namespace node {

	class GENERATE : public DLDL_GENERATION<GENERATE>
	{
	private:
	public:
		GENERATE(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GENERATION<GENERATE>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GENERATION_AST_NODE_GENERATE_H
