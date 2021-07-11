#ifndef DLDL_GENERATION_AST_NODE_SYMBOLS_H
#define DLDL_GENERATION_AST_NODE_SYMBOLS_H

#include "DLDL_GENERATION/Ast/Node/DLDL_GENERATION.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GENERATION { namespace ast { namespace node {

	class SYMBOLS : public DLDL_GENERATION<SYMBOLS>
	{
	private:
	public:
		SYMBOLS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GENERATION<SYMBOLS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GENERATION_AST_NODE_SYMBOLS_H
