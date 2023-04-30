#ifndef DLDL_LPDDEF_DF_AST_NODE_var_type_H
#define DLDL_LPDDEF_DF_AST_NODE_var_type_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node { 

	class var_type : public DLDL_LPDDEF_DF<var_type>
	{
	private:
	public:
		var_type(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LPDDEF_DF<var_type>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_var_type_H
