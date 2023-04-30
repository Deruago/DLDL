#ifndef DLDL_GRAMMAR_AST_NODE_definition_H
#define DLDL_GRAMMAR_AST_NODE_definition_H

#include "DLDL_GRAMMAR/Ast/Node/DLDL_GRAMMAR.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR { namespace ast { namespace node { 

	class definition : public DLDL_GRAMMAR<definition>
	{
	private:
	public:
		definition(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_GRAMMAR<definition>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_NODE_definition_H
