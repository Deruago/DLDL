#ifndef DLDL_IR_PRODUCTIONRULE_H
#define DLDL_IR_PRODUCTIONRULE_H

namespace DLDL
{
	struct ProductionRule
	{
		std::vector<Symbol> Symbols;
		std::string Content;
		ProductionRule()
		{
			Content = "";
		}
		ProductionRule(std::vector<Symbol> symbols)
		{
			Symbols = symbols;
			Content = "";
		}
	};
}

#endif //DLDL_IR_PRODUCTIONRULE_H