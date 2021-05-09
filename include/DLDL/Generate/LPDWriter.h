#ifndef DLDL_GENERATE_LPDWRITER_H
#define DLDL_GENERATE_LPDWRITER_H

#include "DLDL/IR/Language.h"
#include "LPDSubWriterFactory.h"
#include <Deamer/File/Tool/File.h>

#include "DLDL/Template/Language/languageTemplate.h"
#include "DLDL/Template/CompilerGenerator/compilergeneratorTemplate.h"
#include "DLDL/Template/Main/MainTemplate.h"
#include "DLDL/Template/CMakeLists/CMakeListsTemplate.h"

namespace DLDL::generate
{
	class LPDWriter : public SubWriter
	{
	private:
	public:
		LPDWriter() = default;
		~LPDWriter() = default;

	public:
		static deamer::file::tool::File GetLanguage(ir::Language* language)
		{
			deamer::file::tool::File file("Language", "h", "");

			auto generator = DLDL::filetemplate::languageTemplate();

			FillInDefaultVariablesInConstruction(generator, language);

			for (auto* ir : language->GetIRs())
			{
				generator.lpd_->Set(GetTextFromIREnum(ir->GetType()));

				generator.lpd_includes_->ExpandVariableField();
				generator.lpd_bases_->ExpandVariableField();
				generator.lpd_public_bases_->ExpandVariableField();
				generator.lpd_bases_ctor_->ExpandVariableField();
			}
			
			file.SetFileContent(generator.GetOutput());

			return file;
		}

		static deamer::file::tool::File GetCompilerGenerator(ir::Language* language)
		{
			deamer::file::tool::File file("CompilerGenerator", "h", "");

			auto generator = DLDL::filetemplate::compilergeneratorTemplate();

			FillInDefaultVariablesInConstruction(generator, language);

			for (auto* childLanguage : language->GetChildren())
			{
				generator.child_->Set(childLanguage->GetName());
				generator.Reset(generator.child_);
				
				generator.children_compilergenerator_include_->ExpandVariableField();
				generator.children_compilergenerator_bases_->ExpandVariableField();
				generator.children_compilergenerator_bases_ctor_->ExpandVariableField();
				generator.add_children_compilergenerators_->ExpandVariableField();
			}

			for (auto tool : static_cast<ir::special::Generation*>(language->GetIRIfExists(ir::Type::Generation))->GetTools())
			{
				if (!language->DoesIRExist(ir::Type::Lexicon) && tool.type == ir::special::ToolType::Lexer)
				{
					continue;
				}
				if (!language->DoesIRExist(ir::Type::Grammar) && tool.type == ir::special::ToolType::Parser)
				{
					continue;
				}
				if (!language->DoesIRExist(ir::Type::Grammar) && tool.type == ir::special::ToolType::Ast)
				{
					continue;
				}
				generator.tool_->Set(tool.name);
				generator.tool_include_path_->Set(tool.path);
				generator.tool_namespace_->Set(tool.namespace_);
				generator.Reset(generator.tool_);
				generator.Reset(generator.tool_include_path_);
				generator.Reset(generator.tool_namespace_);
				
				generator.tool_includes_->ExpandVariableField();
				generator.add_language_outputs_->ExpandVariableField();
				generator.language_output_initialization_->ExpandVariableField();
			}
			
			file.SetFileContent(generator.GetOutput());
			
			return file;
		}

		static deamer::file::tool::File GetMain(std::vector<ir::Language*> languages)
		{
			deamer::file::tool::File file("Main", "cpp", "");

			auto generator = DLDL::filetemplate::mainTemplate();

			for (auto* language : languages)
			{
				generator.root_language_->Set(language->GetName());

				generator.root_language_includes_->ExpandVariableField();
				generator.generate_root_language_->ExpandVariableField();
			}
			
			file.SetFileContent(generator.GetOutput());

			return file;
		}

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language,
																 const ir::LPD& lpd) override
		{
			deamer::file::tool::File file = LPDSubWriterFactory::GetLPDSubWriter(lpd.GetType())
												->GetFileContentSourceFile(language, lpd);

			return file;
		}

		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language,
																 const ir::LPD& lpd) override
		{
			deamer::file::tool::File file = LPDSubWriterFactory::GetLPDSubWriter(lpd.GetType())
												->GetFileContentHeaderFile(language, lpd);

			return file;
		}

		static std::string GetTextFromIREnum(ir::Type type)
		{
			switch (type)
			{
			case ir::Type::Unknown:
				break;
			case ir::Type::Lexicon:
				return "Lexicon";
			case ir::Type::Grammar:
				return "Grammar";
			case ir::Type::Precedence:
				return "Precedence";
			case ir::Type::Associativity:
				return "Associativity";
			case ir::Type::Generation:
				return "Generation";
			case ir::Type::Identity:
				return "Identity";
			case ir::Type::AstOptimization:
				return "AstOptimization";
			case ir::Type::AstTranslation:
				return "AstTranslation";
			case ir::Type::Coloring:
				return "Coloring";
			case ir::Type::Formatting:
				return "Formatting";
			case ir::Type::Documentation:
				return "Documentation";
			default:
				break;
			}

			throw std::logic_error("Unknown IR given!");
		}

		static deamer::file::tool::File GetCMakeLists(const std::vector<ir::Language*>& languages)
		{
			deamer::file::tool::File file("CMakeLists", "txt", "");

			auto generator = DLDL::filetemplate::CMakeListsTemplate();
			
			std::string languages_string;
			std::string languages_string_comma;
			for (auto* language : languages)
			{
				languages_string += language->GetName() + "_";
				languages_string_comma += language->GetName() + ", ";
			}

			if (!languages_string.empty())
			{
				languages_string.pop_back();
			}

			if (!languages_string.empty())
			{
				languages_string_comma.pop_back();
				languages_string_comma.pop_back();
			}

			generator.languages_->Set(languages_string);
			generator.languages_comma_->Set(languages_string_comma);

			file.SetFileContent(generator.GetOutput());

			return file;
		}
	};
}

#endif // DLDL_GENERATE_LPDWRITER_H