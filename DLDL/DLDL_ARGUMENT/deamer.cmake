# This file is auto-generated and auto-maintained.
# Please don't change code in this file, as new changes will be discarded,
# when Deamer regenerates the project.
#
# If you want to contribute to Deamer.
# Please visit: https://github.com/Deruago/theDeamerProject 

include(GNUInstallDirs)





add_library(deamer_reserved_DLDL_ARGUMENT_core_library ALIAS DLDL_static_library)

function(DLDL_ARGUMENT_add_external_library external_library_name source_files)
	target_sources(DLDL_static_library PRIVATE ${source_files})
endfunction()




