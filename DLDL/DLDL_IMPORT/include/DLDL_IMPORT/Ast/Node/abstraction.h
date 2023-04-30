#ifndef DLDL_IMPORT_AST_NODE_abstraction_H
#define DLDL_IMPORT_AST_NODE_abstraction_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node { 

	class abstraction : public DLDL_IMPORT<abstraction>
	{
	private:
	public:
		abstraction(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_IMPORT<abstraction>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_abstraction_H
