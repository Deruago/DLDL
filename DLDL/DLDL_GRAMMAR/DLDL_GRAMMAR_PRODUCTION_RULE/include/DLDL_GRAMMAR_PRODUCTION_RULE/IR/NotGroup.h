#ifndef DLDL_GRAMMAR_PRODUCTIONRULE_NOTGROUP_H
#define DLDL_GRAMMAR_PRODUCTIONRULE_NOTGROUP_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/ReservedGroup.h"
#include <string>
#include <utility>
#include <vector>

namespace DLDL_GRAMMAR_PRODUCTION_RULE::ir
{
	/*!
	 * \class NotGroup
	 *
	 * \brief Represents a group that negates a set of Terminals
	 */
	class NotGroup : public ReservedGroup
	{
	private:
		const std::vector<std::string>* terminals;

	public:
		NotGroup(std::vector<Group*> subgroups, const std::vector<std::string>* terminals_)
			: ReservedGroup("not", std::move(subgroups), false),
			  terminals(terminals_)
		{
		}

		std::vector<ProductionRule> RetrieveEnvironment(Environment& currentEnvironment,
														const ProductionRule& productionRule,
														DLDL::ir::Grammar* grammar) override
		{
			// Antlr Importing supports this by modifying the production-rule before passing it to
			// the parser
			throw std::logic_error("Unimplemented");
		}
	};
}

#endif // DLDL_GRAMMAR_PRODUCTIONRULE_NOTGROUP_H
