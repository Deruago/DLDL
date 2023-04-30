#ifndef DLDL_PRECEDENCE_AST_NODE_NUMBER_H
#define DLDL_PRECEDENCE_AST_NODE_NUMBER_H

#include "DLDL_PRECEDENCE/Ast/Node/DLDL_PRECEDENCE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_PRECEDENCE { namespace ast { namespace node {

	class NUMBER : public DLDL_PRECEDENCE<NUMBER>
	{
	private:
	public:
		NUMBER(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_PRECEDENCE<NUMBER>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_PRECEDENCE_AST_NODE_NUMBER_H
