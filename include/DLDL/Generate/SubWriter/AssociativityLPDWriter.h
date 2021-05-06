#ifndef DLDL_GENERATE_SUBWRITER_ASSOCIATIVITYLPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_ASSOCIATIVITYLPDWRITER_H

#include "DLDL/Generate/SubWriter.h"
#include "DST/User/ConstructionGenerator.h"

namespace DLDL::generate::sub
{
	class AssociativityLPDWriter : public SubWriter
	{
	public:
		AssociativityLPDWriter() = default;
	public:
		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language, const ir::LPD& lpd) override
		{
			deamer::file::tool::File file("Associativity", "h", "");

			auto* construction = DST::user::ConstructionGenerator().GenerateConstructionFromPath("./Template/Definition/Associativity/associativity.h.dst", "./Template/Definition/Associativity/associativity.h.setting.dst");

			//auto* associativity = static_cast<ir::Associativity*>(lpd.GetIR());

			FillInDefaultVariablesInConstruction(*construction, language);

			delete construction;

			return file;
		}

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language, const ir::LPD& lpd) override
		{
			deamer::file::tool::File file("Associativity", "cpp", "");

			return file;
		}
	};
}

#endif // DLDL_GENERATE_SUBWRITER_ASSOCIATIVITYLPDWRITER_H