#ifndef DLDL_GENERATE_SUBWRITER_PRECEDENCELPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_PRECEDENCELPDWRITER_H

#include "DLDL/Generate/SubWriter.h"
#include "DST/User/ConstructionGenerator.h"

namespace DLDL::generate::sub
{
	class PrecedenceLPDWriter : public SubWriter
	{
	public:
		PrecedenceLPDWriter() = default;
	public:
		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language, const ir::LPD& lpd) override
		{
			deamer::file::tool::File file("Precedence", "h", "");

			auto* construction = DST::user::ConstructionGenerator().GenerateConstructionFromPath("./Template/Definition/Precedence/precedence.h.dst", "./Template/Definition/Precedence/precedence.h.setting.dst");

			//auto* precedence = static_cast<ir::Precedence*>(lpd.GetIR());

			FillInDefaultVariablesInConstruction(*construction, language);

			delete construction;
			
			return file;
		}

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language, const ir::LPD& lpd) override
		{
			deamer::file::tool::File file("Precedence", "cpp", "");

			return file;
		}
	};
}

#endif // DLDL_GENERATE_SUBWRITER_PRECEDENCELPDWRITER_H