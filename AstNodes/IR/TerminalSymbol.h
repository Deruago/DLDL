#ifndef DLDL_IR_TERMINALSYMBOL_H
#define DLDL_IR_TERMINALSYMBOL_H

#include "IR/Symbol.h"

namespace DLDL
{
	struct TerminalSymbol : Symbol
	{
		std::string Regex;
		
		std::vector<std::string> MakeFunctionCall() const override
		{
			return {"NODE(" + Name + ", \"" + MakeRegex() + "\");\n"};
		}
		TerminalSymbol(std::string name, std::string regex) : Symbol(name, "", true)
		{
			Regex = regex;
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

#endif //DLDL_IR_TERMINALSYMBOL_H