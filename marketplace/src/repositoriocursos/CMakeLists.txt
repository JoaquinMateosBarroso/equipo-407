add_library(repositoriocursos repositoriocursos.h repositoriocursos.cc)
target_link_libraries(repositoriocursos PUBLIC usuario)
target_link_libraries(repositoriocursos PUBLIC cursodeextension)
target_include_directories(repositoriocursos PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${PROJECT_SOURCE_DIR}/src/usuario
    ${PROJECT_SOURCE_DIR}/src/cursodeextension)

