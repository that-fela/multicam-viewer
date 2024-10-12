cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
include(cmake/CPM.cmake)
include(cmake/CompilerWarnings.cmake)
include(cmake/Sanitizers.cmake)


# CPM Packages
CPMAddPackage("gh:fmtlib/fmt#7.1.3")


# Google Testing
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(tests)

enable_compiler_warnings(main_program)
enable_compiler_warnings(test_mylib)

enable_sanitizers(main_program)
enable_sanitizers(test_mylib)