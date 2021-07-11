#ifndef DLDL_IDENTITY_AST_NODE_SYMBOLS_H
#define DLDL_IDENTITY_AST_NODE_SYMBOLS_H

#include "DLDL_IDENTITY/Ast/Node/DLDL_IDENTITY.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IDENTITY { namespace ast { namespace node {

	class SYMBOLS : public DLDL_IDENTITY<SYMBOLS>
	{
	private:
	public:
		SYMBOLS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_IDENTITY<SYMBOLS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_IDENTITY_AST_NODE_SYMBOLS_H
