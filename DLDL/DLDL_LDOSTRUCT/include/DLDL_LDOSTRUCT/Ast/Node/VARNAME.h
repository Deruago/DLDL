#ifndef DLDL_LDOSTRUCT_AST_NODE_VARNAME_H
#define DLDL_LDOSTRUCT_AST_NODE_VARNAME_H

#include "DLDL_LDOSTRUCT/Ast/Node/DLDL_LDOSTRUCT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LDOSTRUCT { namespace ast { namespace node {

	class VARNAME : public DLDL_LDOSTRUCT<VARNAME>
	{
	private:
	public:
		VARNAME(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LDOSTRUCT<VARNAME>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LDOSTRUCT_AST_NODE_VARNAME_H
