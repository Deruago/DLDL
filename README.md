# DLDL - Deamer Language Definition Language

## Overview

DLDL is a language made for creating compilers and languages. Its backend is supported by the [Deamer compiler generator](https://github.com/Deruago/theDeamerProject). DLDL contains tools/languages to create C++ deamer cc compatible code.

## Functionality

DLDL currently supports 1 language definition: mixed lexer and parser definition.

DLDL supports abstractions such as:

- DELETE
- IGNORE
- GROUP
- TERMINAL

It also supports threat analysis (using Deamer) giving useful compiler errors and warnings.

## Contributing

If you want to contribute to DLDL, you can do so by contributing to the Deamer project instead. DLDL uses Deamer as backend and all code inputted in DLDL will be translated to Deamer input. 