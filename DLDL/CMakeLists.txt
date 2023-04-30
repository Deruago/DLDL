cmake_minimum_required(VERSION 3.16)

project(DLDL VERSION 2.2.0)

set(CMAKE_CXX_STANDARD 17)
include(GNUInstallDirs)

find_package(Deamer REQUIRED)
find_package(Deamer_External REQUIRED)
find_package(Deamer_Algorithm REQUIRED)

include(deamer.cmake)

macro(option_enable OPTION_NAME OPTION_TEXT OPTION_DEFAULT)
	if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
		option(${OPTION_NAME} ${OPTION_TEXT} ${OPTION_DEFAULT})
	else()
		option(${OPTION_NAME} ${OPTION_TEXT} OFF)
	endif()
endmacro()

option_enable(DLDL_BUILD_EXAMPLES "Build the examples" OFF)
option_enable(DLDL_BUILD_TESTS "Build the tests" ON)
option_enable(DLDL_BUILD_SOURCES "Build the sources" OFF)

add_subdirectory(extern)
add_subdirectory(lib)

target_link_libraries(DLDL_static_library PUBLIC Deamer::Deamer)

add_executable(DLDL)
target_sources(DLDL PRIVATE "main.cpp" "DLDL_VALUE/lib/IR/ValueAbstraction.cpp" "DLDL_IMPORT/lib/IR/ImportRule.cpp")
target_link_libraries(DLDL PRIVATE DLDL_static_library)

if(DLDL_BUILD_SOURCES)
	add_subdirectory(sources)
endif()

add_executable(Deamer::DLDL ALIAS DLDL)

option_enable(DLDL_DEBUG "Debug Build" OFF)

if (DLDL_DEBUG)

else()
	if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		set_target_properties(DLDL PROPERTIES COMPILE_FLAGS "-O3")
	elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set_target_properties(DLDL PROPERTIES COMPILE_FLAGS "-O3")
	elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
		set_target_properties(DLDL PROPERTIES COMPILE_FLAGS "/O3")
	endif()
endif()

if(DLDL_BUILD_TESTS)
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

install(TARGETS DLDL)

# Package

include(CMakePackageConfigHelpers)

configure_package_config_file(${DLDL_SOURCE_DIR}/cmake/DLDLConfig.cmake.in
  "${DLDL_BINARY_DIR}/DLDLConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/DLDL
)

write_basic_package_version_file(
	"DLDLConfigVersion.cmake"
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY SameMajorVersion
)

install(FILES
	${DLDL_BINARY_DIR}/DLDLConfig.cmake
	${DLDL_BINARY_DIR}/DLDLConfigVersion.cmake
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/DLDL
)