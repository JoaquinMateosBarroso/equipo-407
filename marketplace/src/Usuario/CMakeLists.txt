add_library(Usuario Usuario.h)
target_include_directories(Usuario PUBLIC
${CMAKE_CURRENT_LIST_DIR})

set_target_properties(Usuario PROPERTIES LINKER_LANGUAGE CXX)