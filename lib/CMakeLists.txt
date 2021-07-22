# This file is auto-generated and auto-maintained.
# Please don't change code in this file, as new changes will be discarded,
# when Deamer regenerates the project.
#
# If you want to contribute to Deamer.
# Please visit: https://github.com/Deruago/theDeamerProject 
#
# This file is part of the directory: lib

file(GLOB_RECURSE SOURCE_LIST "${DLDL_SOURCE_DIR}/lib/*.cpp")

add_library(DLDL_static_library STATIC ${SOURCE_LIST})

target_include_directories(DLDL_static_library PUBLIC "${DLDL_SOURCE_DIR}/extern" "${DLDL_SOURCE_DIR}/include")
target_compile_features(DLDL_static_library PUBLIC cxx_std_17)
set_target_properties(DLDL_static_library PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(DLDL_static_library PUBLIC Deamer)
target_link_libraries(DLDL_static_library PUBLIC DLDL_external_libraries)
target_link_libraries(DLDL_static_library PUBLIC DLDL_LEXER_static_library)
target_link_libraries(DLDL_static_library PUBLIC DLDL_GRAMMAR_static_library)
target_link_libraries(DLDL_static_library PUBLIC DLDL_GENERATION_static_library)
target_link_libraries(DLDL_static_library PUBLIC DLDL_IDENTITY_static_library)
target_link_libraries(DLDL_static_library PUBLIC DLDL_PRECEDENCE_static_library)
target_link_libraries(DLDL_static_library PUBLIC DLDL_ASSOCIATIVITY_static_library)
target_link_libraries(DLDL_static_library PUBLIC DLDL_GRAMMAR_PRODUCTION_RULE_static_library)

add_library(DLDL_shared_library SHARED ${SOURCE_LIST})

target_include_directories(DLDL_shared_library PUBLIC "${DLDL_SOURCE_DIR}/extern" "${DLDL_SOURCE_DIR}/include")
target_compile_features(DLDL_shared_library PUBLIC cxx_std_17)
set_target_properties(DLDL_shared_library PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(DLDL_shared_library PUBLIC Deamer)
target_link_libraries(DLDL_shared_library PUBLIC DLDL_external_libraries)
target_link_libraries(DLDL_shared_library PUBLIC DLDL_LEXER_shared_library)
target_link_libraries(DLDL_shared_library PUBLIC DLDL_GRAMMAR_shared_library)
target_link_libraries(DLDL_shared_library PUBLIC DLDL_GENERATION_shared_library)
target_link_libraries(DLDL_shared_library PUBLIC DLDL_IDENTITY_shared_library)
target_link_libraries(DLDL_shared_library PUBLIC DLDL_PRECEDENCE_shared_library)
target_link_libraries(DLDL_shared_library PUBLIC DLDL_ASSOCIATIVITY_shared_library)
target_link_libraries(DLDL_shared_library PUBLIC DLDL_GRAMMAR_PRODUCTION_RULE_shared_library)

