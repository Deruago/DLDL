#ifndef DLDL_PRECEDENCE_AST_NODE_terminal_one_or_more_H
#define DLDL_PRECEDENCE_AST_NODE_terminal_one_or_more_H

#include "DLDL_PRECEDENCE/Ast/Node/DLDL_PRECEDENCE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_PRECEDENCE { namespace ast { namespace node { 

	class terminal_one_or_more : public DLDL_PRECEDENCE<terminal_one_or_more>
	{
	private:
	public:
		terminal_one_or_more(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_PRECEDENCE<terminal_one_or_more>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_PRECEDENCE_AST_NODE_terminal_one_or_more_H
