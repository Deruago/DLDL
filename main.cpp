#include "DLDL/Argument/Interpreter.h"

int main(int argc, char* argv[])
{
	DLDL::argument::Interpreter interpreter(argc, argv);
	return interpreter.Run();
}
