#ifndef DLDL_LPDDEF_EF_AST_NODE_standard_variant_specific_number_H
#define DLDL_LPDDEF_EF_AST_NODE_standard_variant_specific_number_H

#include "DLDL_LPDDEF_EF/Ast/Node/DLDL_LPDDEF_EF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_EF { namespace ast { namespace node { 

	class standard_variant_specific_number : public DLDL_LPDDEF_EF<standard_variant_specific_number>
	{
	private:
	public:
		standard_variant_specific_number(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LPDDEF_EF<standard_variant_specific_number>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_EF_AST_NODE_standard_variant_specific_number_H
