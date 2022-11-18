add_library(cursodeextension cursodeextension.h cursodeextension.cc)
target_link_libraries(cursodeextension PUBLIC usuario)
target_include_directories(cursodeextension PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${PROJECT_SOURCE_DIR}/src/usuario)

