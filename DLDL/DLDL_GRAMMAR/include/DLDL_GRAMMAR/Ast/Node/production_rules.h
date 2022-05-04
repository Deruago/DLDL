#ifndef DLDL_GRAMMAR_AST_NODE_production_rules_H
#define DLDL_GRAMMAR_AST_NODE_production_rules_H

#include "DLDL_GRAMMAR/Ast/Node/DLDL_GRAMMAR.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR { namespace ast { namespace node { 

	class production_rules : public DLDL_GRAMMAR<production_rules>
	{
	private:
	public:
		production_rules(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_GRAMMAR<production_rules>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_NODE_production_rules_H
