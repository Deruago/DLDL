#include <Console/ArgumentParser.h>
//#include "./ArgumentParser.h"
#include <Console/ArgumentType_t.h>
#include <Console/DefinitionType_t.h>
#include <Console/Argument.h>
#include <algorithm>
#include <iostream>
#include <vector>


#include "FileTarget.h"

DLDL::ArgumentParser::ArgumentParser()
{
	fileNameToDefinitionType["dldl"] = DLDL::DefinitionType_t::mixed_lexicon_and_cfg;
	fileNameToDefinitionType["dl"] = DLDL::DefinitionType_t::lexicon;
	fileNameToDefinitionType["dcfg"] = DLDL::DefinitionType_t::cfg;
	fileNameToDefinitionType["dst"] = DLDL::DefinitionType_t::st;
	fileNameToDefinitionType["dpr"] = DLDL::DefinitionType_t::precedence;

	for (auto i = 0; i < arguments.size(); i++)
	{
		const auto currentArgument = arguments[i];
		const auto currentArgumentNames = currentArgument->GetArgumentNames();
		for (auto j = 0; j < currentArgumentNames.size(); j++)
		{
			const auto currentArgumentName = currentArgumentNames[j];
			stringToArgumentType[currentArgumentName] = currentArgument->GetArgumentType();
		}
	}
}

DLDL::ArgumentParser::~ArgumentParser()
{
	for (auto i = 0; i < arguments.size(); i++)
	{
		delete arguments[i];
		arguments[i] = nullptr;
	}
}

std::vector<DLDL::Argument> DLDL::ArgumentParser::ParseArguments(int argc, char** argv) const
{
	std::vector<DLDL::Argument> arguments;

	for (auto i = 1; i < argc; i++)
	{
		const std::string argument = argv[i];
		if (argument.empty() ||
			argument[0] != '-')
		{
			continue;
		}
		
		const DLDL::ArgumentType_t argumentType = stringToArgumentType.at(argument.substr(1));
		if (argumentType == DLDL::ArgumentType_t::unknown)
		{
			continue;
		}

		arguments.push_back(DLDL::Argument(argumentType, true));
	}

	return arguments;
}

std::string DLDL::ArgumentParser::Help() const
{
	std::string helpString;
	for (auto i = 0; i < arguments.size(); i++)
	{
		const auto currentArgument = arguments[i];
		helpString += currentArgument->GetHelpInformationFormatted();
	}
	return helpString;
}

bool DLDL::ArgumentParser::IsArgumentActivatedInArguments(const DLDL::ArgumentType_t& argumentType,
	const std::vector<Argument>& arguments) const
{
	for (auto i = 0; i < arguments.size(); i++)
	{
		const auto currentArgument = arguments[i];
		if (currentArgument.type == argumentType)
		{
			return currentArgument.activated;
		}
		
		// All arguments, activates every argument if it is active, thus encountering returns true
		if (currentArgument.type == DLDL::ArgumentType_t::allArguments
			&& argumentType != DLDL::ArgumentType_t::help)
		{
			return currentArgument.activated;
		}
	}

	return false;
}

DLDL::DefinitionType_t DLDL::ArgumentParser::GetDefinitionTypeOfFileName(std::string fileName) const
{
	// Convert string to lower case
	std::transform(fileName.begin(), fileName.end(), fileName.begin(), ::tolower);
	
	// remove till file name
	const size_t last_slash_idx = fileName.find_last_of("\\/");
	if (std::string::npos != last_slash_idx)
	{
		fileName.erase(0, last_slash_idx + 1);
	}

	const auto fileExtensionStart = fileName.find('.');
	if (fileExtensionStart == std::string::npos)
	{
		std::cout << "No file extension given, defaulting to: \"Mixed lexicon and cfg definition\"!" << std::endl;
		return DLDL::DefinitionType_t::mixed_lexicon_and_cfg;
	}
	
	const auto definitionType = ReturnDefinitionTypeBasedOnFileExtension(fileName.substr(fileExtensionStart + 1));
	if (definitionType == DLDL::DefinitionType_t::unknown)
	{
		std::cout << "Unknown file extension, defaulting to: \"Mixed lexicon and cfg definition\"!" << std::endl;
		return DLDL::DefinitionType_t::mixed_lexicon_and_cfg;
	}

	return definitionType;
}

DLDL::DefinitionType_t DLDL::ArgumentParser::ReturnDefinitionTypeBasedOnFileExtension(const std::string& fileExtension) const
{
	return fileNameToDefinitionType.at(fileExtension);
}

std::vector<DLDL::FileTarget> DLDL::ArgumentParser::GetDefinitionTypesFromArgumentList(int argc, char** argv) const
{
	std::vector<DLDL::FileTarget> fileNameDefinitionTypes;

	for (auto i = 1; i < argc; i++)
	{
		const std::string fileName = argv[i];
		if (fileName.empty() ||
			fileName[0] == '-')
		{
			continue;
		}

		auto fileTarget = DLDL::FileTarget(fileName, GetDefinitionTypeOfFileName(fileName));
		fileNameDefinitionTypes.push_back(fileTarget);
	}

	return fileNameDefinitionTypes;
}
