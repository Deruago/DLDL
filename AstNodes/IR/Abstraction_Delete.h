#ifndef DLDL_IR_ABSTRACTION_DELETE_H
#define DLDL_IR_ABSTRACTION_DELETE_H

#include "IR/AbstractionSymbol.h"
#include <string>
#include <vector>

namespace DLDL
{
	struct Abstraction_Delete : AbstractionSymbol
	{
		std::string Regex;
		
		std::vector<std::string> MakeFunctionCall() const override
		{
			return {"DELETENODE(" + Name + ", \"" + MakeRegex(Regex) + "\");\n"};
		}
		Abstraction_Delete(std::vector<std::string> input, std::vector<std::string> content) : AbstractionSymbol(input, content)
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

#endif //DLDL_IR_ABSTRACTION_DELETE_H