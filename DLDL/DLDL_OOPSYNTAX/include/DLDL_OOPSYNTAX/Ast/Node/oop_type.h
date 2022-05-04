#ifndef DLDL_OOPSYNTAX_AST_NODE_oop_type_H
#define DLDL_OOPSYNTAX_AST_NODE_oop_type_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node { 

	class oop_type : public DLDL_OOPSYNTAX<oop_type>
	{
	private:
	public:
		oop_type(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_OOPSYNTAX<oop_type>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_oop_type_H
