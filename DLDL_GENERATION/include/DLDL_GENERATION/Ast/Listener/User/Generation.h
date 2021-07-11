#ifndef DLDL_GENERATION_AST_LISTENER_USER_GENERATION_H
#define DLDL_GENERATION_AST_LISTENER_USER_GENERATION_H

#include "DLDL_GENERATION/Ast/Listener/Listener.h"
#include "DLDL/IR/SpecialDefinition/Generation.h"

namespace DLDL_GENERATION::ast::listener::user
{
	class Generation : public ::DLDL_GENERATION::ast::listener::Listener
	{
	private:
		DLDL::ir::special::Generation* generation;

	public:
		Generation(deamer::file::tool::OSType os_)
		{
			generation = new ::DLDL::ir::special::Generation(os_);
		}
		~Generation() override = default;

	public:
		::DLDL::ir::special::ToolType GetGenerationType(const std::string& text) const
		{
			std::string text_lowered;
			for (const auto& character : text)
			{
				text_lowered += ::tolower(character);
			}

			if (text_lowered == "lexer")
			{
				return ::DLDL::ir::special::ToolType::Lexer;
			}

			if (text_lowered == "grammar" || text_lowered == "parser")
			{
				return ::DLDL::ir::special::ToolType::Parser;
			}

			if (text_lowered == "ast")
			{
				return ::DLDL::ir::special::ToolType::Ast;
			}

			return ::DLDL::ir::special::ToolType::User;
		}

		void Listen(const DLDL_GENERATION::ast::node::generate_declaration* node) override
		{
			const auto firstTool = node->Get(::DLDL_GENERATION::ast::Type::tool)[0]->GetChildValue();
			const auto toolType = GetGenerationType(node->Get(::DLDL_GENERATION::ast::Type::type)[0]->GetChildValue());
			generation->AddTool({ firstTool, toolType });
		}

		void Listen(const DLDL_GENERATION::ast::node::integrate_declaration* node) override
		{
			const auto sourceTool = node->Get(::DLDL_GENERATION::ast::Type::tool)[0]->GetChildValue();
			const auto targetTool = node->Get(::DLDL_GENERATION::ast::Type::tool)[1]->GetChildValue();
			generation->AddIntegration(sourceTool, targetTool);
		}

		std::string currentTool;
		void Listen(const DLDL_GENERATION::ast::node::argument_declaration* node) override
		{
			currentTool = node->Get(::DLDL_GENERATION::ast::Type::tool)[0]->GetChildValue();
		}
		void Listen(const DLDL_GENERATION::ast::node::argument_data* node) override
		{
			const auto currentValue = node->Get(::DLDL_GENERATION::ast::Type::VALUE)[0]->GetChildValue();
			generation->AddArgument(currentTool, currentValue);
		}

		DLDL::ir::special::Generation* GetGeneration() const
		{
			return generation;
		}
	};
}

#endif // DLDL_GENERATION_AST_LISTENER_USER_GENERATION_H
