#ifndef DLDL_GRAMMAR_PRODUCTIONRULE_RESERVEDGROUP_H
#define DLDL_GRAMMAR_PRODUCTIONRULE_RESERVEDGROUP_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/Group.h"
#include <utility>
#include <vector>

namespace DLDL_GRAMMAR_PRODUCTION_RULE::ir
{
	/*!
	 * \class ReservedGroup
	 *
	 * \brief Represents a reserved group.
	 */
	class ReservedGroup : public Group
	{
	public:
		bool inlineExtension;
		std::string reservedName;

		ReservedGroup(std::string reservedName_, std::vector<Group*> subgroups_ = {},
					  bool inlineExtension_ = false)
			: Group(std::move(subgroups_)),
			  inlineExtension(inlineExtension_),
			  reservedName(std::move(reservedName_))
		{
		}

		virtual std::string GetReferenceName() const
		{
			std::string name = "deamerreserved_" + reservedName + "__";
			for (auto* const subgroup : subgroups)
			{
				name += subgroup->GetReferenceName() + "__";
			}

			return name;
		}
	};
}

#endif // DLDL_GRAMMAR_PRODUCTIONRULE_RESERVEDGROUP_H
