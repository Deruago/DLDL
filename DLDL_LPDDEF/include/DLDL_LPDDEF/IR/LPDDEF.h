#ifndef DLDL_LPDDEF_IR_LPDDEF_H
#define DLDL_LPDDEF_IR_LPDDEF_H

#include "DLDL/IR/IR.h"
#include <memory>
#include <string>
#include <vector>

namespace DLDL::ir
{
	class LpdDef;

	enum class LDOType
	{
		unknown = 0,

		Ldo,
		Struct,
		Enumeration,
	};

	struct DataMember
	{
		// if Empty no explicit LPD is given. Otherwise check for corresponding LPD
		std::string explicitLPD;
		std::string comments;
		std::string name;
		std::string type;
		std::string defaultValue;

		bool optional = false;
		bool variadic = false;
	};

	struct Function
	{
		std::string function;

		std::string GetFunctionPrototype() const;
	};

	struct LDO
	{
		struct UniqueField
		{
			std::vector<DataMember*> datamembers;
		};

		std::string name;
		std::string description;
		std::vector<DataMember> dataMembers;
		std::vector<Function> functions;
		std::vector<UniqueField> uniqueFields;
		LDOType type;
		LpdDef* lpdDef;
		bool Generate = true;

		~LDO();

	public:
		void SetName(const std::string& name_);
		void SetDescription(const std::string& description_);
		void SetType(const LDOType type_);
		void SetDataMembers(std::vector<DataMember> dataMembers_);
		void SetLPD(::DLDL::ir::LpdDef* lpdDef_);
		void AddFunction(Function function);

	public:
		std::string GetDescription() const;
		LDOType GetLDOType() const;
		std::string GetName() const;
		std::vector<DataMember> GetDataMembers() const;
		LpdDef* GetLPD() const;
		std::vector<Function> GetFunction() const;
	};

	enum class LPDType
	{
		unknown = 0,

		main,
		special,
		tool,
	};

	using LpdMember = DataMember;

	class LpdDef : public DLDL::ir::IR
	{
	public:
		struct Dependency
		{
			std::string Lpd;
		};

	private:
		std::vector<std::string> forwardDeclarations;
		std::vector<std::unique_ptr<DLDL::ir::LDO>> LDOs;
		std::vector<LpdMember> lpdMembers;
		std::vector<Function> functions;
		LPDType type = LPDType::unknown;
		std::string name;
		std::string description;
		std::vector<Dependency> dependencies;

	public:
		bool Generate = true;
		bool Explicit = false;

	public:
		LpdDef() : IR(Type::LpdDef)
		{
		}

	public:
		void SetLPDType(LPDType type_);
		void SetLPDName(const std::string& name_);
		void SetDescription(const std::string& description_);
		void SetLDOs(std::vector<std::unique_ptr<LDO>> ldos);

		void AddLdoForwardDeclaration(std::string ldo);
		void AddDependency(Dependency dependency);
		void AddLpdMember(LpdMember lpdMember);
		void AddFunction(Function function);
		void SetLpdMembers(std::vector<LpdMember> dataMembers_);

	public:
		std::string GetName() const;
		LPDType GetLPDType() const;
		std::string GetDescription() const;
		std::vector<std::string> GetLdoForwardDeclarations() const;
		const std::vector<std::unique_ptr<DLDL::ir::LDO>>& GetLDOs() const;
		std::vector<Dependency> GetDependencies() const;
		std::vector<LpdMember> GetLpdMembers() const;
		LDO* GetLDOFromString(const std::string& LdoName_);
		std::vector<Function> GetFunctions() const;
		bool IsTool() const;
	};

	struct LPDProject
	{
		std::vector<std::unique_ptr<LpdDef>> LPDs;

		void AddLPD(std::unique_ptr<LpdDef> LPD)
		{
			LPDs.push_back(std::move(LPD));
		}

		const std::vector<std::unique_ptr<LpdDef>>& GetLPDs() const
		{
			return LPDs;
		}
	};
}

#endif // DLDL_LPDDEF_IR_LPDDEF_H
