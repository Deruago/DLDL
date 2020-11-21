#ifndef DLDL_IR_NONTERMINALSYMBOL_H
#define DLDL_IR_NONTERMINALSYMBOL_H

#include "IR/Symbol.h"
#include "IR/ProductionRule.h"
#include <string>
#include <vector>

namespace DLDL
{
	struct NonTerminalSymbol : Symbol
	{
		std::vector<ProductionRule> ProductionRules;
		
		std::vector<std::string> MakeFunctionCall() const override
		{
			return {"TYPE(" + Name + ");\n"};
		}
		
		std::vector<std::string> MakeImplementationPart() const override
		{
			std::vector<std::string> return_string;
			for (ProductionRule production_rule : ProductionRules)
				return_string.push_back(MakeProductionRule(production_rule));
			return return_string;
		}
		std::string MakeProductionRule(ProductionRule production_rule) const
		{
			std::string rule = "RULE(" + Name + ", ";
			for(int i = 0; i < production_rule.Symbols.size(); i++)
			{
				rule += production_rule.Symbols[i].Name;
				if (i < production_rule.Symbols.size() - 1)
					rule += ", ";
			}
			rule += ");\n";
			return rule;
		}
		NonTerminalSymbol(std::string name, std::vector<ProductionRule> production_rules) : Symbol(name, "", false)
		{
			ProductionRules = production_rules;
		}
	};
}

#endif //DLDL_IR_NONTERMINALSYMBOL_H