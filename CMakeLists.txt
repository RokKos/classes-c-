cmake_minimum_required (VERSION 2.6)
project (Polynomial)

# Setting default folders
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Include header files
include_directories(src)
# Include .cpp files
add_subdirectory(src)

set(MAIN_FILE src/testPolynomial.cpp)

add_executable(testfile ${MAIN_FILE})
# Linking up all libraries
target_link_libraries(testfile polynomial)
