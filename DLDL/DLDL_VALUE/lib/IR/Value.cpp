#include "DLDL_VALUE/IR/Value.h"

DLDL::ir::Value::Value() : IR(Type::Value)
{
}

void DLDL::ir::Value::AddValueCharacteristic(
	std::unique_ptr<ValueCharacteristic> valueCharacteristic)
{
	valueCharacteristics.push_back(std::move(valueCharacteristic));
}

void DLDL::ir::Value::AddValueRule(std::unique_ptr<ValueRule> valueRule)
{
	valueRules.push_back(std::move(valueRule));
}

void DLDL::ir::Value::AddValueAbstraction(std::unique_ptr<ValueAbstraction> valueAbstraction)
{
	valueAbstractions.push_back(std::move(valueAbstraction));
}

std::vector<DLDL::ir::ValueCharacteristic*> DLDL::ir::Value::GetValueCharacteristics()
{
	std::vector<DLDL::ir::ValueCharacteristic*> result;
	for (auto& i : valueCharacteristics)
	{
		result.push_back(i.get());
	}
	return result;
}

std::vector<DLDL::ir::ValueRule*> DLDL::ir::Value::GetValueRules()
{
	std::vector<DLDL::ir::ValueRule*> result;
	for (auto& i : valueRules)
	{
		result.push_back(i.get());
	}
	return result;
}

std::vector<DLDL::ir::ValueAbstraction*> DLDL::ir::Value::GetValueAbstractions()
{
	std::vector<DLDL::ir::ValueAbstraction*> result;
	for (auto& i : valueAbstractions)
	{
		result.push_back(i.get());
	}
	return result;
}

std::optional<std::string>
DLDL::ir::Value::GetValueRuleViaNTerminal(const std::vector<std::string>& nterminals)
{
	for (auto& valueCharacteristic : valueCharacteristics)
	{
		if (valueCharacteristic->GetSyntacticContexts() == nterminals)
		{
			return valueCharacteristic->GetRuleName();
		}
	}

	for (auto& valueRule : valueRules)
	{
		if (valueRule->GetSyntacticContexts() == nterminals)
		{
			return valueRule->GetRuleName();
		}
	}

	return std::nullopt;
}
