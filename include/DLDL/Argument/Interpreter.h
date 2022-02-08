#ifndef DLDL_ARGUMENT_INTERPRETER_H
#define DLDL_ARGUMENT_INTERPRETER_H

#include "DLDL/Argument/LicenseLibrary.h"
#include "DLDL/Argument/Parser.h"
#include "DLDL/Generate/Lpd/Project.h"
#include "DLDL/Generate/Project.h"
#include "DLDL/IR/Language.h"
#include "DLDL_LPDDEF/IR/LPDDEF.h"

namespace DLDL::argument
{
	class Interpreter
	{
	private:
		::deamer::file::tool::OSType os = ::deamer::file::tool::os_used;

		Parser parser;

	private:
		bool deamerDirExists = false;
		std::string deamerDirRelocation = "./";
		std::string RelocationDir = "./";
		std::string DefinitionMap = "definition";
		std::string BuildMap = "build";
		std::string LpdMap = "";
		std::string ToolMap = "";
		std::string language_name;
		std::vector<std::string> supportedGrammars = {
			"Lexicon ; Used to define lexicons.",
			"Grammar ; Used to define context free grammars.",
			"Generation ; Used to define how to generate the language.",
			"LPDDef ; Used to forward declare a LPD for Deamer CC.",
			"LPDStruct ; Used to define a LPD structure for Deamer CC.",
			"LDOStruct ; Used to define a LDO structure for Deamer CC.",
			"TOOLDef ; Used to forward declare a tool for Deamer CC.",
		};
		static constexpr const char* compatibleDeamerCC_Versions = "Deamer v2.0.0 - Deamer v2.3.0";
		static constexpr const char* version = "v2.2.0";

	private:
		std::unique_ptr<ir::LPDProject> lpdProject;
		std::vector<DLDL::ir::Language*> languages;
		DLDL::generate::Project* projectGeneration = nullptr;

	public:
		Interpreter(size_t count, const char* arguments[]);
		~Interpreter();
		void InitializeInterpreter(bool force = false);
		void AutoRun();
		void AutoCompile();

	public:
		/*!	\fn Run
		 *
		 *	\brief Runs the interpreter
		 *
		 *	\return exit code. 0 is success, -1 or other negative is fail.
		 *
		 *	\details Runs the interpreter, the user can interact by giving different arguments.
		 */
		std::size_t Run();

	private:
		/*!	\fn Disclaimer
		 *
		 *	\brief Shows short license notice.
		 */
		void Disclaimer();

		/*!	\fn ExitArguments
		 *
		 *	\brief Contains all arguments that when called exit DLDL.
		 */
		bool ExitArguments();

		void Help();
		void Information();
		void Copyright();
		void Version();
		void License();
		void PrintUsedLicenses() const;
		void Exit();
		void Compatible();
		void Initialize();
		void SupportedGrammars();
		void About();

		void InitializeDeamerMap();
		void InitializeLpd();
		void InitializeTool();

		void PrintLanguages();
		bool InitializeLanguages();
		void CompilerGenerator_Generation();

		void GitOptions();
		void CreateGitignore();

		std::string RegenerationArgsDefinition() const;
		std::string RegenerationArgsLPD() const;
		std::string RegenerationArgsTool() const;
		std::string RegenerationArgsMiccel() const;

		std::size_t GenerateLanguage();
		std::size_t GenerateLpd();
		std::size_t GenerateTool();

	private:
		// Licensed libraries DLDL uses
		LicenseLibrary DeamerCC = LicenseLibrary(
			"Deamer CC", "GPL v3",
			"Deamer CC is an infrastructure for compiler and ecosystem generation.\n",
			"https://github.com/Deruago/theDeamerProject");

		LicenseLibrary DeamerExternal = LicenseLibrary(
			"Deamer External", "Apache-2.0",
			"Deamer External is the external library used by output generated by Deamer CC.\n",
			"https://github.com/Deruago/DeamerExternal");

		LicenseLibrary DeamerAlgorithm = LicenseLibrary(
			"Deamer Algorithm", "Apache-2.0",
			"Deamer Algorithm offers different algorithms used by output generated by Deamer CC.\n",
			"https://github.com/Deruago/DeamerAlgorithm");

		/*!	\fn LoadInDeamerDir
		 *	\brief Loads in the closest Deamer Dir.
		 *
		 *	\note If there is no Deamer directory, DLDL will operate like <v2.3.0
		 */
		void LoadInDeamerDir();
		void WriteToDisk(const deamer::file::tool::Directory& directory, std::string path = "./");
		deamer::file::tool::Directory
		GenerateRootDirectory(std::vector<DLDL::ir::Language*> languages);

	private:
		void GenerateLpdMainLpdSource(DLDL::generate::lpd::Project::LPDDirectory projectDirectory);
		void GenerateLpdMainLpdInclude(const generate::lpd::Project::LPDDirectory& lpdDirectory);
		void GenerateLpdToolLpdSource(const generate::lpd::Project::LPDDirectory& lpdDirectory);
		void GenerateLpdToolLpdInclude(const generate::lpd::Project::LPDDirectory& lpdDirectory);
		void GenerateLpdMainLdoSource(const generate::lpd::Project::LPDDirectory& lpdDirectory);
		void GenerateLpdMainLdoInclude(const generate::lpd::Project::LPDDirectory& lpdDirectory);
		void GenerateLpdToolLdoSource(const generate::lpd::Project::LPDDirectory& lpdDirectory);
		void GenerateLpdToolLdoInclude(const generate::lpd::Project::LPDDirectory& lpdDirectory);
		void GenerateLpdConvertor(const generate::lpd::Project::LPDDirectory& lpdDirectory);
		void GenerateLpdValidator(const generate::lpd::Project::LPDDirectory& lpdDirectory);
		void GenerateLpdMainGenerator(const generate::lpd::Project::LPDDirectory& lpdDirectory);
		void GenerateLpdToolGenerator(const generate::lpd::Project::LPDDirectory& lpdDirectory);
		void GenerateLpdEnumerationsLpd(const generate::lpd::Project::LPDDirectory& lpdDirectory);
		void GenerateLpdEnumerationsLdo(const generate::lpd::Project::LPDDirectory& lpdDirectory);
	};
}

#endif // DLDL_ARGUMENT_INTERPRETER_H
