#ifndef DLDL_GRAMMAR_AST_NODE_abstraction_H
#define DLDL_GRAMMAR_AST_NODE_abstraction_H

#include "DLDL_GRAMMAR/Ast/Node/DLDL_GRAMMAR.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR { namespace ast { namespace node { 

	class abstraction : public DLDL_GRAMMAR<abstraction>
	{
	private:
	public:
		abstraction(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_GRAMMAR<abstraction>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_NODE_abstraction_H
