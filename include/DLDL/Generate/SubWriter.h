#ifndef DLDL_GENERATE_SUBWRITER_H
#define DLDL_GENERATE_SUBWRITER_H

#include "DLDL/IR/Language.h"
#include <Deamer/File/Tool/File.h>

namespace DLDL::generate
{
	class SubWriter
	{
	public:
		SubWriter() = default;
		virtual ~SubWriter() = default;
	public:
		template<typename T>
		static void FillInDefaultVariablesInConstruction(T& generator, ir::Language* language)
		{
			const std::string language_full_name = GetLanguageFullName(language);
			const std::string language_full_name_double_colon = GetLanguageFullName(language);
			const std::string language_full_name_underscore = GetLanguageFullName(language, "_");
			const std::string language_full_name_slash = GetLanguageFullName(language, "/");
			const std::string language_full_name_backslash = GetLanguageFullName(language, "\\");

			generator.language_full_name_->Set(language_full_name);
			generator.language_full_name_underscore_->Set(language_full_name_underscore);
			generator.language_full_name_slash_->Set(language_full_name_slash);
			generator.language_full_name_->Upper();
			generator.language_full_name_underscore_->Upper();
			generator.language_full_name_slash_->Upper();
		}
		
		static std::string GetLanguageFullName(ir::Language* language, std::string separator = "::")
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
		
		virtual deamer::file::tool::File GetFileContentSourceFile(ir::Language* language,
														  const ir::LPD& lpd) = 0;

		virtual deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language,
																  const ir::LPD& lpd) = 0;
	};
}


#endif // DLDL_GENERATE_SUBWRITER_H