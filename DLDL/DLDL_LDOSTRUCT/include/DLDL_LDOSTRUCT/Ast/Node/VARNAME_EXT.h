#ifndef DLDL_LDOSTRUCT_AST_NODE_VARNAME_EXT_H
#define DLDL_LDOSTRUCT_AST_NODE_VARNAME_EXT_H

#include "DLDL_LDOSTRUCT/Ast/Node/DLDL_LDOSTRUCT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LDOSTRUCT { namespace ast { namespace node {

	class VARNAME_EXT : public DLDL_LDOSTRUCT<VARNAME_EXT>
	{
	private:
	public:
		VARNAME_EXT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LDOSTRUCT<VARNAME_EXT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LDOSTRUCT_AST_NODE_VARNAME_EXT_H
