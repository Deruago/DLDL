#ifndef DLDL_VALUE_AST_NODE_VARNAME_H
#define DLDL_VALUE_AST_NODE_VARNAME_H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node {

	class VARNAME : public DLDL_VALUE<VARNAME>
	{
	private:
	public:
		VARNAME(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_VALUE<VARNAME>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_VARNAME_H
