#ifndef DLDL_GENERATE_SUBWRITER_GRAMMARLPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_GRAMMARLPDWRITER_H

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

			auto* construction = DST::user::ConstructionGenerator().GenerateConstructionFromPath("./Template/Definition/Grammar/grammar.h.dst", "./Template/Definition/Grammar/grammar.h.setting.dst");

			auto* grammar = static_cast<ir::Grammar*>(lpd.GetIR());

			FillInDefaultVariablesInConstruction(*construction, language);

			for (const auto& nonterminal : grammar->GetNonTerminals())
			{
				construction->SetVariable("nonterminal", "", {nonterminal.name});
				construction->ExpandVariableField("nonterminal_declaration");
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

				construction->SetVariable("productionrule", "", { name });
				construction->ExpandVariableField("productionrule_declaration");
			}

			file.SetFileContent(construction->Output());
			std::cout << construction->Output() << '\n';

			delete construction;
			
			return file;
		}

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language,
														  const ir::LPD& lpd) override
		{
			deamer::file::tool::File file("Grammar", "cpp", "");

			auto* construction = DST::user::ConstructionGenerator().GenerateConstructionFromPath("./Template/Definition/Grammar/grammar.cpp.dst", "./Template/Definition/Grammar/grammar.cpp.setting.dst");

			auto* grammar = static_cast<ir::Grammar*>(lpd.GetIR());
			FillInDefaultVariablesInConstruction(*construction, language);

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
				
				construction->SetVariable("nonterminal", "", { nonterminal.name });
				construction->SetVariable("productionrule_references", "", { productionrule_references });

				construction->ExpandVariableField("nonterminal_add_object");
				construction->ExpandVariableField("nonterminal_initialization");
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
				
				construction->SetVariable("token_references", "", { token_references });

				construction->SetVariable("productionrule", "", { name });
				construction->ExpandVariableField("productionrule_add_object");
				construction->ExpandVariableField("productionrule_initialization");
			}
			
			file.SetFileContent(construction->Output());

			delete construction;
			
			return file;
		}
	};
}

#endif // DLDL_GENERATE_SUBWRITER_GRAMMARLPDWRITER_H