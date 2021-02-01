#include <DLDLCompiler.h>
#include <Console/DefinitionType_t.h>
#include <Console/ArgumentType_t.h>
#include <Console/Argument.h>
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <Console/ArgumentParser.h>
#include "./Console/ArgumentParser.h"
#include "Console/FileTarget.h"

#define if_in(check_value, vector_value, vector_member)\
auto found_index = -1;\
bool return_check = false;\
for (auto i = 0; i < vector_value.size(); i++)\
{\
    if (vector_value[i]vector_member == check_value)\
    {\
        found_index = i;\
        return_check = true;\
    }\
}\
if (return_check)

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "No input given! Make sure to include the file location of the DLDL definition!" << std::endl;
		return -1;
	}
	const DLDL::ArgumentParser argumentParser;
	const auto arguments = argumentParser.ParseArguments(argc, argv);
	const auto fileTargets = argumentParser.GetDefinitionTypesFromArgumentList(argc, argv);

	if (argumentParser.IsArgumentActivatedInArguments(DLDL::ArgumentType_t::help, arguments))
	{
		std::cout << argumentParser.Help() << std::endl;
		return 0;
	}
	
    DLDL::DLDLCompiler* compiler = nullptr;
	for (auto i = 0; i < fileTargets.size(); i++)
	{
		const DLDL::FileTarget currentFileTarget = fileTargets[i];
		switch (currentFileTarget.definitionType)
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
			compiler->CompileFile(currentFileTarget.fileLocation);
		}
	}
	
    return 0;
}