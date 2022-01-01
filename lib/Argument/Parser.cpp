#include "DLDL/Argument/Parser.h"
#include <iostream>
#include <map>

using namespace DLDL::argument;

static std::map<std::string, DLDL::argument::Type> stringToType = {};
static std::map<DLDL::argument::Type, std::string> typeToString = {};

static void initializeMaps()
{
	static bool initialized = false;
	if (initialized)
	{
		return;
	}
	else
	{
		initialized = true;
	}

	static const std::vector<std::tuple<std::string, DLDL::argument::Type>> tuples = {
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
		{"license", Type::copyright},
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
		{"sp", Type::single_project},
		{"single-project", Type::single_project},
		{"mp", Type::multi_project},
		{"multi-project", Type::multi_project},
		{"cp", Type::custom_project},
		{"custom-project", Type::custom_project},
		{"regen", Type::regenerate},
		{"regenerate", Type::regenerate},
		{"lpd-map", Type::lpd_map},
		{"lm", Type::lpd_map},
		{"tool-map", Type::tool_map},
		{"tm", Type::tool_map},
		{"deamer-map", Type::deamer_map},
		{"no-deamer", Type::no_deamer},
		{"activate-lpd-generation", Type::activate_lpd_generation},
		{"activate-tool-generation", Type::activate_tool_generation},
		{"generate-lpd", Type::generate_lpd},
		{"generate-tool", Type::generate_tool},
		{"glpd", Type::generate_lpd},
		{"gtool", Type::generate_tool},
	};

	for (auto [str, type] : tuples)
	{
		stringToType.insert({str, type});
		typeToString.insert({type, str});
	}
}

Parser::Parser()
{
	initializeMaps();
}

DLDL::argument::Parser::Parser(size_t totalArguments, const char* input[])
{
	initializeMaps();

	for (int i = 1; i < totalArguments; i++)
	{
		const Type type = GetTypeFromString(input[i]);
		const std::string value = GetValueFromString(input[i]);

		arguments.emplace_back(type, value);
	}
}

Parser::Parser(std::vector<std::string> input)
{
	initializeMaps();

	for (int i = 1; i < input.size(); i++)
	{
		const Type type = GetTypeFromString(input[i]);
		const std::string value = GetValueFromString(input[i]);

		arguments.emplace_back(type, value);
	}
}

bool DLDL::argument::Parser::IsArgumentSet(Type type) const
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

DLDL::argument::Argument DLDL::argument::Parser::GetArgument(Type type) const
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

	const auto result = stringToType.find(argumentReworked);
	if (result == stringToType.end())
	{
		return Type::unknown;
	}
	else
	{
		return result->second;
	}
}

std::string DLDL::argument::Parser::GetStringFromType(const Type& argument)
{
	const auto result = typeToString.find(argument);
	if (result == typeToString.end())
	{
		return "";
	}

	std::string argumentReworked = "-";
	argumentReworked.reserve(5);
	size_t index = 0;
	for (auto character : result->second)
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

	return argumentReworked;
}

void Parser::Overwrites(const std::string& originalArgs)
{
	std::vector<std::string> args;
	std::string current_arg;
	bool encapsulated = false;
	for (auto character : originalArgs)
	{
		switch (character)
		{
		case ' ': {
			if (encapsulated)
			{
				current_arg += character;
			}
			else
			{
				if (!current_arg.empty())
				{
					args.push_back(current_arg);
					current_arg.clear();
				}
			}
			break;
		}
		case '"': {
			encapsulated = !encapsulated;
			break;
		}
		default: {
			current_arg += character;
			break;
		}
		}
	}
	if (!current_arg.empty())
	{
		args.push_back(current_arg);
		current_arg.clear();
	}

	const auto regenParser = Parser(args);
	for (const auto& originalArg : regenParser.arguments)
	{
		AddArgumentIfNotPresent(originalArg);
	}
}

void Parser::SetArgument(const Argument& arg)
{
	for (auto iter = std::begin(arguments); iter != std::end(arguments); ++iter)
	{
		if (iter->type == arg.type)
		{
			iter->value = arg.value;
			return;
		}
	}

	arguments.push_back(arg);
}

void Parser::SetArguments(std::vector<Argument> args)
{
	for (const auto& arg : args)
	{
		SetArgument(arg);
	}
}

void Parser::AddArgumentIfNotPresent(const Argument& value)
{
	for (auto arg : arguments)
	{
		if (arg.type == value.type)
		{
			return;
		}
	}

	arguments.push_back(value);
}
