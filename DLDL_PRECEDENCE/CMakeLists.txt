cmake_minimum_required(VERSION 3.16)

project(DLDL_PRECEDENCE)

find_package(Deamer_External REQUIRED)

include(deamer.cmake)

add_subdirectory(extern)
add_subdirectory(lib)

