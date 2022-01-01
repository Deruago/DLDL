#ifndef DLDL_LDOSTRUCT_AST_NODE_INDENTED_VALUE_H
#define DLDL_LDOSTRUCT_AST_NODE_INDENTED_VALUE_H

#include "DLDL_LDOSTRUCT/Ast/Node/DLDL_LDOSTRUCT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LDOSTRUCT { namespace ast { namespace node {

	class INDENTED_VALUE : public DLDL_LDOSTRUCT<INDENTED_VALUE>
	{
	private:
	public:
		INDENTED_VALUE(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LDOSTRUCT<INDENTED_VALUE>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LDOSTRUCT_AST_NODE_INDENTED_VALUE_H
