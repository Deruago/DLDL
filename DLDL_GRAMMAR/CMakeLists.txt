cmake_minimum_required(VERSION 3.18)

project(DLDL_GRAMMAR)

find_package(Deamer REQUIRED)
find_package(Deamer_External REQUIRED)

include(deamer.cmake)

add_subdirectory(extern)
add_subdirectory(lib)

target_link_libraries(DLDL_GRAMMAR_external_libraries PUBLIC Deamer Deamer_External DLDL_GRAMMAR_PRODUCTION_RULE_static_library)
target_include_directories(DLDL_GRAMMAR_external_libraries PUBLIC "${DLDL_SOURCE_DIR}/include" "${DLDL_GRAMMAR_SOURCE_DIR}/DLDL_GRAMMAR_PRODUCTION_RULE/include")
target_include_directories(DLDL_GRAMMAR_static_library PUBLIC "${DLDL_SOURCE_DIR}/include" "${DLDL_GRAMMAR_SOURCE_DIR}/DLDL_GRAMMAR_PRODUCTION_RULE/include")

add_executable(DLDL_Grammar_Main "main.cpp")
target_link_libraries(DLDL_Grammar_Main DLDL_GRAMMAR_static_library)

