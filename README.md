[![Codacy Badge](https://app.codacy.com/project/badge/Grade/b5738e6d64d046ac92740d54194bc127)](https://www.codacy.com/gh/Deruago/DLDL/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Deruago/DLDL&amp;utm_campaign=Badge_Grade)

[![](https://tokei.rs/b1/github/Deruago/DLDL)](https://github.com/Deruago/DLDL)

# DLDL

DLDL is a front-end of Deamer CC. It contains specialized DSL's to generate Deamer CC code. The outputted code can be compiled using Deamer CC to create a compiler generator.

When ran this compiler generator, generates the defined language in DLDL.

## Installing DLDL for Linux

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

## Starting a Deamer project
When installed, you can initialize a Deamer and DLDL project. Do this by using the following command:
```bash
DLDL -init -language-name=MyNewLanguage
```

This will generate a Definition directory with a "MyNewLanguage" directory inside.
The "MyNewLanguage" directory contains default generated files, these files are empty and can be overriden by writing your DLDL definitions in it.

When you are done defining your language, go back to the root directory of your project, and generate the compilergenerator.

Note: information about the definitions can be found in this wiki.

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

## Examples

For examples take a look at the example repo: https://github.com/Deruago/DeamerExample

