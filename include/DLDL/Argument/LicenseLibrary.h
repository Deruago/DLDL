#ifndef DLDL_ARGUMENT_LICENSELIBRARY_H
#define DLDL_ARGUMENT_LICENSELIBRARY_H

#include <string>
#include <utility>

namespace DLDL::argument
{
	/*! \class LicenseLibrary
	 *
	 *	\brief Set ups a simple license message.
	 */
	class LicenseLibrary
	{
	private:
		std::string libraryName;
		std::string licenseName;
		std::string description;
		std::string link;

	public:
		LicenseLibrary(std::string libraryName_, std::string licenseName_, std::string description_,
					   std::string link_ = "");

	public:
		std::string GetIndent(size_t size) const;

		std::string GetLicenseMessage(size_t indent = 0) const;
	};
}

#endif // DLDL_ARGUMENT_LICENSELIBRARY_H
