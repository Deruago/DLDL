#ifndef DLDL_PRECEDENCE_AST_NODE_PRECEDENCE_H
#define DLDL_PRECEDENCE_AST_NODE_PRECEDENCE_H

#include "DLDL_PRECEDENCE/Ast/Node/DLDL_PRECEDENCE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_PRECEDENCE { namespace ast { namespace node {

	class PRECEDENCE : public DLDL_PRECEDENCE<PRECEDENCE>
	{
	private:
	public:
		PRECEDENCE(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_PRECEDENCE<PRECEDENCE>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_PRECEDENCE_AST_NODE_PRECEDENCE_H
