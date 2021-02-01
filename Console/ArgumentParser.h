#ifndef DLDL_CONSOLE_ARGUMENTPARSER_H
#define DLDL_CONSOLE_ARGUMENTPARSER_H
#include "ArgumentInformation/Help.h"
#include "ArgumentInformation/ShowAST.h"
#include "ArgumentInformation/ShowText.h"
#include "ArgumentInformation/ShowStructure.h"
#include "ArgumentInformation/DebugInformation.h"
#include "ArgumentInformation/ShowTextAfterPreProcessor.h"
#include "ArgumentInformation/Threat.h"
#include "ArgumentInformation/AllArguments.h"
#include "ArgumentInformation/AutoCompile.h"
#include <map>
#include <string>
#include <vector>


namespace DLDL {
	enum class ArgumentType_t;
	enum class DefinitionType_t;
	struct Argument;
	struct FileTarget;

	class ArgumentParser
	{
	private:
		std::vector<ArgumentInformation*> arguments = {
			new DLDL::Help(),
			new DLDL::ShowAST(),
			new DLDL::ShowText(),
			new DLDL::ShowStructure(),
			new DLDL::ShowTextAfterPreProcessor(),
			new DLDL::Threat(),
			new DLDL::AutoCompile(),
			new DLDL::DebugInformation(),
			new DLDL::AllArguments(),
		};
		
		std::map<std::string, DLDL::ArgumentType_t> stringToArgumentType;
		std::map<std::string, DLDL::DefinitionType_t> fileNameToDefinitionType;
	public:
		ArgumentParser();
		~ArgumentParser();

		std::vector<Argument> ParseArguments(int argc, char** argv) const;
		std::string Help() const;

		bool IsArgumentActivatedInArguments(const DLDL::ArgumentType_t& argumentType, const std::vector<Argument>& arguments) const;

		std::vector<DLDL::FileTarget> GetDefinitionTypesFromArgumentList(int argc, char** argv) const;

		DLDL::DefinitionType_t GetDefinitionTypeOfFileName(std::string fileName) const;
		DLDL::DefinitionType_t ReturnDefinitionTypeBasedOnFileExtension(const std::string& fileExtension) const;
	};
}

#endif //DLDL_CONSOLE_ARGUMENTPARSER_H