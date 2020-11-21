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
		virtual ~Symbol() = default;
	};
}

#endif //DLDL_IR_SYMBOL_H