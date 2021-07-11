#ifndef DLDL_IR_LANGUAGE_H
#define DLDL_IR_LANGUAGE_H

#include "DLDL/IR/Type.h"
#include "DLDL_GENERATION/IR/Parser.h"
#include "IR.h"
#include "IR_Config.h"
#include "LPD.h"
#include "SpecialDefinition/Generation.h"
#include "SpecialDefinition/Identity.h"
#include <Deamer/File/Tool/OSType.h>
#include <string>
#include <vector>

namespace DLDL::ir
{
	/*	\class Language
	 *
	 *	\brief Language contains references to its children and parents.
	 *	It also contains information about its own LPD's;
	 */
	class Language
	{
	private:
		std::string name;

		mutable Language* parent = nullptr;
		std::vector<Language*> children;

		// IR and IR_Config combined makes an complete generatable LPD
		std::vector<IR*> IRs;
		std::vector<IR_Config*> IR_Configs;

		::deamer::file::tool::OSType os;

	public:
		// The default os is os_used.
		// The os DLDL is installed on is thus the default os to target.
		Language(std::string name_,
				 ::deamer::file::tool::OSType os_ = ::deamer::file::tool::os_used);

		virtual ~Language();

		Language(const Language&) = delete;
		Language(Language&&) noexcept = delete;

		Language& operator=(const Language&) = delete;
		Language& operator=(Language&&) noexcept = delete;

	public:
		std::string GetName() const;

		std::vector<std::string> GetParents() const;

		std::vector<std::string> GetParents(std::vector<std::string>& current) const;

	public:
		bool DoesIRExist(Type getType) const;

		IR* GetIRIfExists(Type getType) const;

		bool DoesIR_ConfigExist(Type getType) const;

		void ReplaceIR(IR* ir);

		void AddIR(IR* newIR);

		void AddIR_Config(IR_Config* newConfig);

		void AddLanguage(Language* newLanguage);

		std::vector<IR*> GetIRs() const;

		std::vector<IR_Config*> GetIR_Configs() const;

		std::vector<LPD> GetCurrentLPDs();

		std::vector<Language*> GetChildren() const;

		Language* GetParent() const;

		std::vector<const Language*> GetParentPath() const;
	};
}

#endif // DLDL_IR_LANGUAGE_H
