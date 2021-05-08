#ifndef DLDL_GENERATE_SUBWRITER_GRAMMARLPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_GRAMMARLPDWRITER_H

#include "DLDL/Template/Definition/Grammar/GrammarHTemplate.h"
#include "DLDL/Template/Definition/Grammar/GrammarCPPTemplate.h"

namespace DLDL::generate::sub
{
	class GrammarLPDWriter : public SubWriter
	{
	public:
		GrammarLPDWriter() = default;

	public:
		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language,
														  const ir::LPD& lpd) override
		{
			deamer::file::tool::File file("Grammar", "h", "");

			auto* grammar = static_cast<ir::Grammar*>(lpd.GetIR());

			auto generator = DLDL::filetemplate::GrammarTemplate();
			
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

			file.SetFileContent(generator.GetOutput());
			
			return file;
		}

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language,
														  const ir::LPD& lpd) override
		{
			deamer::file::tool::File file("Grammar", "cpp", "");

			auto* grammar = static_cast<ir::Grammar*>(lpd.GetIR());

			auto generator = DLDL::filetemplate::GrammarCPPTemplate();
			
			FillInDefaultVariablesInConstruction(generator, language);

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
						token_references += "Language->" + token + ".Pointer(),";
					}
					token_references.pop_back();
					token_references += " }";
				}

				generator.token_references_->Set(token_references);
				generator.productionrule_->Set(name);

				generator.productionrule_add_object_->ExpandVariableField();
				generator.productionrule_initialization_->ExpandVariableField();
			}
			
			file.SetFileContent(generator.GetOutput());
			
			return file;
		}
	};
}

#endif // DLDL_GENERATE_SUBWRITER_GRAMMARLPDWRITER_H