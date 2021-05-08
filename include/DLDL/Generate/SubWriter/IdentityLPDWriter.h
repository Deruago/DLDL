#ifndef DLDL_GENERATE_SUBWRITER_IDENTITYLPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_IDENTITYLPDWRITER_H

#include "DLDL/Generate/SubWriter.h"
#include "DLDL/Template/Definition/Identity/IdentityTemplate.h"

namespace DLDL::generate::sub
{
	class IdentityLPDWriter : public SubWriter
	{
	public:
		IdentityLPDWriter() = default;
	public:
		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language, const ir::LPD& lpd) override
		{
			deamer::file::tool::File file("Identity", "h", "");

			auto* identity = static_cast<ir::special::Identity*>(lpd.GetIR());

			auto generator = DLDL::filetemplate::IdentityTemplate();
			
			FillInDefaultVariablesInConstruction(generator, language);

			if (!identity->IsDefaultImplementedByDLDL())
			{
				generator.identity_name_->Set(identity->GetName());
			}

			file.SetFileContent(generator.GetOutput());

			return file;
		}

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language, const ir::LPD& lpd) override
		{
			deamer::file::tool::File file("Identity", "cpp", "");

			return file;
		}
	};
}

#endif // DLDL_GENERATE_SUBWRITER_IDENTITYLPDWRITER_H