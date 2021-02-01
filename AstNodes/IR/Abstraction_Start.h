#ifndef DLDL_IR_ABSTRACTION_START_H
#define DLDL_IR_ABSTRACTION_START_H

#include "IR/AbstractionSymbol.h"
#include <string>
#include <vector>

namespace DLDL
{
	struct Abstraction_Start : AbstractionSymbol
	{
		std::string Regex;
		
		std::vector<std::string> MakeFunctionCall() const override
		{
			return {"IGNORENODE(" + Name + ", \"" + MakeRegex(Regex) + "\");\n"};
		}
		std::vector<std::string> MakeImplementationPart() const override
		{
			return {};
		}
		Abstraction_Start(std::vector<std::string> input, std::vector<std::string> content) : AbstractionSymbol(input, content)
		{
			Name = input[0];
			for(int i = 1; i < input.size(); i++)
			{
				Regex += input[i];
				if (i < input.size() - 1)
				{
					Regex +=  + " ";
				}
			}
		}
	};
}

#endif //DLDL_IR_ABSTRACTION_START_H