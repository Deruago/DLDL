#ifndef DLDL_IR_CONSTRUCTLPD_H
#define DLDL_IR_CONSTRUCTLPD_H

#include "DLDL_LPDDEF/IR/LPDDEF.h"
#include <Deamer/File/Tool/File.h>
#include <Deamer/File/Tool/OSType.h>
#include <filesystem>
#include <string>

namespace DLDL::ir
{
	/*!	\class ConstructLPD
	 *
	 *	\brief Constructs a language object given a relative path
	 */
	class ConstructLPD
	{
	private:
		const std::string relativeDirectoryToLpdDefinitions;
		std::unique_ptr<DLDL::ir::LPDProject> lpdProject;

	public:
		ConstructLPD(const std::string& relativeDirectoryToLpdDefinitions_);
		~ConstructLPD() = default;

	public:
		/*!	\fn Construct
		 *
		 *	\brief Constructs the LPDs.
		 */
		void Construct(::deamer::file::tool::OSType os = ::deamer::file::tool::os_used);

		/*!	\fn GetLPDProject
		 *
		 *	\brief Get LPD project
		 */
		std::unique_ptr<DLDL::ir::LPDProject> GetLPDProject();

	private:
		std::unique_ptr<DLDL::ir::LpdDef> ParseLpdDirectory(const std::string& lpd);
		std::vector<std::unique_ptr<DLDL::ir::LDO>> ParseLdoDirectory(const std::string& cs);
		std::unique_ptr<DLDL::ir::LDO> ParseLdo(const deamer::file::tool::File& file);
	};
}

#endif // DLDL_IR_CONSTRUCTLPD_H
