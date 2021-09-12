#include "DLDL/Generate/SubWriter/GrammarLPDWriter.h"
#include "DLDL/Template/Definition/Grammar/GrammarHTemplate.h"
#include "DLDL/Template/Definition/Grammar/GrammarCPPTemplate.h"
#include <Deamer/Deamer.h>

#ifndef DEAMER_CC_V2_RESERVED_MACRO_VALUE_VERSION_NUMBER
#define DEAMER_CC_V2_RESERVED_MACRO_VALUE_VERSION_NUMBER 000'000'000UL
#endif // DEAMER_CC_V2_RESERVED_MACRO_VALUE_VERSION_NUMBER

deamer::file::tool::File
DLDL::generate::sub::GrammarLPDWriter::GetFileContentHeaderFile(ir::Language* language,
																const ir::LPD& lpd)
{
	deamer::file::tool::File file("Grammar", "h", "");

	auto* grammar = static_cast<ir::Grammar*>(lpd.GetIR());

	auto generator = DLDL::filetemplate::GrammarHTemplate();

	FillInDefaultVariablesInConstruction(generator, language);

	for (const auto& nonterminal : grammar->GetNonTerminals())
	{
		generator.nonterminal_->Set(nonterminal.name);

		generator.nonterminal_declaration_->ExpandVariableField();
	}

	for (const auto& productionrule : grammar->GetProductionRules())
	{
		std::string name = productionrule.nonterminal;
		for (const auto& token : productionrule.tokens)
		{
			name += "_" + token;
		}
		if (productionrule.tokens.empty())
		{
			name += "_EMPTY";
		}

		generator.productionrule_->Set(name);

		generator.productionrule_declaration_->ExpandVariableField();
	}

	for (const auto& unknownReference : grammar->GetUnknownReferences())
	{
		generator.unknown_reference_->Set(unknownReference);
		generator.unknown_reference_declaration_->ExpandVariableField();
	}

	file.SetFileContent(generator.GetOutput());

	return file;
}

deamer::file::tool::File
DLDL::generate::sub::GrammarLPDWriter::GetFileContentSourceFile(ir::Language* language,
																const ir::LPD& lpd)
{
	deamer::file::tool::File file("Grammar", "cpp", "");

	auto* grammar = static_cast<ir::Grammar*>(lpd.GetIR());

	auto generator = DLDL::filetemplate::GrammarCPPTemplate();

	FillInDefaultVariablesInConstruction(generator, language);

	if constexpr (DEAMER_CC_V2_RESERVED_MACRO_VALUE_VERSION_NUMBER < 002'001'000UL)
	{
		generator.enable_nonterminal_inlined_->Set("");
	}

	for (const auto& nonterminal : grammar->GetNonTerminals())
	{
		std::string productionrule_references;
		for (const auto& productionrule : nonterminal.productionRules)
		{
			std::string name = productionrule.nonterminal;
			for (const auto& token : productionrule.tokens)
			{
				name += "_" + token;
			}
			if (productionrule.tokens.empty())
			{
				name += "_EMPTY";
			}
			name += ".Pointer(),";

			productionrule_references += name;
		}
		if (!nonterminal.productionRules.empty())
		{
			productionrule_references.pop_back();
		}

		generator.nonterminal_->Set(nonterminal.name);
		generator.productionrule_references_->Set(productionrule_references);

		switch (nonterminal.abstraction)
		{
		case deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard:
			generator.nonterminal_abstraction_->Set("Standard");
			break;
		case deamer::language::type::definition::object::main::NonTerminalAbstraction::Group:
			generator.nonterminal_abstraction_->Set("Group");
			break;
		default:
			generator.nonterminal_abstraction_->Set("Standard");
			break;
		}

		if (nonterminal.inlineNonTerminal)
		{
			generator.nonterminal_inlined_->Set("true");
		}
		else
		{
			generator.nonterminal_inlined_->Set("false");
		}

		generator.nonterminal_add_object_->ExpandVariableField();
		generator.nonterminal_initialization_->ExpandVariableField();
	}

	for (const auto& productionrule : grammar->GetProductionRules())
	{
		std::string name = productionrule.nonterminal;
		for (const auto& token : productionrule.tokens)
		{
			name += "_" + token;
		}
		if (productionrule.tokens.empty())
		{
			name += "_EMPTY";
		}

		std::string token_references;
		if (!productionrule.tokens.empty())
		{
			token_references += "{ ";
			for (const auto& token : productionrule.tokens)
			{
				if (grammar->IsUnknownReference(token))
				{
					token_references += "this->";
				}
				else
				{
					token_references += "Language->";
				}
				token_references += token + ".Pointer(),";
			}
			token_references.pop_back();
			token_references += " }";
		}

		generator.token_references_->Set(token_references);
		generator.productionrule_->Set(name);

		generator.productionrule_add_object_->ExpandVariableField();
		generator.productionrule_initialization_->ExpandVariableField();
	}

	for (const auto& unknownReference : grammar->GetUnknownReferences())
	{
		generator.unknown_type_->Set(unknownReference);
		generator.unknown_reference_->ExpandVariableField();
		generator.unknown_reference_add_object_->ExpandVariableField();
	}

	file.SetFileContent(generator.GetOutput());

	return file;
}
