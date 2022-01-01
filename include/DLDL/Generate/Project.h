#ifndef DLDL_GENERATE_PROJECT_H
#define DLDL_GENERATE_PROJECT_H

#include "DLDL/Generate/LPDWriter.h"
#include "DLDL/IR/Language.h"
#include "Deamer/File/Tool/Directory.h"
#include "Deamer/File/Tool/File.h"
#include <filesystem>
#include <fstream>

namespace DLDL::generate
{
	class Project
	{
	private:
		std::vector<ir::Language*> languages;
		deamer::file::tool::Directory CompilerGenerator;
		bool multiProject;

	public:
		Project(std::vector<ir::Language*> languages_, bool multiProject_ = false,
				const std::string& compilerGeneratorDirName = "CompilerGenerator");

	public:
		void WriteToDisk(deamer::file::tool::Directory directoryToWrite, std::string path = "./");

		deamer::file::tool::Directory Generate();

		std::string GetLanguageTarget();

	private:
		void Generate(ir::Language* language_, deamer::file::tool::Directory& parentHeader,
					  deamer::file::tool::Directory& parentSource);
	};
}

#endif // DLDL_GENERATE_PROJECT_H
