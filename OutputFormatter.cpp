#include "OutputFormatter.h"

DLDL::OutputFormatter::OutputFormatter(const DLDL::DLDL_AstVisitor& ast_visitor, const std::string& language_name)
{
	ast_visitor_ = ast_visitor;
	LanguageName = language_name;
}

std::string DLDL::OutputFormatter::Format() const
{
	return
	LanguageInit() +
	LanguageGrammer() +
	RetrieveLanguageDefinition() +
	LanguageThreatAnalysis() +
	LanguageCompilation();
}

std::string DLDL::OutputFormatter::LanguageInit() const
{
	return
	"#include \"Deamer/LanguageGen/LanguageGen.h\"\n"
	"#include \"Deamer/LanguageAnalyzer/LanguageOptimiser.h\"\n"
	"#include \"Deamer/LanguageAnalyzer/LanguagePrinter/LanguageDefinitionPrinter.h\"\n"
	"#include \"Deamer/LanguageGen/LanguageDefMacros.h\"\n"
	"#include \"Deamer/AstGen/AstGen.h\"\n"
	"#include \"Deamer/AstGen/AstNodeDataStructures/AstBuilderType.h\"\n"
	"#include \"Deamer/ThreatAnalyzer/Printer/ThreatPrinter.h\"\n"
	"#include \"Deamer/ThreatAnalyzer/LanguageDefinition/LanguageDefinitionThreatAnalyzer.h\"\n"
	"#include <iostream>\n"
	"using namespace deamer;\n"
	"\n"
	"int main()\n"
	"{\n"
    "    #ifdef currentLangDef\n"
    "    #undef currentLangDef\n"
    "    #endif\n"
    "    #define currentLangDef language_definition_builder\n"
	"\n"
    "    LanguageDefinitionBuilder language_definition_builder = LanguageDefinitionBuilder();\n"
	"    language_definition_builder.SetTypeContinuation(TypeContinuation_t::vector);\n";
}

std::string DLDL::OutputFormatter::LanguageGrammer() const
{
	std::string language_symbols;
	std::string language_rules;
	for (Symbol* symbol : ast_visitor_.Symbols_)
	{
		std::vector<std::string> SymbolFunctionCalls = symbol->MakeFunctionCall();
		for(std::string SymbolFunctionCall : SymbolFunctionCalls)
			language_symbols += "    " + SymbolFunctionCall;
		std::vector<std::string> SymbolImplementations = symbol->MakeImplementationPart();
		for(std::string SymbolImplementation : SymbolImplementations)
			language_rules += "    " + SymbolImplementation;
	}
	return	language_symbols +
			"\n" +
			language_rules;
}

std::string DLDL::OutputFormatter::LanguageThreatAnalysis() const
{
	return
			"    auto langThreatAnalyzer = deamer::threat::analyzer::languagedefinition::LanguageDefinitionThreatAnalyzer();\n"
			"    auto threatData = langThreatAnalyzer.AnalyseLanguageDefinition(language_definition);\n"
			"\n"
			"    if (threatData.empty())\n"
			"    {\n"
			"        std::cout << \"No errors or warnings! Continuing with generation!\" << std::endl;\n"
			"    }\n"
			"    else\n"
			"    {\n"
			"        auto threatPrinter = deamer::threat::ThreatPrinter(threatData);\n"
			"        threatPrinter.Print();\n"
			"        if (langThreatAnalyzer.DoesThreatDataContainErrors(threatData))\n"
			"        {\n"
			"            return -1; // We found fatal errors so we wont continue\n"
			"        }\n"
			"    }\n";
}

std::string DLDL::OutputFormatter::RetrieveLanguageDefinition() const
{
	return 
			"    language_definition_builder.SetLanguageName(\"" + LanguageName +"\");\n"
			"    LanguageDefinition language_definition = language_definition_builder.GetLanguageDefinition();\n";
}

std::string DLDL::OutputFormatter::LanguageCompilation() const
{
	return
			"    auto languageGen = new LanguageGen(LexerType_t::flex, ParserType_t::bison, language_definition);\n"
			"    languageGen->DirTarget(\"\");\n"
			"\n"
			"    LanguageDefinitionPrinter().Print(language_definition);\n"
			"\n"
			"    languageGen->Finish();\n"
			"\n"
			"    auto astGen = new AstGen(language_definition, AstBuilderType::visitor);\n"
			"    astGen->CreateAstNodes();\n"
			"    return 0;\n"
			"}\n";
}

std::string DLDL::OutputFormatter::MakeMakeFile() const
{
	return
		"LANGUAGE=" + LanguageName + "\n"
		"LANG_LEXER=$(LANGUAGE)_Lexer.o\n"
		"LANG_PARSER=$(LANGUAGE)_Parser.o\n"
		"LANG_COMPILER=$(LANGUAGE)_Compiler.o\n"
		"LANG_LANGUAGE=$(LANGUAGE)_Language.o\n"
		"COMPILER_GENERATOR=$(LANGUAGE)Generator.cpp\n"
		"\n"
		"PARSER_SOURCE=Parser/$(LANGUAGE)parser.tab.cpp\n"
		"LEXER_SOURCE=Lexer/lex.$(LANGUAGE).cpp\n"
		"COMPILER_SOURCE=$(LANGUAGE)Compiler.cpp\n"
		"ASTNODES_SOURCE=$(wildcard AstNodes/*.cpp)\n"
		"ASTNODES_OBJECT=$(subst AstNodes/,,$(patsubst %.cpp,%.o,$(ASTNODES_SOURCE)))\n"
		"\n"
		"CC=clang++\n"
		"ARGS=-Wall\n"
		"\n"
		"INTERNAL_INCLUDES=-IParser/ -ILexer/ -I./ -IAstNodes/\n"
		"EXT_LIBS=-L/usr/lib/Deamer -lDeamer\n"
		"\n"
		".PHONY: AstNodes Parser Lexer Compiler Language\n"
		"\n"
		"all: full_clean AstNodes Parser Lexer Compiler Language\n"
		"	printf \"Done\\n\"\n"
		"\n"
		"Parser:\n"
		"	$(CC) $(ARGS) $(INTERNAL_INCLUDES) -c $(PARSER_SOURCE) -o $(LANG_PARSER)\n"
		"	printf \"Done\\n\"\n"
		"\n"
		"Lexer:\n"
		"	$(CC) $(ARGS) $(INTERNAL_INCLUDES) -c $(LEXER_SOURCE)  -o $(LANG_LEXER)\n"
		"	printf \"Done\\n\"\n"
		"	\n"
		"Compiler:\n"
		"	$(CC) $(ARGS) $(INTERNAL_INCLUDES) -c $(COMPILER_SOURCE) -o $(LANG_COMPILER)\n"
		"	printf \"Done\\n\"\n"
		"	\n"
		"AstNodes:\n"
		"	$(CC) $(ARGS) $(INTERNAL_INCLUDES) -c $(ASTNODES_SOURCE)\n"
		"	printf \"Done\\n\"\n"
		"	\n"
		"Language:\n"
		"	ld -relocatable $(LANG_PARSER) $(LANG_LEXER) $(LANG_COMPILER) $(ASTNODES_OBJECT)  -o $(LANGUAGE)Compiler.out\n"
		"	printf \"Done\\n\"\n"
		"	\n"
		"CompilerGenerator: full_clean GeneratorClean\n"
		"	$(CC) $(ARGS) $(COMPILER_GENERATOR) $(EXT_LIBS) -o $(LANGUAGE)CompilerGenerator.out\n"
		"	./$(LANGUAGE)CompilerGenerator.out\n"
		"\n"
		"Executable: $(LANGUAGE)Compiler.out\n"
		"	$(CC) $(ARGS) $(wildcard AstNodes/AstVisitor/*.cpp) Compiler.cpp $(LANGUAGE)Compiler.out $(INTERNAL_INCLUDES) $(EXT_LIBS) -o $(LANGUAGE).out\n"
		"	make clean\n"
		"\n"
		"$(LANGUAGE)Compiler.out: all\n"
		"\n"
		"\n"
		"GeneratorClean:\n"
		"	rm -r -f Parser/\n"
		"	rm -r -f AstNodes/\n"
		"	rm -r -f Lexer/\n"
		"	\n"
		"full_clean:\n"
		"	rm -f $(ASTNODES_OBJECT)\n"
		"	rm -f $(LANG_PARSER)\n"
		"	rm -f $(LANG_LEXER)\n"
		"	rm -f $(LANG_COMPILER)\n"
		"	rm -f *.o\n"
		"	printf \"Done\\n\"\n"
		"	\n"
		"clean:\n"
		"	rm -f *.o\n"
		"	printf \"Done\\n\"";
}