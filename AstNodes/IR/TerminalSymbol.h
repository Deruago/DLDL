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
			return {"NODE(" + Name + ", \"" + MakeRegex(Regex) + "\");\n"};
		}
		TerminalSymbol(std::string name, std::string regex) : Symbol(name, "", true)
		{
			Regex = regex;
		}
	};
}

#endif //DLDL_IR_TERMINALSYMBOL_H