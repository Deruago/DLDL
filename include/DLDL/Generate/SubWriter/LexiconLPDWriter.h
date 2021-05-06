#ifndef DLDL_GENERATE_SUBWRITER_LEXICONLPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_LEXICONLPDWRITER_H

#include "DST/User/ConstructionGenerator.h"

namespace DLDL::generate::sub
{
	class LexiconLPDWriter : public SubWriter
	{
	public:
		LexiconLPDWriter() = default;
	public:
		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language, const ir::LPD& lpd) override
		{
			deamer::file::tool::File file("Lexicon", "h", "");

			auto* construction = DST::user::ConstructionGenerator().GenerateConstructionFromPath("./Template/Definition/Lexicon/lexicon.h.dst", "./Template/Definition/Lexicon/lexicon.h.setting.dst");

			auto* lexicon = static_cast<ir::Lexicon*>(lpd.GetIR());

			FillInDefaultVariablesInConstruction(*construction, language);
			
			for (const auto& terminal : lexicon->GetTerminals())
			{
				construction->SetVariable("variable_name", "", { terminal.Name });
				construction->SetVariable("variable_regex", "", { terminal.Regex });
				std::string abstraction = "::deamer::language::type::definition::object::main::SpecialType::Standard";
				switch (terminal.Special)
				{
				case deamer::language::type::definition::object::main::SpecialType::Standard:
					abstraction = "::deamer::language::type::definition::object::main::SpecialType::Standard";
					break;
				case deamer::language::type::definition::object::main::SpecialType::Delete:
					abstraction = "::deamer::language::type::definition::object::main::SpecialType::Delete";
					break;
				case deamer::language::type::definition::object::main::SpecialType::Ignore:
					abstraction = "::deamer::language::type::definition::object::main::SpecialType::Ignore";
					break;
				case deamer::language::type::definition::object::main::SpecialType::NoValue:
					abstraction = "::deamer::language::type::definition::object::main::SpecialType::NoValue";
					break;
				case deamer::language::type::definition::object::main::SpecialType::Crash:
					abstraction = "::deamer::language::type::definition::object::main::SpecialType::Crash";
					break;
				default:
					break;
				}
				construction->SetVariable("variable_abstraction", "", { abstraction });

				construction->ExpandVariableField("variable_declaration");
				construction->ExpandVariableField("variable_initialization");
				construction->ExpandVariableField("add_object");
			}

			file.SetFileContent(construction->Output());
			std::cout << construction->Output();

			delete construction;
			
			return file;
		}

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language, const ir::LPD& lpd) override
		{
			deamer::file::tool::File file("Lexicon", "cpp", "");

			return file;
		}
	};
}

#endif // DLDL_GENERATE_SUBWRITER_LEXICONLPDWRITER_H