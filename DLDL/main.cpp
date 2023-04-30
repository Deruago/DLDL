#include "DLDL/Argument/Interpreter.h"

int main(int argc, const char* argv[])
{
	DLDL::argument::Interpreter interpreter(argc, argv);
	return interpreter.Run();
}
