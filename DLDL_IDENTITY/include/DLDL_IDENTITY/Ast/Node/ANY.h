#ifndef DLDL_IDENTITY_AST_NODE_ANY_H
#define DLDL_IDENTITY_AST_NODE_ANY_H

#include "DLDL_IDENTITY/Ast/Node/DLDL_IDENTITY.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IDENTITY { namespace ast { namespace node {

	class ANY : public DLDL_IDENTITY<ANY>
	{
	private:
	public:
		ANY(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_IDENTITY<ANY>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_IDENTITY_AST_NODE_ANY_H
