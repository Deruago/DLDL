#ifndef DLDL_OOPSYNTAX_AST_NODE_extended_terminal_access_H
#define DLDL_OOPSYNTAX_AST_NODE_extended_terminal_access_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node { 

	class extended_terminal_access : public DLDL_OOPSYNTAX<extended_terminal_access>
	{
	private:
	public:
		extended_terminal_access(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_OOPSYNTAX<extended_terminal_access>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_extended_terminal_access_H
