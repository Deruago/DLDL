#ifndef DLDL_GENERATE_LPDWRITER_H
#define DLDL_GENERATE_LPDWRITER_H

#include "DLDL/IR/Language.h"
#include "DLDL/Template/CMakeLists/CMakeListsTemplate.h"
#include "DLDL/Template/CompilerGenerator/compilergeneratorTemplate.h"
#include "DLDL/Template/Language/languageTemplate.h"
#include "DLDL/Template/Main/MainTemplate.h"
#include "LPDSubWriterFactory.h"
#include <Deamer/File/Tool/File.h>

namespace DLDL::generate
{
	class LPDWriter : public SubWriter
	{
	private:
	public:
		LPDWriter() = default;
		virtual ~LPDWriter() override = default;

	public:
		static deamer::file::tool::File GetLanguage(ir::Language* language);

		static deamer::file::tool::File GetCompilerGenerator(ir::Language* language);

		static deamer::file::tool::File GetMain(const std::vector<ir::Language*>& languages);

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language,
		                                                  const ir::LPD& lpd) override;

		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language,
		                                                  const ir::LPD& lpd) override;

		static std::string GetTextFromIREnum(ir::Type type);

		static deamer::file::tool::File GetCMakeLists(const std::vector<ir::Language*>& languages);
	};
}

#endif // DLDL_GENERATE_LPDWRITER_H
