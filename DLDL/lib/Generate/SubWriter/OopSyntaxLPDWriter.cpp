#include "DLDL/Generate/SubWriter/OopSyntaxLPDWriter.h"
#include "DLDL/IR/Language.h"
#include "DLDL/Template/Definition/OopSyntax/OopSyntaxCPPTemplate.h"
#include "DLDL/Template/Definition/OopSyntax/OopSyntaxHTemplate.h"
#include "DLDL_GRAMMAR/IR/Grammar.h"
#include "DLDL_LEXER/IR/Lexicon.h"
#include "DLDL_OOPSYNTAX/IR/OopSyntax.h"

deamer::file::tool::File
DLDL::generate::sub::OopSyntaxLPDWriter::GetFileContentHeaderFile(ir::Language* language,
																  const ir::LPD& lpd)
{
	deamer::file::tool::File file("OopSyntax", "h", "");

	auto* oopSyntax = static_cast<ir::OopSyntax*>(lpd.GetIR());
	auto* lexicon = static_cast<ir::Lexicon*>(language->GetIRIfExists(ir::Type::Lexicon));
	auto* grammar = static_cast<ir::Grammar*>(language->GetIRIfExists(ir::Type::Grammar));
	if (grammar == nullptr)
	{
		throw std::logic_error(
			"OopSyntax LPD requires a Grammar LPD. No Grammar LPD found in Definition directory.");
	}
	if (lexicon == nullptr)
	{
		throw std::logic_error(
			"OopSyntax LPD requires a Lexicon LPD. No Lexicon LPD found in Definition directory.");
	}

	auto generator = std::make_unique<DLDL::filetemplate::OopSyntaxHTemplate>();
	FillInDefaultVariablesInConstruction(*generator, language);

	std::set<std::string> unknownReferences;
	for (const auto& oopProperty : oopSyntax->GetOopProperties())
	{
		generator->object_name_->Set(oopProperty->object);
		generator->oop_syntax_scope_->Set(GetOopTypeName(oopProperty->oopType));
		generator->oop_encapsulation_declaration_->ExpandVariableField();

		if (!grammar->DoesNonTerminalExist(oopProperty->object) &&
			!lexicon->DoesTerminalExist(oopProperty->object))
		{
			generator->unknown_reference_->Set(oopProperty->object);
			generator->unknown_reference_declaration_->ExpandVariableField();
			unknownReferences.insert(oopProperty->object);
			continue;
		}

		for (const auto& productionRule : oopProperty->productionRuleAssignments)
		{
			generator->productionrule_index_->Set(std::to_string(productionRule->productionRule));
			generator->oop_link_declaration_->ExpandVariableField();
			for (const auto& directAssignment : productionRule->directAssignments)
			{
				if (unknownReferences.find(directAssignment->object) != unknownReferences.end())
				{
					continue;
				}
				if (!grammar->DoesNonTerminalExist(directAssignment->object) &&
					!lexicon->DoesTerminalExist(directAssignment->object))
				{
					generator->unknown_reference_->Set(directAssignment->object);
					generator->unknown_reference_declaration_->ExpandVariableField();
					unknownReferences.insert(directAssignment->object);
					continue;
				}

				generator->oop_concept_member_object_name_->Set(directAssignment->object);
				generator->oop_concept_member_type_->Set(
					GetOopTypeName(directAssignment->oopType) + "_" +
					GetOopPropertyName(directAssignment->oopProperty));
				generator->oop_concept_link_declaration_->ExpandVariableField();
			}
		}
	}

	file.SetFileContent(generator->GetOutput());

	return file;
}

deamer::file::tool::File
DLDL::generate::sub::OopSyntaxLPDWriter::GetFileContentSourceFile(ir::Language* language,
																  const ir::LPD& lpd)
{
	deamer::file::tool::File file("OopSyntax", "cpp", "");

	auto* oopSyntax = static_cast<ir::OopSyntax*>(lpd.GetIR());
	auto* lexicon = static_cast<ir::Lexicon*>(language->GetIRIfExists(ir::Type::Lexicon));
	auto* grammar = static_cast<ir::Grammar*>(language->GetIRIfExists(ir::Type::Grammar));
	if (grammar == nullptr)
	{
		throw std::logic_error(
			"OopSyntax LPD requires a Grammar LPD. No Grammar LPD found in Definition directory.");
	}
	if (lexicon == nullptr)
	{
		throw std::logic_error(
			"OopSyntax LPD requires a Lexicon LPD. No Lexicon LPD found in Definition directory.");
	}

	auto generator = std::make_unique<DLDL::filetemplate::OopSyntaxCPPTemplate>();
	FillInDefaultVariablesInConstruction(*generator, language);

	std::set<std::string> unknownReferences;
	for (const auto& oopProperty : oopSyntax->GetOopProperties())
	{
		generator->object_name_->Set(oopProperty->object);
		generator->oop_syntax_scope_->Set(GetOopTypeName(oopProperty->oopType));
		generator->oop_encapsulation_implementation_->ExpandVariableField();
		generator->add_encapsulation_->ExpandVariableField();

		for (const auto& productionRule : oopProperty->productionRuleAssignments)
		{
			// reset
			generator->oop_link_member_->variable_field_->Clear();

			generator->productionrule_index_->Set(std::to_string(productionRule->productionRule));

			if (!grammar->DoesNonTerminalExist(oopProperty->object) &&
				!lexicon->DoesTerminalExist(oopProperty->object))
			{
				generator->unknown_reference_->Set(oopProperty->object);
				generator->unknown_reference_implementation_->ExpandVariableField();
				generator->add_unknown_reference_->ExpandVariableField();
				unknownReferences.insert(oopProperty->object);
				continue;
			}
			if (grammar->DoesNonTerminalExist(oopProperty->object) &&
				productionRule->productionRule >=
					grammar->GetNonTerminal(oopProperty->object).productionRules.size())
			{
				continue;
			}

			auto productionRuleName = grammar->GetNonTerminal(oopProperty->object)
										  .productionRules[productionRule->productionRule]
										  .GetName();
			generator->oop_link_productionrule_name_->Set(productionRuleName);

			bool first = true;
			for (const auto& directAssignment : productionRule->directAssignments)
			{
				if (unknownReferences.find(directAssignment->object) != unknownReferences.end())
				{
					continue;
				}
				if (!grammar->DoesNonTerminalExist(directAssignment->object) &&
					!lexicon->DoesTerminalExist(directAssignment->object))
				{
					generator->unknown_reference_->Set(directAssignment->object);
					generator->unknown_reference_implementation_->ExpandVariableField();
					generator->add_unknown_reference_->ExpandVariableField();
					unknownReferences.insert(directAssignment->object);
					continue;
				}

				if (first)
				{
					generator->optional_comma_extension_->Set("");
					first = false;
				}
				else
				{
					generator->optional_comma_extension_->Set(generator->comma_extension_);
				}

				generator->oop_concept_member_object_name_->Set(directAssignment->object);
				generator->oop_concept_member_type_->Set(
					GetOopTypeName(directAssignment->oopType) + "_" +
					GetOopPropertyName(directAssignment->oopProperty));
				generator->oop_concept_link_implementation_->ExpandVariableField();
				generator->oop_link_member_->ExpandVariableField();
				generator->add_concept_link_->ExpandVariableField();
			}
			generator->add_link_->ExpandVariableField();
			generator->oop_link_implementation_->ExpandVariableField();
		}
	}

	file.SetFileContent(generator->GetOutput());

	return file;
}

std::string DLDL::generate::sub::OopSyntaxLPDWriter::GetOopPropertyName(
	deamer::language::type::definition::object::main::OopConceptMemberType oopProperty)
{
	switch (oopProperty)
	{
	case deamer::language::type::definition::object::main::OopConceptMemberType::
		reserved_default_enum_option:
	case deamer::language::type::definition::object::main::OopConceptMemberType::Name:
		return "Name";
	case deamer::language::type::definition::object::main::OopConceptMemberType::Type:
		return "Type";
	case deamer::language::type::definition::object::main::OopConceptMemberType::Member:
		return "Member";
	}

	return "Name";
}

std::string DLDL::generate::sub::OopSyntaxLPDWriter::GetOopTypeName(
	const std::optional<deamer::language::type::definition::object::main::OopSyntaxScope>&
		oopSyntaxScope_)
{
	if (!oopSyntaxScope_.has_value())
	{
		return "Class";
	}

	switch (oopSyntaxScope_.value())
	{
	case deamer::language::type::definition::object::main::OopSyntaxScope::Struct:
		return "Struct";
	case deamer::language::type::definition::object::main::OopSyntaxScope::Interface:
		return "Interface";
	case deamer::language::type::definition::object::main::OopSyntaxScope::
		reserved_default_enum_option:
	case deamer::language::type::definition::object::main::OopSyntaxScope::Class:
		return "Class";
	case deamer::language::type::definition::object::main::OopSyntaxScope::BaseTypes:
		return "BaseTypes";
	case deamer::language::type::definition::object::main::OopSyntaxScope::Function:
		return "Function";
	case deamer::language::type::definition::object::main::OopSyntaxScope::FunctionArguments:
		return "FunctionArguments";
	case deamer::language::type::definition::object::main::OopSyntaxScope::Property:
		return "Property";
	case deamer::language::type::definition::object::main::OopSyntaxScope::Enum:
		return "Enum";
	case deamer::language::type::definition::object::main::OopSyntaxScope::Any:
		return "Any";
	}

	return "Class";
}
