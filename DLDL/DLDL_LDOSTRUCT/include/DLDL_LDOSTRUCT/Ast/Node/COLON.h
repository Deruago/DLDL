#ifndef DLDL_LDOSTRUCT_AST_NODE_COLON_H
#define DLDL_LDOSTRUCT_AST_NODE_COLON_H

#include "DLDL_LDOSTRUCT/Ast/Node/DLDL_LDOSTRUCT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LDOSTRUCT { namespace ast { namespace node {

	class COLON : public DLDL_LDOSTRUCT<COLON>
	{
	private:
	public:
		COLON(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LDOSTRUCT<COLON>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LDOSTRUCT_AST_NODE_COLON_H
