#ifndef DLDL_IDENTITY_AST_NODE_ESCAPE_CHARS_H
#define DLDL_IDENTITY_AST_NODE_ESCAPE_CHARS_H

#include "DLDL_IDENTITY/Ast/Node/DLDL_IDENTITY.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IDENTITY { namespace ast { namespace node {

	class ESCAPE_CHARS : public DLDL_IDENTITY<ESCAPE_CHARS>
	{
	private:
	public:
		ESCAPE_CHARS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_IDENTITY<ESCAPE_CHARS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_IDENTITY_AST_NODE_ESCAPE_CHARS_H
