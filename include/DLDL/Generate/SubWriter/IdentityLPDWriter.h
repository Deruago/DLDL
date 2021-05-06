#ifndef DLDL_GENERATE_SUBWRITER_IDENTITYLPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_IDENTITYLPDWRITER_H

#include "DLDL/Generate/SubWriter.h"
#include "DST/User/ConstructionGenerator.h"

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

			auto* construction = DST::user::ConstructionGenerator().GenerateConstructionFromPath("./Template/Definition/Identity/identity.h.dst", "./Template/Definition/Identity/identity.h.setting.dst");

			auto* identity = static_cast<ir::special::Identity*>(lpd.GetIR());

			FillInDefaultVariablesInConstruction(*construction, language);

			if (!identity->IsDefaultImplementedByDLDL())
			{
				construction->SetVariable("identity_name", "", { identity->GetName() });
			}

			file.SetFileContent(construction->Output());
			
			delete construction;

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