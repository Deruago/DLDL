#ifndef DLDL_OOPSYNTAX_AST_NODE_numbered_pr_convert_H
#define DLDL_OOPSYNTAX_AST_NODE_numbered_pr_convert_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node { 

	class numbered_pr_convert : public DLDL_OOPSYNTAX<numbered_pr_convert>
	{
	private:
	public:
		numbered_pr_convert(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_OOPSYNTAX<numbered_pr_convert>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_numbered_pr_convert_H
