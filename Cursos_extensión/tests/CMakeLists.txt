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

#Testing2 basket library
# add_executable(basket_test2 basket_test2.cc)
# target_link_libraries(basket_test2
#  PRIVATE GTest::GTest basket
#  PRIVATE GTest::GTest tv
#  PRIVATE GTest::GTest product
#  PRIVATE GTest::GTest computer)
# add_test(basket_gtests basket_test2)