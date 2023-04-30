#ifndef DLDL_IR_CONSTRUCTLANUAGE_H
#define DLDL_IR_CONSTRUCTLANUAGE_H

#include "DLDL/IR/Language.h"
#include "DLDL_GENERATION/IR/Parser.h"
#include <filesystem>
#include <string>

namespace DLDL::ir
{
	/*!	\class ConstructLanguage
	 *
	 *	\brief Constructs a language object given a relative path
	 *
	 *	\details It will look through the given map for a "Definition" directory.
	 *	This directory will be completely searched for every DLDL definition.
	 *	This class will parse all these languages into IR's and construct the language.
	 */
	class ConstructLanguage
	{
	private:
		std::string relativeDirectory;
		std::vector<Language*> languages;
		const std::string definitionMap;

	public:
		ConstructLanguage(const std::string& relativeDirectory_,
						  const std::string& definitionMap_ = "definition");
		~ConstructLanguage();

	public:
		/*!	\fn Construct
		 *
		 *	\brief Constructs the language.
		 *
		 *	\note Call GetLanguages to retrieve the constructed language.
		 */
		void Construct(::deamer::file::tool::OSType os = ::deamer::file::tool::os_used);

		std::vector<Language*> GetLanguages();

	private:
		void Construct(Language* parentLanguage, std::string path,
					   ::deamer::file::tool::OSType os = ::deamer::file::tool::os_used);

		Language* GetLanguageFromMap(const std::string& path,
									 deamer::file::tool::OSType os = deamer::file::tool::os_used);

		Type ConvertTextToEnum(const std::string& text);

		std::string ReadInFile(const std::string& file);

		std::vector<IR*> GetIR(const Type type, const std::string& path,
							   deamer::file::tool::OSType os = deamer::file::tool::os_used);

		IR_Config* GetConfig(const Type type, const std::string& path);
	};
}

#endif // DLDL_IR_CONSTRUCTLANUAGE_H
