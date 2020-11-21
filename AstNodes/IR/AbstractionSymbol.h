#ifndef DLDL_IR_ABSTRACTIONSYMBOL_H
#define DLDL_IR_ABSTRACTIONSYMBOL_H

#include "IR/Symbol.h"
#include <string>
#include <vector>

namespace DLDL
{
	struct AbstractionSymbol : Symbol
	{
		std::vector<std::string> input_;
		std::vector<std::string> content_;
		
		std::vector<std::string> MakeFunctionCall() const override
		{
			return {};
		}
		AbstractionSymbol(std::vector<std::string> input, std::vector<std::string> content) : Symbol("", "", true)
		{
			input_ = input;
			content_ = content;
		}
	};
}

#endif //DLDL_IR_ABSTRACTIONSYMBOL_H