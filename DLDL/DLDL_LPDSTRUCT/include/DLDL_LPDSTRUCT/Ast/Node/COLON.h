#ifndef DLDL_LPDSTRUCT_AST_NODE_COLON_H
#define DLDL_LPDSTRUCT_AST_NODE_COLON_H

#include "DLDL_LPDSTRUCT/Ast/Node/DLDL_LPDSTRUCT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDSTRUCT { namespace ast { namespace node {

	class COLON : public DLDL_LPDSTRUCT<COLON>
	{
	private:
	public:
		COLON(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDSTRUCT<COLON>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDSTRUCT_AST_NODE_COLON_H
