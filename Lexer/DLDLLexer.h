#ifndef LEXER_DLDL_LEXERAPIFILE_H
#define LEXER_DLDL_LEXERAPIFILE_H

#include <Deamer/DefaultAPI/DeamerLexerAPI.h>
#include <Deamer/AstGen/AstInformation.h>
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstTree.h>

namespace DLDL
{
    class DLDLLexer : public deamer::DeamerLexerAPI
    {
        private:
        protected:
        public:
            deamer::AstInformation* LexText(std::string inputText) override;
            deamer::AstInformation* LexFile(FILE* inputFile) override;
            deamer::AstInformation* LexFile(std::string fileLocation) override;
    };
}

#endif //LEXER_DLDL_LEXERAPIFILE_H

