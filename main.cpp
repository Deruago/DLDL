#include "DLDL/IR/ConstructLanguage.h"
#include "DLDL/Print/Language.h"
#include "DLDL/Generate/Project.h"
#include "DLDL/Template/CMakeLists/RootCMakeListstTemplate.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string GenerateRootCMakeLists(std::vector<DLDL::ir::Language*> languages)
{
	std::string language_string;

	for (auto* language : languages)
	{
		language_string += language->GetName() + ", ";
	}
	if (!language_string.empty())
	{
		language_string.pop_back();
		language_string.pop_back();
	}

	auto generator = DLDL::filetemplate::RootCMakeListstTemplate();
	generator.languages_->Set(language_string);

	for (auto* language : languages)
	{
		generator.language_->Set(language->GetName());
		generator.language_directory_->ExpandVariableField();
	}

	return generator.GetOutput();
}

deamer::file::tool::Directory InitialiseLanguageDirectory(DLDL::ir::Language* language)
{
	auto directory = deamer::file::tool::Directory(language->GetName());
	directory.AddFile({ "CMakeLists","txt" });

	return directory;
}

deamer::file::tool::Directory GenerateRootDirectory(std::vector<DLDL::ir::Language*> languages)
{
	auto rootDirectory = deamer::file::tool::Directory("./");

	auto rootCMakeProjectFile = deamer::file::tool::File("CMakeLists", "txt");
	rootCMakeProjectFile.SetFileContent(GenerateRootCMakeLists(languages));

	rootDirectory.AddFile(rootCMakeProjectFile);

	for (auto* language : languages)
	{
		rootDirectory.AddDirectory({ InitialiseLanguageDirectory(language) });
	}

	rootDirectory.AddDirectory({ "build" });

	return rootDirectory;
}

int main(int argc, char* argv[])
{
	std::vector<DLDL::ir::Language*> languages;
	try
	{
		DLDL::ir::ConstructLanguage constructLanguage("./");
		constructLanguage.Construct();
		languages = constructLanguage.GetLanguages();
	}
	catch (const std::logic_error&)
	{
		std::cout << "Your directory doesn't have a definition directory.\n";
		return -1;
	}

	DLDL::print::Language printer(languages);
	printer.Print();

	DLDL::generate::Project projectGeneration(languages);
	auto directory = projectGeneration.Generate();

	auto currentDirectory = GenerateRootDirectory(languages);
	currentDirectory.AddDirectory(directory);

	projectGeneration.WriteToDisk(currentDirectory);

	std::string completeCommand = 
		"cd ./build &&"
		" cmake .. &&"
		"cmake --build . --target " + projectGeneration.GetLanguageTarget() + "&&"
		"cd ../ &&" 
		"$(find . -name \"" + projectGeneration.GetLanguageTarget() + "\") &&"
		"rm -f -r ./build &&"
		"mkdir build &&"
		"cd ./build &&"
		"cmake ..";
	
	deamer::file::tool::Action completeAction = { completeCommand };
	std::system(completeAction.GetSubShellAction(deamer::file::tool::os_used).c_str());

	return 0;
}
