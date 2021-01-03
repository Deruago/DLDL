#ifndef DLDL_CONSOLE_DEFINITIONTYPE_T_h
#define DLDL_CONSOLE_DEFINITIONTYPE_T_h

namespace DLDL {
	enum class DefinitionType_t
	{
		unknown,
		
		// Implemented definitions
		mixed_lexicon_and_cfg,
		
		// Reserved definitions
		lexicon,
		cfg,
		st,
		precedence,
	};
}

#endif //DLDL_CONSOLE_DEFINITIONTYPE_T_h