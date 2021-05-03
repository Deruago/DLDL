#ifndef DLDL_GENERATE_LPDSUBWRITERFACTORY_H
#define DLDL_GENERATE_LPDSUBWRITERFACTORY_H

#include "DLDL/Generate/SubWriter.h"
#include "DLDL/Generate/SubWriter/LexiconLPDWriter.h"
#include "DLDL/Generate/SubWriter/GrammarLPDWriter.h"

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
				break;
			case ir::Type::Associativity:
				break;
			case ir::Type::Generation:
				break;
			case ir::Type::Identity:
				break;
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