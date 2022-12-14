# GTest include code for fetch content over the internet 
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)
# End GTest include code 

# Testing historia1
add_executable(historia1_test historia1_test.cc)
target_link_libraries(historia1_test
  PRIVATE GTest::GTest database)
add_test(historia1_gtests historia1_test)

# Testing historia2
add_executable(historia2_test historia2_test.cc)
target_link_libraries(historia2_test
  PRIVATE GTest::GTest database)
add_test(historia1_gtests historia2_test)
