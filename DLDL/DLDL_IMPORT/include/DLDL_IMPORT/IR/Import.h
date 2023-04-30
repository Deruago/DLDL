#ifndef DLDL_IMPORT_IR_IMPORT_H
#define DLDL_IMPORT_IR_IMPORT_H

#include "DLDL/IR/IR.h"
#include "DLDL_IMPORT/IR/ImportRule.h"
#include <deque>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace DLDL::ir
{
	class Import : public DLDL::ir::IR
	{
	private:
		std::vector<std::unique_ptr<ImportRule>> importRules;

	public:
		Import();
		virtual ~Import() = default;

	public:
		void AddImportRule(std::unique_ptr<ImportRule> importRule_);

	public:
		std::vector<ImportRule*> GetImportRules();
	};
}

#endif // DLDL_IMPORT_IR_IMPORT_H
