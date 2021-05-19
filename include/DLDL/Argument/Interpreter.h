#ifndef DLDL_ARGUMENT_INTERPRETER_H
#define DLDL_ARGUMENT_INTERPRETER_H

#include "DLDL/Argument/Parser.h"
#include "DLDL/Generate/Project.h"
#include "DLDL/IR/Language.h"

namespace DLDL::argument
{
	class Interpreter
	{
	private:
		::deamer::file::tool::OSType os = ::deamer::file::tool::os_used;
		
		Parser parser;
	private:
		std::string DefinitionMap = "definition";
		std::string BuildMap = "build";
		std::string language_name;
		std::vector<std::string> supportedGrammars = {"Lexicon ; Used to define lexicons.", "Grammar ; Used to define context free grammars."};
		static constexpr const char* compatibleDeamerCC_Versions = "Deamer v2.0.0";
		static constexpr const char* version = "v2.0.0 pre-release";
	private:
		std::vector<DLDL::ir::Language*> languages;
		DLDL::generate::Project* projectGeneration = nullptr;
	public:
		Interpreter(size_t count, char* arguments[]);
		~Interpreter();
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
		size_t Run();

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
		void Exit();
		void Compatible();
		void Initialize();
		void SupportedGrammars();
		void About();
		
		void PrintLanguages();
		bool InitializeLanguages();
		void CompilerGenerator_Generation();

		void GitOptions();
		void CreateGitignore();
	};
}

#endif // DLDL_ARGUMENT_INTERPRETER_H