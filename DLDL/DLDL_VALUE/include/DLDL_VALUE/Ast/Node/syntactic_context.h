#ifndef DLDL_VALUE_AST_NODE_syntactic_context_H
#define DLDL_VALUE_AST_NODE_syntactic_context_H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node { 

	class syntactic_context : public DLDL_VALUE<syntactic_context>
	{
	private:
	public:
		syntactic_context(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_VALUE<syntactic_context>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_syntactic_context_H
