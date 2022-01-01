#ifndef DLDL_LPDSTRUCT_AST_NODE_VARNAME_EXT_H
#define DLDL_LPDSTRUCT_AST_NODE_VARNAME_EXT_H

#include "DLDL_LPDSTRUCT/Ast/Node/DLDL_LPDSTRUCT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDSTRUCT { namespace ast { namespace node {

	class VARNAME_EXT : public DLDL_LPDSTRUCT<VARNAME_EXT>
	{
	private:
	public:
		VARNAME_EXT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDSTRUCT<VARNAME_EXT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDSTRUCT_AST_NODE_VARNAME_EXT_H
