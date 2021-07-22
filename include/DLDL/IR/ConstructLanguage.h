#ifndef DLDL_IR_CONSTRUCTLANUAGE_H
#define DLDL_IR_CONSTRUCTLANUAGE_H

#include "DLDL/IR/Language.h"
#include "DLDL_GENERATION/IR/Parser.h"
#include "DLDL_GRAMMAR/IR/Parser.h"
#include "DLDL_LEXER/IR/Parser.h"
#include <Deamer/File/Tool/Directory.h>
#include <filesystem>
#include <fstream>
#include <sstream>
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
						  const std::string& definitionMap_ = "definition")
			: relativeDirectory(relativeDirectory_),
			  definitionMap(definitionMap_)
		{
			/*if (relativeDirectory.rfind("./", 0) != 0)
			{
				relativeDirectory = "./" + relativeDirectory_;
			}*/

			while (relativeDirectory[relativeDirectory.size() - 1] == '/' &&
				   relativeDirectory[relativeDirectory.size() - 2] == '/')
			{
				relativeDirectory.pop_back();
			}

			for (auto& item : std::filesystem::directory_iterator(relativeDirectory))
			{
				if (!item.is_directory())
				{
					continue;
				}

				std::string path = item.path().generic_string();
				path.erase(0, relativeDirectory.size());

				std::string loweredPath;
				for (auto character : path)
				{
					loweredPath += ::tolower(character);
				}

				if (loweredPath == definitionMap)
				{
					relativeDirectory += loweredPath + "/";
					return;
				}
			}

			throw std::logic_error("Given path doesn't contain a definition directory!");
		}
		~ConstructLanguage() = default;

	public:
		/*!	\fn Construct
		 *
		 *	\brief Constructs the language.
		 *
		 *	\note Call GetLanguages to retrieve the constructed language.
		 */
		void Construct(::deamer::file::tool::OSType os = ::deamer::file::tool::os_used)
		{
			std::vector<Language*> rootLanguages;
			for (const auto& item : std::filesystem::directory_iterator(relativeDirectory))
			{
				if (!item.is_directory())
				{
					continue;
				}

				std::string languageDirectory =
					relativeDirectory +
					item.path().generic_string().erase(0, relativeDirectory.size());

				Language* language = GetLanguageFromMap(languageDirectory, os);
				rootLanguages.push_back(language);

				Construct(language, languageDirectory, os);
			}

			languages = rootLanguages;
		}

		std::vector<Language*> GetLanguages()
		{
			return languages;
		}

	private:
		void Construct(Language* parentLanguage, std::string path,
					   ::deamer::file::tool::OSType os = ::deamer::file::tool::os_used)
		{
			for (auto& item : std::filesystem::directory_iterator(path))
			{
				if (!item.is_directory())
				{
					continue;
				}

				std::string languageDirectory =
					path + item.path().generic_string().erase(0, path.size());
				std::cout << languageDirectory << '\n';

				Language* currentLanguage = GetLanguageFromMap(languageDirectory, os);
				parentLanguage->AddLanguage(currentLanguage);

				Construct(currentLanguage, languageDirectory, os);
			}
		}

		Language* GetLanguageFromMap(const std::string& path,
									 deamer::file::tool::OSType os = deamer::file::tool::os_used)
		{
			const std::string languageName =
				*(deamer::file::tool::Directory(path).SplitDirectoryName().end() - 1);

			auto* newLanguage = new Language(languageName, os);
			
			for (const auto& item : std::filesystem::directory_iterator(path))
			{
				if (item.is_directory())
				{
					continue;
				}

				const std::string fileName = item.path().generic_string().erase(0, path.size());
				std::string fileNameWithoutExtension;
				for (auto character : fileName)
				{
					if (character == '.')
					{
						break;
					}
					if (character == '/')
					{
						continue;
					}

					fileNameWithoutExtension += character;
				}

				std::string extension;
				bool add = false;
				for (auto character : fileName)
				{
					if (character == '.')
					{
						add = true;
						continue;
					}
					if (character == '/')
					{
						continue;
					}
					if (add)
					{
						extension += character;
					}
				}

				if (extension == "dldl")
				{
					const auto type = ConvertTextToEnum(fileNameWithoutExtension);
					if (type == Type::Unknown)
					{
						continue;
					}
					std::cout << path << '\n';
					newLanguage->AddIR(GetIR(type, path + fileName, os));
				}
				else if (extension == "config.dldl")
				{
					const auto type = ConvertTextToEnum(fileNameWithoutExtension);
					if (type == Type::Unknown)
					{
						continue;
					}

					newLanguage->AddIR_Config(GetConfig(type, path + fileName));
				}
				else
				{
					continue;
				}
			}

			newLanguage->FixUnknownReferences();
			
			return newLanguage;
		}

		Type ConvertTextToEnum(const std::string& text)
		{
			std::string textLowered;
			for (auto character : text)
			{
				textLowered += ::tolower(character);
			}

			if (textLowered == "lexicon")
			{
				return Type::Lexicon;
			}
			if (textLowered == "grammar")
			{
				return Type::Grammar;
			}
			if (textLowered == "associativity")
			{
				return Type::Associativity;
			}
			if (textLowered == "precedence")
			{
				return Type::Precedence;
			}
			if (textLowered == "generation")
			{
				return Type::Generation;
			}
			if (textLowered == "identity")
			{
				return Type::Identity;
			}

			return Type::Unknown;
		}

		std::string ReadInFile(const std::string& file)
		{
			const std::ifstream inputFile(file);

			std::ostringstream sstr;
			sstr << inputFile.rdbuf();

			std::string input = sstr.str();

			return input;
		}

		IR* GetIR(const Type type, const std::string& path,
				  deamer::file::tool::OSType os = deamer::file::tool::os_used)
		{
			std::cout << path << '\n';

			IR* newIR = nullptr;
			const std::string fileContent = ReadInFile(path);

			switch (type)
			{
			case Type::Unknown:
				break;
			case Type::Lexicon:
				newIR = ::DLDL::ir::lexer::Parser().GetIR(fileContent);
				break;
			case Type::Grammar:
				newIR = ::DLDL::ir::grammar::Parser().GetIR(fileContent);
				break;
			case Type::Precedence:
				break;
			case Type::Associativity:
				break;
			case Type::Generation:
				newIR = ::DLDL::ir::generation::Parser(os).GetIR(fileContent);
				break;
			case Type::Identity:
				break;
			case Type::AstOptimization:
				break;
			case Type::AstTranslation:
				break;
			case Type::Coloring:
				break;
			case Type::Formatting:
				break;
			case Type::Documentation:
				break;
			case Type::Threat:
				break;
			default:
				break;
			}

			return newIR;
		}

		IR_Config* GetConfig(const Type type, const std::string& path)
		{
			auto* newConfig = new IR_Config(type);

			return newConfig;
		}
	};
}

#endif // DLDL_IR_CONSTRUCTLANUAGE_H
