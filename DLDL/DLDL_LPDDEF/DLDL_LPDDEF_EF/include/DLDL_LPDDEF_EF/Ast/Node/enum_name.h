#ifndef DLDL_LPDDEF_EF_AST_NODE_enum_name_H
#define DLDL_LPDDEF_EF_AST_NODE_enum_name_H

#include "DLDL_LPDDEF_EF/Ast/Node/DLDL_LPDDEF_EF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_EF { namespace ast { namespace node { 

	class enum_name : public DLDL_LPDDEF_EF<enum_name>
	{
	private:
	public:
		enum_name(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LPDDEF_EF<enum_name>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_EF_AST_NODE_enum_name_H
