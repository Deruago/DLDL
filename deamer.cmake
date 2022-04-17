# This file is auto-generated and auto-maintained.
# Please don't change code in this file, as new changes will be discarded,
# when Deamer regenerates the project.
#
# If you want to contribute to Deamer.
# Please visit: https://github.com/Deruago/theDeamerProject 

include(GNUInstallDirs)





add_library(DLDL_static_library STATIC)
target_compile_features(DLDL_static_library PUBLIC cxx_std_17)
set_target_properties(DLDL_static_library PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(DLDL_static_library PUBLIC 
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries(DLDL_static_library PRIVATE Deamer::External Deamer::Algorithm)


function(DLDL_root_library_extend projectname extern_directory include_directory source_files)
	target_sources(DLDL_static_library PRIVATE ${source_files})

	target_include_directories(DLDL_static_library PUBLIC 
		$<BUILD_INTERFACE:${include_directory}>
		$<BUILD_INTERFACE:${extern_directory}>
	)
endfunction()


add_library(deamer_reserved_DLDL_core_library ALIAS DLDL_static_library)

function(DLDL_add_external_library external_library_name source_files)
	target_sources(DLDL_static_library PRIVATE ${source_files})
endfunction()

add_subdirectory(DLDL_ASSOCIATIVITY)
add_subdirectory(DLDL_GENERATION)
add_subdirectory(DLDL_GRAMMAR)
add_subdirectory(DLDL_IDENTITY)
add_subdirectory(DLDL_LDOSTRUCT)
add_subdirectory(DLDL_LEXER)
add_subdirectory(DLDL_LPDDEF)
add_subdirectory(DLDL_LPDSTRUCT)
add_subdirectory(DLDL_OOPSYNTAX)
add_subdirectory(DLDL_PRECEDENCE)



