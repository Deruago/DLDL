cmake_minimum_required(VERSION 3.16)

project(DLDL VERSION 2.2.0)

include(GNUInstallDirs)

find_package(Deamer REQUIRED)
find_package(Deamer_External REQUIRED)
find_package(Deamer_Algorithm REQUIRED)

include(deamer.cmake)

add_subdirectory(extern)
add_subdirectory(lib)

target_link_libraries(DLDL_static_library PUBLIC Deamer::Deamer)

add_executable(DLDL)
target_sources(DLDL PRIVATE "main.cpp")
target_link_libraries(DLDL PRIVATE DLDL_static_library)

add_subdirectory(sources)

add_executable(Deamer::DLDL ALIAS DLDL)

macro(option_enable OPTION_NAME OPTION_TEXT OPTION_DEFAULT)
	if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
		option(${OPTION_NAME} ${OPTION_TEXT} ${OPTION_DEFAULT})
	else()
		option(${OPTION_NAME} ${OPTION_TEXT} OFF)
	endif()
endmacro()

option_enable(DLDL_BUILD_EXAMPLES "Build the examples" OFF)
option_enable(DLDL_BUILD_TESTS "Build the tests" ON)

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