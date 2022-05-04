#ifndef DLDL_OOPSYNTAX_AST_NODE_embedded_assignment_H
#define DLDL_OOPSYNTAX_AST_NODE_embedded_assignment_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node { 

	class embedded_assignment : public DLDL_OOPSYNTAX<embedded_assignment>
	{
	private:
	public:
		embedded_assignment(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_OOPSYNTAX<embedded_assignment>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_embedded_assignment_H
