cmake_minimum_required(VERSION 3.10)
project(multicam_viewer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
include(cmake/CPM.cmake)
include(cmake/CompilerWarnings.cmake)
include(cmake/Sanitizers.cmake)



# =========== Config ===========

set(SERVER_BIN_NAME server)
set(PIS_BIN_NAME pis)

# CPM Packages
CPMAddPackage("gh:fmtlib/fmt#7.1.3")
CPMAddPackage("gh:nlohmann/json@3.10.5")
CPMAddPackage("gh:catchorg/Catch2@3.4.0")

# Dependencies
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED)

# Libraries
set(LIBRARIES 
    fmt::fmt
    nlohmann_json::nlohmann_json
    ${OpenCV_LIBS}
    ${Boost_LIBRARIES}
    CACHE INTERNAL ""
)

# Include dirs
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

# ==============================


include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)

enable_compiler_warnings(${SERVER_BIN_NAME})
enable_compiler_warnings(${PIS_BIN_NAME})

enable_sanitizers(${SERVER_BIN_NAME})
enable_sanitizers(${PIS_BIN_NAME})