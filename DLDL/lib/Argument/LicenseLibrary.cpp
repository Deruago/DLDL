#include "DLDL/Argument/LicenseLibrary.h"

DLDL::argument::LicenseLibrary::LicenseLibrary(std::string libraryName_, std::string licenseName_,
											   std::string description_, std::string link_)
	: libraryName(std::move(libraryName_)),
	  licenseName(std::move(licenseName_)),
	  description(std::move(description_)),
	  link(link_)
{
}

std::string DLDL::argument::LicenseLibrary::GetIndent(size_t size) const
{
	std::string output;
	for (auto i = 0; i < size; i++)
	{
		output += "\t";
	}

	return output;
}

std::string DLDL::argument::LicenseLibrary::GetLicenseMessage(size_t indent) const
{
	return GetIndent(indent) + "Library: " + libraryName + "\n" + GetIndent(indent) +
		   "License: " + licenseName + "\n" + GetIndent(indent) + "Link: " + link +
		   "\n"
		   "\n" +
		   GetIndent(indent) + "Description:\n" + GetIndent(indent) + description + "\n";
}
