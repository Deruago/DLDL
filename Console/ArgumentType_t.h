#ifndef DLDL_CONSOLE_ARGUMENTTYPE_T_h
#define DLDL_CONSOLE_ARGUMENTTYPE_T_h

namespace DLDL {
	enum class ArgumentType_t
	{
		unknown,
		
		//implemented
		showtext,
		showstructure,
		showAST,
		showTextAfterFilePreProcessor,
		addThreatAnalysis,
		allArguments,
		autoCompile,
		help,
		
		//reserved arguments
		debugInformation,
	};
}

#endif //DLDL_CONSOLE_ARGUMENTTYPE_T_h