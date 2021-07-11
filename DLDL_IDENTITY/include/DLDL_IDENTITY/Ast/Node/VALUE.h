#ifndef DLDL_IDENTITY_AST_NODE_VALUE_H
#define DLDL_IDENTITY_AST_NODE_VALUE_H

#include "DLDL_IDENTITY/Ast/Node/DLDL_IDENTITY.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IDENTITY { namespace ast { namespace node {

	class VALUE : public DLDL_IDENTITY<VALUE>
	{
	private:
	public:
		VALUE(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_IDENTITY<VALUE>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_IDENTITY_AST_NODE_VALUE_H
