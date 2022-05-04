#ifndef DLDL_LPDDEF_DF_AST_NODE_VECTOR_H
#define DLDL_LPDDEF_DF_AST_NODE_VECTOR_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

	class VECTOR : public DLDL_LPDDEF_DF<VECTOR>
	{
	private:
	public:
		VECTOR(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_DF<VECTOR>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_VECTOR_H
