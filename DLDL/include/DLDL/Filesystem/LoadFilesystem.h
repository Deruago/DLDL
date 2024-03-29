#ifndef DLDL_FILESYSTEM_LOADFILESYSTEM_H
#define DLDL_FILESYSTEM_LOADFILESYSTEM_H

#include "Deamer/File/Tool/Directory.h"
#include "Deamer/File/Tool/File.h"
#include <filesystem>
#include <string>

namespace DLDL::filesystem
{
	class LoadFilesystem
	{
	private:
		deamer::file::tool::Directory& outputDir;
		std::string startingDir;

		std::vector<std::string> directories;
		std::vector<std::string> files;
		bool reachedRoot = false;
		bool error_state = false;

	public:
		/*!	\fn LoadFilesystem
		 *	\param outputDir_ Directory used to store found structures
		 *	\param startingDir_ Starting directory
		 */
		LoadFilesystem(deamer::file::tool::Directory& outputDir_,
					   const std::string& startingDir_ = "./");

		/*!	\fn Upper
		 *	\brief Loads the upper directory
		 */
		LoadFilesystem& Upper();

		/*!	\fn RecursiveExpand
		 *	\brief Recursively expands underlying filesystem
		 */
		LoadFilesystem& RecursiveExpand();

		/*!	\fn DirectLoad
		 *	\brief Loads direct members.
		 */
		LoadFilesystem& DirectLoad();

		/*!	\fn Enter
		 *	\brief Enters direct subdirectory
		 */
		LoadFilesystem& Enter(const std::string& path);

		std::vector<std::string> GetDirectDirectories() const;
		std::vector<std::string> GetDirectFiles() const;
		bool DirectContainsDirectory(const std::string& directoryName) const;
		bool DirectContainsFile(const std::string& fileName) const;
		bool ReachedRoot() const;
		std::string GetPath() const;

		/*!	\fn Error
		 *	\brief If true an error has occured
		 */
		bool Error() const;

	private:
		void LoadPath(bool loadContent = false);
		deamer::file::tool::Directory LoadDirectory(const std::filesystem::directory_entry& iter);
		deamer::file::tool::File LoadFile(const std::filesystem::directory_entry& iter,
										  bool loadContent = false);
	};
}

#endif // DLDL_FILESYSTEM_LOADFILESYSTEM_H
