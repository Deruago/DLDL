#ifndef DLDL_GENERATION_AST_NODE_argument_declaration_H
#define DLDL_GENERATION_AST_NODE_argument_declaration_H

#include "DLDL_GENERATION/Ast/Node/DLDL_GENERATION.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GENERATION { namespace ast { namespace node { 

	class argument_declaration : public DLDL_GENERATION<argument_declaration>
	{
	private:
	public:
		argument_declaration(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_GENERATION<argument_declaration>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_GENERATION_AST_NODE_argument_declaration_H
