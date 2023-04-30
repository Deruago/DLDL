#include "DLDL/Generate/SubWriter/ImportLPDWriter.h"
#include "DLDL/IR/Language.h"
#include "DLDL/Template/Definition/Import/ImportCPPTemplate.h"
#include "DLDL/Template/Definition/Import/ImportHTemplate.h"
#include "DLDL_GRAMMAR/IR/Grammar.h"
#include "DLDL_IMPORT/IR/Import.h"
#include "DLDL_LEXER/IR/Lexicon.h"
#include "DLDL_VALUE/IR/Value.h"

deamer::file::tool::File
DLDL::generate::sub::ImportLPDWriter::GetFileContentHeaderFile(ir::Language* language,
															   const ir::LPD& lpd)
{
	deamer::file::tool::File file("Import", "h", "");

	auto* Import = static_cast<ir::Import*>(lpd.GetIR());
	auto* lexicon = static_cast<ir::Lexicon*>(language->GetIRIfExists(ir::Type::Lexicon));
	auto* grammar = static_cast<ir::Grammar*>(language->GetIRIfExists(ir::Type::Grammar));
	auto* value = static_cast<ir::Value*>(language->GetIRIfExists(ir::Type::Value));
	if (grammar == nullptr)
	{
		throw std::logic_error(
			"Import LPD requires a Grammar LPD. No Grammar LPD found in Definition directory.");
	}
	if (lexicon == nullptr)
	{
		throw std::logic_error(
			"Import LPD requires a Lexicon LPD. No Lexicon LPD found in Definition directory.");
	}

	auto generator = std::make_unique<DLDL::filetemplate::ImportHTemplate>();
	FillInDefaultVariablesInConstruction(*generator, language);

	for (auto importSpecification : Import->GetImportRules())
	{
		auto importName = importSpecification->GetImportRuleName();
		generator->name_import_specification_impl_->Set(importName);
		generator->name_import_syntactic_relation_impl_->Set(
			importName + "_" + importSpecification->GetSyntacticRelations()[0]);
		generator->name_import_file_target_impl_->Set(importName);
		generator->name_import_object_target_impl_->Set(importName);

		generator->declaration_import_specification_->ExpandVariableField();
		switch (importSpecification->GetImportRuleType())
		{
		case ir::ImportRuleType::FileImport: {
			generator->name_import_file_import_rule_impl_->Set(importName);

			generator->declaration_import_file_import_rule_->ExpandVariableField();
			generator->declaration_import_file_target_->ExpandVariableField();
			break;
		}
		case ir::ImportRuleType::FileObjectImport: {
			generator->name_import_file_object_import_rule_impl_->Set(importName);

			generator->declaration_import_file_object_import_rule_->ExpandVariableField();
			generator->declaration_import_file_target_->ExpandVariableField();
			generator->declaration_import_object_target_->ExpandVariableField();
			break;
		}
		case ir::ImportRuleType::ModuleImport: {
			break;
		}
		case ir::ImportRuleType::ModuleObjectImport: {
			break;
		}
		case ir::ImportRuleType::FileModuleImport: {
			break;
		}
		case ir::ImportRuleType::FileModuleObjectImport: {
			break;
		}
		}

		for (auto syntacticRelation : importSpecification->GetSyntacticRelations())
		{
			generator->name_import_syntactic_relation_impl_->Set(importName + "_" +
																 syntacticRelation);
			generator->declaration_import_syntactic_relation_->ExpandVariableField();
		}
	}

	file.SetFileContent(generator->GetOutput());

	return file;
}

deamer::file::tool::File
DLDL::generate::sub::ImportLPDWriter::GetFileContentSourceFile(ir::Language* language,
															   const ir::LPD& lpd)
{
	deamer::file::tool::File file("Import", "cpp", "");

	auto* Import = static_cast<ir::Import*>(lpd.GetIR());
	auto* lexicon = static_cast<ir::Lexicon*>(language->GetIRIfExists(ir::Type::Lexicon));
	auto* grammar = static_cast<ir::Grammar*>(language->GetIRIfExists(ir::Type::Grammar));
	auto* value = static_cast<ir::Value*>(language->GetIRIfExists(ir::Type::Value));
	if (grammar == nullptr)
	{
		throw std::logic_error(
			"Import LPD requires a Grammar LPD. No Grammar LPD found in Definition directory.");
	}
	if (lexicon == nullptr)
	{
		throw std::logic_error(
			"Import LPD requires a Lexicon LPD. No Lexicon LPD found in Definition directory.");
	}
	if (value == nullptr)
	{
		throw std::logic_error(
			"Import LPD requires a Value LPD. No Value LPD found in Definition directory.");
	}

	auto generator = std::make_unique<DLDL::filetemplate::ImportCPPTemplate>();
	FillInDefaultVariablesInConstruction(*generator, language);

	generator->underlying_syntax_relation_->Set(generator->name_import_syntactic_relation_);
	generator->underlying_file_target_->Set(generator->name_import_file_target_);
	generator->underlying_object_target_->Set(generator->name_import_object_target_);

	for (auto importSpecification : Import->GetImportRules())
	{
		auto importName = importSpecification->GetImportRuleName();
		generator->name_import_specification_impl_->Set(importName);
		generator->name_import_file_import_rule_impl_->Set(importName);
		generator->name_import_file_object_import_rule_impl_->Set(importName);
		generator->name_import_file_target_impl_->Set(importName);
		generator->name_import_object_target_impl_->Set(importName);
		generator->name_import_syntactic_relation_impl_->Set(
			importName + "_" + importSpecification->GetSyntacticRelations()[0]);

		switch (importSpecification->GetImportRuleType())
		{
		case ir::ImportRuleType::FileImport: {
			generator->import_specification_underlying_name_->Set(
				generator->name_import_file_import_rule_);
			generator->import_type_impl_->Set(generator->import_type_file_import_);

			auto valueRule = GetValueRule(importSpecification->GetFileTarget().value(), value);
			generator->import_object_value_rule_name_->Set(valueRule.value());

			generator->implementation_import_file_import_rule_->ExpandVariableField();
			generator->implementation_import_file_target_->ExpandVariableField();
			break;
		}
		case ir::ImportRuleType::FileObjectImport: {
			generator->import_specification_underlying_name_->Set(
				generator->name_import_file_object_import_rule_);
			generator->import_type_impl_->Set(generator->import_type_type_in_file_import_);

			auto valueRule = GetValueRule(importSpecification->GetObjectTarget().value(), value);
			generator->import_object_value_rule_name_->Set(valueRule.value());

			generator->implementation_import_file_import_rule_->ExpandVariableField();
			generator->implementation_import_file_target_->ExpandVariableField();
			generator->implementation_import_object_target_->ExpandVariableField();
			break;
		}
		case ir::ImportRuleType::ModuleImport: {
			break;
		}
		case ir::ImportRuleType::ModuleObjectImport: {
			break;
		}
		case ir::ImportRuleType::FileModuleImport: {
			break;
		}
		case ir::ImportRuleType::FileModuleObjectImport: {
			break;
		}
		}
		generator->implementation_import_specification_->ExpandVariableField();
		generator->add_import_specification_->ExpandVariableField();

		for (std::size_t i = 0; i < importSpecification->GetSyntacticRelations().size(); i++)
		{
			auto syntacticRelation = importSpecification->GetSyntacticRelations()[i];
			generator->terminal_name_->Set(syntacticRelation);
			generator->name_import_syntactic_relation_impl_->Set(importName + "_" +
																 syntacticRelation);
			if (i < importSpecification->GetSyntacticRelations().size() - 1)
			{
				generator->implementation_import_syntactic_relation_impl_->Set(
					generator->implementation_import_syntactic_relation_type_1_);
				generator->name_secondary_import_syntactic_relation_impl_->Set(
					importName + "_" + importSpecification->GetSyntacticRelations()[i + 1]);
			}
			else
			{
				generator->implementation_import_syntactic_relation_impl_->Set(
					generator->implementation_import_syntactic_relation_type_2_);
			}
			generator->implementation_import_syntactic_relation_->ExpandVariableField();
			generator->add_import_syntactic_relation_->ExpandVariableField();
		}
	}

	file.SetFileContent(generator->GetOutput());

	return file;
}

std::optional<std::string>
DLDL::generate::sub::ImportLPDWriter::GetValueRule(const std::string& valueRule,
												   ir::Value* valueLpd)
{
	return valueLpd->GetValueRuleViaNTerminal({valueRule});
}
