#ifndef DLDL_IR_ABSTRACTION_TERMINAL_H
#define DLDL_IR_ABSTRACTION_TERMINAL_H

#include "IR/AbstractionSymbol.h"
#include <string>
#include <vector>

namespace DLDL
{
	struct Abstraction_Terminal : AbstractionSymbol
	{
		std::string Regex;
		
		std::vector<std::string> MakeFunctionCall() const override
		{
			return {"NODE(" + Name + ", \"" + MakeRegex() + "\");\n"};
		}
		Abstraction_Terminal(std::vector<std::string> input, std::vector<std::string> content) : AbstractionSymbol(input, content)
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
			unsigned backslash_encountered = 0;
			std::string updated_regex;
			for(const char character : Regex)
			{
				switch(character)
				{
				case '\\':
					updated_regex += "\\\\";
					backslash_encountered++;
					break;
				case '"':
					if ((backslash_encountered % 2) == 1)
					{
						updated_regex[updated_regex.size() - 1] = character;
					}
					else
					{
						backslash_encountered = 0;
						updated_regex += character;
					}
					break;
				default:
					updated_regex += character;
					backslash_encountered = 0;
					break;
				}
			}
			return updated_regex;
		}
	};
}

#endif //DLDL_IR_ABSTRACTION_TERMINAL_H