#ifndef DLDL_VALUE_IR_VALUE_H
#define DLDL_VALUE_IR_VALUE_H

#include "DLDL/IR/IR.h"
#include "DLDL_VALUE/IR/ValueAbstraction.h"
#include "DLDL_VALUE/IR/ValueCharacteristic.h"
#include "DLDL_VALUE/IR/ValueRule.h"
#include <deque>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace DLDL::ir
{
	class Value : public DLDL::ir::IR
	{
	private:
		std::vector<std::unique_ptr<ValueRule>> valueRules;
		std::vector<std::unique_ptr<ValueCharacteristic>> valueCharacteristics;
		std::vector<std::unique_ptr<ValueAbstraction>> valueAbstractions;

	public:
		Value();

	public:
		void AddValueCharacteristic(std::unique_ptr<ValueCharacteristic> valueCharacteristic);
		void AddValueRule(std::unique_ptr<ValueRule> valueRule);
		void AddValueAbstraction(std::unique_ptr<ValueAbstraction> valueAbstraction);

	public:
		std::vector<ValueCharacteristic*> GetValueCharacteristics();
		std::vector<ValueRule*> GetValueRules();
		std::vector<ValueAbstraction*> GetValueAbstractions();

	public:
		std::optional<std::string>
		GetValueRuleViaNTerminal(const std::vector<std::string>& nterminals);
	};
}

#endif // DLDL_VALUE_IR_VALUE_H
