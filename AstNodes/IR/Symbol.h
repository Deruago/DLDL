#ifndef DLDL_IR_SYMBOL_H
#define DLDL_IR_SYMBOL_H

#include <string>

namespace DLDL
{
	struct Symbol
	{
		std::string Name;
		std::string Content;
		bool IsTerminal;
		
		virtual std::vector<std::string> MakeFunctionCall() const
		{
			return {};
		}
		
		// Used for implementations that need everything to be first defined
		virtual std::vector<std::string> MakeImplementationPart() const
		{
			return {};
		}
		
		Symbol(std::string name)
		{
			Name = name;
			Content = "";
			IsTerminal = false;
		}
		Symbol(std::string name, std::string content, bool is_terminal)
		{
			Name = name;
			Content = content;
			IsTerminal = is_terminal;
		}
		
		std::string MakeRegex(const std::string& Regex) const
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
		
		virtual ~Symbol() = default;
	};
}

#endif //DLDL_IR_SYMBOL_H