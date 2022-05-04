[![Codacy Badge](https://app.codacy.com/project/badge/Grade/b5738e6d64d046ac92740d54194bc127)](https://www.codacy.com/gh/Deruago/DLDL/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Deruago/DLDL&amp;utm_campaign=Badge_Grade)

[![](https://tokei.rs/b1/github/Deruago/DLDL)](https://github.com/Deruago/DLDL)

# DLDL

[DLDL](https://github.com/Deruago/DLDL) is used to specify definitions in order to generate languages/compilers. It functions as a specialized front-end for [Deamer CC](https://github.com/Deruago/theDeamerProject). 

[DLDL](https://github.com/Deruago/DLDL) contains varies DSL's to generate [Deamer CC](https://github.com/Deruago/theDeamerProject) definitions, it supports EBNF and more.

## Examples

For examples take a look at the example repo: https://github.com/Deruago/DeamerExamples

The example repo contains varies tutorials and examples to help you get started using Deamer.

## Installing

As DLDL uses Deamer, it is recommended to also install Deamer Project: https://github.com/Deruago/theDeamerProject.

It also uses Deamer External and Deamer Algorithm, you can install those here:

- https://github.com/Deruago/DeamerExternal
- https://github.com/Deruago/DeamerAlgorithm

### General installation

**Getting the source code**

```bash
git clone https://github.com/Deruago/DLDL.git
cd DLDL
```

**Creating the build directory**

```bash
mkdir build
cd build
```

**Building and Installing DLDL**

```bash
cmake ..
cmake --build . --target install
```

## Starting a Deamer language project

When installed, you can initialize a Deamer language project. Do this by using the following command:
```bash
DLDL -init -language-name=MyNewLanguage
```

This will generate a Definition directory with a "MyNewLanguage" directory inside.
The "MyNewLanguage" directory contains default generated files, these files are empty and can be overridden by writing your DLDL definitions in it.

When you are done defining your language, go back to the root directory of your project, and generate the compilergenerator.

## Generating the CompilerGenerator

When you have created a Definition folder and implemented at least the lexicon and grammar.
You can run the following command to generate the compilergenerator:

```bash
DLDL -g
```

If you want to automatically compile the compiler generator after it is generated:
```bash
DLDL -auto-compile
```

If you want to automatically run the compiled compiler-generator to get the actual compiler:
```bash
DLDL -auto-run
```

And if you want to do this all in 1 go:
```bash
DLDL -g -ac -ar
```

## Target specific OS

It is possible to target a specific OS, you can do so by using the following argument:

```bash
DLDL -target-os=windows
```

You can replace "windows" with "linux" or a different supported OS.

## Current implemented definitions (LPD's)

As Deamer grows more LPD's get added, these definitions take time to become available in DLDL, as we need to define a DSL and create the appropriate back-end for it.

| LPD        | User definable | DLDL default implementation |
| ---------- | -------------- | --------------------------- |
| Lexicon    | Yes            | No                          |
| Grammar    | Yes            | No                          |
| Generation | Yes            | Yes (by default)            |
| Identity   | No             | Yes (by default)            |

## DLDL Commands

DLDL has several arguments available to modify what DLDL does.
To get a full list of these arguments run:

```bash
DLDL -h
```

This will output something like this:
```
Informational arguments:
        -help                                       ; Shows this page.
        -license, -copyright                        ; Shows the license.
        -information                                ; Shows version, compatibility, copyright, and this page.
        -version                                    ; Shows the current version of DLDL.
        -compatible                                 ; Shows the compatibility with Deamer CC.
        -exit                                       ; Exits DLDL.
        -echo                                       ; Repeats the text that was given.
        -supported-grammars                         ; Shows list of supported grammars available in this version of DLDL.
        -about                                      ; Shows information about DLDL and Deamer.

Behavioural arguments (modify what DLDL does):
        -init, -initial, -initialize                ; Initializes DLDL project for the 'language'.
        -generate, -gen, -g                         ; Generates the compiler generator project,
                                                    ; given a 'Definition Map'.
        -auto-compile, -ac                          ; Auto compiles the CompilerGenerator.
        -auto-run, -ar                              ; Auto runs the compiled executable.

Internal behavioural settings (modify how DLDL does stuff):
        -language-name, -lang-name                  ; Modify the 'language' used to initialize.
        -target-language, tl                        ; Sets the 'target language', by default this is C++.
        -build-map, -bm                             ; Specify the build map. Default: './build'
        -definition-map, -dm                        ; Specify the definition map. Default: './Definition'

Debug options:
        -debug-dldl                                 ; Allow DLDL to output debug messages from DLDL.
        -debug-build                                ; Creates a debug build for Deamer CC.
        -log                                        ; Logs DLDL output to a txt.
        -print-parser-output                        ; Prints the DLDL parser result after reading the definitions.

The next set of arguments are arguments allowing automated calls to executables.
E.g. DLDL can automatically initialize git repo's if Git is installed.
Git maintaince arguments:
        -git-init, -git-initialize                  ; Automatically initializes git repo.
        -git-maintain-definition                    ; Automatically commits when the Definition is updated.

Clang format arguments:
        -clang-format-default                       ; Initializes default clang format style (Deamer CC style).
```

