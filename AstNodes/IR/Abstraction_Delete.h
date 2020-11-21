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
			return {"DELETENODE(" + Name + ", \"" + MakeRegex() + "\");\n"};
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

#endif //DLDL_IR_ABSTRACTION_DELETE_H