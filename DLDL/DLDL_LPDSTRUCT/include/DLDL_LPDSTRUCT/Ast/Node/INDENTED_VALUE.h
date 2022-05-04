#ifndef DLDL_LPDSTRUCT_AST_NODE_INDENTED_VALUE_H
#define DLDL_LPDSTRUCT_AST_NODE_INDENTED_VALUE_H

#include "DLDL_LPDSTRUCT/Ast/Node/DLDL_LPDSTRUCT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDSTRUCT { namespace ast { namespace node {

	class INDENTED_VALUE : public DLDL_LPDSTRUCT<INDENTED_VALUE>
	{
	private:
	public:
		INDENTED_VALUE(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDSTRUCT<INDENTED_VALUE>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDSTRUCT_AST_NODE_INDENTED_VALUE_H
