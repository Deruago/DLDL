#include "DLDL_COMMENT/IR/Parser.h"
#include "DLDL_COMMENT/IR/Comment.h"

DLDL::ir::comment::Parser::Parser(::deamer::file::tool::OSType os_)
	: ::DLDL::ir::Parser(Type::OopSyntax)
{
}

DLDL::ir::IR* DLDL::ir::comment::Parser::GetIR(std::string text)
{
	const auto parser = DLDL_COMMENT::bison::parser::Parser();
	auto tree = std::unique_ptr<deamer::external::cpp::ast::Tree>(parser.Parse(text));
	if (tree == nullptr || tree->GetStartNode() == nullptr)
	{
		return new DLDL::ir::Comment();
	}

	auto commentListener = DLDL_COMMENT::ast::listener::user::Comment();
	commentListener.Dispatch(tree->GetStartNode());

	auto* commentIr = commentListener.GetComment();

	return commentIr;
}
