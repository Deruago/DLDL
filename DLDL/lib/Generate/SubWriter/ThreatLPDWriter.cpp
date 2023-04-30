#include "DLDL/Generate/SubWriter/ThreatLPDWriter.h"
#include "DLDL/Template/Definition/Threat/ThreatTemplate.h"

deamer::file::tool::File
DLDL::generate::sub::ThreatLPDWriter::GetFileContentHeaderFile(ir::Language* language,
															   const ir::LPD& lpd)
{
	deamer::file::tool::File file("Threat", "h", "");

	auto generator = DLDL::filetemplate::ThreatTemplate();

	FillInDefaultVariablesInConstruction(generator, language);

	file.SetFileContent(generator.GetOutput());

	return file;
}

deamer::file::tool::File
DLDL::generate::sub::ThreatLPDWriter::GetFileContentSourceFile(ir::Language* language,
															   const ir::LPD& lpd)
{
	deamer::file::tool::File file("Threat", "cpp", "");

	return file;
}
