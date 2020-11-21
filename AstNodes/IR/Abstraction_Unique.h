#ifndef DLDL_IR_ABSTRACTION_UNIQUE_H
#define DLDL_IR_ABSTRACTION_UNIQUE_H

#include "IR/AbstractionSymbol.h"
#include <string>
#include <vector>

namespace DLDL
{
	struct Abstraction_Unique : AbstractionSymbol
	{
		std::string Regex;
		
		std::vector<std::string> MakeFunctionCall() const override
		{
			return {"IGNORENODE(" + Name + ", \"" + MakeRegex() + "\");\n"};
		}
		Abstraction_Unique(std::vector<std::string> input, std::vector<std::string> content) : AbstractionSymbol(input, content)
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
		
		std::string MakeRegex() const
		{			
			std::string updated_regex;
			for(const char character : Regex)
			{
				switch(character)
				{
				case '\\':
					updated_regex += "\\\\";
					break;
				default:
					updated_regex += character;
					break;
				}
			}
			return updated_regex;
		}
	};
}

#endif //DLDL_IR_ABSTRACTION_UNIQUE_H