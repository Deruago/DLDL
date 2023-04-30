#include "DLDL/Generate/LPDWriter.h"
#include "Deamer/Deamer.h"

#ifndef DEAMER_CC_V2_RESERVED_MACRO_VALUE_VERSION_NUMBER
#define DEAMER_CC_V2_RESERVED_MACRO_VALUE_VERSION_NUMBER 000'000'000UL
#endif // DEAMER_CC_V2_RESERVED_MACRO_VALUE_VERSION_NUMBER

deamer::file::tool::File DLDL::generate::LPDWriter::GetLanguage(ir::Language* language)
{
	deamer::file::tool::File file("Language", "h", "");

	auto generator = DLDL::filetemplate::LanguageTemplate();

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

deamer::file::tool::File DLDL::generate::LPDWriter::GetCompilerGenerator(ir::Language* language)
{
	deamer::file::tool::File file("CompilerGenerator", "h", "");

	auto generator = DLDL::filetemplate::compilergeneratorTemplate();

	FillInDefaultVariablesInConstruction(generator, language);

	if constexpr (DEAMER_CC_V2_RESERVED_MACRO_VALUE_VERSION_NUMBER < 002'001'000UL)
	{
		generator.print_threats_->Set("");
	}

	for (auto* childLanguage : language->GetChildren())
	{
		generator.child_->Set(childLanguage->GetName());

		generator.children_compilergenerator_include_->ExpandVariableField();
		generator.children_compilergenerator_bases_->ExpandVariableField();
		generator.children_compilergenerator_bases_ctor_->ExpandVariableField();
		generator.add_children_compilergenerators_->ExpandVariableField();
	}

	for (const auto& tool :
		 static_cast<ir::special::Generation*>(language->GetIRIfExists(ir::Type::Generation))
			 ->GetTools())
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

		generator.tool_includes_->ExpandVariableField();
		generator.add_language_outputs_->ExpandVariableField();
		generator.language_output_initialization_->ExpandVariableField();
	}

	file.SetFileContent(generator.GetOutput());

	return file;
}

deamer::file::tool::File
DLDL::generate::LPDWriter::GetMain(const std::vector<ir::Language*>& languages, bool multiProject,
								   bool useLegacyNames)
{
	deamer::file::tool::File file("main", "cpp", "");

	auto generator = DLDL::filetemplate::mainTemplate();

	if (useLegacyNames)
	{
		generator.optional_use_legacy_names_->Set(generator.use_legacy_names_);
	}

	if constexpr (DEAMER_CC_V2_RESERVED_MACRO_VALUE_VERSION_NUMBER >= 002'001'001UL)
	{
		if (multiProject)
		{
			generator.project_type_value_->Set("multi");
		}
		else
		{
			generator.project_type_value_->Set("single");
		}
	}
	else
	{
		generator.optional_project_type_->Set("");
	}

	for (auto* language : languages)
	{
		generator.root_language_->Set(language->GetName());

		generator.root_language_includes_->ExpandVariableField();
		generator.generate_root_language_->ExpandVariableField();
	}

	file.SetFileContent(generator.GetOutput());

	return file;
}

deamer::file::tool::File DLDL::generate::LPDWriter::GetFileContentSourceFile(ir::Language* language,
																			 const ir::LPD& lpd)
{
	deamer::file::tool::File file = LPDSubWriterFactory::GetLPDSubWriter(lpd.GetType())
										->GetFileContentSourceFile(language, lpd);

	return file;
}

deamer::file::tool::File DLDL::generate::LPDWriter::GetFileContentHeaderFile(ir::Language* language,
																			 const ir::LPD& lpd)
{
	deamer::file::tool::File file = LPDSubWriterFactory::GetLPDSubWriter(lpd.GetType())
										->GetFileContentHeaderFile(language, lpd);

	return file;
}

std::string DLDL::generate::LPDWriter::GetTextFromIREnum(ir::Type type)
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
	case ir::Type::OopSyntax:
		return "OopSyntax";
	case ir::Type::Threat:
		return "Threat";
	case ir::Type::LpdDef:
		return "LpdDef";
	case ir::Type::LpdStruct:
		return "LpdStruct";
	case ir::Type::LdoStruct:
		return "LdoStruct";
	case ir::Type::ToolDef:
		return "ToolDef";
	case ir::Type::ToolStruct:
		return "ToolStruct";
	case ir::Type::Argument:
		return "Argument";
	case ir::Type::Comment:
		return "Comment";
	case ir::Type::Import:
		return "Import";
	case ir::Type::Value:
		return "Value";
	}

	throw std::logic_error("Unknown IR given!");
}

deamer::file::tool::File
DLDL::generate::LPDWriter::GetCMakeLists(const std::vector<ir::Language*>& languages)
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
