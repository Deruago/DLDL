#ifndef DLDL_IR_PARSER_H
#define DLDL_IR_PARSER_H

#include "DLDL/IR/IR.h"
#include "DLDL/IR/Type.h"
#include <string>
#include <vector>

namespace DLDL::ir
{
	class Parser
	{
	private:
		Type type;

	public:
		Parser(Type type_) : type(type_)
		{
		}
		virtual ~Parser() = default;

	public:
		Type GetType() const
		{
			return type;
		}

		virtual DLDL::ir::IR* GetIR(std::string text)
		{
			return nullptr;
		}

		virtual std::vector<DLDL::ir::IR*> GetIRs(std::string text)
		{
			return {GetIR(text)};
		}
	};
}

#endif // DLDL_IR_PARSER_H
