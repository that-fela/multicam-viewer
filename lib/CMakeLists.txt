# Set the library output directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Create the dynamic library
add_library(mylib SHARED 
    mylib.cpp
)

# Specify the include directories for this target
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
