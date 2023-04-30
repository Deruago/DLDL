#ifndef DLDL_VALUE_IR_VALUEABSTRACTION_H
#define DLDL_VALUE_IR_VALUEABSTRACTION_H

#include "DLDL_VALUE/IR/ValueAbstractionType.h"
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace DLDL::ir
{
	class ValueAbstraction
	{
	private:
		ValueAbstractionType abstractionType = ValueAbstractionType::Unknown;
		std::string abstractionName;
		std::vector<ValueAbstraction*> underlyingAbstractions;
		std::size_t abstractionId;
		std::string abstractionValue;

	public:
		ValueAbstraction(const std::string& abstractionName_, std::size_t abstractionId_,
						 const std::string& abstractionValue_);

	public:
		void AddUnderlyingAbstraction(ValueAbstraction* underlyingAbstraction);

	public:
		ValueAbstractionType GetValueAbstractionType();
		std::string GetAbstractionName();
		std::size_t GetAbstractionId();
		std::vector<ValueAbstraction*> GetUnderlyingAbstractions();

		// Returns displayed value
		std::string GetAbstractionValue();
	};
}

#endif // DLDL_VALUE_IR_VALUEABSTRACTION_H
