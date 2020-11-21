#ifndef DLDL_COMPILERAPIFILE_H
#define DLDL_COMPILERAPIFILE_H

#include <Deamer/DefaultAPI/DeamerCompilerAPI.h>
#include <Deamer/CompilerGen/CompiledObject.h>
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstTree.h>

namespace DLDL
{
    class DLDLCompiler : public deamer::DeamerCompilerAPI
    {
        private:
			void WriteToFile(const std::string& file_location, const std::string& file_content);
        protected:
        public:
            const bool SupportsCompilation = true; // If this can compile data. Set this to false if it cant
            const bool SupportsDebugging = false; // Set this to true if it supports Debugging note that it needs to inherit the specified interface

            const std::string Language = "DLDL";

            DLDLCompiler();
            ~DLDLCompiler();

            deamer::CompiledObject* CompileText(std::string inputText) override;
            deamer::CompiledObject* CompileFile(FILE* inputFile) override;
            deamer::CompiledObject* CompileFile(std::string fileLocation) override;
    };
}

#endif //DLDL_COMPILERAPIFILE_H

