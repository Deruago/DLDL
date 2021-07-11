cmake_minimum_required(VERSION 3.18)

project(DLDL_GRAMMAR_PRODUCTION_RULE)

find_package(Deamer REQUIRED)
find_package(Deamer_External REQUIRED)

include(deamer.cmake)

add_subdirectory(extern)
add_subdirectory(lib)
