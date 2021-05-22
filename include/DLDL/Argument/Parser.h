#ifndef DLDL_ARGUMENT_PARSER_H
#define DLDL_ARGUMENT_PARSER_H

#include "DLDL/Argument/Type.h"
#include <string>
#include <vector>

namespace DLDL::argument
{
	struct Argument
	{
		Type type;
		std::string value;

		Argument(Type type_, const std::string& value_)
			: type(type_), value(value_)
		{
		}
	};
	
	class Parser
	{
	private:
		std::vector<Argument> arguments;
	public:
		Parser() = default;
		Parser(size_t totalArguments, char* input[]);
		~Parser() = default;
		
	public:
		bool IsArgumentSet(Type type);
		Argument GetArgument(Type type);

		std::string GetValueFromString(const std::string& str);

		Type GetTypeFromString(const std::string& argument);
	};
}

#endif // DLDL_ARGUMENT_PARSER_H