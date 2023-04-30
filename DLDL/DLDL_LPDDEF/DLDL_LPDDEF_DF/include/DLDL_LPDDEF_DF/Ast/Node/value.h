#ifndef DLDL_LPDDEF_DF_AST_NODE_value_H
#define DLDL_LPDDEF_DF_AST_NODE_value_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node { 

	class value : public DLDL_LPDDEF_DF<value>
	{
	private:
	public:
		value(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LPDDEF_DF<value>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_value_H
