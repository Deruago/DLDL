#include "DLDL_VALUE/IR/ValueAbstraction.h"

DLDL::ir::ValueAbstraction::ValueAbstraction(const std::string& abstractionName_,
											 std::size_t abstractionId_,
											 const std::string& abstractionValue_)
	: abstractionName(abstractionName_),
	  abstractionId(abstractionId_),
	  abstractionValue(abstractionValue_)
{
	if (abstractionValue.size() >= 2)
	{
		if (abstractionValue[0] == '@')
		{
			abstractionValue.erase(0, 2);
			abstractionValue.pop_back();
			abstractionValue.pop_back();
		}
		else if (abstractionValue[0] == '\'' || abstractionValue[0] == '"')
		{
			abstractionValue.erase(0, 1);
			abstractionValue.pop_back();
		}
	}

	std::string lowered_string;
	for (auto character : abstractionName)
	{
		if (std::isalpha(character))
		{
			lowered_string.push_back(std::tolower(character));
		}
		else
		{
			lowered_string.push_back(character);
		}
	}

	if (lowered_string == "isstring")
	{
		abstractionType = ValueAbstractionType::IsString;
	}
	else if (lowered_string == "isvector")
	{
		abstractionType = ValueAbstractionType::IsVector;
	}
	else if (lowered_string == "isinteger")
	{
		abstractionType = ValueAbstractionType::IsInteger;
	}
	else if (lowered_string == "isdecimal")
	{
		abstractionType = ValueAbstractionType::IsDecimal;
	}
	else if (lowered_string == "isvalue")
	{
		abstractionType = ValueAbstractionType::IsValue;
	}
	else if (lowered_string == "wildcard")
	{
		abstractionType = ValueAbstractionType::Wildcard;
	}
	else if (lowered_string == "start")
	{
		abstractionType = ValueAbstractionType::Start;
	}
	else if (lowered_string == "end")
	{
		abstractionType = ValueAbstractionType::End;
	}
	else if (lowered_string == "escape" || lowered_string == "escapesequence" ||
			 lowered_string == "escape_sequence")
	{
		abstractionType = ValueAbstractionType::Escape;
	}
	else
	{
		abstractionType = ValueAbstractionType::Unknown;
	}
}

void DLDL::ir::ValueAbstraction::AddUnderlyingAbstraction(ValueAbstraction* underlyingAbstraction)
{
	underlyingAbstractions.push_back(underlyingAbstraction);
}

DLDL::ir::ValueAbstractionType DLDL::ir::ValueAbstraction::GetValueAbstractionType()
{
	return abstractionType;
}

std::string DLDL::ir::ValueAbstraction::GetAbstractionName()
{
	return abstractionName;
}

std::size_t DLDL::ir::ValueAbstraction::GetAbstractionId()
{
	return abstractionId;
}

std::vector<DLDL::ir::ValueAbstraction*> DLDL::ir::ValueAbstraction::GetUnderlyingAbstractions()
{
	return underlyingAbstractions;
}

std::string DLDL::ir::ValueAbstraction::GetAbstractionValue()
{
	std::string newValue;
	for (char character : abstractionValue)
	{
		switch (character)
		{
		case '\n': {
			newValue += "\\n";
			break;
		}
		case '\r': {
			newValue += "\\r";
			break;
		}
		case '\t': {
			newValue += "\\t";
			break;
		}
		case '\f': {
			newValue += "\\f";
			break;
		}
		case '\v': {
			newValue += "\\v";
			break;
		}
		default: {
			newValue += character;
			break;
		}
		}
	}
	return newValue;
}
