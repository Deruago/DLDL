cmake_minimum_required(VERSION 3.18)

project(DLDL_LEXER)

find_package(Deamer REQUIRED)
find_package(Deamer_External REQUIRED)

add_library(DLDL_LEXER_external_libraries STATIC "${DLDL_LEXER_SOURCE_DIR}/lib/DLDL_LEXER.cpp")
set_property(TARGET DLDL_LEXER_external_libraries PROPERTY POSITION_INDEPENDENT_CODE ON)
target_link_libraries(DLDL_LEXER_external_libraries PUBLIC Deamer Deamer_External)
target_include_directories(DLDL_LEXER_external_libraries PUBLIC "${DLDL_LEXER_SOURCE_DIR}/extern" "${DLDL_LEXER_SOURCE_DIR}/include" "${DLDL_SOURCE_DIR}/include")

function(DLDL_LEXER_add_external_library external_library_name source_files)
	set(external_library_full_name "DLDL_LEXER_${external_library_name}_static_library")

	add_library(${external_library_full_name} STATIC ${source_files})

	target_link_libraries(${external_library_full_name} PUBLIC Deamer Deamer_External)
	target_include_directories(${external_library_full_name} PRIVATE "${DLDL_LEXER_SOURCE_DIR}/extern" "${DLDL_LEXER_SOURCE_DIR}/include")
	target_compile_features(${external_library_full_name} PUBLIC cxx_std_17)
	set_target_properties(${external_library_full_name} PROPERTIES LINKED_LANGUAGE CXX)
	set_property(TARGET ${external_library_full_name} PROPERTY POSITION_INDEPENDENT_CODE ON)
	
	target_link_libraries(DLDL_LEXER_external_libraries PUBLIC ${external_library_full_name})
	
endfunction()

add_subdirectory(extern)
add_subdirectory(lib)

add_executable(DLDL_Lexer_Main "main.cpp")
target_link_libraries(DLDL_Lexer_Main DLDL_LEXER_static_library)
