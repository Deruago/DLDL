#include "DLDL/Filesystem/LoadFilesystem.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

std::string ReadInFile(const std::string& file)
{
	const std::ifstream inputFile(file);

	std::ostringstream sstr;
	sstr << inputFile.rdbuf();

	std::string input = sstr.str();

	return input;
}

DLDL::filesystem::LoadFilesystem::LoadFilesystem(class deamer::file::tool::Directory& outputDir_,
												 const std::string& startingDir_)
	: outputDir(outputDir_),
	  startingDir(startingDir_)
{
	if (std::filesystem::exists(startingDir))
	{
		LoadPath();
	}
	else
	{
		error_state = true;
	}
}

DLDL::filesystem::LoadFilesystem& DLDL::filesystem::LoadFilesystem::Upper()
{
	if (error_state)
	{
		return *this;
	}

	if (reachedRoot)
	{
		return *this;
	}

	startingDir += "../";

	const auto currentDir = std::filesystem::canonical(startingDir).generic_string();
	std::string parentPath;
	try
	{
		parentPath = std::filesystem::canonical(startingDir + "../").generic_string();
	} catch (const std::exception& ex)
	{
		reachedRoot = true;
	}
	if (parentPath == currentDir)
	{
		reachedRoot = true;
	}

	LoadPath();

	return *this;
}

DLDL::filesystem::LoadFilesystem& DLDL::filesystem::LoadFilesystem::RecursiveExpand()
{
	if (error_state)
	{
		return *this;
	}

	return *this;
}

DLDL::filesystem::LoadFilesystem& DLDL::filesystem::LoadFilesystem::DirectLoad()
{
	if (error_state)
	{
		return *this;
	}

	LoadPath(true);
	return *this;
}

DLDL::filesystem::LoadFilesystem& DLDL::filesystem::LoadFilesystem::Enter(const std::string& path)
{
	if (error_state)
	{
		return *this;
	}

	reachedRoot = false;

	if (!DirectContainsDirectory(path))
	{
		files.clear();
		directories.clear();
		outputDir = ::deamer::file::tool::Directory("./");
		error_state = true;
		return *this;
	}
	startingDir += path + "/";
	LoadPath();
	return *this;
}

std::vector<std::string> DLDL::filesystem::LoadFilesystem::GetDirectDirectories() const
{
	return directories;
}

std::vector<std::string> DLDL::filesystem::LoadFilesystem::GetDirectFiles() const
{
	return files;
}

bool DLDL::filesystem::LoadFilesystem::DirectContainsDirectory(
	const std::string& directoryName) const
{
	for (const auto& dir : directories)
	{
		auto formattedDir = dir;
		if (!dir.empty() && dir[0] == '/')
			formattedDir.erase(0, 1);
		if (!dir.empty() && dir[dir.size() - 1] == '/')
			formattedDir.pop_back();

		if (formattedDir == directoryName)
		{
			return true;
		}
	}

	return false;
}

bool DLDL::filesystem::LoadFilesystem::DirectContainsFile(const std::string& fileName) const
{
	for (const auto& dir : files)
	{
		auto formattedDir = dir;
		if (!dir.empty() && dir[0] == '/')
			formattedDir.erase(0, 1);
		if (!dir.empty() && dir[dir.size() - 1] == '/')
			formattedDir.pop_back();

		if (formattedDir == fileName)
		{
			return true;
		}
	}

	return false;
}

bool DLDL::filesystem::LoadFilesystem::ReachedRoot() const
{
	return reachedRoot;
}

std::string DLDL::filesystem::LoadFilesystem::GetPath() const
{
	return startingDir;
}

bool DLDL::filesystem::LoadFilesystem::Error() const
{
	return error_state;
}

void DLDL::filesystem::LoadFilesystem::LoadPath(bool loadContent)
{
	directories.clear();
	files.clear();

	deamer::file::tool::Directory directory;

	for (const auto& iter : std::filesystem::directory_iterator(startingDir))
	{
		if (iter.is_directory())
		{
			directory.AddDirectory(LoadDirectory(iter));
		}
		else
		{
			directory.AddFile(LoadFile(iter, loadContent));
		}
	}

	outputDir = directory;
}

deamer::file::tool::Directory
DLDL::filesystem::LoadFilesystem::LoadDirectory(const std::filesystem::directory_entry& iter)
{
	const std::string directoryName = iter.path().generic_string().erase(0, startingDir.size());
	directories.push_back(directoryName);

	return deamer::file::tool::Directory(directoryName);
}

deamer::file::tool::File
DLDL::filesystem::LoadFilesystem::LoadFile(const std::filesystem::directory_entry& iter,
										   bool loadContent)
{
	const std::string fileName = iter.path().generic_string().erase(0, startingDir.size());

	std::string fileNameWithoutExtension;
	files.push_back(fileNameWithoutExtension);
	for (auto character : fileName)
	{
		if (character == '.')
		{
			break;
		}
		if (character == '/')
		{
			continue;
		}

		fileNameWithoutExtension += character;
	}

	std::string extension;
	bool add = false;
	for (auto character : fileName)
	{
		if (character == '.')
		{
			add = true;
			continue;
		}
		if (character == '/')
		{
			continue;
		}
		if (add)
		{
			extension += character;
		}
	}

	std::string content;
	if (loadContent)
	{
		content = ReadInFile(iter.path().generic_string());
	}

	return deamer::file::tool::File(fileNameWithoutExtension, extension, content);
}
