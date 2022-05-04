#ifndef DLDL_IR_PARSER_H
#define DLDL_IR_PARSER_H

#include "DLDL/IR/IR.h"
#include "DLDL/IR/Type.h"
#include <string>

namespace DLDL::ir
{
	class Parser
	{
	private:
		Type type;
	public:
		Parser(Type type_)
			: type(type_)
		{
		}
		virtual ~Parser() = default;
	public:
		Type GetType() const
		{
			return type;
		}

		virtual DLDL::ir::IR* GetIR(std::string text) = 0;
	};
}

#endif // DLDL_IR_PARSER_H