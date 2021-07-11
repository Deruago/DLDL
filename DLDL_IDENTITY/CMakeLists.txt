cmake_minimum_required(VERSION 3.18)

project(DLDL_IDENTITY)

find_package(Deamer_External REQUIRED)

include(deamer.cmake)

add_subdirectory(extern)
add_subdirectory(lib)

