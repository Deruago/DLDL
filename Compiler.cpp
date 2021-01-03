#include <DLDLCompiler.h>
#include <Console/DefinitionType_t.h>
#include <Console/ArgumentType_t.h>
#include <Console/Argument.h>
#include <map>
#include <algorithm>
#include <iostream>

DLDL::DefinitionType_t ReturnDefinitionTypeBasedOnFileExtension(std::string fileExtension)
{
	// Convert string to lower case
	transform(fileExtension.begin(), fileExtension.end(), fileExtension.begin(), ::tolower);
	
	std::map<std::string, DLDL::DefinitionType_t> fileNameToDefinitionType;
	fileNameToDefinitionType["dldl"] = DLDL::DefinitionType_t::mixed_lexicon_and_cfg;
	fileNameToDefinitionType["dl"] = DLDL::DefinitionType_t::lexicon;
	fileNameToDefinitionType["dcfg"] = DLDL::DefinitionType_t::cfg;
	fileNameToDefinitionType["dst"] = DLDL::DefinitionType_t::st;
	fileNameToDefinitionType["dpr"] = DLDL::DefinitionType_t::precedence;
	
	return fileNameToDefinitionType[fileExtension];
}

DLDL::DefinitionType_t RetrieveDefinitionTypeFromFileName(std::string fileName)
{
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

std::string RetrieveLanguageNameFromFileName(const std::string& fileName)
{
	const auto fileExtensionStart = fileName.find('.');
	
	return fileName.substr(0, fileExtensionStart);
}

std::vector<DLDL::Argument> ParseArguments(int argc, char **argv)
{
	if (argc <= 1)
	{
		return {};
	}
	
	std::vector<DLDL::Argument> arguments;
	
	std::map<std::string, DLDL::ArgumentType_t> stringToArgumentType;
	stringToArgumentType["show-text"] = DLDL::ArgumentType_t::showtext;
	stringToArgumentType["show-structure"] = DLDL::ArgumentType_t::showstructure;
	stringToArgumentType["show-ast"] = DLDL::ArgumentType_t::showAST;
	stringToArgumentType["debug-information"] = DLDL::ArgumentType_t::debugInformation;
	stringToArgumentType["show-text-after-pre-processor"] = DLDL::ArgumentType_t::showTextAfterFilePreProcessor;
	stringToArgumentType["threat"] = DLDL::ArgumentType_t::addThreatAnalysis;
	stringToArgumentType["all-arguments"] = DLDL::ArgumentType_t::allArguments;
	stringToArgumentType["auto-compile"] = DLDL::ArgumentType_t::autoCompile;
	
	for (auto i = 2; i < argc; i++)
	{
		const std::string argument = argv[i];
		const DLDL::ArgumentType_t argumentType = stringToArgumentType[argument.substr(1)];
		if (argumentType == DLDL::ArgumentType_t::unknown)
		{
			continue;
		}
		
		arguments.push_back(DLDL::Argument(argumentType, true));
	}
	
	return arguments;
}

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "No input given! Make sure to include the file location of the DLDL definition!" << std::endl;
		return -1;
	}
	
	const std::string file_argument_unfiltered = argv[1];
	const std::string languageName = RetrieveLanguageNameFromFileName(file_argument_unfiltered);
	const DLDL::DefinitionType_t definition = RetrieveDefinitionTypeFromFileName(file_argument_unfiltered);
	
	const auto arguments = ParseArguments(argc, argv);
	
    DLDL::DLDLCompiler* compiler = nullptr;
	switch(definition)
	{
		case DLDL::DefinitionType_t::mixed_lexicon_and_cfg:
			compiler = new DLDL::DLDLCompiler(arguments);
			break;
		case DLDL::DefinitionType_t::lexicon:
			std::cout << "The lexicon definition is not implemented yet." << std::endl;
			break;
		case DLDL::DefinitionType_t::cfg:
			std::cout << "The cfg definition is not implemented yet." << std::endl;
			break;
		case DLDL::DefinitionType_t::st:
			std::cout << "The st definition is not implemented yet." << std::endl;
			break;
		case DLDL::DefinitionType_t::precedence:
			std::cout << "The precendence definition is not implemented yet." << std::endl;
			break;
		case DLDL::DefinitionType_t::unknown:
			std::cout << "The unknown definition is not known." << std::endl;
	}
	
	if (compiler != nullptr)
	{
		compiler->CompileFile(file_argument_unfiltered);
	}
	
    return 0;
}