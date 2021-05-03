#include "DLDL/IR/ConstructLanguage.h"
#include "DLDL/Print/Language.h"
#include "DLDL/Generate/Project.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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
	projectGeneration.WriteToDisk(directory);
	
	return 0;
}
