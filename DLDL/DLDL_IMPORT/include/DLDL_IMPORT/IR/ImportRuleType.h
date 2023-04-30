#ifndef DLDL_IMPORT_IR_IMPORTRULETYPE_H
#define DLDL_IMPORT_IR_IMPORTRULETYPE_H

#include <memory>
#include <vector>

namespace DLDL::ir
{
	enum class ImportRuleType
	{
		Unknown,

		FileImport,
		FileObjectImport, // Import an Specific set of Objects from a specific File

		ModuleImport,
		ModuleObjectImport,

		FileModuleImport,
		FileModuleObjectImport,
	};
}

#endif // DLDL_IMPORT_IR_IMPORTRULETYPE_H
