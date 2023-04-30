#include "DLDL/IR/Language.h"
#include "DLDL/IR/SpecialDefinition/Threat.h"
#include "Deamer/Deamer.h"

#ifndef DEAMER_CC_V2_RESERVED_MACRO_VALUE_VERSION_NUMBER
#define DEAMER_CC_V2_RESERVED_MACRO_VALUE_VERSION_NUMBER 000'000'000UL
#endif // DEAMER_CC_V2_RESERVED_MACRO_VALUE_VERSION_NUMBER

DLDL::ir::Language::Language(std::string name_, ::deamer::file::tool::OSType os_)
	: name(name_),
	  os(os_)
{
	AddIR(::DLDL::ir::generation::Parser(os).GetDefaultIR());

	auto* defaultIdentity = new special::Identity(name);
	defaultIdentity->SetAsDefaultImplementedByDLDL();

	if constexpr (DEAMER_CC_V2_RESERVED_MACRO_VALUE_VERSION_NUMBER >= 002'001'000UL)
	{
		auto* defaultThreat = new special::Threat();
		defaultThreat->SetAsDefaultImplementedByDLDL();
		AddIR(defaultThreat);
	}

	AddIR(defaultIdentity);
}

DLDL::ir::Language::~Language()
{
	for (auto* child : children)
	{
		delete child;
	}

	for (auto* ir : IRs)
	{
		delete ir;
	}

	for (auto* ir_config : IR_Configs)
	{
		delete ir_config;
	}
}

std::string DLDL::ir::Language::GetName() const
{
	return name;
}

std::vector<std::string> DLDL::ir::Language::GetParents() const
{
	std::vector<std::string> path;
	return GetParents(path);
}

std::vector<std::string> DLDL::ir::Language::GetParents(std::vector<std::string>& current) const
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

void DLDL::ir::Language::FixUnknownReferences()
{
	for (auto* ir : IRs)
	{
		ir->FillInUnknownReferences(this);
	}
}

bool DLDL::ir::Language::DoesIRExist(Type getType) const
{
	return GetIRIfExists(getType) != nullptr;
}

DLDL::ir::IR* DLDL::ir::Language::GetIRIfExists(Type getType) const
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

bool DLDL::ir::Language::DoesIR_ConfigExist(Type getType) const
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

void DLDL::ir::Language::ReplaceIR(IR* ir)
{
	size_t index = 0;
	bool found = false;
	for (auto* ir_ : GetIRs())
	{
		if (ir_->GetType() == ir->GetType())
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

void DLDL::ir::Language::AddIR(std::vector<IR*> newIRs)
{
	for (auto newIr : newIRs)
	{
		AddIR(newIr);
	}
}

void DLDL::ir::Language::AddIR(IR* newIR)
{
	if (newIR == nullptr)
	{
		return;
	}

	if (DoesIRExist(newIR->GetType()))
	{
		ReplaceIR(newIR);
		return;
	}

	IRs.push_back(newIR);
}

void DLDL::ir::Language::AddIR_Config(IR_Config* newConfig)
{
	if (DoesIR_ConfigExist(newConfig->GetType()))
	{
		return;
	}

	IR_Configs.push_back(newConfig);
}

void DLDL::ir::Language::AddLanguage(Language* newLanguage)
{
	newLanguage->parent = this;
	children.push_back(newLanguage);
}

std::vector<DLDL::ir::IR*> DLDL::ir::Language::GetIRs() const
{
	return IRs;
}

std::vector<DLDL::ir::IR_Config*> DLDL::ir::Language::GetIR_Configs() const
{
	return IR_Configs;
}

std::vector<DLDL::ir::LPD> DLDL::ir::Language::GetCurrentLPDs()
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

std::vector<DLDL::ir::Language*> DLDL::ir::Language::GetChildren() const
{
	return children;
}

DLDL::ir::Language* DLDL::ir::Language::GetParent() const
{
	return parent;
}

std::vector<const DLDL::ir::Language*> DLDL::ir::Language::GetParentPath() const
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
