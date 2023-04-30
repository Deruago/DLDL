#ifndef DLDL_LPDDEF_DF_AST_NODE_OPTIONAL_H
#define DLDL_LPDDEF_DF_AST_NODE_OPTIONAL_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

	class OPTIONAL : public DLDL_LPDDEF_DF<OPTIONAL>
	{
	private:
	public:
		OPTIONAL(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_DF<OPTIONAL>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_OPTIONAL_H
