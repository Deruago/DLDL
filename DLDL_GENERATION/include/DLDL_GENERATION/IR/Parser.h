#ifndef DLDL_GENERATION_IR_PARSER_H
#define DLDL_GENERATION_IR_PARSER_H

#include "DLDL/IR/Parser.h"
#include "DLDL_GENERATION/Ast/Listener/User/Generation.h"
#include "DLDL_GENERATION/Bison/Parser.h"
#include <memory>
#include <string>

namespace DLDL::ir::generation
{
	class Parser : public ::DLDL::ir::Parser
	{
	private:
		deamer::file::tool::OSType os;

	public:
		Parser(::deamer::file::tool::OSType os_) : ::DLDL::ir::Parser(Type::Generation), os(os_)
		{
		}

	public:
		DLDL::ir::IR* GetDefaultIR() const
		{
			auto* defaultGeneration = new special::Generation(os);
			defaultGeneration->SetAsDefaultImplementedByDLDL();

			// This is the tool for DeamerAst with C++ as target.
			defaultGeneration->AddTool({"CPP", special::ToolType::Ast});

			defaultGeneration->AddTool({"Flex", special::ToolType::Lexer});
			defaultGeneration->AddIntegration("Flex", "Bison");
			defaultGeneration->AddIntegration("Flex", "DeamerAST");
			defaultGeneration->AddArgument("Flex", "Output-terminal-objects");
			// defaultGeneration->AddArgument("Flex", "Debug");
			defaultGeneration->AddTool({"Bison", special::ToolType::Parser});
			defaultGeneration->AddIntegration("Bison", "DeamerAST");
			defaultGeneration->AddArgument("Bison", "Declare-deleted-terminals");

			defaultGeneration->AddTool({"DeamerDefaultApplication", special::ToolType::User});
			

			return defaultGeneration;
		}

		DLDL::ir::IR* GetIR(std::string text) override
		{
			if (text.empty())
			{
				return GetDefaultIR();
			}

			const auto parser = DLDL_GENERATION::parser::Parser();
			auto tree = std::unique_ptr<deamer::external::cpp::ast::Tree>(parser.Parse(text));
			if (tree == nullptr || tree->GetStartNode() == nullptr)
			{
				return GetDefaultIR();
			}

			auto generationListener = DLDL_GENERATION::ast::listener::user::Generation(os);
			generationListener.Dispatch(tree->GetStartNode());

			auto* generationIr = generationListener.GetGeneration();

			return generationIr;
		}
	};
}

#endif // DLDL_GENERATION_IR_PARSER_H
