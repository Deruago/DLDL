#include "DLDL_OOPSYNTAX/IR/Parser.h"
#include "DLDL_OOPSYNTAX/IR/OopSyntax.h"

DLDL::ir::oopsyntax::Parser::Parser(::deamer::file::tool::OSType os_)
	: ::DLDL::ir::Parser(Type::OopSyntax)
{
}

DLDL::ir::IR* DLDL::ir::oopsyntax::Parser::GetIR(std::string text)
{
	const auto parser = DLDL_OOPSYNTAX::bison::parser::Parser();
	auto tree = std::unique_ptr<deamer::external::cpp::ast::Tree>(parser.Parse(text));
	if (tree == nullptr || tree->GetStartNode() == nullptr)
	{
		return new DLDL::ir::OopSyntax();
	}

	auto oopSyntaxListener = DLDL_OOPSYNTAX::ast::listener::user::OopSyntax();
	oopSyntaxListener.Dispatch(tree->GetStartNode());

	auto* oopSyntaxIr = oopSyntaxListener.GetOopSyntax();

	return oopSyntaxIr;
}
