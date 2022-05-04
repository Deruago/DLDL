#ifndef DLDL_IR_SPECIALDEFINITION_GENERATION_H
#define DLDL_IR_SPECIALDEFINITION_GENERATION_H

#include "DLDL/IR/IR.h"
#include <Deamer/File/Tool/OSType.h>
#include <string>
#include <vector>

namespace DLDL::ir::special
{
	struct Argument
	{
		std::string argumentName;

		Argument(std::string argumentName_);
		~Argument() = default;

		std::string GetArgumentName() const;

		std::string GetArgumentNameUnderscored() const;
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

		Tool(const char* name_, ToolType type_ = ToolType::User);
		Tool(std::string name_, ToolType type_ = ToolType::User);
		~Tool() = default;
	};

	class Generation : public IR
	{
	private:
		::deamer::file::tool::OSType os;

		std::vector<Tool> tools;

	public:
		Generation(::deamer::file::tool::OSType os_ = ::deamer::file::tool::os_used);
		~Generation() override = default;

	public:
		void AddTool(Tool tool);

		Tool& GetTool(const std::string& name);

		bool DoesToolExist(const std::string& toolName);

		void AddIntegration(std::string toolName, std::string targetToolName);

		void AddArgument(std::string toolName, std::string argumentName);

		std::vector<Tool> GetTools() const;

		deamer::file::tool::OSType GetOs() const;

		void FillInUnknownReferences(DLDL::ir::Language* language) override;
	};
}

#endif // DLDL_IR_SPECIALDEFINITION_GENERATION_H
