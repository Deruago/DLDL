#ifndef DLDL_IDENTITY_AST_NODE_name_declaration_H
#define DLDL_IDENTITY_AST_NODE_name_declaration_H

#include "DLDL_IDENTITY/Ast/Node/DLDL_IDENTITY.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IDENTITY { namespace ast { namespace node { 

	class name_declaration : public DLDL_IDENTITY<name_declaration>
	{
	private:
	public:
		name_declaration(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_IDENTITY<name_declaration>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_IDENTITY_AST_NODE_name_declaration_H
