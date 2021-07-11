cmake_minimum_required(VERSION 3.18)

project(DLDL_GRAMMAR)

find_package(Deamer REQUIRED)
find_package(Deamer_External REQUIRED)

include(deamer.cmake)

add_subdirectory(extern)
add_subdirectory(lib)

add_executable(DLDL_Grammar_Main "main.cpp")
target_link_libraries(DLDL_Grammar_Main DLDL_GRAMMAR_static_library)

