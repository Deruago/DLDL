#ifndef DLDL_ARGUMENT_AST_NODE_TEXT_H
#define DLDL_ARGUMENT_AST_NODE_TEXT_H

#include "DLDL_ARGUMENT/Ast/Node/DLDL_ARGUMENT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_ARGUMENT { namespace ast { namespace node {

	class TEXT : public DLDL_ARGUMENT<TEXT>
	{
	private:
	public:
		TEXT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_ARGUMENT<TEXT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_ARGUMENT_AST_NODE_TEXT_H
