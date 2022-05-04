#ifndef DLDL_OOPSYNTAX_AST_NODE_direct_property_assignment_H
#define DLDL_OOPSYNTAX_AST_NODE_direct_property_assignment_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node { 

	class direct_property_assignment : public DLDL_OOPSYNTAX<direct_property_assignment>
	{
	private:
	public:
		direct_property_assignment(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_OOPSYNTAX<direct_property_assignment>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_direct_property_assignment_H
