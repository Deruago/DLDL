#ifndef DLDL_IR_SPECIALDEFINITION_GENERATION_H
#define DLDL_IR_SPECIALDEFINITION_GENERATION_H


#include "DLDL/IR/IR.h"
#include <Deamer/File/Tool/OSType.h>
#include <stdexcept>
#include <string>
#include <vector>

namespace DLDL::ir::special
{
	struct Argument
	{
		std::string argumentName;

		Argument(std::string argumentName_)
			: argumentName(argumentName_)
		{
		}

		std::string GetArgumentName() const
		{
			return argumentName;
		}
		
		std::string GetArgumentNameUnderscored() const
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
	};

	enum class ToolType
	{
		Lexer,
		Parser,
		User,
		Ast,
	};
	
	struct Tool
	{
		std::string name;
		std::vector<Tool> integrations;
		std::vector<Argument> arguments;
		std::string path;
		std::string namespace_;
		ToolType type;

		Tool(const char* name_, ToolType type_ = ToolType::User)
			: name(name_), type(type_)
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
				break;
			default:
				break;
			}

			path += name + "/" + name + ".h";
		}
		
		Tool(std::string name_, ToolType type_ = ToolType::User)
			: Tool(name_.c_str(), type_)
		{
		}
	};
	
	class Generation : public IR
	{
	private:
		::deamer::file::tool::OSType os;
		
		std::vector<Tool> tools;
	public:
		Generation(::deamer::file::tool::OSType os_ = ::deamer::file::tool::os_used) : IR(Type::Generation), os(os_)
		{
		}
		
		~Generation() override = default;
	public:
		void AddTool(Tool tool)
		{
			tools.push_back(tool);
		}

		Tool& GetTool(const std::string& name)
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

		bool DoesToolExist(const std::string& toolName)
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

		void AddIntegration(std::string toolName, std::string targetToolName)
		{
			if (!DoesToolExist(toolName))
			{
				AddTool(toolName);
			}

			GetTool(toolName).integrations.emplace_back(targetToolName);
		}

		void AddArgument(std::string toolName, std::string argumentName)
		{
			if (!DoesToolExist(toolName))
			{
				AddTool(toolName);
			}

			GetTool(toolName).arguments.emplace_back(argumentName);
		}

		std::vector<Tool> GetTools() const
		{
			return tools;
		}

		deamer::file::tool::OSType GetOs() const
		{
			return os;
		}
	};
}

#endif // DLDL_IR_SPECIALDEFINITION_GENERATION_H