#ifndef DLDL_IMPORT_AST_NODE_import_abstraction_H
#define DLDL_IMPORT_AST_NODE_import_abstraction_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node { 

	class import_abstraction : public DLDL_IMPORT<import_abstraction>
	{
	private:
	public:
		import_abstraction(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_IMPORT<import_abstraction>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_import_abstraction_H
