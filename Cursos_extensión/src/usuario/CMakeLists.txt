add_library(usuario usuario.h)
target_include_directories(usuario PUBLIC
${CMAKE_CURRENT_LIST_DIR})

set_target_properties(usuario PROPERTIES LINKER_LANGUAGE CXX)