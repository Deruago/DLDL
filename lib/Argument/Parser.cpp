#include "DLDL/Argument/Parser.h"
#include <map>

DLDL::argument::Parser::Parser(size_t totalArguments, const char* input[])
{
	for (int i = 1; i < totalArguments; i++)
	{
		const Type type = GetTypeFromString(input[i]);
		const std::string value = GetValueFromString(input[i]);

		arguments.emplace_back(type, value);
	}
}

bool DLDL::argument::Parser::IsArgumentSet(Type type)
{
	for (const auto& argument : arguments)
	{
		if (argument.type == type)
		{
			return true;
		}
	}

	return false;
}

DLDL::argument::Argument DLDL::argument::Parser::GetArgument(Type type)
{
	for (const auto& argument : arguments)
	{
		if (argument.type == type)
		{
			return argument;
		}
	}

	return Argument(Type::unknown, "");
}

std::string DLDL::argument::Parser::GetValueFromString(const std::string& str)
{
	std::string value;
	bool addToValue = false;
	for (auto character : str)
	{
		if (character == '=' && !addToValue)
		{
			addToValue = true;
			continue;
		}

		if (addToValue)
		{
			value += character;
		}
	}

	if (value.empty())
	{
		return "";
	}

	if (value.size() >= 2)
	{
		if (value[0] == '"' && value[value.size() - 1] == '"')
		{
			value.erase(0, 1);
			value.erase(value.size() - 1, 1);
		}
	}

	return value;
}

DLDL::argument::Type DLDL::argument::Parser::GetTypeFromString(const std::string& argument)
{
	const std::map<std::string, Type> map = {
		{"", Type::unknown},
		{"init", Type::initialize},
		{"initial", Type::initialize},
		{"initialize", Type::initialize},
		{"ln", Type::language_name},
		{"lang-name", Type::language_name},
		{"language-name", Type::language_name},
		{"g", Type::generate},
		{"gen", Type::generate},
		{"generate", Type::generate},
		{"v", Type::version},
		{"version", Type::version},
		{"copyright", Type::copyright},
		{"h", Type::help},
		{"help", Type::help},
		{"ac", Type::auto_compile},
		{"auto-compile", Type::auto_compile},
		{"ar", Type::auto_run},
		{"auto-run", Type::auto_run},
		{"profile", Type::profile},
		{"echo", Type::echo},
		{"debug-dldl", Type::debug_dldl},
		{"debug-build", Type::debug_build},
		{"log", Type::log},
		{"q", Type::exit},
		{"quit", Type::exit},
		{"exit", Type::exit},
		{"info", Type::information},
		{"information", Type::information},
		{"target-language", Type::target_language},
		{"tl", Type::target_language},
		{"git-init", Type::git_initialize},
		{"git-initialize", Type::git_initialize},
		{"dm", Type::definition_map},
		{"definition-map", Type::definition_map},
		{"bm", Type::build_map},
		{"build-map", Type::build_map},
		{"print-parser-output", Type::print_parse_result},
		{"compatible", Type::compatible},
		{"supported-grammars", Type::supported_grammars},
		{"about", Type::about},
		{"target-os", Type::target_os},
	};

	std::string argumentReworked;
	size_t index = 0;
	for (auto character : argument)
	{
		if (character == '-' && index == 0)
		{
		}
		else if (character == '-')
		{
			argumentReworked += std::tolower(character);
		}
		else if (std::isalpha(character))
		{
			argumentReworked += std::tolower(character);
		}
		else
		{
			break;
		}
		index++;
	}

	const auto result = map.find(argumentReworked);
	if (result == map.end())
	{
		return Type::unknown;
	}
	else
	{
		return result->second;
	}
}
