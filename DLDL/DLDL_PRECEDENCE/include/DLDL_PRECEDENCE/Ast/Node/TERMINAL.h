#ifndef DLDL_PRECEDENCE_AST_NODE_TERMINAL_H
#define DLDL_PRECEDENCE_AST_NODE_TERMINAL_H

#include "DLDL_PRECEDENCE/Ast/Node/DLDL_PRECEDENCE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_PRECEDENCE { namespace ast { namespace node {

	class TERMINAL : public DLDL_PRECEDENCE<TERMINAL>
	{
	private:
	public:
		TERMINAL(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_PRECEDENCE<TERMINAL>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_PRECEDENCE_AST_NODE_TERMINAL_H
