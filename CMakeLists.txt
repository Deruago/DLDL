cmake_minimum_required(VERSION 3.18)

project(DLDL)

find_package(Deamer REQUIRED)

include(deamer.cmake)

add_subdirectory(extern)
add_subdirectory(lib)

add_executable(DLDL "main.cpp")
target_link_libraries(DLDL DLDL_static_library)

install (TARGETS DLDL)