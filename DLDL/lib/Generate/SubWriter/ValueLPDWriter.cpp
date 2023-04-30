#include "DLDL/Generate/SubWriter/ValueLPDWriter.h"
#include "DLDL/IR/Language.h"
#include "DLDL/Template/Definition/Value/ValueCPPTemplate.h"
#include "DLDL/Template/Definition/Value/ValueHTemplate.h"
#include "DLDL_GRAMMAR/IR/Grammar.h"
#include "DLDL_LEXER/IR/Lexicon.h"
#include "DLDL_VALUE/IR/Value.h"

deamer::file::tool::File
DLDL::generate::sub::ValueLPDWriter::GetFileContentHeaderFile(ir::Language* language,
															  const ir::LPD& lpd)
{
	deamer::file::tool::File file("Value", "h", "");

	auto* Value = static_cast<ir::Value*>(lpd.GetIR());
	auto* lexicon = static_cast<ir::Lexicon*>(language->GetIRIfExists(ir::Type::Lexicon));
	auto* grammar = static_cast<ir::Grammar*>(language->GetIRIfExists(ir::Type::Grammar));
	if (grammar == nullptr)
	{
		throw std::logic_error(
			"Value LPD requires a Grammar LPD. No Grammar LPD found in Definition directory.");
	}
	if (lexicon == nullptr)
	{
		throw std::logic_error(
			"Value LPD requires a Lexicon LPD. No Lexicon LPD found in Definition directory.");
	}

	auto generator = std::make_unique<DLDL::filetemplate::ValueHTemplate>();
	FillInDefaultVariablesInConstruction(*generator, language);

	for (auto value_rule : Value->GetValueRules())
	{
		generator->value_object_name_->Set(value_rule->GetRuleName());
		generator->value_object_declaration_->ExpandVariableField();
	}

	for (auto value_characteristic : Value->GetValueCharacteristics())
	{
		generator->value_object_name_->Set(value_characteristic->GetRuleName());
		generator->value_object_declaration_->ExpandVariableField();
	}

	for (auto value_abstraction : Value->GetValueAbstractions())
	{
		generator->value_abstraction_primary_name_->Set(
			std::to_string(value_abstraction->GetAbstractionId()));
		generator->value_abstraction_declaration_->ExpandVariableField();
	}

	file.SetFileContent(generator->GetOutput());

	return file;
}

deamer::file::tool::File
DLDL::generate::sub::ValueLPDWriter::GetFileContentSourceFile(ir::Language* language,
															  const ir::LPD& lpd)
{
	deamer::file::tool::File file("Value", "cpp", "");

	auto* Value = static_cast<ir::Value*>(lpd.GetIR());
	auto* lexicon = static_cast<ir::Lexicon*>(language->GetIRIfExists(ir::Type::Lexicon));
	auto* grammar = static_cast<ir::Grammar*>(language->GetIRIfExists(ir::Type::Grammar));
	if (grammar == nullptr)
	{
		throw std::logic_error(
			"Value LPD requires a Grammar LPD. No Grammar LPD found in Definition directory.");
	}
	if (lexicon == nullptr)
	{
		throw std::logic_error(
			"Value LPD requires a Lexicon LPD. No Lexicon LPD found in Definition directory.");
	}

	auto generator = std::make_unique<DLDL::filetemplate::ValueCPPTemplate>();
	FillInDefaultVariablesInConstruction(*generator, language);

	for (auto value_rule : Value->GetValueRules())
	{
		generator->value_object_syntactic_relation_->variable_field_->Clear();
		generator->value_object_abstraction_->variable_field_->Clear();

		generator->value_object_name_->Set(value_rule->GetRuleName());
		generator->value_object_rule_name_str_->Set(value_rule->GetRuleName());
		generator->value_object_type_->Set(generator->value_object_type_standard_);
		for (auto syntactic : value_rule->GetSyntacticContexts())
		{
			generator->terminal_name_->Set(syntactic);
			generator->value_object_syntactic_relation_->ExpandVariableField();
		}

		for (auto abstraction : value_rule->GetUnderlyingAbstraction())
		{
			generator->value_abstraction_primary_name_->Set(
				std::to_string(abstraction->GetAbstractionId()));
			generator->value_object_abstraction_->ExpandVariableField();
		}

		generator->value_object_implementation_->ExpandVariableField();
	}

	for (auto value_characteristic : Value->GetValueCharacteristics())
	{
		generator->value_object_syntactic_relation_->variable_field_->Clear();
		generator->value_object_abstraction_->variable_field_->Clear();

		generator->value_object_name_->Set(value_characteristic->GetRuleName());
		generator->value_object_rule_name_str_->Set(value_characteristic->GetRuleName());
		generator->value_object_type_->Set(generator->value_object_type_characteristic_);
		for (auto syntactic : value_characteristic->GetSyntacticContexts())
		{
			generator->terminal_name_->Set(syntactic);
			generator->value_object_syntactic_relation_->ExpandVariableField();
		}

		for (auto abstraction : value_characteristic->GetUnderlyingAbstraction())
		{
			generator->value_abstraction_primary_name_->Set(
				std::to_string(abstraction->GetAbstractionId()));
			generator->value_object_abstraction_->ExpandVariableField();
		}

		generator->value_object_implementation_->ExpandVariableField();
	}

	for (auto value_abstraction : Value->GetValueAbstractions())
	{
		generator->value_underlying_abstraction_->variable_field_->Clear();

		generator->value_abstraction_primary_name_->Set(
			std::to_string(value_abstraction->GetAbstractionId()));

		generator->value_abstraction_value_->Set(value_abstraction->GetAbstractionValue());
		switch (value_abstraction->GetValueAbstractionType())
		{
		case ir::ValueAbstractionType::Unknown: {
			generator->value_abstraction_type_impl_->Set(
				generator->value_abstraction_type_isstring_);
			break;
		}
		case ir::ValueAbstractionType::IsString: {
			generator->value_abstraction_type_impl_->Set(
				generator->value_abstraction_type_isstring_);
			break;
		}
		case ir::ValueAbstractionType::IsInteger: {
			generator->value_abstraction_type_impl_->Set(
				generator->value_abstraction_type_isinteger_);
			break;
		}
		case ir::ValueAbstractionType::IsValue: {
			generator->value_abstraction_type_impl_->Set(
				generator->value_abstraction_type_isvalue_);
			break;
		}
		case ir::ValueAbstractionType::Start: {
			generator->value_abstraction_type_impl_->Set(
				generator->value_abstraction_type_stringstartpattern_);
			break;
		}
		case ir::ValueAbstractionType::End: {
			generator->value_abstraction_type_impl_->Set(
				generator->value_abstraction_type_stringendpattern_);
			break;
		}
		case ir::ValueAbstractionType::Escape: {
			generator->value_abstraction_type_impl_->Set(
				generator->value_abstraction_type_stringescapepattern_);
			break;
		}
		case ir::ValueAbstractionType::IsVector: {
			generator->value_abstraction_type_impl_->Set(
				generator->value_abstraction_type_isvector_);
			break;
		}
		case ir::ValueAbstractionType::Wildcard: {
			generator->value_abstraction_type_impl_->Set(
				generator->value_abstraction_type_wildcardpattern_);
			break;
		}
		}

		for (auto abstraction : value_abstraction->GetUnderlyingAbstractions())
		{
			generator->value_abstraction_secondary_name_->Set(
				std::to_string(abstraction->GetAbstractionId()));
			generator->value_underlying_abstraction_->ExpandVariableField();
		}

		generator->value_abstraction_implementation_->ExpandVariableField();
	}

	file.SetFileContent(generator->GetOutput());

	return file;
}
