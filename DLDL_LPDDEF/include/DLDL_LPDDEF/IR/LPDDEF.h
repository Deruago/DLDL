#ifndef DLDL_LPDDEF_IR_LPDDEF_H
#define DLDL_LPDDEF_IR_LPDDEF_H

#include "DLDL/IR/IR.h"
#include <string>
#include <vector>

namespace DLDL::ir
{
	struct LDO
	{
		std::vector<std::string> namespaces;
		std::string name;
	};

	enum class LPDType
	{
		unknown = 0,

		main,
		special,
		tool,
	};

	class LpdDef : public DLDL::ir::IR
	{
	private:
		std::vector<LDO> forwardDeclaration;
		LPDType type = LPDType::unknown;
		std::string name;
		std::string description;

	public:
		LpdDef() : IR(Type::LpdDef)
		{
		}

	public:
		void SetLPDType(LPDType type_);
		void SetLPDName(const std::string& name_);
		void SetDescription(const std::string& description_);

		void AddLdoForwardDeclaration(LDO ldo);

	public:
		std::string GetName() const;
		LPDType GetLPDType() const;
		std::string GetDescription() const;
		std::vector<LDO> GetForwardDeclarations() const;
	};
}

#endif // DLDL_LPDDEF_IR_LPDDEF_H
