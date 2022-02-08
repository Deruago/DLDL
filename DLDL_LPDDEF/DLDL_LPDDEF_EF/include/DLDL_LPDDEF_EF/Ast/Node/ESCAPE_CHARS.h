#ifndef DLDL_LPDDEF_EF_AST_NODE_ESCAPE_CHARS_H
#define DLDL_LPDDEF_EF_AST_NODE_ESCAPE_CHARS_H

#include "DLDL_LPDDEF_EF/Ast/Node/DLDL_LPDDEF_EF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_EF { namespace ast { namespace node {

	class ESCAPE_CHARS : public DLDL_LPDDEF_EF<ESCAPE_CHARS>
	{
	private:
	public:
		ESCAPE_CHARS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_EF<ESCAPE_CHARS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_EF_AST_NODE_ESCAPE_CHARS_H
