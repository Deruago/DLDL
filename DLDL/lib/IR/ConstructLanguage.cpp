#include "DLDL/IR/ConstructLanguage.h"
#include "DLDL_GRAMMAR/IR/Parser.h"
#include "DLDL_LEXER/IR/Parser.h"
#include "DLDL_OOPSYNTAX/IR/Parser.h"
#include <Deamer/File/Tool/Directory.h>
#include <fstream>
#include <sstream>

DLDL::ir::ConstructLanguage::ConstructLanguage(const std::string& relativeDirectory_,
											   const std::string& definitionMap_)
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

	for (const auto& item : std::filesystem::directory_iterator(relativeDirectory))
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

DLDL::ir::ConstructLanguage::~ConstructLanguage() = default;

void DLDL::ir::ConstructLanguage::Construct(::deamer::file::tool::OSType os)
{
	std::vector<Language*> rootLanguages;
	for (const auto& item : std::filesystem::directory_iterator(relativeDirectory))
	{
		if (!item.is_directory())
		{
			continue;
		}

		std::string languageDirectory =
			relativeDirectory + item.path().generic_string().erase(0, relativeDirectory.size());

		Language* language = GetLanguageFromMap(languageDirectory, os);
		rootLanguages.push_back(language);

		Construct(language, languageDirectory, os);
	}

	languages = rootLanguages;
}

std::vector<DLDL::ir::Language*> DLDL::ir::ConstructLanguage::GetLanguages()
{
	return languages;
}

void DLDL::ir::ConstructLanguage::Construct(Language* parentLanguage, std::string path,
											::deamer::file::tool::OSType os)
{
	for (auto& item : std::filesystem::directory_iterator(path))
	{
		if (!item.is_directory())
		{
			continue;
		}

		std::string languageDirectory = path + item.path().generic_string().erase(0, path.size());
		std::cout << languageDirectory << '\n';

		Language* currentLanguage = GetLanguageFromMap(languageDirectory, os);
		parentLanguage->AddLanguage(currentLanguage);

		Construct(currentLanguage, languageDirectory, os);
	}
}

DLDL::ir::Language* DLDL::ir::ConstructLanguage::GetLanguageFromMap(const std::string& path,
																	deamer::file::tool::OSType os)
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

DLDL::ir::Type DLDL::ir::ConstructLanguage::ConvertTextToEnum(const std::string& text)
{
	std::string textLowered;
	for (auto character : text)
	{
		if (::isalpha(character))
		{
			textLowered += ::tolower(character);
		}
		else
		{
			textLowered += character;
		}
	}

	return GetLpdType(textLowered);
}

std::string DLDL::ir::ConstructLanguage::ReadInFile(const std::string& file)
{
	const std::ifstream inputFile(file);

	std::ostringstream sstr;
	sstr << inputFile.rdbuf();

	std::string input = sstr.str();

	return input;
}

DLDL::ir::IR* DLDL::ir::ConstructLanguage::GetIR(const Type type, const std::string& path,
												 deamer::file::tool::OSType os)
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
	case Type::OopSyntax:
		newIR = ::DLDL::ir::oopsyntax::Parser(os).GetIR(fileContent);
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

DLDL::ir::IR_Config* DLDL::ir::ConstructLanguage::GetConfig(const Type type,
															const std::string& path)
{
	auto* newConfig = new IR_Config(type);

	return newConfig;
}
