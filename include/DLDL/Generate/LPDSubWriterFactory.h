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
		static std::shared_ptr<SubWriter> GetLPDSubWriter(ir::Type type)
		{
			switch (type)
			{
			case ir::Type::Lexicon:
				return std::make_shared<sub::LexiconLPDWriter>();
			case ir::Type::Grammar:
				return std::make_shared<sub::GrammarLPDWriter>();
			case ir::Type::Precedence:
				return std::make_shared<sub::PrecedenceLPDWriter>();
			case ir::Type::Associativity:
				return std::make_shared<sub::AssociativityLPDWriter>();
			case ir::Type::Generation:
				return std::make_shared<sub::GenerationLPDWriter>();
			case ir::Type::Identity:
				return std::make_shared<sub::IdentityLPDWriter>();
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