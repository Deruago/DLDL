#ifndef DLDL_IR_ABSTRACTION_NONTERMINAL_H
#define DLDL_IR_ABSTRACTION_NONTERMINAL_H

#include "IR/AbstractionSymbol.h"
#include <string>
#include <vector>

namespace DLDL
{
	struct Abstraction_NonTerminal : AbstractionSymbol
	{	
		std::vector<std::string> MakeFunctionCall() const override
		{
			return {"TYPE_NOT_IMPLEMENTED(" + Name + ");\n"};
		}
		Abstraction_NonTerminal(std::vector<std::string> input, std::vector<std::string> content) : AbstractionSymbol(input, content)
		{
			Name = input[input.size() - 1];
		}
	};
}

#endif //DLDL_IR_ABSTRACTION_NONTERMINAL_H