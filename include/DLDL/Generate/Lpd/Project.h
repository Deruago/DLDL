#ifndef DLDL_GENERATE_LPD_PROJECT_H
#define DLDL_GENERATE_LPD_PROJECT_H

#include <Deamer/File/Tool/Directory.h>
#include <filesystem>
#include <fstream>

namespace DLDL::generate::lpd
{
	/*!	\fn Project
	 *	\brief Generates the LPD project, this consists of various directories.
	 *	\details The set of directories are not bound to some directory,
	 *	the user is required to encapsulate the directories to the right paths.
	 */
	class Project
	{
	public:
		Project();
		~Project();

	public:
		/*!	\fn Generate
		 *	\brief Generate LPD directories
		 */
		::deamer::file::tool::Directory Generate();
	};
}

#endif // DLDL_GENERATE_LPD_PROJECT_H
