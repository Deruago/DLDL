#include "Deamer/LanguageGen/LanguageGen.h"
#include "Deamer/LanguageAnalyzer/LanguageOptimiser.h"
#include "Deamer/LanguageAnalyzer/LanguagePrinter/LanguageDefinitionPrinter.h"
#include "Deamer/LanguageGen/LanguageDefMacros.h"
#include "Deamer/AstGen/AstGen.h"
#include "Deamer/AstGen/AstNodeDataStructures/AstBuilderType.h"
#include <iostream>
using namespace deamer;

int main()
{
    #ifdef currentLangDef
    #undef currentLangDef
    #endif
    #define currentLangDef language_definition_builder

    LanguageDefinitionBuilder language_definition_builder = LanguageDefinitionBuilder();
    language_definition_builder.SetTypeContinuation(TypeContinuation_t::vector);
    DELETENODE(NEWLINE, "[\\n]");
    DELETENODE(SPACES, "[ ]+");
    DELETENODE(CR, "[\\r]");
    DELETENODE(TAB, "[\\t]");
    IGNORENODE(LEFT_CURLY_BRACKET, "[(]");
    IGNORENODE(RIGHT_CURLY_BRACKET, "[)]");
    IGNORENODE(LEFT_BRACKET, "[{]");
    IGNORENODE(RIGHT_BRACKET, "[}]");
    IGNORENODE(LEFT_SQUARE_BRACKET, "[\\[]");
    IGNORENODE(RIGHT_SQUARE_BRACKET, "[\\]]");
    NODE(DELETE, "DELETE[:]");
    NODE(IGNORE, "IGNORE[:]");
    NODE(TERMINAL, "TERMINAL[:]");
    NODE(NONTERMINAL, "NONTERMINAL[:]");
    NODE(GROUP, "GROUP[:]");
    NODE(ALIAS, "ALIAS[:]");
    NODE(START, "START[:]");
    NODE(COMMENT, "COMMENT[:]");
    NODE(UNIQUE, "UNIQUE[:]");
    NODE(TYPE, "TYPE[:]");
    NODE(VARNAME, "(([\\[][^\\]]+[\\] \\\\a-zA-Z_0-9\\}\\{\\&\\#\\@\\%\\$]*[\\]](([\\{][ ]*[0-9]+[ ]*[,][ ]*[0-9]+[ ]*[\\}])|([+*]{0,1}))([\\)]*)[|]{0,1})|([\\^]{0,1}[\\(][^\\)]+[\\) a-zA-Z_0-9\\[\\]\\}\\{\\&\\#\\@\\%\\$]*[\\)][\\]]{0,1}(([\\{][ ]*[0-9]+[ ]*[,][ ]*[0-9]+[ ]*[\\}])|([+*]{0,1}))((([|\\)]*))[+*]{0,1}[$]{0,1}))|([a-zA-Z_0-9]+))+");
    TYPE(PROG);
    TYPE(STMTS);
    GROUPEDTYPE(STMT);
    GROUPEDTYPE(ABSTRACTION);
    TYPE(TERMINALS);
    TYPE(TERMINAL_DECL);
    TYPE(NONTERMINAL_DECL);
    TYPE(ABSTRACTION_DECL);
    TYPE(RULE_DECL);
    TYPE(TERMINAL_BLOCK);
    TYPE(NONTERMINAL_BLOCK);
    TYPE(RULES);
    TYPE(ABSTRACTION_BLOCK);
    TYPE(ABSTRACTION_INPUTS);
    TYPE(ABSTRACTION_INPUT);
    TYPE(GENERAL_BLOCK);
    TYPE(VARLIST);

    RULE(PROG, STMTS);
    RULE(STMTS, STMT, STMTS);
    RULE(STMTS, EMPTY);
    GROUPTOKENS(STMT, TERMINAL_DECL, NONTERMINAL_DECL, ABSTRACTION_DECL);
    GROUPTOKENS(ABSTRACTION, DELETE, IGNORE, TERMINAL, NONTERMINAL, GROUP, ALIAS, START, COMMENT, UNIQUE, TYPE);
    RULE(TERMINALS, TERMINAL_DECL, TERMINALS);
    RULE(TERMINALS, EMPTY);
    RULE(TERMINAL_DECL, VARNAME, VARLIST, LEFT_BRACKET, TERMINAL_BLOCK, RIGHT_BRACKET);
    RULE(NONTERMINAL_DECL, VARNAME, LEFT_BRACKET, NONTERMINAL_BLOCK, RIGHT_BRACKET);
    RULE(ABSTRACTION_DECL, ABSTRACTION, VARLIST, LEFT_BRACKET, ABSTRACTION_BLOCK, RIGHT_BRACKET);
    RULE(RULE_DECL, VARLIST, LEFT_BRACKET, GENERAL_BLOCK, RIGHT_BRACKET);
    RULE(TERMINAL_BLOCK, GENERAL_BLOCK);
    RULE(NONTERMINAL_BLOCK, RULES);
    RULE(RULES, RULE_DECL, RULES);
    RULE(RULES, RULE_DECL);
    RULE(ABSTRACTION_BLOCK, ABSTRACTION_INPUTS);
    RULE(ABSTRACTION_INPUTS, ABSTRACTION_INPUT, LEFT_BRACKET, RIGHT_BRACKET, ABSTRACTION_INPUTS);
    RULE(ABSTRACTION_INPUTS, EMPTY);
    RULE(ABSTRACTION_INPUT, VARLIST);
    RULE(GENERAL_BLOCK, VARLIST);
    RULE(GENERAL_BLOCK, EMPTY);
    RULE(VARLIST, VARNAME, VARLIST);
    RULE(VARLIST, VARNAME);
    language_definition_builder.SetLanguageName("DLDL");
    LanguageDefinition language_definition = language_definition_builder.GetLanguageDefinition();
    auto languageGen = new LanguageGen(LexerType_t::flex, ParserType_t::bison, language_definition);
    languageGen->DirTarget("");

    LanguageDefinitionPrinter().Print(language_definition);

    languageGen->Finish();

    auto astGen = new AstGen(language_definition, AstBuilderType::visitor);
    astGen->CreateAstNodes();
    return 0;
}

