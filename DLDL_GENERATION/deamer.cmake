# This file is auto-generated and auto-maintained.
# Please don't change code in this file, as new changes will be discarded,
# when Deamer regenerates the project.
#
# If you want to contribute to Deamer.
# Please visit: https://github.com/Deruago/theDeamerProject 

find_package(Deamer_External REQUIRED)


add_library(DLDL_GENERATION_external_libraries STATIC "${DLDL_GENERATION_SOURCE_DIR}/lib/DLDL_GENERATION.cpp")
target_link_libraries(DLDL_GENERATION_external_libraries PUBLIC Deamer_External)
target_include_directories(DLDL_GENERATION_external_libraries PUBLIC "${DLDL_GENERATION_SOURCE_DIR}/extern" "${DLDL_GENERATION_SOURCE_DIR}/include")

function(DLDL_GENERATION_add_external_library external_library_name source_files)
	set(external_library_full_name "DLDL_GENERATION_${external_library_name}_static_library")

	add_library(${external_library_full_name} STATIC ${source_files})

	target_link_libraries(${external_library_full_name} PUBLIC Deamer_External)
	target_include_directories(${external_library_full_name} PRIVATE "${DLDL_GENERATION_SOURCE_DIR}/extern" "${DLDL_GENERATION_SOURCE_DIR}/include")
	target_compile_features(${external_library_full_name} PUBLIC cxx_std_17)
	set_target_properties(${external_library_full_name} PROPERTIES LINKED_LANGUAGE CXX)
	set_property(TARGET ${external_library_full_name} PROPERTY POSITION_INDEPENDENT_CODE ON)
	
	target_link_libraries(DLDL_GENERATION_external_libraries PUBLIC ${external_library_full_name})
	
endfunction()
