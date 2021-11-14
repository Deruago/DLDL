# This file is auto-generated and auto-maintained.
# Please don't change code in this file, as new changes will be discarded,
# when Deamer regenerates the project.
#
# If you want to contribute to Deamer.
# Please visit: https://github.com/Deruago/theDeamerProject 

find_package(Deamer_External REQUIRED)
find_package(Deamer_Algorithm REQUIRED)


add_library(DLDL_external_libraries STATIC "${DLDL_SOURCE_DIR}/lib/DLDL.cpp")
target_link_libraries(DLDL_external_libraries PUBLIC Deamer_External)
target_link_libraries(DLDL_external_libraries PUBLIC Deamer_Algorithm)
target_include_directories(DLDL_external_libraries PUBLIC "${DLDL_SOURCE_DIR}/extern" "${DLDL_SOURCE_DIR}/include")

add_library(DLDL_static_library STATIC)
target_compile_features(DLDL_static_library PUBLIC cxx_std_17)
set_target_properties(DLDL_static_library PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(DLDL_static_library PUBLIC DLDL_external_libraries Deamer_External Deamer_Algorithm)

add_library(DLDL_shared_library SHARED)
target_compile_features(DLDL_shared_library PUBLIC cxx_std_17)
set_target_properties(DLDL_shared_library PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(DLDL_shared_library PUBLIC DLDL_external_libraries Deamer_External Deamer_Algorithm)

function(DLDL_root_library_extend projectname extern_directory include_directory source_files)
	target_sources(DLDL_static_library PRIVATE ${source_files})
	target_sources(DLDL_shared_library PRIVATE ${source_files})

	target_include_directories(DLDL_static_library PUBLIC ${extern_directory} ${include_directory})
	target_include_directories(DLDL_shared_library PUBLIC ${extern_directory} ${include_directory})
endfunction()


function(DLDL_add_external_library external_library_name source_files)
	set(external_library_full_name "DLDL_${external_library_name}_static_library")
	add_library(${external_library_full_name} STATIC ${source_files})

	target_link_libraries(${external_library_full_name} PUBLIC Deamer_External)
	target_link_libraries(${external_library_full_name} PUBLIC Deamer_Algorithm)
	target_include_directories(${external_library_full_name} PRIVATE "${DLDL_SOURCE_DIR}/extern" "${DLDL_SOURCE_DIR}/include")
	target_compile_features(${external_library_full_name} PUBLIC cxx_std_17)
	set_target_properties(${external_library_full_name} PROPERTIES LINKED_LANGUAGE CXX)
	set_property(TARGET ${external_library_full_name} PROPERTY POSITION_INDEPENDENT_CODE ON)
	
	target_link_libraries(DLDL_external_libraries PUBLIC ${external_library_full_name})
endfunction()

add_subdirectory(DLDL_ASSOCIATIVITY)
add_subdirectory(DLDL_GENERATION)
add_subdirectory(DLDL_GRAMMAR)
add_subdirectory(DLDL_IDENTITY)
add_subdirectory(DLDL_LEXER)
add_subdirectory(DLDL_PRECEDENCE)
