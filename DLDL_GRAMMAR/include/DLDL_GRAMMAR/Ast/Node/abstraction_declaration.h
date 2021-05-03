#ifndef DLDL_GRAMMAR_AST_NODE_abstraction_declaration_H
#define DLDL_GRAMMAR_AST_NODE_abstraction_declaration_H

#include "DLDL_GRAMMAR/Ast/Node/DLDL_GRAMMAR.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR { namespace ast { namespace node { 

	class abstraction_declaration : public DLDL_GRAMMAR<abstraction_declaration>
	{
	private:
	public:
		abstraction_declaration(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_GRAMMAR<abstraction_declaration>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_NODE_abstraction_declaration_H
