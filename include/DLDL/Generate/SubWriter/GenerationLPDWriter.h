#ifndef DLDL_GENERATE_SUBWRITER_GENERATIONLPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_GENERATIONLPDWRITER_H

#include "DLDL/Generate/SubWriter.h"
#include "DST/User/ConstructionGenerator.h"

namespace DLDL::generate::sub
{
	class GenerationLPDWriter : public SubWriter
	{
	public:
		GenerationLPDWriter() = default;
	public:
		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language, const ir::LPD& lpd) override
		{
			deamer::file::tool::File file("Generation", "h", "");

			auto* construction = DST::user::ConstructionGenerator().GenerateConstructionFromPath("./Template/Definition/Generation/generation.h.dst", "./Template/Definition/Generation/generation.h.setting.dst");

			auto* generation = static_cast<ir::special::Generation*>(lpd.GetIR());

			FillInDefaultVariablesInConstruction(*construction, language);

			for (auto tool : generation->GetTools())
			{
				std::string sourcetool;
						  if (tool.type == ir::special::ToolType::Ast && tool.name == "CPP") {
							  sourcetool = "DeamerAST";
						  }
						  else {
							  sourcetool = tool.name;
						  }

				construction->SetVariable("generate_tool", "", { sourcetool });
				
				for (auto integration : tool.integrations)
				{
					construction->SetVariable("generate_tool_source", "", { sourcetool });
					construction->SetVariable("generate_tool_target", "", { integration.name });

					construction->ExpandVariableField("integration_declaration");
					construction->ExpandVariableField("integration_implementation");
					construction->ExpandVariableField("integration_add_object");
				}
				
				for (auto argument : tool.arguments)
				{
					construction->SetVariable("argument", "", { argument.GetArgumentNameUnderscored() });
					construction->SetVariable("argument_string", "", { argument.GetArgumentName() });

					construction->ExpandVariableField("argument_declaration");
					construction->ExpandVariableField("argument_implementation");
					construction->ExpandVariableField("argument_add_object");
				}

				construction->ExpandVariableField("generate_tools_declaration");
				construction->ExpandVariableField("generate_tools_implementation");
				construction->ExpandVariableField("generate_tools_add_object");
			}
			
			file.SetFileContent(construction->Output());
			
			delete construction;

			return file;
		}

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language, const ir::LPD& lpd) override
		{
			deamer::file::tool::File file("Generation", "cpp", "");

			return file;
		}
	};
}

#endif // DLDL_GENERATE_SUBWRITER_GENERATIONLPDWRITER_H