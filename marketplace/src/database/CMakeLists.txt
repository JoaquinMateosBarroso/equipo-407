add_library(database database.h database.cc)
target_link_libraries(database PUBLIC usuario)
target_link_libraries(database PUBLIC cursodeextension)
target_include_directories(database PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${PROJECT_SOURCE_DIR}/src/usuario
    ${PROJECT_SOURCE_DIR}/src/cursodeextension)

