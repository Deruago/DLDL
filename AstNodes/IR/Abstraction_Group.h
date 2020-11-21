#ifndef DLDL_IR_ABSTRACTION_GROUP_H
#define DLDL_IR_ABSTRACTION_GROUP_H

#include "IR/AbstractionSymbol.h"
#include <string>
#include <vector>

namespace DLDL
{
	struct Abstraction_Group : AbstractionSymbol
	{
		std::string Symbols;
		
		std::vector<std::string> MakeFunctionCall() const override
		{
			std::vector<std::string> return_string;
			return_string.push_back("GROUPEDTYPE(" + Name + ");\n");
			return return_string;
		}
		std::vector<std::string> MakeImplementationPart() const override
		{
			std::vector<std::string> return_string;
			return_string.push_back("GROUPTOKENS(" + Name + Symbols + ");\n");
			return return_string;
		}
		Abstraction_Group(std::vector<std::string> input, std::vector<std::string> content) : AbstractionSymbol(input, content)
		{
			Name = input[0];
			for(int i = 1; i < input.size(); i++)
			{
				Symbols += ", " + input[i];
			}
			for(int i = content.size() - 1; i >= 0; i--)
			{
				Symbols += ", " + content[i];
			}
		}
	};
}

#endif //DLDL_IR_ABSTRACTION_GROUP_H