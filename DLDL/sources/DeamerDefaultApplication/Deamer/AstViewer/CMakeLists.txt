# This file is auto-generated and auto-maintained.
# Please don't change code in this file, as new changes will be discarded,
# when Deamer regenerates the project.
#
# If you want to contribute to Deamer.
# Please visit: https://github.com/Deruago/theDeamerProject 
#
# This file is part of the directory: AstViewer

add_executable(DLDLdeamerAstViewer main.cpp)
target_link_libraries(DLDLdeamerAstViewer PRIVATE Deamer::External Deamer::Algorithm deamer_reserved_DLDL_core_library)
