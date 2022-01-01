#ifndef DLDL_GENERATE_LPDSUBWRITERFACTORY_H
#define DLDL_GENERATE_LPDSUBWRITERFACTORY_H

#include "DLDL/Generate/SubWriter.h"
#include "DLDL/Generate/SubWriter/AssociativityLPDWriter.h"
#include "DLDL/Generate/SubWriter/GenerationLPDWriter.h"
#include "DLDL/Generate/SubWriter/GrammarLPDWriter.h"
#include "DLDL/Generate/SubWriter/IdentityLPDWriter.h"
#include "DLDL/Generate/SubWriter/LexiconLPDWriter.h"
#include "DLDL/Generate/SubWriter/PrecedenceLPDWriter.h"
#include "DLDL/Generate/SubWriter/ThreatLPDWriter.h"
#include "DLDL/IR/Type.h"
#include <memory>
#include <stdexcept>

namespace DLDL::generate
{
	class LPDSubWriterFactory
	{
	public:
		static std::shared_ptr<SubWriter> GetLPDSubWriter(ir::Type type);
	};
}

#endif // DLDL_GENERATE_LPDSUBWRITERFACTORY_H
