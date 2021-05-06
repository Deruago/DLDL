#ifndef DLDL_IR_LANGUAGE_H
#define DLDL_IR_LANGUAGE_H

#include "DLDL/IR/Type.h"
#include <string>
#include <vector>

#include "IR.h"
#include "IR_Config.h"
#include "LPD.h"
#include "SpecialDefinition/Generation.h"
#include "SpecialDefinition/Identity.h"

namespace DLDL::ir
{
	/*	\class Language
	 *
	 *	\brief Language contains references to its children and parents.
	 *	It also contains information about its own LPD's;
	 */
	class Language
	{
	private:
		std::string name;

		mutable Language* parent = nullptr;
		std::vector<Language*> children;

		// IR and IR_Config combined makes an complete generatable LPD
		std::vector<IR*> IRs;
		std::vector<IR_Config*> IR_Configs;
		
	public:
		Language(std::string name_) : name(name_)
		{
			auto* defaultIdentity = new special::Identity(name);
			defaultIdentity->SetAsDefaultImplementedByDLDL();
			
			AddIR(defaultIdentity);

			auto* defaultGeneration = new special::Generation();
			defaultGeneration->SetAsDefaultImplementedByDLDL();

			// This is the tool for DeamerAst with C++ as target.
			defaultGeneration->AddTool({ "CPP", special::ToolType::Ast });

			defaultGeneration->AddTool({ "Flex", special::ToolType::Lexer });
			defaultGeneration->AddIntegration("Flex", "Bison");
			defaultGeneration->AddIntegration("Flex", "DeamerAST");
			defaultGeneration->AddArgument("Flex", "Output-terminal-objects");
			// defaultGeneration->AddArgument("Flex", "Debug");
			defaultGeneration->AddTool({ "Bison", special::ToolType::Parser });
			defaultGeneration->AddIntegration("Bison", "DeamerAST");
			defaultGeneration->AddArgument("Bison", "Declare-deleted-terminals");
			// defaultGeneration->AddArgument("Bison", "Debug");

			AddIR(defaultGeneration);
		}
		virtual ~Language() = default;

	public:
		std::string GetName() const
		{
			return name;
		}

		std::vector<std::string> GetParents() const
		{
			std::vector<std::string> path;
			return GetParents(path);
		}
		
		std::vector<std::string> GetParents(std::vector<std::string>& current) const
		{
			if (parent != nullptr)
			{
				parent->GetParents(current);
				current.push_back(GetName());
			}
			else
			{
				current.push_back(GetName());
			}

			return current;
		}
	public:
		bool DoesIRExist(Type getType) const
		{
			return GetIRIfExists(getType) != nullptr;
		}

		IR* GetIRIfExists(Type getType) const
		{
			for (auto* currentIR : IRs)
			{
				if (currentIR->GetType() == getType)
				{
					return currentIR;
				}
			}

			return nullptr;
		}
		
		bool DoesIR_ConfigExist(Type getType) const
		{
			for (auto* currentConfig : IR_Configs)
			{
				if (currentConfig->GetType() == getType)
				{
					return true;
				}
			}

			return false;
		}

		void ReplaceIR(IR* ir)
		{
			size_t index = 0;
			bool found = false;
			for (auto* ir_ : GetIRs())
			{
				if (ir_ == ir)
				{
					delete ir_;
					found = true;
					break;
				}
				index++;
			}

			if (!found)
			{
				return;
			}
			
			IRs.erase(IRs.begin() + index);
			AddIR(ir);
		}

		void AddIR(IR* newIR)
		{
			if (DoesIRExist(newIR->GetType()))
			{
				ReplaceIR(newIR);
				return;
			}

			IRs.push_back(newIR);
		}

		void AddIR_Config(IR_Config* newConfig)
		{
			if (DoesIR_ConfigExist(newConfig->GetType()))
			{
				return;
			}

			IR_Configs.push_back(newConfig);
		}

		void AddLanguage(Language* newLanguage)
		{
			newLanguage->parent = this;
			children.push_back(newLanguage);
		}

		std::vector<IR*> GetIRs() const
		{
			return IRs;
		}

		std::vector<IR_Config*> GetIR_Configs() const
		{
			return IR_Configs;
		}

		std::vector<LPD> GetCurrentLPDs()
		{
			std::vector<LPD> LPDs;
			
			for (auto* ir : IRs)
			{
				bool found = false;
				for (auto* ir_config : IR_Configs)
				{
					if (ir->GetType() == ir_config->GetType())
					{
						found = true;
						LPDs.emplace_back(ir, ir_config);
					}
				}

				if (!found)
				{
					auto* newIR_Config = new IR_Config(ir->GetType());
					AddIR_Config(newIR_Config);
					LPDs.emplace_back(ir, newIR_Config);
				}
			}

			return LPDs;
		}

		std::vector<Language*> GetChildren() const
		{
			return children;
		}

		Language* GetParent() const
		{
			return parent;
		}

		std::vector<const Language*> GetParentPath() const
		{
			std::vector<const Language*> parentPath;
			
			const Language* currentLanguage = this;
			while (currentLanguage != nullptr)
			{
				parentPath.push_back(currentLanguage);
				currentLanguage = currentLanguage->parent;
			}

			return parentPath;
		}
	};
}

#endif // DLDL_IR_LANGUAGE_H