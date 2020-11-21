#ifndef DLDL_IR_ABSTRACTION_ALIAS_H
#define DLDL_IR_ABSTRACTION_ALIAS_H

#include "IR/AbstractionSymbol.h"
#include <string>
#include <vector>

namespace DLDL
{
	struct Abstraction_Alias : AbstractionSymbol
	{
		std::vector<std::string> MakeFunctionCall() const override
		{
			std::vector<std::string> return_string;
			for(int i = 1; i < input_.size(); i++)
			{
				std::string TypeName = input_[i];
				return_string.push_back("using " + TypeName + " = " + Name + ";\n");
			}
			return return_string;
		}
		Abstraction_Alias(std::vector<std::string> input, std::vector<std::string> content) : AbstractionSymbol(input, content)
		{
			Name = input[0];
		}
	};
}

#endif //DLDL_IR_ABSTRACTION_ALIAS_H