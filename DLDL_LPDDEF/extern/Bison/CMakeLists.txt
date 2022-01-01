# This file is auto-generated and auto-maintained.
# Please don't change code in this file, as new changes will be discarded,
# when Deamer regenerates the project.
#
# If you want to contribute to Deamer.
# Please visit: https://github.com/Deruago/theDeamerProject 
#
# This file is part of the directory: Bison

set(source_files ./DLDL_LPDDEF_parser.tab.cpp)
DLDL_LPDDEF_add_external_library(Bison ${source_files})
target_link_libraries(DLDL_LPDDEF_Bison_static_library PUBLIC DLDL_LPDDEF_Flex_static_library)
