#include "DLDL/Generate/LPDSubWriterFactory.h"

std::shared_ptr<DLDL::generate::SubWriter>
DLDL::generate::LPDSubWriterFactory::GetLPDSubWriter(ir::Type type)
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
	case ir::Type::Threat:
		return std::make_shared<sub::ThreatLPDWriter>();
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
	case ir::Type::OopSyntax:
		return std::make_shared<sub::OopSyntaxLPDWriter>();
	default:
		break;
	}

	throw std::logic_error("Type is currently not supported!");
}
