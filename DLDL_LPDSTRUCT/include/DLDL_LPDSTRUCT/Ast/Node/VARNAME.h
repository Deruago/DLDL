#ifndef DLDL_LPDSTRUCT_AST_NODE_VARNAME_H
#define DLDL_LPDSTRUCT_AST_NODE_VARNAME_H

#include "DLDL_LPDSTRUCT/Ast/Node/DLDL_LPDSTRUCT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDSTRUCT { namespace ast { namespace node {

	class VARNAME : public DLDL_LPDSTRUCT<VARNAME>
	{
	private:
	public:
		VARNAME(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDSTRUCT<VARNAME>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDSTRUCT_AST_NODE_VARNAME_H
