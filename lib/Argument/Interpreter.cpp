#include "DLDL/Argument/Interpreter.h"
#include "DLDL/Generate/Project.h"
#include "DLDL/IR/ConstructLanguage.h"
#include "DLDL/Print/Language.h"
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
	directory.AddFile({"CMakeLists", "txt", "",
					   deamer::file::tool::GenerationLevel::Dont_generate_if_file_already_exists});

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
		rootDirectory.AddDirectory({InitialiseLanguageDirectory(language)});
	}

	rootDirectory.AddDirectory({"build"});

	return rootDirectory;
}

::deamer::file::tool::OSType ConvertStringToOS(std::string osStr)
{
	if (osStr == "windows")
	{
		return deamer::file::tool::OSType::os_windows;
	}
	else if (osStr == "mac")
	{
		return deamer::file::tool::OSType::os_mac;
	}
	else if (osStr == "linux")
	{
		return deamer::file::tool::OSType::os_linux;
	}
	else
	{
		return deamer::file::tool::os_used;
	}
}

DLDL::argument::Interpreter::Interpreter(size_t count, const char* arguments[])
	: parser(count, arguments)
{
	if (parser.IsArgumentSet(Type::definition_map))
	{
		DefinitionMap = parser.GetArgument(Type::definition_map).value;
	}

	if (parser.IsArgumentSet(Type::build_map))
	{
		BuildMap = parser.GetArgument(Type::build_map).value;
	}

	if (parser.IsArgumentSet(Type::language_name))
	{
		language_name = parser.GetArgument(Type::language_name).value;
	}

	if (parser.IsArgumentSet(Type::target_os))
	{
		os = ConvertStringToOS(parser.GetArgument(Type::target_os).value);
	}
}

DLDL::argument::Interpreter::~Interpreter()
{
	for (auto* language : languages)
	{
		delete language;
	}

	delete projectGeneration;
}

size_t DLDL::argument::Interpreter::Run()
{
	Disclaimer();

	if (ExitArguments())
		return 0;

	if (parser.IsArgumentSet(Type::echo))
	{
		std::cout << "Echo: " << parser.GetArgument(Type::echo).value << "\n";
	}

	if (!InitializeLanguages())
		return -1;

	PrintLanguages();

	CompilerGenerator_Generation();

	AutoCompile();

	AutoRun();

	GitOptions();

	return 0;
}

void DLDL::argument::Interpreter::Disclaimer()
{
	std::cout << "Copyright (C) 2020-2021  Thimo Bohmer\n"
				 "For more information about DLDL: https://github.com/Deruago/DLDL \n"
				 "\n";
	std::cout
		<< "This program comes with ABSOLUTELY NO WARRANTY; for details type `DLDL -license'.\n"
		   "This is free software, and you are welcome to redistribute it\n"
		   "\n";
}

bool DLDL::argument::Interpreter::ExitArguments()
{
	if (parser.IsArgumentSet(Type::exit))
	{
		Exit();
		return true;
	}

	if (parser.IsArgumentSet(Type::help))
	{
		Help();
		return true;
	}

	if (parser.IsArgumentSet(Type::information))
	{
		Information();
		return true;
	}

	if (parser.IsArgumentSet(Type::copyright))
	{
		Copyright();
		return true;
	}

	if (parser.IsArgumentSet(Type::version))
	{
		Version();
		return true;
	}

	if (parser.IsArgumentSet(Type::license))
	{
		License();
		return true;
	}

	if (parser.IsArgumentSet(Type::compatible))
	{
		Compatible();
		return true;
	}

	if (parser.IsArgumentSet(Type::initialize))
	{
		Initialize();
		return true;
	}

	if (parser.IsArgumentSet(Type::supported_grammars))
	{
		SupportedGrammars();
		return true;
	}

	if (parser.IsArgumentSet(Type::about))
	{
		About();
		return true;
	}

	return false;
}

void DLDL::argument::Interpreter::Help()
{
	std::cout
		<< "This is the help page, this shows all the documented arguments that you can use with "
		   "DLDL.\n"
		   "Some arguments might not work, because they may not be implemented yet.\n"
		   "\n"
		   "Informational arguments:\n"
		   "	-help                                       ; Shows this page.\n"
		   "	-license, -copyright                        ; Shows the license.\n"
		   "	-information                                ; Shows version, compatibility, "
		   "copyright, and this page.\n"
		   "	-version                                    ; Shows the current version of DLDL.\n"
		   "	-compatible                                 ; Shows the compatibility with Deamer "
		   "CC.\n"
		   "	-exit                                       ; Exits DLDL.\n"
		   "	-echo                                       ; Repeats the text that was given.\n"
		   "	-supported-grammars                         ; Shows list of supported grammars "
		   "available in this version of DLDL.\n"
		   "	-about                                      ; Shows information about DLDL and "
		   "Deamer.\n"
		   "\n"
		   "Behavioural arguments (modify what DLDL does):\n"
		   "	-init, -initial, -initialize                ; Initializes DLDL project for the "
		   "'language'.\n"
		   "	-generate, -gen, -g                         ; Generates the compiler generator "
		   "project,\n"
		   "	                                            ; given a 'Definition Map'.\n"
		   "	-auto-compile, -ac                          ; Auto compiles the "
		   "CompilerGenerator.\n"
		   "	-auto-run, -ar                              ; Auto runs the compiled executable.\n"
		   "Single/Multi Project generation (Single Project is Default):\n"
		   "	-single-project, -sp                        ; Generate a single project.\n"
		   "	-multi-project, -mp                         ; Generate a multi project, each language\n"
		   "	                                            ; is its own project.\n"
		   "\n"
		   "Internal behavioural settings (modify how DLDL does stuff):\n"
		   "	-language-name, -lang-name                  ; Modify the 'language' used to "
		   "initialize.\n"
		   "	-target-language, tl                        ; Sets the 'target language', by "
		   "default this is C++.\n"
		   "	-build-map, -bm                             ; Specify the build map. Default: "
		   "'./build'\n"
		   "	-definition-map, -dm                        ; Specify the definition map. Default: "
		   "'./Definition'\n"
		   "	-target-os                                  ; Specifies which OS should be "
		   "targeted when generating the compiler.\n"
		   "	                                            ; Default is the OS this executable is "
		   "installed in.\n"
		   "\n"
		   "Debug options:\n"
		   "	-debug-dldl                                 ; Allow DLDL to output debug messages "
		   "from DLDL.\n"
		   "	-debug-build                                ; Creates a debug build for Deamer "
		   "CC.\n"
		   "	-log                                        ; Logs DLDL output to a txt.\n"
		   "	-print-parser-output                        ; Prints the DLDL parser result after "
		   "reading the definitions.\n"
		   "\n"
		   "The next set of arguments are arguments allowing automated calls to executables.\n"
		   "E.g. DLDL can automatically initialize git repo's if Git is installed.\n"
		   "Git maintaince arguments:\n"
		   "	-git-init, -git-initialize                  ; Automatically initializes git repo.\n"
		   "	-git-maintain-definition                    ; Automatically commits when the "
		   "Definition is updated.\n"
		   "\n"
		   "Clang format arguments:\n"
		   "	-clang-format-default                       ; Initializes default clang format "
		   "style (Deamer CC style).\n";
}

void DLDL::argument::Interpreter::Information()
{
	Version();
	std::cout << "\n"
				 "Copyright (C) 2020-2021  Thimo Bohmer\n"
				 "For more information about DLDL: https://github.com/Deruago/DLDL \n"
				 "\n";
	Help();
}

void DLDL::argument::Interpreter::Copyright()
{
	License();
}

void DLDL::argument::Interpreter::Version()
{
	std::cout << "Current DLDL version: " << version << "\n";
}

void DLDL::argument::Interpreter::License()
{
	std::cout << "Copyright (C) 2020-2021  Thimo Bohmer\n"
				 "For more information about DLDL: https://github.com/Deruago/DLDL \n"
				 "\n"
			  << "This program is free software; you can redistribute it and/or\n"
				 "modify it under the terms of the GNU General Public License\n"
				 "as published by the Free Software Foundation; either version 3\n"
				 "of the License, or (at your option) any later version.\n"
				 "\n"
				 "This program is distributed in the hope that it will be useful,\n"
				 "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
				 "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
				 "GNU General Public License for more details.\n"
				 "\n"
				 "You should have received a copy of the GNU General Public License\n"
				 "along with this program; if not, write to the Free Software Foundation,\n"
				 "Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.\n"
				 "\n";

	PrintUsedLicenses();
}

void DLDL::argument::Interpreter::PrintUsedLicenses() const
{
	std::cout << "Dependencies:\n";
	std::cout << DeamerCC.GetLicenseMessage(1) << "\t----------------------------\n";
	std::cout << DeamerExternal.GetLicenseMessage(1) << "\n";
	std::cout << DeamerAlgorithm.GetLicenseMessage(1) << "\n";
}

void DLDL::argument::Interpreter::Exit()
{
	std::cout << "Now exiting!\n";
}

void DLDL::argument::Interpreter::Compatible()
{
	std::cout << "DLDL is compatible with Deamer CC versions: " << compatibleDeamerCC_Versions
			  << "\n";
}

void DLDL::argument::Interpreter::Initialize()
{
	if (parser.IsArgumentSet(Type::initialize))
	{
		if (language_name.empty())
		{
			std::cout << "Please specify a language name using the argument: '-language-name'\n";
			return;
		}

		deamer::file::tool::Directory rootDirectory("./");
		deamer::file::tool::Directory definition(DefinitionMap);
		deamer::file::tool::Directory languageDefinition(language_name);
		deamer::file::tool::Directory languageOutput(language_name);

		languageDefinition.AddFile({"Lexicon", "dldl"});
		languageDefinition.AddFile({"Lexicon", "dldls"});

		languageDefinition.AddFile({"Grammar", "dldl"});
		languageDefinition.AddFile({"Grammar", "dldls"});

		languageDefinition.AddFile({"Generation", "dldl"});
		languageDefinition.AddFile({"Generation", "dldls"});

		languageDefinition.AddFile({"Identity", "dldl"});
		languageDefinition.AddFile({"Identity", "dldls"});

		definition.AddDirectory(languageDefinition);
		rootDirectory.AddDirectory(definition);
		rootDirectory.AddDirectory(languageOutput);

		generate::Project(languages, parser.IsArgumentSet(Type::multi_project))
			.WriteToDisk(rootDirectory);
	}
}

void DLDL::argument::Interpreter::SupportedGrammars()
{
	std::cout << "DLDL supported grammars:\n";
	for (const auto& supportedGrammar : supportedGrammars)
	{
		std::cout << "	-" + supportedGrammar << "\n";
	}
}

void DLDL::argument::Interpreter::About()
{
	std::cout
		<< "DLDL is a set of DSL's for generating definitions for Deamer CC.\n"
		   "DLDL can initialize Deamer-projects, generate compiler generators, and much more\n"
		   "when given a set of definitions.\n"
		   "\n"
		   "When DLDL is done generating the definitions for Deamer CC.\n"
		   "Deamer CC will take its role as infrastructure for compiler and ecosystem generation.\n"
		   "Using Deamer CC you can compile the definitions and generate your defined compiler and "
		   "ecosystem.\n"
		   "\n"
		   "For more information about DLDL go to: https://github.com/Deruago/DLDL \n"
		   "For more information about Deamer CC go to: "
		   "https://github.com/Deruago/theDeamerProject \n"
		   "\n";
}

void DLDL::argument::Interpreter::PrintLanguages()
{
	if (parser.IsArgumentSet(Type::print_parse_result))
	{
		DLDL::print::Language printer(languages);
		printer.Print();
	}
}

bool DLDL::argument::Interpreter::InitializeLanguages()
{
	try
	{
		DLDL::ir::ConstructLanguage constructLanguage("./", DefinitionMap);
		constructLanguage.Construct(os);
		languages = constructLanguage.GetLanguages();
	} catch (const std::logic_error&)
	{
		std::cout << "Your directory doesn't have a definition directory.\n";
		return false;
	}
	return true;
}

void DLDL::argument::Interpreter::CompilerGenerator_Generation()
{
	projectGeneration =
		new DLDL::generate::Project(languages, parser.IsArgumentSet(Type::multi_project));
	if (parser.IsArgumentSet(Type::generate))
	{
		auto directory = projectGeneration->Generate();

		auto currentDirectory = GenerateRootDirectory(languages);
		currentDirectory.AddDirectory(directory);

		projectGeneration->WriteToDisk(currentDirectory);
	}
}

void DLDL::argument::Interpreter::AutoCompile()
{
	if (parser.IsArgumentSet(Type::auto_compile))
	{
		const std::string autoCompile = "rm -f -r ./" + BuildMap +
										" &&"
										"mkdir ./" +
										BuildMap +
										" &&"
										"cd ./" +
										BuildMap +
										" &&"
										" cmake .. &&"
										"cmake --build . --target " +
										projectGeneration->GetLanguageTarget() +
										"&&"
										"cd ../";

		const deamer::file::tool::Action autoCompileAction = {autoCompile};
		std::system(autoCompileAction.GetSubShellAction(deamer::file::tool::os_used).c_str());
	}
}

void DLDL::argument::Interpreter::AutoRun()
{
	if (parser.IsArgumentSet(Type::auto_run))
	{
		const std::string autoRun = "$(find . -name \"" + projectGeneration->GetLanguageTarget() +
									"\") &&"
									"rm -f -r ./" +
									BuildMap +
									" &&"
									"mkdir ./" +
									BuildMap +
									" &&"
									"cd ./" +
									BuildMap +
									" &&"
									"cmake ..";
		const deamer::file::tool::Action autoRunAction = {autoRun};
		std::system(autoRunAction.GetSubShellAction(deamer::file::tool::os_used).c_str());
	}
}

void DLDL::argument::Interpreter::GitOptions()
{
	if (parser.IsArgumentSet(Type::git_initialize))
	{
		const bool gitDirectoryExists = std::filesystem::exists("./.git");
		if (!gitDirectoryExists)
		{
			const std::string gitInit = "git init";
			const deamer::file::tool::Action gitInitAction = {gitInit};
			std::system(gitInitAction.GetSubShellAction(deamer::file::tool::os_used).c_str());

			CreateGitignore();

			const std::string gitAddDot = "git add .";
			const deamer::file::tool::Action gitAddDotAction = {gitAddDot};
			std::system(gitAddDotAction.GetSubShellAction(deamer::file::tool::os_used).c_str());

			const std::string gitInitialCommit = "git commit -m \"Initial Commit!\"";
			const deamer::file::tool::Action gitInitialCommitAction = {gitInitialCommit};
			std::system(
				gitInitialCommitAction.GetSubShellAction(deamer::file::tool::os_used).c_str());
		}
	}
}

void DLDL::argument::Interpreter::CreateGitignore()
{
	deamer::file::tool::Directory rootDirectory("./");

	deamer::file::tool::File gitignore("", "gitignore", "**/build/*");

	rootDirectory.AddFile(gitignore);

	generate::Project(languages, parser.IsArgumentSet(Type::multi_project))
		.WriteToDisk(rootDirectory);
}
