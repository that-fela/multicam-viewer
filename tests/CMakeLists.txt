# Set the test output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add the test executable
add_executable(test_mylib 
    test_mylib.cpp
)

# Link GoogleTest and the dynamic library to the test executable
target_link_libraries(test_mylib gtest gtest_main mylib)

# Add the tests to CMake
include(GoogleTest)
gtest_discover_tests(test_mylib)
