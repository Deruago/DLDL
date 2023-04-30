#include "DLDL_IMPORT/IR/Parser.h"
#include "DLDL_IMPORT/IR/Import.h"

DLDL::ir::import::Parser::Parser(::deamer::file::tool::OSType os_)
	: ::DLDL::ir::Parser(Type::OopSyntax)
{
}

DLDL::ir::IR* DLDL::ir::import::Parser::GetIR(std::string text)
{
	const auto parser = DLDL_IMPORT::bison::parser::Parser();
	auto tree = std::unique_ptr<deamer::external::cpp::ast::Tree>(parser.Parse(text));
	if (tree == nullptr || tree->GetStartNode() == nullptr)
	{
		return new DLDL::ir::Import();
	}

	auto importListener = DLDL_IMPORT::ast::listener::user::Import();
	importListener.Dispatch(tree->GetStartNode());

	auto* importIr = importListener.GetImport();

	return importIr;
}
