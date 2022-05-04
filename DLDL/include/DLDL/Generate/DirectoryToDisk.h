#ifndef DLDL_GENERATE_BASEPROJECT_H
#define DLDL_GENERATE_BASEPROJECT_H

#include "DLDL/Generate/LPDWriter.h"
#include "DLDL/IR/Language.h"
#include "Deamer/File/Tool/Directory.h"
#include "Deamer/File/Tool/File.h"
#include <filesystem>
#include <fstream>

namespace DLDL::generate
{
	class DirectoryToDisk
	{
	private:
		DirectoryToDisk();
		~DirectoryToDisk();

	public:
		static void WriteToDisk(deamer::file::tool::Directory directoryToWrite, std::string path = "./");
	};
}

#endif // DLDL_GENERATE_BASEPROJECT_H
