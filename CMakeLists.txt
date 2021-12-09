cmake_minimum_required(VERSION 3.16)

project(DLDL)

find_package(Deamer REQUIRED)
find_package(Deamer_External REQUIRED)

include(deamer.cmake)

add_subdirectory(extern)
add_subdirectory(lib)

target_link_libraries(DLDL_static_library PUBLIC Deamer)
target_link_libraries(DLDL_shared_library PUBLIC Deamer)

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
	find_package(GTest)
	if (GTEST_FOUND)
		enable_testing()
		add_subdirectory(tests)
	else()
		enable_testing()
		include(GoogleTest)
		add_subdirectory(tests)
	endif()
endif()

add_executable(DLDL "main.cpp")
target_link_libraries(DLDL DLDL_static_library)

add_subdirectory(sources)

install (TARGETS DLDL)