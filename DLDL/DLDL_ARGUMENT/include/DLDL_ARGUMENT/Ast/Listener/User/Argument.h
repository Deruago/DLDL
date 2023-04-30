#ifndef DLDL_ARGUMENT_AST_LISTENER_USER_ARGUMENT_H
#define DLDL_ARGUMENT_AST_LISTENER_USER_ARGUMENT_H

#include "DLDL_ARGUMENT/Ast/Listener/EnterExitListener.h"
#include "DLDL_ARGUMENT/Ast/Reference/Access.h"
#include "DLDL_ARGUMENT/IR/Argument.h"

namespace DLDL_ARGUMENT::ast::listener::user
{
	class Argument : public ::DLDL_ARGUMENT::ast::listener::EnterExitListener
	{
	private:
		DLDL::ir::Argument* ArgumentLpd;

	public:
		Argument()
		{
			ArgumentLpd = new ::DLDL::ir::Argument();
		}
		~Argument() override = default;

	public:
	public:
		DLDL::ir::Argument* GetArgument()
		{
			return ArgumentLpd;
		}
	};
}

#endif // DLDL_ARGUMENT_AST_LISTENER_USER_ARGUMENT_H
