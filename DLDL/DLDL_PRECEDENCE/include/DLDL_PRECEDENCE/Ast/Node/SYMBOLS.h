#ifndef DLDL_PRECEDENCE_AST_NODE_SYMBOLS_H
#define DLDL_PRECEDENCE_AST_NODE_SYMBOLS_H

#include "DLDL_PRECEDENCE/Ast/Node/DLDL_PRECEDENCE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_PRECEDENCE { namespace ast { namespace node {

	class SYMBOLS : public DLDL_PRECEDENCE<SYMBOLS>
	{
	private:
	public:
		SYMBOLS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_PRECEDENCE<SYMBOLS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_PRECEDENCE_AST_NODE_SYMBOLS_H
