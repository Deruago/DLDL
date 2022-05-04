#include "DLDL/Generate/DirectoryToDisk.h"

void DLDL::generate::DirectoryToDisk::WriteToDisk(deamer::file::tool::Directory directoryToWrite,
												  std::string path)
{
	path += directoryToWrite.GetThisDirectory() + "/";

	std::filesystem::create_directories(path);

	for (const auto& file : directoryToWrite.GetFiles())
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

	for (const auto& childDirectory : directoryToWrite.GetDirectories())
	{
		WriteToDisk(childDirectory, path);
	}
}