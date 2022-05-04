#ifndef DLDL_LPDDEF_AST_NODE_INDENTED_VALUE_H
#define DLDL_LPDDEF_AST_NODE_INDENTED_VALUE_H

#include "DLDL_LPDDEF/Ast/Node/DLDL_LPDDEF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF { namespace ast { namespace node {

	class INDENTED_VALUE : public DLDL_LPDDEF<INDENTED_VALUE>
	{
	private:
	public:
		INDENTED_VALUE(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF<INDENTED_VALUE>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_AST_NODE_INDENTED_VALUE_H
