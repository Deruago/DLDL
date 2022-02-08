#include "DLDL_LPDDEF/IR/LPDDEF.h"

static std::vector<std::string> Split(const std::string& str, char split)
{
	std::vector<std::string> out;

	std::string tmp;
	for (auto character : str)
	{
		if (character == split)
		{
			out.push_back(tmp);
			tmp.clear();
		}
		else
		{
			tmp += character;
		}
	}

	return out;
}

std::string DLDL::ir::Function::GetFunctionPrototype() const
{
	for (auto line : Split(function, '\n'))
	{
		bool isComment = false;
		for (auto i : line)
		{
			if (i == ' ' || i == '\t')
			{
				continue;
			}

			if (i == '/')
			{
				isComment = true;
			}
			else
			{
				break;
			}
		}

		if (isComment)
		{
			continue;
		}
		else
		{
			if (!line.empty() && line[line.size() - 1] == '\n')
			{
				line.pop_back();
			}
			return line;
		}
	}

	return "";
}

DLDL::ir::LDO::~LDO()
{
}

void DLDL::ir::LDO::SetName(const std::string& name_)
{
	name = name_;
}

void DLDL::ir::LDO::SetDescription(const std::string& description_)
{
	description = description_;
}

void DLDL::ir::LDO::SetType(const LDOType type_)
{
	type = type_;
}

void DLDL::ir::LDO::SetDataMembers(std::vector<DataMember> dataMembers_)
{
	dataMembers = dataMembers_;
}

std::vector<DLDL::ir::DataMember> DLDL::ir::LDO::GetDataMembers() const
{
	return dataMembers;
}

DLDL::ir::LpdDef* DLDL::ir::LDO::GetLPD() const
{
	return lpdDef;
}

std::vector<DLDL::ir::Function> DLDL::ir::LDO::GetFunction() const
{
	return functions;
}

void DLDL::ir::LDO::SetLPD(::DLDL::ir::LpdDef* lpdDef_)
{
	lpdDef = lpdDef_;
}

void DLDL::ir::LDO::AddFunction(Function function)
{
	functions.push_back(function);
}

std::string DLDL::ir::LDO::GetDescription() const
{
	return description;
}

DLDL::ir::LDOType DLDL::ir::LDO::GetLDOType() const
{
	return type;
}

std::string DLDL::ir::LDO::GetName() const
{
	return name;
}

void DLDL::ir::LpdDef::SetLPDType(LPDType type_)
{
	type = type_;
}

void DLDL::ir::LpdDef::SetLPDName(const std::string& name_)
{
	name = name_;
}

void DLDL::ir::LpdDef::AddLdoForwardDeclaration(std::string ldo)
{
	forwardDeclarations.push_back(ldo);
}

void DLDL::ir::LpdDef::AddDependency(Dependency dependency)
{
	dependencies.push_back(dependency);
}

void DLDL::ir::LpdDef::AddLpdMember(LpdMember lpdMember)
{
	lpdMembers.push_back(lpdMember);
}

void DLDL::ir::LpdDef::AddFunction(Function function)
{
	functions.push_back(function);
}

void DLDL::ir::LpdDef::SetLpdMembers(std::vector<LpdMember> dataMembers_)
{
	lpdMembers = dataMembers_;
}

std::string DLDL::ir::LpdDef::GetName() const
{
	return name;
}

DLDL::ir::LPDType DLDL::ir::LpdDef::GetLPDType() const
{
	return type;
}

std::string DLDL::ir::LpdDef::GetDescription() const
{
	return description;
}

std::vector<std::string> DLDL::ir::LpdDef::GetLdoForwardDeclarations() const
{
	return forwardDeclarations;
}

const std::vector<std::unique_ptr<DLDL::ir::LDO>>& DLDL::ir::LpdDef::GetLDOs() const
{
	return LDOs;
}

std::vector<DLDL::ir::LpdDef::Dependency> DLDL::ir::LpdDef::GetDependencies() const
{
	return dependencies;
}

std::vector<DLDL::ir::LpdMember> DLDL::ir::LpdDef::GetLpdMembers() const
{
	return lpdMembers;
}
#include <iostream>
DLDL::ir::LDO* DLDL::ir::LpdDef::GetLDOFromString(const std::string& LdoName_)
{
	for (auto& ldo : LDOs)
	{
		if (ldo->GetName() == LdoName_)
		{
			return ldo.get();
		}
	}

	return nullptr;
}

std::vector<DLDL::ir::Function> DLDL::ir::LpdDef::GetFunctions() const
{
	return functions;
}

bool DLDL::ir::LpdDef::IsTool() const
{
	return GetLPDType() == LPDType::tool;
}

void DLDL::ir::LpdDef::SetLDOs(std::vector<std::unique_ptr<LDO>> ldos)
{
	LDOs = std::move(ldos);
	for (auto& ldo : LDOs)
	{
		ldo->SetLPD(this);
	}
}

void DLDL::ir::LpdDef::SetDescription(const std::string& description_)
{
	description = description_;
}
