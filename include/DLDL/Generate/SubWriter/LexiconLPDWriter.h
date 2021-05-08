#ifndef DLDL_GENERATE_SUBWRITER_LEXICONLPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_LEXICONLPDWRITER_H

#include "DLDL/Template/Definition/Lexicon/LexiconTemplate.h"

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

			auto* lexicon = static_cast<ir::Lexicon*>(lpd.GetIR());

			auto generator = DLDL::filetemplate::LexiconTemplate();
			
			FillInDefaultVariablesInConstruction(generator, language);
			
			for (const auto& terminal : lexicon->GetTerminals())
			{
				generator.variable_name_->Set(terminal.Name);
				generator.variable_regex_->Set(terminal.Regex);
				
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
				generator.variable_abstraction_->Set(abstraction);

				generator.variable_declaration_->ExpandVariableField();
				generator.variable_initialization_->ExpandVariableField();
				generator.add_object_->ExpandVariableField();
			}

			file.SetFileContent(generator.GetOutput());
			
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