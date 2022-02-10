#ifndef DLDL_GENERATE_LPD_PROJECT_H
#define DLDL_GENERATE_LPD_PROJECT_H

#include "DLDL_LPDDEF/IR/LPDDEF.h"
#include <Deamer/File/Tool/Directory.h>
#include <filesystem>
#include <fstream>

namespace DLDL
{
	namespace ir
	{
		class LPD;
	}
}

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
		struct LPDDirectory
		{
			// Include directories
			::deamer::file::tool::Directory mainLPD;
			::deamer::file::tool::Directory toolLPD;
			::deamer::file::tool::Directory mainLDO;
			::deamer::file::tool::Directory toolLDO;

			// Source directories
			::deamer::file::tool::Directory mainSourceLPD;
			::deamer::file::tool::Directory toolSourceLPD;
			::deamer::file::tool::Directory mainSourceLDO;
			::deamer::file::tool::Directory toolSourceLDO;

			::deamer::file::tool::Directory converter;
			::deamer::file::tool::Directory validater;
			::deamer::file::tool::Directory generater;
			::deamer::file::tool::Directory generaterSpecial;
			::deamer::file::tool::Directory generaterTool;
			::deamer::file::tool::Directory ldoEnumeration;
			::deamer::file::tool::Directory lpdEnumeration;
		};

	private:
		std::unique_ptr<ir::LPDProject>& lpdProject;

	public:
		Project(std::unique_ptr<ir::LPDProject>& lpdProject_);
		~Project() = default;

	public:
		/*!	\fn Generate
		 *	\brief Generate LPD directories
		 */
		LPDDirectory Generate();

	private:
		void GenerateMainLpd(LPDDirectory& directory) const;
		void GenerateMainLdo(LPDDirectory& directory) const;

		void GenerateConverter(LPDDirectory& directory) const;
		void GenerateValidater(LPDDirectory& directory) const;
		void GenerateGenerater(LPDDirectory& directory) const;
		void GenerateEnumerations(LPDDirectory& directory) const;

	private:
		ir::LDO* GetLDOfromString(const ir::DataMember& value,
								  const std::unique_ptr<ir::LpdDef>& lpd) const;
		std::string GetLPDFromLDO(const std::unique_ptr<ir::LpdDef>& lpd, ir::DataMember lpdMember,
								  ir::LDO*& ldo) const;
		ir::LpdDef* GetLPDfromString(const std::string& lpdStr) const;
	};
}

#endif // DLDL_GENERATE_LPD_PROJECT_H
