#include "DLDL/Generate/SubWriter.h"

std::string DLDL::generate::SubWriter::GetLanguageFullName(ir::Language* language,
														   std::string separator)
{
	std::string language_full_name;
	for (auto& lang : language->GetParents())
	{
		language_full_name += lang + separator;
	}
	if (!language_full_name.empty())
	{
		for (int i = 0; i < separator.size(); i++)
		{
			language_full_name.pop_back();
		}
	}

	return language_full_name;
}
