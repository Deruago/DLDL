find_package(Deamer REQUIRED)
find_package(Deamer_External REQUIRED)

add_subdirectory(${DLDL_SOURCE_DIR}/DLDL_LEXER)
add_subdirectory(${DLDL_SOURCE_DIR}/DLDL_GRAMMAR)

add_library(DLDL_external_libraries STATIC "${DLDL_SOURCE_DIR}/lib/DLDL.cpp")
target_link_libraries(DLDL_external_libraries PUBLIC Deamer Deamer_External DLDL_LEXER_static_library DLDL_GRAMMAR_static_library)
target_include_directories(DLDL_external_libraries PUBLIC "${DLDL_SOURCE_DIR}/extern" "${DLDL_SOURCE_DIR}/include"  "${DLDL_LEXER_SOURCE_DIR}/include" "${DLDL_GRAMMAR_SOURCE_DIR}/include")

function(DLDL_add_external_library external_library_name source_files)
	set(external_library_full_name "DLDL_${external_library_name}_static_library")

	add_library(${external_library_full_name} STATIC ${source_files})

	target_link_libraries(${external_library_full_name} PUBLIC Deamer Deamer_External)
	target_include_directories(${external_library_full_name} PRIVATE "${DLDL_SOURCE_DIR}/extern" "${DLDL_SOURCE_DIR}/include")
	target_compile_features(${external_library_full_name} PUBLIC cxx_std_17)
	set_target_properties(${external_library_full_name} PROPERTIES LINKED_LANGUAGE CXX)
	set_property(TARGET ${external_library_full_name} PROPERTY POSITION_INDEPENDENT_CODE ON)
	
	target_link_libraries(DLDL_external_libraries PUBLIC ${external_library_full_name})
	
endfunction()