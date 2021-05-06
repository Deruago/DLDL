#ifndef DLDL_GENERATE_LPDWRITER_H
#define DLDL_GENERATE_LPDWRITER_H

#include "DLDL/IR/Language.h"
#include "LPDSubWriterFactory.h"
#include <Deamer/File/Tool/File.h>

namespace DLDL::generate
{
	class LPDWriter : public SubWriter
	{
	private:
	private:
		LPDWriter() = default;
		~LPDWriter() = default;

	public:
		static deamer::file::tool::File GetLanguage(ir::Language* language)
		{
			deamer::file::tool::File file("Language", "h", "");

			auto* construction = DST::user::ConstructionGenerator().GenerateConstructionFromPath("./Template/Language/language.h.dst", "./Template/Language/language.h.setting.dst");

			FillInDefaultVariablesInConstruction(*construction, language);

			for (auto* ir : language->GetIRs())
			{
				construction->SetVariable("lpd", "", { GetTextFromIREnum(ir->GetType()) });

				construction->ExpandVariableField("lpd_includes");
				construction->ExpandVariableField("lpd_bases");
				construction->ExpandVariableField("lpd_public_bases");
				construction->ExpandVariableField("lpd_bases_ctor");
			}
			
			file.SetFileContent(construction->Output());

			delete construction;

			return file;
		}

		static deamer::file::tool::File GetCompilerGenerator(ir::Language* language)
		{
			deamer::file::tool::File file("CompilerGenerator", "h", "");

			auto* construction = DST::user::ConstructionGenerator().GenerateConstructionFromPath("./Template/CompilerGenerator/compilergenerator.h.dst", "./Template/CompilerGenerator/compilergenerator.h.setting.dst");

			FillInDefaultVariablesInConstruction(*construction, language);

			for (auto* childLanguage : language->GetChildren())
			{
				construction->SetVariable("child", "", { childLanguage->GetName() });
				
				construction->ExpandVariableField("children_compilergenerator_include");
				construction->ExpandVariableField("children_compilergenerator_bases");
				construction->ExpandVariableField("children_compilergenerator_bases_ctor");
				construction->ExpandVariableField("add_children_compilergenerators");
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
				
				construction->SetVariable("tool", "", { tool.name });
				construction->SetVariable("tool_include_path", "", { tool.path });
				construction->SetVariable("tool_namespace", "", { tool.namespace_ });

				construction->ExpandVariableField("tool_includes");
				construction->ExpandVariableField("add_language_outputs");
				construction->ExpandVariableField("language_output_initialization");
			}
			
			file.SetFileContent(construction->Output());
			
			delete construction;

			return file;
		}

		static deamer::file::tool::File GetMain(std::vector<ir::Language*> languages)
		{
			deamer::file::tool::File file("Main", "cpp", "");

			auto* construction = DST::user::ConstructionGenerator().GenerateConstructionFromPath("./Template/Main/main.cpp.dst", "./Template/Main/main.cpp.setting.dst");

			for (auto* language : languages)
			{
				construction->SetVariable("root_language", "", { language->GetName() });
				construction->ExpandVariableField("root_language_includes");
				construction->ExpandVariableField("generate_root_language");
			}
			
			file.SetFileContent(construction->Output());

			delete construction;

			return file;
		}

		static deamer::file::tool::File GetFileContentSourceFile(ir::Language* language,
																 const ir::LPD& lpd)
		{
			deamer::file::tool::File file = LPDSubWriterFactory::GetLPDSubWriter(lpd.GetType())
												->GetFileContentSourceFile(language, lpd);

			return file;
		}

		static deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language,
																 const ir::LPD& lpd)
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

			auto* construction = DST::user::ConstructionGenerator().GenerateConstructionFromPath("./Template/CMakeLists/CMakeLists.txt.dst", "./Template/CMakeLists/CMakeLists.txt.setting.dst");

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

			construction->SetVariable("languages", "", { languages_string });
			construction->SetVariable("languages_comma", "", { languages_string_comma });

			file.SetFileContent(construction->Output());

			delete construction;

			return file;
		}
	};
}

#endif // DLDL_GENERATE_LPDWRITER_H