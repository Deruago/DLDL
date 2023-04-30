#ifndef DLDL_OOPSYNTAX_AST_NODE_extended_property_H
#define DLDL_OOPSYNTAX_AST_NODE_extended_property_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node { 

	class extended_property : public DLDL_OOPSYNTAX<extended_property>
	{
	private:
	public:
		extended_property(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_OOPSYNTAX<extended_property>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_extended_property_H
