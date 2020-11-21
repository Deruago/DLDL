LANGUAGE=DLDL
LANG_LEXER=$(LANGUAGE)_Lexer.o
LANG_PARSER=$(LANGUAGE)_Parser.o
LANG_COMPILER=$(LANGUAGE)_Compiler.o
LANG_LANGUAGE=$(LANGUAGE)_Language.o
COMPILER_GENERATOR=$(LANGUAGE)Generator.cpp

PARSER_SOURCE=Parser/$(LANGUAGE)parser.tab.cpp
LEXER_SOURCE=Lexer/lex.$(LANGUAGE).cpp
COMPILER_SOURCE=$(LANGUAGE)Compiler.cpp
ASTNODES_SOURCE=$(wildcard AstNodes/*.cpp)
ASTNODES_OBJECT=$(subst AstNodes/,,$(patsubst %.cpp,%.o,$(ASTNODES_SOURCE)))

CC=clang++
ARGS=-Wall

INTERNAL_INCLUDES=-IParser/ -ILexer/ -I./ -IAstNodes/
EXT_LIBS=-L/usr/lib/Deamer -lDeamer

.PHONY: AstNodes Parser Lexer Compiler Language

all: full_clean AstNodes Parser Lexer Compiler Language
	printf "Done\n"

Parser:
	$(CC) $(ARGS) $(INTERNAL_INCLUDES) -c $(PARSER_SOURCE) -o $(LANG_PARSER)
	printf "Done\n"

Lexer:
	$(CC) $(ARGS) $(INTERNAL_INCLUDES) -c $(LEXER_SOURCE)  -o $(LANG_LEXER)
	printf "Done\n"
	
Compiler:
	$(CC) $(ARGS) $(INTERNAL_INCLUDES) -c $(COMPILER_SOURCE) -o $(LANG_COMPILER)
	printf "Done\n"
	
AstNodes:
	$(CC) $(ARGS) $(INTERNAL_INCLUDES) -c $(ASTNODES_SOURCE)
	printf "Done\n"
	
Language:
	ld -relocatable $(LANG_PARSER) $(LANG_LEXER) $(LANG_COMPILER) $(ASTNODES_OBJECT)  -o $(LANGUAGE)Compiler.out
	printf "Done\n"
	
CompilerGenerator: full_clean GeneratorClean
	$(CC) $(ARGS) $(COMPILER_GENERATOR) $(EXT_LIBS) -o $(LANGUAGE)CompilerGenerator.out
	./$(LANGUAGE)CompilerGenerator.out

Executable: $(LANGUAGE)Compiler.out
	$(CC) $(ARGS) $(wildcard AstNodes/AstVisitor/*.cpp) OutputFormatter.cpp Compiler.cpp $(LANGUAGE)Compiler.out $(INTERNAL_INCLUDES) $(EXT_LIBS) -o $(LANGUAGE).out
	make clean
	sudo rm -f /bin/DLDL
	sudo cp ./DLDL.out /bin/DLDL

$(LANGUAGE)Compiler.out: all


GeneratorClean:
	rm -r -f Parser/
	rm -r -f AstNodes/
	rm -r -f Lexer/
	
full_clean:
	rm -f $(ASTNODES_OBJECT)
	rm -f $(LANG_PARSER)
	rm -f $(LANG_LEXER)
	rm -f $(LANG_COMPILER)
	rm -f *.o
	printf "Done\n"
	
clean:
	rm -f *.o
	printf "Done\n"
	
clean_output:
	rm -f *.out
