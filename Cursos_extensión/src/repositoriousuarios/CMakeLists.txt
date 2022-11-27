add_library(repositoriousuarios repositoriousuarios.h repositoriousuarios.cc)
target_link_libraries(repositoriousuarios PUBLIC usuario)
target_link_libraries(repositoriousuarios PUBLIC cursodeextension)
target_include_directories(repositoriousuarios PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${PROJECT_SOURCE_DIR}/src/usuario
    ${PROJECT_SOURCE_DIR}/src/cursodeextension)

