#ifndef DLDL_COMPILERAPIFILE_H
#define DLDL_COMPILERAPIFILE_H

#include <Deamer/DefaultAPI/DeamerCompilerAPI.h>
#include <Deamer/CompilerGen/CompiledObject.h>
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstTree.h>
#include <Console/Argument.h>
#include <Console/ArgumentType_t.h>
#include <vector>

namespace DLDL
{
    class DLDLCompiler : public deamer::DeamerCompilerAPI
    {
        private:
			const std::vector<DLDL::Argument> Arguments;
			bool IsArgumentActive(const DLDL::ArgumentType_t type) const;
			
			void PrintReformattedCode(const std::string reformatted_code);
			void PrintAST(deamer::AstNode* astnode);
			void TryCompilingNewCompiler();
			
			void PrintToConsole(const std::string& text);
		
			void WriteToFile(const std::string& file_location, const std::string& file_content);
        protected:
        public:
            const bool SupportsCompilation = true; // If this can compile data. Set this to false if it cant
            const bool SupportsDebugging = false; // Set this to true if it supports Debugging note that it needs to inherit the specified interface

            const std::string Language = "DLDL";

            DLDLCompiler(){};
			DLDLCompiler(const std::vector<DLDL::Argument>& arguments);

            ~DLDLCompiler() = default;

            deamer::CompiledObject* CompileText(std::string inputText) override;
            deamer::CompiledObject* CompileFile(FILE* inputFile) override;
            deamer::CompiledObject* CompileFile(std::string fileLocation) override;
    };
}

#endif //DLDL_COMPILERAPIFILE_H

