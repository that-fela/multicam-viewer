cmake_minimum_required(VERSION 3.10)
project(multicam_viewer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SERVER_BIN_NAME server)
set(PIS_BIN_NAME pis)

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

add_subdirectory(src)
add_subdirectory(tests)

enable_compiler_warnings(${SERVER_BIN_NAME})
enable_compiler_warnings(${PIS_BIN_NAME})

enable_sanitizers(${SERVER_BIN_NAME})
enable_sanitizers(${PIS_BIN_NAME})