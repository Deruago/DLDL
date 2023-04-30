#ifndef DLDL_IMPORT_AST_NODE_VARNAME_H
#define DLDL_IMPORT_AST_NODE_VARNAME_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node {

	class VARNAME : public DLDL_IMPORT<VARNAME>
	{
	private:
	public:
		VARNAME(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_IMPORT<VARNAME>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_VARNAME_H
