#ifndef DLDL_IR_LPD_H
#define DLDL_IR_LPD_H

#include "DLDL/IR/IR.h"
#include "DLDL/IR/IR_Config.h"

namespace DLDL::ir
{
	class Language;

	class LPD
	{
	private:
		IR* ir;
		IR_Config* config;
	public:
		LPD(IR* ir_, IR_Config* config_)
			: ir(ir_),
		      config(config_)
		{
		}
	public:
		std::string GetLPDName() const
		{
			return "test";
		}

		Type GetType() const
		{
			return ir->GetType();
		}

		IR* GetIR() const
		{
			return ir;
		}

		IR_Config* GetIR_Config() const
		{
			return config;
		}
	};
}

#endif // DLDL_IR_LPD_H