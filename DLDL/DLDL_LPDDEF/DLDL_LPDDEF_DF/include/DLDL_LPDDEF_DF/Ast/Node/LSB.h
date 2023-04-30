#ifndef DLDL_LPDDEF_DF_AST_NODE_LSB_H
#define DLDL_LPDDEF_DF_AST_NODE_LSB_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

	class LSB : public DLDL_LPDDEF_DF<LSB>
	{
	private:
	public:
		LSB(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_DF<LSB>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_LSB_H
