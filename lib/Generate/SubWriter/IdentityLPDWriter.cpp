#include "DLDL/Generate/SubWriter/IdentityLPDWriter.h"
#include "DLDL/Template/Definition/Identity/IdentityTemplate.h"

deamer::file::tool::File
DLDL::generate::sub::IdentityLPDWriter::GetFileContentHeaderFile(ir::Language* language,
																 const ir::LPD& lpd)
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

deamer::file::tool::File
DLDL::generate::sub::IdentityLPDWriter::GetFileContentSourceFile(ir::Language* language,
																 const ir::LPD& lpd)
{
	deamer::file::tool::File file("Identity", "cpp", "");

	return file;
}
