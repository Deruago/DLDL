cmake_minimum_required(VERSION 3.16)

project(DLDL_LanguageProject
                      DESCRIPTION "Project for the language(s): DLDL"
                      LANGUAGES CXX)

option(DLDL_ENABLE_COMPILER_GENERATOR "Enable Compiler Generation" ON)
if (DLDL_ENABLE_COMPILER_GENERATOR)
	find_package(Deamer REQUIRED)
	add_subdirectory(CompilerGenerator)
endif()

add_subdirectory(DLDL)
