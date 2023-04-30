#include "DLDL_ARGUMENT/IR/Parser.h"
#include "DLDL_ARGUMENT/IR/Argument.h"

DLDL::ir::argument::Parser::Parser(::deamer::file::tool::OSType os_)
	: ::DLDL::ir::Parser(Type::OopSyntax)
{
}

DLDL::ir::IR* DLDL::ir::argument::Parser::GetIR(std::string text)
{
	const auto parser = DLDL_ARGUMENT::bison::parser::Parser();
	auto tree = std::unique_ptr<deamer::external::cpp::ast::Tree>(parser.Parse(text));
	if (tree == nullptr || tree->GetStartNode() == nullptr)
	{
		return new DLDL::ir::Argument();
	}

	auto argumentListener = DLDL_ARGUMENT::ast::listener::user::Argument();
	argumentListener.Dispatch(tree->GetStartNode());

	auto* argumentIr = argumentListener.GetArgument();

	return argumentIr;
}
