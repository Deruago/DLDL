#ifndef DLDL_LPDDEF_DF_AST_NODE_standard_variant_H
#define DLDL_LPDDEF_DF_AST_NODE_standard_variant_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node { 

	class standard_variant : public DLDL_LPDDEF_DF<standard_variant>
	{
	private:
	public:
		standard_variant(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LPDDEF_DF<standard_variant>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_standard_variant_H
