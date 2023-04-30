cmake_minimum_required(VERSION 3.16)

project(DLDL_LPDDEF)

find_package(Deamer_External REQUIRED)
find_package(Deamer_Algorithm REQUIRED)

include(deamer.cmake)

add_subdirectory(extern)
add_subdirectory(lib)

option(TESTS "Enables all the tests" OFF)
if(TESTS)
	message(STATUS "Tests are now available.")
	add_subdirectory(tests)
endif()

option(APPLICATIONS "Enables all the applications" OFF)
if(APPLICATIONS)
	message(STATUS "Applications are now available.")
	add_subdirectory(sources)
endif()
