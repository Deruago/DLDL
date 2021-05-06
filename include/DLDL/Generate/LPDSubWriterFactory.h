#ifndef DLDL_GENERATE_LPDSUBWRITERFACTORY_H
#define DLDL_GENERATE_LPDSUBWRITERFACTORY_H

#include "DLDL/Generate/SubWriter.h"
#include "DLDL/Generate/SubWriter/LexiconLPDWriter.h"
#include "DLDL/Generate/SubWriter/GrammarLPDWriter.h"
#include "DLDL/Generate/SubWriter/PrecedenceLPDWriter.h"
#include "DLDL/Generate/SubWriter/AssociativityLPDWriter.h"
#include "DLDL/Generate/SubWriter/GenerationLPDWriter.h"
#include "DLDL/Generate/SubWriter/IdentityLPDWriter.h"

#include "DLDL/IR/Type.h"
#include <stdexcept>

namespace DLDL::generate
{
	class LPDSubWriterFactory
	{
	public:
		static SubWriter* GetLPDSubWriter(ir::Type type)
		{
			switch (type)
			{
			case ir::Type::Lexicon:
				return new sub::LexiconLPDWriter();
			case ir::Type::Grammar:
				return new sub::GrammarLPDWriter();
			case ir::Type::Precedence:
				return new sub::PrecedenceLPDWriter();
			case ir::Type::Associativity:
				return new sub::AssociativityLPDWriter();
			case ir::Type::Generation:
				return new sub::GenerationLPDWriter();
			case ir::Type::Identity:
				return new sub::IdentityLPDWriter();
			case ir::Type::AstOptimization:
				break;
			case ir::Type::AstTranslation:
				break;
			case ir::Type::Coloring:
				break;
			case ir::Type::Formatting:
				break;
			case ir::Type::Documentation:
				break;
			default:
				break;
			}

			throw std::logic_error("Type is currently not supported!");
		}
	};
}

#endif // DLDL_GENERATE_LPDSUBWRITERFACTORY_H