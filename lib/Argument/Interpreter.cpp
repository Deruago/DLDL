#include "DLDL/Argument/Interpreter.h"
#include "DLDL/Filesystem/LoadFilesystem.h"
#include "DLDL/Generate/DirectoryToDisk.h"
#include "DLDL/Generate/Lpd/Project.h"
#include "DLDL/Generate/Project.h"
#include "DLDL/IR/ConstructLanguage.h"
#include "DLDL/IR/Lpd/ConstructLPD.h"
#include "DLDL/Print/Language.h"
#include "DLDL/Template/CMakeLists/RootCMakeListsTemplate.h"
#include "DLDL/Template/Python/CrossPlatform/ConsolePyTemplate.h"
#include <Deamer/File/Tool/Action/Builder.h>
#include <Deamer/File/Tool/Action/PythonConsole.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
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

	auto generator = DLDL::filetemplate::RootCMakeListsTemplate();
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

deamer::file::tool::Directory
DLDL::argument::Interpreter::GenerateRootDirectory(std::vector<DLDL::ir::Language*> languages)
{
	auto rootDirectory = deamer::file::tool::Directory(deamerDirRelocation);

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

void DLDL::argument::Interpreter::InitializeInterpreter(bool force)
{
	// Load in and ensure if there is a .deamer directory to load in that directory.
	// Unless it is in initialization stage.
	if (!parser.IsArgumentSet(Type::initialize) || !force)
	{
		LoadInDeamerDir();
		::deamer::file::tool::Directory deamerArgs;
		filesystem::LoadFilesystem(deamerArgs, deamerDirRelocation)
			.Enter(".deamer")
			.Enter("dldl")
			.Enter("arguments")
			.DirectLoad();
		auto files = deamerArgs.GetFiles();
		std::optional<::deamer::file::tool::File> regenArgs;
		for (const auto& file : files)
		{
			if (file.GetFilename() == "full")
			{
				regenArgs = file;
			}
		}

		if (regenArgs.has_value())
		{
			parser.Overwrites(regenArgs.value().FileContent());
		}
	}

	if (parser.IsArgumentSet(Type::regenerate))
	{
		// Definition auto generate arguments
		parser.SetArguments({{Type::generate}, {Type::auto_compile}, {Type::auto_run}});

		// LPD auto generate arguments
		parser.SetArguments({{Type::generate_lpd}});

		// Tool auto generate arguments
		parser.SetArguments({{Type::generate_tool}});
	}

	if (parser.IsArgumentSet(Type::definition_map))
	{
		DefinitionMap = parser.GetArgument(Type::definition_map).value;
	}

	if (parser.IsArgumentSet(Type::build_map))
	{
		BuildMap = parser.GetArgument(Type::build_map).value;
	}

	if (parser.IsArgumentSet(Type::lpd_map))
	{
		LpdMap = parser.GetArgument(Type::lpd_map).value;
	}

	if (parser.IsArgumentSet(Type::tool_map))
	{
		ToolMap = parser.GetArgument(Type::tool_map).value;
	}

	if (parser.IsArgumentSet(Type::language_name))
	{
		language_name = parser.GetArgument(Type::language_name).value;
	}

	if (parser.IsArgumentSet(Type::target_os))
	{
		os = ConvertStringToOS(parser.GetArgument(Type::target_os).value);
	}

	if (!parser.IsArgumentSet(Type::initialize) || !force)
	{
		InitializeDeamerMap();
	}
}

DLDL::argument::Interpreter::Interpreter(size_t count, const char* arguments[])
	: parser(count, arguments)
{
	InitializeInterpreter();
}

DLDL::argument::Interpreter::~Interpreter()
{
	for (auto* language : languages)
	{
		delete language;
	}

	delete projectGeneration;
}

std::size_t DLDL::argument::Interpreter::GenerateLanguage()
{
	if (parser.IsArgumentSet(Type::activate_language_generation) &&
		parser.GetArgument(Type::activate_language_generation).value == "false")
	{
		return 0;
	}

	if (!InitializeLanguages())
	{
		return -1;
	}

	PrintLanguages();

	CompilerGenerator_Generation();

	AutoCompile();

	AutoRun();

	return 0;
}

std::size_t DLDL::argument::Interpreter::GenerateLpd()
{
	if (!(parser.IsArgumentSet(Type::activate_lpd_generation) &&
		  parser.GetArgument(Type::activate_lpd_generation).value == "true" &&
		  parser.IsArgumentSet(Type::generate_lpd)))
	{
		return 0;
	}

	const std::string lpdDirectoryLocation =
		deamerDirRelocation + parser.GetArgument(Type::lpd_map).value;
	auto constructLpd = ir::ConstructLPD(lpdDirectoryLocation);
	constructLpd.Construct(os);
	lpdProject = constructLpd.GetLPDProject();
	auto projectGen = DLDL::generate::lpd::Project(lpdProject);
	const auto projectDirectory = projectGen.Generate();

	GenerateLpdMainLpdSource(projectDirectory);
	GenerateLpdMainLpdInclude(projectDirectory);

	GenerateLpdToolLpdSource(projectDirectory);
	GenerateLpdToolLpdInclude(projectDirectory);

	GenerateLpdMainLdoSource(projectDirectory);
	GenerateLpdMainLdoInclude(projectDirectory);

	GenerateLpdToolLdoSource(projectDirectory);
	GenerateLpdToolLdoInclude(projectDirectory);

	GenerateLpdConvertor(projectDirectory);
	GenerateLpdValidator(projectDirectory);

	GenerateLpdMainGenerator(projectDirectory);
	GenerateLpdSpecialGenerator(projectDirectory);
	GenerateLpdToolGenerator(projectDirectory);

	GenerateLpdEnumerationsLpd(projectDirectory);
	GenerateLpdEnumerationsLdo(projectDirectory);

	return 0;
}

void DLDL::argument::Interpreter::GenerateLpdMainLpdSource(
	const DLDL::generate::lpd::Project::LPDDirectory lpdDirectory)
{
	if (!parser.IsArgumentSet(Type::lpd_generation_map_main_lpd_source))
	{
		return;
	}
	const auto path = parser.GetArgument(Type::lpd_generation_map_main_lpd_source).value;
	::deamer::file::tool::Directory outputDirectory(path);
	outputDirectory.AddDirectory(lpdDirectory.mainSourceLPD);
	generate::DirectoryToDisk::WriteToDisk(outputDirectory, "./");
}

void DLDL::argument::Interpreter::GenerateLpdMainLpdInclude(
	const generate::lpd::Project::LPDDirectory& lpdDirectory)
{
	if (!parser.IsArgumentSet(Type::lpd_generation_map_main_lpd_include))
	{
		return;
	}
	const auto path = parser.GetArgument(Type::lpd_generation_map_main_lpd_include).value;
	::deamer::file::tool::Directory outputDirectory(path);
	outputDirectory.AddDirectory(lpdDirectory.mainLPD);
	generate::DirectoryToDisk::WriteToDisk(outputDirectory, "./");
}

void DLDL::argument::Interpreter::GenerateLpdToolLpdSource(
	const generate::lpd::Project::LPDDirectory& lpdDirectory)
{
	if (!parser.IsArgumentSet(Type::lpd_generation_map_tool_lpd_source))
	{
		return;
	}
	const auto path = parser.GetArgument(Type::lpd_generation_map_tool_lpd_source).value;
	::deamer::file::tool::Directory outputDirectory(path);
	outputDirectory.AddDirectory(lpdDirectory.toolSourceLPD);
	generate::DirectoryToDisk::WriteToDisk(outputDirectory, "./");
}

void DLDL::argument::Interpreter::GenerateLpdToolLpdInclude(
	const generate::lpd::Project::LPDDirectory& lpdDirectory)
{
	if (!parser.IsArgumentSet(Type::lpd_generation_map_tool_lpd_include))
	{
		return;
	}
	const auto path = parser.GetArgument(Type::lpd_generation_map_tool_lpd_include).value;
	::deamer::file::tool::Directory outputDirectory(path);
	outputDirectory.AddDirectory(lpdDirectory.toolLPD);
	generate::DirectoryToDisk::WriteToDisk(outputDirectory, "./");
}

void DLDL::argument::Interpreter::GenerateLpdMainLdoSource(
	const generate::lpd::Project::LPDDirectory& lpdDirectory)
{
	if (!parser.IsArgumentSet(Type::lpd_generation_map_main_ldo_source))
	{
		return;
	}
	const auto path = parser.GetArgument(Type::lpd_generation_map_main_ldo_source).value;
	::deamer::file::tool::Directory outputDirectory(path);
	outputDirectory.AddDirectory(lpdDirectory.mainSourceLDO);
	generate::DirectoryToDisk::WriteToDisk(outputDirectory, "./");
}

void DLDL::argument::Interpreter::GenerateLpdMainLdoInclude(
	const generate::lpd::Project::LPDDirectory& lpdDirectory)
{
	if (!parser.IsArgumentSet(Type::lpd_generation_map_main_ldo_include))
	{
		return;
	}
	const auto path = parser.GetArgument(Type::lpd_generation_map_main_ldo_include).value;
	::deamer::file::tool::Directory outputDirectory(path);
	outputDirectory.AddDirectory(lpdDirectory.mainLDO);
	generate::DirectoryToDisk::WriteToDisk(outputDirectory, "./");
}

void DLDL::argument::Interpreter::GenerateLpdToolLdoSource(
	const generate::lpd::Project::LPDDirectory& lpdDirectory)
{
	if (!parser.IsArgumentSet(Type::lpd_generation_map_tool_ldo_source))
	{
		return;
	}
	const auto path = parser.GetArgument(Type::lpd_generation_map_tool_ldo_source).value;
	::deamer::file::tool::Directory outputDirectory(path);
	outputDirectory.AddDirectory(lpdDirectory.toolSourceLDO);
	generate::DirectoryToDisk::WriteToDisk(outputDirectory, "./");
}

void DLDL::argument::Interpreter::GenerateLpdToolLdoInclude(
	const generate::lpd::Project::LPDDirectory& lpdDirectory)
{
	if (!parser.IsArgumentSet(Type::lpd_generation_map_tool_ldo_include))
	{
		return;
	}
	const auto path = parser.GetArgument(Type::lpd_generation_map_tool_ldo_include).value;
	::deamer::file::tool::Directory outputDirectory(path);
	outputDirectory.AddDirectory(lpdDirectory.toolLDO);
	generate::DirectoryToDisk::WriteToDisk(outputDirectory, "./");
}

void DLDL::argument::Interpreter::GenerateLpdConvertor(
	const generate::lpd::Project::LPDDirectory& lpdDirectory)
{
	if (!parser.IsArgumentSet(Type::lpd_generation_map_convertor))
	{
		return;
	}
	const auto path = parser.GetArgument(Type::lpd_generation_map_convertor).value;
	::deamer::file::tool::Directory outputDirectory(path);
	outputDirectory.AddDirectory(lpdDirectory.converter);
	generate::DirectoryToDisk::WriteToDisk(outputDirectory, "./");
}

void DLDL::argument::Interpreter::GenerateLpdValidator(
	const generate::lpd::Project::LPDDirectory& lpdDirectory)
{
	if (!parser.IsArgumentSet(Type::lpd_generation_map_validator))
	{
		return;
	}
	const auto path = parser.GetArgument(Type::lpd_generation_map_validator).value;
	::deamer::file::tool::Directory outputDirectory(path);
	outputDirectory.AddDirectory(lpdDirectory.validater);
	generate::DirectoryToDisk::WriteToDisk(outputDirectory, "./");
}

void DLDL::argument::Interpreter::GenerateLpdMainGenerator(
	const generate::lpd::Project::LPDDirectory& lpdDirectory)
{
	if (!parser.IsArgumentSet(Type::lpd_generation_map_main_generator))
	{
		return;
	}
	const auto path = parser.GetArgument(Type::lpd_generation_map_main_generator).value;
	::deamer::file::tool::Directory outputDirectory(path);
	outputDirectory.AddDirectory(lpdDirectory.generater);
	generate::DirectoryToDisk::WriteToDisk(outputDirectory, "./");
}

void DLDL::argument::Interpreter::GenerateLpdSpecialGenerator(
	const generate::lpd::Project::LPDDirectory& lpdDirectory)
{
	if (!parser.IsArgumentSet(Type::lpd_generation_map_special_generator))
	{
		return;
	}
	const auto path = parser.GetArgument(Type::lpd_generation_map_special_generator).value;
	::deamer::file::tool::Directory outputDirectory(path);
	outputDirectory.AddDirectory(lpdDirectory.generaterSpecial);
	generate::DirectoryToDisk::WriteToDisk(outputDirectory, "./");
}

void DLDL::argument::Interpreter::GenerateLpdToolGenerator(
	const generate::lpd::Project::LPDDirectory& lpdDirectory)
{
	if (!parser.IsArgumentSet(Type::lpd_generation_map_tool_generator))
	{
		return;
	}
	const auto path = parser.GetArgument(Type::lpd_generation_map_tool_generator).value;
	::deamer::file::tool::Directory outputDirectory(path);
	outputDirectory.AddDirectory(lpdDirectory.generaterTool);
	generate::DirectoryToDisk::WriteToDisk(outputDirectory, "./");
}

void DLDL::argument::Interpreter::GenerateLpdEnumerationsLpd(
	const generate::lpd::Project::LPDDirectory& lpdDirectory)
{
	if (!parser.IsArgumentSet(Type::lpd_generation_map_lpd_enumerations))
	{
		return;
	}
	const auto path = parser.GetArgument(Type::lpd_generation_map_lpd_enumerations).value;
	::deamer::file::tool::Directory outputDirectory(path);
	outputDirectory.AddDirectory(lpdDirectory.lpdEnumeration);
	generate::DirectoryToDisk::WriteToDisk(outputDirectory, "./");
}

void DLDL::argument::Interpreter::GenerateLpdEnumerationsLdo(
	const generate::lpd::Project::LPDDirectory& lpdDirectory)
{
	if (!parser.IsArgumentSet(Type::lpd_generation_map_ldo_enumerations))
	{
		return;
	}
	const auto path = parser.GetArgument(Type::lpd_generation_map_ldo_enumerations).value;
	::deamer::file::tool::Directory outputDirectory(path);
	outputDirectory.AddDirectory(lpdDirectory.ldoEnumeration);
	generate::DirectoryToDisk::WriteToDisk(outputDirectory, "./");
}

std::size_t DLDL::argument::Interpreter::GenerateTool()
{
	if (!(parser.IsArgumentSet(Type::activate_tool_generation) &&
		  parser.GetArgument(Type::activate_tool_generation).value == "true" &&
		  parser.IsArgumentSet(Type::generate_tool)))
	{
		return 0;
	}

	return 0;
}

std::size_t DLDL::argument::Interpreter::Run()
{
	Disclaimer();

	if (ExitArguments())
		return 0;
	InitializeInterpreter(true); // If there is a .deamer dir, reinitialize the interpreter

	if (parser.IsArgumentSet(Type::echo))
	{
		std::cout << "Echo: " << parser.GetArgument(Type::echo).value << "\n";
	}

	const std::size_t languageSuccess = GenerateLanguage();
	const std::size_t lpdSuccess = GenerateLpd();
	const std::size_t toolSuccess = GenerateTool();

	const std::size_t success = languageSuccess | lpdSuccess | toolSuccess;
	if (success != 0)
	{
		return success;
	}

	GitOptions();

	return 0;
}

void DLDL::argument::Interpreter::Disclaimer()
{
	std::cout << "Copyright (C) 2020-2022  Thimo Bohmer\n"
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

	if (parser.IsArgumentSet(Type::init_lpd))
	{
		InitializeLpd();
		return true;
	}

	if (parser.IsArgumentSet(Type::init_tool))
	{
		InitializeTool();
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
		<< "This is the help page, this shows all the documented arguments that you can use "
		   "with "
		   "DLDL.\n"
		   "Some arguments might not work, because they may not be implemented yet.\n"
		   "\n"
		   "Informational arguments:\n"
		   "	-help                                       ; Shows this page.\n"
		   "	-license, -copyright                        ; Shows the license.\n"
		   "	-information                                ; Shows version, compatibility, "
		   "copyright, and this page.\n"
		   "	-version                                    ; Shows the current version of "
		   "DLDL.\n"
		   "	-compatible                                 ; Shows the compatibility with "
		   "Deamer "
		   "CC.\n"
		   "	-exit                                       ; Exits DLDL.\n"
		   "	-echo                                       ; Repeats the text that was "
		   "given.\n"
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
		   "	-auto-run, -ar                              ; Auto runs the compiled "
		   "executable.\n"
		   "	-regen, -regenerate                         ; Regenerates the Deamer project.\n"
		   "	                                            ; Goes to nearest .deamer dir, and "
		   "regenerates the project.\n"
		   "	-cp, -custom-project                        ; Specifies a custom project, this "
		   "may\n"
		   "	                                            ; not be a language project.\n"
		   "	-init-lpd                                   ; Initializes a new LPD definition.\n"
		   "	-init-tool                                  ; Initializes a new Tool definition.\n"
		   "\n"
		   "Single/Multi Project generation (Single Project is Default):\n"
		   "	-single-project, -sp                        ; Generate a single project.\n"
		   "	-multi-project, -mp                         ; Generate a multi project, each "
		   "language\n"
		   "	                                            ; is its own project.\n"
		   "	-no-deamer                                  ; Removes the .deamer map, some "
		   "features might become unavailable.\n"
		   "	-generate-language                          ; If false no language project is "
		   "generated.\n"
		   "\n"
		   "Internal behavioural settings (modify how DLDL does stuff):\n"
		   "	-language-name, -lang-name                  ; Modify the 'language' used to "
		   "initialize.\n"
		   "	-lpd-name                                   ; Specifies the target lpd name.\n"
		   "	-tool-name                                  ; Specifies the target tool name.\n"
		   "	-target-language, tl                        ; Sets the 'target language', by "
		   "default this is C++.\n"
		   "	-build-map, -bm                             ; Specify the build map. Default: "
		   "'./build'\n"
		   "	-definition-map, -dm                        ; Specify the definition map. "
		   "Default: "
		   "'./Definition'\n"
		   "	-lpd-map, -lm                               ; Specify the LPD map. Default: "
		   "there is no LPD map.\n"
		   "	-tool-map, -tm                              ; Specify the Tool map. Default: "
		   "there is no Tool map.\n"
		   "	-deamer-map                                 ; Specify the .deamer map. "
		   "Default: "
		   "current map DLDL is called, or nearest .deamer map\n"
		   "	-target-os                                  ; Specifies which OS should be "
		   "targeted when generating the compiler.\n"
		   "	                                            ; Default is the OS this "
		   "executable is "
		   "installed in.\n"
		   "\n"
		   "Debug options:\n"
		   "	-debug-dldl                                 ; Allow DLDL to output debug "
		   "messages "
		   "from DLDL.\n"
		   "	-debug-build                                ; Creates a debug build for Deamer "
		   "CC.\n"
		   "	-log                                        ; Logs DLDL output to a txt.\n"
		   "	-print-parser-output                        ; Prints the DLDL parser result "
		   "after "
		   "reading the definitions.\n"
		   "\n"
		   "The next set of arguments are arguments allowing automated calls to executables.\n"
		   "E.g. DLDL can automatically initialize git repo's if Git is installed.\n"
		   "Git maintaince arguments:\n"
		   "	-git-init, -git-initialize                  ; Automatically initializes git "
		   "repo.\n"
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
				 "Copyright (C) 2020-2022  Thimo Bohmer\n"
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
	std::cout << "Copyright (C) 2020-2022  Thimo Bohmer\n"
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
	if (!parser.IsArgumentSet(Type::initialize))
	{
		return;
	}

	InitializeDeamerMap();

	if (parser.IsArgumentSet(Type::custom_project))
	{
		return;
	}

	if (language_name.empty())
	{
		std::cout << "Please specify a language name using the argument: '-language-name'\n";
		return;
	}

	deamer::file::tool::Directory rootDirectory(deamerDirRelocation);
	deamer::file::tool::Directory definition(DefinitionMap);
	deamer::file::tool::Directory languageDefinition(language_name);
	deamer::file::tool::Directory languageOutput(language_name);

	languageDefinition.AddFile({"Lexicon", "dldl"});
	languageDefinition.AddFile({"Grammar", "dldl"});
	languageDefinition.AddFile({"Generation", "dldl"});
	languageDefinition.AddFile({"Identity", "dldl"});

	if (parser.IsArgumentSet(Type::include_dldls))
	{
		languageDefinition.AddFile({"Lexicon", "dldls"});
		languageDefinition.AddFile({"Grammar", "dldls"});
		languageDefinition.AddFile({"Generation", "dldls"});
		languageDefinition.AddFile({"Identity", "dldls"});
	}

	definition.AddDirectory(languageDefinition);
	rootDirectory.AddDirectory(definition);
	rootDirectory.AddDirectory(languageOutput);

	generate::DirectoryToDisk::WriteToDisk(rootDirectory);
}

void DLDL::argument::Interpreter::InitializeDeamerMap()
{
	if (parser.IsArgumentSet(Type::no_deamer))
	{
		return;
	}

	// On initialization always "./", unless pre-discovered
	// when pre-discovered, it maps to the path
	deamer::file::tool::Directory rootDirectory(deamerDirRelocation);
	deamer::file::tool::Directory deamerDirectory(".deamer");
	deamer::file::tool::Directory deamerDLDLDirectory("dldl");
	deamer::file::tool::Directory deamerDLDLScriptsDirectory("scripts");
	deamer::file::tool::Directory deamerDLDLDefinitionDirectory("definition");
	deamer::file::tool::Directory deamerDLDLargumentsDirectory("arguments");

	auto regeneration_arguments = RegenerationArgsDefinition() + " " + RegenerationArgsLPD() + " " +
								  RegenerationArgsTool() + " " + RegenerationArgsMiccel();

	deamer::file::tool::File dldl_regen_args("full", "deamer", regeneration_arguments);
	deamer::file::tool::File dldl_regen_args_lpd("lpd", "deamer", RegenerationArgsLPD());
	deamer::file::tool::File dldl_regen_args_definition("definition", "deamer",
														RegenerationArgsDefinition());
	deamer::file::tool::File dldl_regen_args_tool("tool", "deamer", RegenerationArgsTool());
	deamer::file::tool::File dldl_regen_args_miccel("miccel", "deamer", RegenerationArgsMiccel());

	if (!(parser.IsArgumentSet(Type::no_console) &&
		  parser.GetArgument(Type::no_console).value == "true"))
	{
		auto consolePyTemplate = std::make_unique<filetemplate::ConsolePyTemplate>();

		if (parser.IsArgumentSet(Type::console_debug_mode) &&
			parser.GetArgument(Type::console_debug_mode).value == "true")
		{
			consolePyTemplate->debug_mode_->Set("True");
		}
		else
		{
			consolePyTemplate->debug_mode_->Set("False");
		}
		deamer::file::tool::File dldl_script_console_py("Console", "py",
														consolePyTemplate->GetOutput());
		deamerDLDLScriptsDirectory.AddFile(dldl_script_console_py);
	}
	deamerDLDLargumentsDirectory.AddFile(dldl_regen_args);
	deamerDLDLargumentsDirectory.AddFile(dldl_regen_args_lpd);
	deamerDLDLargumentsDirectory.AddFile(dldl_regen_args_definition);
	deamerDLDLargumentsDirectory.AddFile(dldl_regen_args_tool);
	deamerDLDLargumentsDirectory.AddFile(dldl_regen_args_miccel);

	deamerDLDLDirectory.AddDirectory(deamerDLDLScriptsDirectory);
	deamerDLDLDirectory.AddDirectory(deamerDLDLDefinitionDirectory);
	deamerDLDLDirectory.AddDirectory(deamerDLDLargumentsDirectory);
	deamerDirectory.AddDirectory(deamerDLDLDirectory);
	rootDirectory.AddDirectory(deamerDirectory);

	// Write to disk
	WriteToDisk(rootDirectory);
}

void DLDL::argument::Interpreter::InitializeLpd()
{
	if (!parser.IsArgumentSet(Type::init_lpd) || parser.GetArgument(Type::lpd_name).value.empty())
	{
		std::cout << "Please specify a lpd name using the argument: '-lpd-name'\n";
		return;
	}
	if (!parser.IsArgumentSet(Type::lpd_map) || parser.GetArgument(Type::lpd_map).value.empty())
	{
		std::cout << "Please specify the map where all LPD definitions are located, using the "
					 "argument: '-lpd-map'\n";
		return;
	}

	::deamer::file::tool::Directory lpdDir_;
	const auto lpdName = parser.GetArgument(Type::lpd_name).value;
	const auto exists = filesystem::LoadFilesystem(lpdDir_, deamerDirRelocation + LpdMap)
							.DirectContainsDirectory(lpdName);
	if (exists)
	{
		std::cout << "Given LPD is already defined, please specify a different name\n";
		return;
	}

	auto projectDir = ::deamer::file::tool::Directory(deamerDirRelocation);
	auto lpdDir = ::deamer::file::tool::Directory(LpdMap);
	auto lpdMap = ::deamer::file::tool::Directory(lpdName);
	auto lpdInitFile = ::deamer::file::tool::File("LpdDef", "dldl", "lpd: " + lpdName + "\n");

	lpdMap.AddFile(lpdInitFile);
	lpdDir.AddDirectory(lpdMap);
	projectDir.AddDirectory(lpdDir);

	WriteToDisk(projectDir);
}

void DLDL::argument::Interpreter::InitializeTool()
{
	if (!parser.IsArgumentSet(Type::init_tool) || parser.GetArgument(Type::tool_name).value.empty())
	{
		std::cout << "Please specify a tool name using the argument: '-tool-name'\n";
		return;
	}
	if (!parser.IsArgumentSet(Type::tool_map) || parser.GetArgument(Type::tool_map).value.empty())
	{
		std::cout << "Please specify the map where all tool definitions are located, using the "
					 "argument: '-tool-map'\n";
		return;
	}

	::deamer::file::tool::Directory toolDir_;
	const auto toolName = parser.GetArgument(Type::tool_name).value;
	const auto exists = filesystem::LoadFilesystem(toolDir_, deamerDirRelocation + ToolMap)
							.DirectContainsDirectory(toolName);
	if (exists)
	{
		std::cout << "Given tool is already defined, please specify a different name\n";
		return;
	}

	auto projectDir = ::deamer::file::tool::Directory(deamerDirRelocation);
	auto toolDir = ::deamer::file::tool::Directory(ToolMap);
	auto toolMap = ::deamer::file::tool::Directory(toolName);
	auto toolInitFile = ::deamer::file::tool::File("ToolDef", "dldl", "Tool: " + toolName + "\n");

	toolMap.AddFile(toolInitFile);
	toolDir.AddDirectory(toolMap);
	projectDir.AddDirectory(toolDir);

	WriteToDisk(projectDir);
}

void DLDL::argument::Interpreter::LoadInDeamerDir()
{
	deamer::file::tool::Directory dir;
	auto loader = filesystem::LoadFilesystem(dir);
	while (!loader.DirectContainsDirectory(".deamer") && !loader.ReachedRoot())
	{
		loader.Upper();
	}

	if (loader.ReachedRoot())
	{
		return;
	}

	deamerDirRelocation = loader.GetPath();
	deamerDirExists = true;
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
		   "Deamer CC will take its role as infrastructure for compiler and ecosystem "
		   "generation.\n"
		   "Using Deamer CC you can compile the definitions and generate your defined compiler "
		   "and "
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
		DLDL::ir::ConstructLanguage constructLanguage(deamerDirRelocation, DefinitionMap);
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

		generate::DirectoryToDisk::WriteToDisk(currentDirectory);
	}
}

void DLDL::argument::Interpreter::AutoCompile()
{
	if (parser.IsArgumentSet(Type::auto_compile))
	{
		auto builder = ::deamer::file::tool::action::Builder();
		builder.RemoveDirectory("./" + BuildMap)
			.CreateDirectory("./" + BuildMap)
			.ChangeDirectory("./" + BuildMap)
			.CrossPlatformCommand("cmake ..")
			.CrossPlatformCommand("cmake --build . --target " +
								  projectGeneration->GetLanguageTarget())
			.ChangeDirectory("../"); // should calculate difference

		const auto action = builder.GetAction();
		const auto command = action->ConstructArgument(
			deamer::file::tool::action::CommandTarget::python, deamerDirRelocation);
		std::system(command.c_str());
	}
}

void DLDL::argument::Interpreter::AutoRun()
{
	if (parser.IsArgumentSet(Type::auto_run))
	{
		auto builder = ::deamer::file::tool::action::Builder();
		std::string extension; // empty if on linux, .exe if on windows
		if (deamer::file::tool::os_used == deamer::file::tool::OSType::os_windows &&
			deamer::file::tool::action::PythonConsole::IsAvailable())
		{
			extension = ".exe";
		}
		else
		{
			extension = "";
		}
		builder.FindAndExecute(projectGeneration->GetLanguageTarget() + extension)
			.RemoveDirectory("./" + BuildMap)
			.CreateDirectory("./" + BuildMap)
			.ChangeDirectory("./" + BuildMap)
			.CrossPlatformCommand("cmake ..");

		const auto action = builder.GetAction();
		const auto command = action->ConstructArgument(
			deamer::file::tool::action::CommandTarget::python, deamerDirRelocation);
		std::system(command.c_str());
	}
}

void DLDL::argument::Interpreter::GitOptions()
{
	if (parser.IsArgumentSet(Type::git_initialize))
	{
		const bool gitDirectoryExists =
			std::filesystem::exists("./" + deamerDirRelocation + ".git");
		if (!gitDirectoryExists)
		{
			auto gitInitBuilder = deamer::file::tool::action::Builder();
			gitInitBuilder.CrossPlatformCommand("git init");
			const auto gitInitAction = gitInitBuilder.GetAction();
			const auto gitInitCommand = gitInitAction->ConstructArgument(
				deamer::file::tool::action::CommandTarget::python, deamerDirRelocation);
			std::system(gitInitCommand.c_str());

			CreateGitignore();

			auto gitAddDotBuilder = deamer::file::tool::action::Builder();
			gitAddDotBuilder.CrossPlatformCommand("git add .");
			const auto gitAddDotAction = gitAddDotBuilder.GetAction();
			const auto gitAddDotCommand = gitAddDotAction->ConstructArgument(
				deamer::file::tool::action::CommandTarget::python, deamerDirRelocation);
			std::system(gitAddDotCommand.c_str());

			auto gitInitialBuilder = deamer::file::tool::action::Builder();
			gitInitialBuilder.CrossPlatformCommand("git commit -m \"Initial Commit!\"");
			const auto gitInitialAction = gitInitialBuilder.GetAction();
			const auto gitInitialCommand = gitInitialAction->ConstructArgument(
				deamer::file::tool::action::CommandTarget::python, deamerDirRelocation);
			std::system(gitInitialCommand.c_str());
		}
	}
}

void DLDL::argument::Interpreter::CreateGitignore()
{
	deamer::file::tool::Directory rootDirectory(deamerDirRelocation);

	deamer::file::tool::File gitignore("", "gitignore", "**/build/*");

	rootDirectory.AddFile(gitignore);

	generate::DirectoryToDisk::WriteToDisk(rootDirectory);
}

std::string DLDL::argument::Interpreter::RegenerationArgsDefinition() const
{
	std::string args;
	args += " -definition-map=\"" + DefinitionMap + "\"";
	args += " -build-map=\"" + BuildMap + "\"";
	args += " " + parser.CompileToArgument(Type::activate_language_generation);
	return args;
}

std::string DLDL::argument::Interpreter::RegenerationArgsLPD() const
{
	std::string args;
	args += " -lpd-map=\"" + LpdMap + "\"";
	args += " -activate-lpd-generation=";
	if (parser.IsArgumentSet(Type::activate_lpd_generation))
	{
		args += parser.GetArgument(Type::activate_lpd_generation).value;
	}
	else
	{
		args += "false";
	}

	args += " ";
	args += parser.CompileToArgument(Type::lpd_generation_map_main_lpd_include) + " ";
	args += parser.CompileToArgument(Type::lpd_generation_map_tool_lpd_include) + " ";
	args += parser.CompileToArgument(Type::lpd_generation_map_main_ldo_include) + " ";
	args += parser.CompileToArgument(Type::lpd_generation_map_tool_ldo_include) + " ";
	args += parser.CompileToArgument(Type::lpd_generation_map_main_lpd_source) + " ";
	args += parser.CompileToArgument(Type::lpd_generation_map_tool_lpd_source) + " ";
	args += parser.CompileToArgument(Type::lpd_generation_map_main_ldo_source) + " ";
	args += parser.CompileToArgument(Type::lpd_generation_map_tool_ldo_source) + " ";
	args += parser.CompileToArgument(Type::lpd_generation_map_convertor) + " ";
	args += parser.CompileToArgument(Type::lpd_generation_map_validator) + " ";
	args += parser.CompileToArgument(Type::lpd_generation_map_main_generator) + " ";
	args += parser.CompileToArgument(Type::lpd_generation_map_special_generator) + " ";
	args += parser.CompileToArgument(Type::lpd_generation_map_tool_generator) + " ";
	args += parser.CompileToArgument(Type::lpd_generation_map_ldo_enumerations) + " ";
	args += parser.CompileToArgument(Type::lpd_generation_map_lpd_enumerations) + " ";

	return args;
}

std::string DLDL::argument::Interpreter::RegenerationArgsTool() const
{
	std::string args;
	args += " -tool-map=\"" + ToolMap + "\"";
	args += " -activate-tool-generation=";
	if (parser.IsArgumentSet(Type::activate_tool_generation))
	{
		args += parser.GetArgument(Type::activate_tool_generation).value;
	}
	else
	{
		args += "false";
	}
	return args;
}

std::string DLDL::argument::Interpreter::RegenerationArgsMiccel() const
{
	std::string args;

	args += " -target-os=";
	if (!parser.IsArgumentSet(Type::target_os))
	{
		switch (os)
		{
		case deamer::file::tool::OSType::os_linux: {
			args += "linux";
			break;
		}
		case deamer::file::tool::OSType::os_windows: {
			args += "windows";
			break;
		}
		case deamer::file::tool::OSType::os_mac: {
			args += "mac";
			break;
		}
		}
	}
	else
	{
		args += parser.GetArgument(Type::target_os).value;
	}

	args += " ";
	args += parser.CompileToArgument(Type::no_console) + " ";
	args += parser.CompileToArgument(Type::console_debug_mode) + " ";

	return args;
}

void DLDL::argument::Interpreter::WriteToDisk(const deamer::file::tool::Directory& directory,
											  std::string path)
{
	path += directory.GetThisDirectory() + "/";

	std::filesystem::create_directories(path);

	for (const auto& file : directory.GetFiles())
	{
		const auto filePath = path + file.GetCompleteFileName();

		if (file.GetGenerationLevel() ==
				::deamer::file::tool::GenerationLevel::Dont_generate_if_file_already_exists &&
			std::filesystem::exists(filePath) && !std::filesystem::is_empty(filePath))
		{
			return;
		}

		std::ofstream outputFile;
		outputFile.open(filePath);

		outputFile << file.FileContent();

		outputFile.close();
	}

	for (const auto& childDirectory : directory.GetDirectories())
	{
		WriteToDisk(childDirectory, path);
	}
}
