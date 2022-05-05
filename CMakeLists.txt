cmake_minimum_required(VERSION 3.16)

project(DLDL_LanguageProject
                      DESCRIPTION "Project for the language(s): DLDL"
                      LANGUAGES CXX)

option(DLDL_ENABLE_COMPILER_GENERATOR "Enable Compiler Generation" OFF)
if (DLDL_ENABLE_COMPILER_GENERATOR)
	find_package(Deamer REQUIRED)
	add_subdirectory(CompilerGenerator)
endif()

option(DLDL_ENABLE_LANGUAGE_BUILD "Enable Language CMake Build." ON)
if (DLDL_ENABLE_LANGUAGE_BUILD)
	add_subdirectory(DLDL)

endif()
