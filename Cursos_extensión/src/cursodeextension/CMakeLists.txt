add_library(cursodeextension cursodeextension.h cursodeextension.cc)
target_link_libraries(cursodeextension PUBLIC usuario)
target_link_libraries(cursodeextension PUBLIC repositoriousuarios)
target_link_libraries(cursodeextension PUBLIC repositoriocursos)
target_link_libraries(cursodeextension PUBLIC repositoriorecursos)
target_link_libraries(cursodeextension PUBLIC database)
target_include_directories(cursodeextension PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${PROJECT_SOURCE_DIR}/src/usuario
    ${PROJECT_SOURCE_DIR}/src/repositoriorecursos
    ${PROJECT_SOURCE_DIR}/src/repositoriocursos
    ${PROJECT_SOURCE_DIR}/src/database
    ${PROJECT_SOURCE_DIR}/src/repositoriousuarios)

