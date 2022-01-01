#ifndef DLDL_LPDDEF_IR_PARSER_H
#define DLDL_LPDDEF_IR_PARSER_H

#include "DLDL/IR/Parser.h"
#include "DLDL_LPDDEF/Ast/Listener/User/LpdDef.h"
#include "DLDL_LPDDEF/Bison/Parser.h"
#include <memory>
#include <string>

namespace DLDL::ir::lpddef
{
	class Parser : public ::DLDL::ir::Parser
	{
	public:
		Parser() : ::DLDL::ir::Parser(Type::LpdDef)
		{
		}

	public:
		DLDL::ir::IR* GetIR(std::string text) override
		{
			const auto parser = DLDL_LPDDEF::parser::Parser();
			auto tree = std::unique_ptr<deamer::external::cpp::ast::Tree>(parser.Parse(text));
			if (tree == nullptr || tree->GetStartNode() == nullptr)
			{
				return new DLDL::ir::LpdDef();
			}

			auto lpdDefListener = DLDL_LPDDEF::ast::listener::user::LpdDef();

			lpdDefListener.Dispatch(tree->GetStartNode());

			auto* lpdDefIr = lpdDefListener.GetLpdDef();

			return lpdDefIr;
		}
	};
}

#endif // DLDL_LPDDEF_IR_PARSER_H
