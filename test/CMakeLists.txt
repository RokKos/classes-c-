# Include google test
add_subdirectory(googletest)
include_directories(googletest/googletest/include)
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})

set(TEST_FILES
    polynomial_unittest.cpp
    complex_unittest.cpp
    stack_unittest.cpp
)

add_executable(tests ${TEST_FILES})
# Linking up all libraries
target_link_libraries(tests polynomial gtest gtest_main)
