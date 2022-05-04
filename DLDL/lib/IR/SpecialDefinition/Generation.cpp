#include "DLDL/IR/SpecialDefinition/Generation.h"
#include "DLDL/IR/Language.h"
#include <stdexcept>

DLDL::ir::special::Argument::Argument(std::string argumentName_) : argumentName(argumentName_)
{
}

std::string DLDL::ir::special::Argument::GetArgumentName() const
{
	return argumentName;
}

std::string DLDL::ir::special::Argument::GetArgumentNameUnderscored() const
{
	std::string argumentNameReworked;
	for (auto character : argumentName)
	{
		switch (character)
		{
		case ' ':
		case '\n':
		case '\t':
		case '\r':
		case '-':
		case '+':
			argumentNameReworked += '_';
			break;
		default:
			argumentNameReworked += character;
			break;
		}
	}

	return argumentNameReworked;
}

DLDL::ir::special::Tool::Tool(const char* name_, ToolType type_) : name(name_), type(type_)
{
	switch (type)
	{
	case ToolType::Lexer:
		path = "Deamer/Lexer/Generator/";
		namespace_ = "::deamer::lexer::generator";
		break;
	case ToolType::Parser:
		path = "Deamer/Parser/Generator/";
		namespace_ = "::deamer::parser::generator";
		break;
	case ToolType::Ast:
		path = "Deamer/Ast/Generation/";
		namespace_ = "::deamer::ast::generation";
		break;
	case ToolType::User:
		path = "Deamer/Tool/Type/";
		namespace_ = "::deamer::tool::type";
		break;
	default:
		break;
	}

	path += name + "/" + name + ".h";
}

DLDL::ir::special::Tool::Tool(std::string name_, ToolType type_) : Tool(name_.c_str(), type_)
{
}

DLDL::ir::special::Generation::Generation(::deamer::file::tool::OSType os_)
	: IR(Type::Generation),
	  os(os_)
{
}

void DLDL::ir::special::Generation::AddTool(Tool tool)
{
	tools.push_back(tool);
}

DLDL::ir::special::Tool& DLDL::ir::special::Generation::GetTool(const std::string& name)
{
	for (auto& tool : tools)
	{
		if (tool.name == name)
		{
			return tool;
		}
	}

	throw std::logic_error("Requested tool does not exist!");
}

bool DLDL::ir::special::Generation::DoesToolExist(const std::string& toolName)
{
	for (auto& tool : tools)
	{
		if (tool.name == toolName)
		{
			return true;
		}
	}

	return false;
}

void DLDL::ir::special::Generation::AddIntegration(std::string toolName, std::string targetToolName)
{
	if (!DoesToolExist(toolName))
	{
		AddTool(toolName);
	}

	GetTool(toolName).integrations.emplace_back(targetToolName);
}

void DLDL::ir::special::Generation::AddArgument(std::string toolName, std::string argumentName)
{
	if (!DoesToolExist(toolName))
	{
		AddTool(toolName);
	}

	GetTool(toolName).arguments.emplace_back(argumentName);
}

std::vector<DLDL::ir::special::Tool> DLDL::ir::special::Generation::GetTools() const
{
	return tools;
}

deamer::file::tool::OSType DLDL::ir::special::Generation::GetOs() const
{
	return os;
}

void DLDL::ir::special::Generation::FillInUnknownReferences(DLDL::ir::Language* language)
{
	if (!IsDefaultImplementedByDLDL())
	{
		return;
	}

	if (language->DoesIRExist(Type::OopSyntax))
	{
		AddTool("OopSyntaxRecognizer");
	}
}
