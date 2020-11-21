#include <DLDLCompiler.h>
#include <iostream>


int main(int argc, char **argv)
{
    DLDL::DLDLCompiler* compiler = new DLDL::DLDLCompiler();
    compiler->CompileFile(argv[1]);
    return 0;
}