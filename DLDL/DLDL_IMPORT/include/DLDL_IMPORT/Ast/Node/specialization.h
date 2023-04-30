#ifndef DLDL_IMPORT_AST_NODE_specialization_H
#define DLDL_IMPORT_AST_NODE_specialization_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node { 

	class specialization : public DLDL_IMPORT<specialization>
	{
	private:
	public:
		specialization(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_IMPORT<specialization>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_specialization_H
