#ifndef DLDL_IDENTITY_AST_NODE_NAME_H
#define DLDL_IDENTITY_AST_NODE_NAME_H

#include "DLDL_IDENTITY/Ast/Node/DLDL_IDENTITY.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IDENTITY { namespace ast { namespace node {

	class NAME : public DLDL_IDENTITY<NAME>
	{
	private:
	public:
		NAME(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_IDENTITY<NAME>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_IDENTITY_AST_NODE_NAME_H
