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
		LicenseLibrary(std::string libraryName_, std::string licenseName_, std::string description_, std::string link_ = "")
			: libraryName(std::move(libraryName_)), licenseName(std::move(licenseName_)), description(
				std::move(description_)), link(link_)

		{
		}

	public:
		std::string GetIndent(size_t size) const
		{
			std::string output;
			for (auto i = 0; i < size; i++)
			{
				output += "\t";
			}

			return output;
		}

		std::string GetLicenseMessage(size_t indent = 0) const
		{
			return
				GetIndent(indent) + "Library: " + libraryName + "\n" +
				GetIndent(indent) + "License: " + licenseName + "\n" +
				GetIndent(indent) + "Link: " + link + "\n"
				"\n" +
				GetIndent(indent) + "Description:\n" +
				GetIndent(indent) + description + "\n";
		}
	};
}

#endif // DLDL_ARGUMENT_LICENSELIBRARY_H