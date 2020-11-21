#ifndef PARSER_DLDL_PARSERAPIFILE_H
#define PARSER_DLDL_PARSERAPIFILE_H

#include <Deamer/DefaultAPI/DeamerParserAPI.h>
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstTree.h>

namespace DLDL
{
    class DLDLParser : public deamer::DeamerParserAPI
    {
        private:
        protected:
        public:
            DLDLParser();
            ~DLDLParser();

            deamer::AstNode* ParseText(std::string inputText) override;
            deamer::AstNode* ParseFile(FILE* inputFile) override;
            deamer::AstNode* ParseFile(std::string fileLocation) override;
    };
}

#endif //PARSER_DLDL_PARSERAPIFILE_H

