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

		Argument(Type type_, const std::string& value_ = "") : type(type_), value(value_)
		{
		}
	};

	class Parser
	{
	private:
		std::vector<Argument> arguments;

	public:
		Parser();
		Parser(size_t totalArguments, const char* input[]);
		Parser(std::vector<std::string> input);
		~Parser() = default;

	public:
		bool IsArgumentSet(Type type) const;
		Argument GetArgument(Type type) const;
		std::string CompileToArgument(Type type) const;

		std::string GetValueFromString(const std::string& str) const;

		Type GetTypeFromString(const std::string& argument) const;
		std::string GetStringFromType(const Type& argument) const;
		void Overwrites(const std::string& originalArgs);
		void SetArgument(const Argument& arg);
		void SetArguments(std::vector<Argument> args);

	private:
		void AddArgumentIfNotPresent(const Argument& value);
	};
}

#endif // DLDL_ARGUMENT_PARSER_H
