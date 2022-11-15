add_library(person person.h person.cc)
target_include_directories(person PUBLIC
${CMAKE_CURRENT_LIST_DIR})

add_executable(person_main person_main.cc)
target_link_libraries(person_main PUBLIC person)