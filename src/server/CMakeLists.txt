# Set the executable output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Source files
add_executable(${SERVER_BIN_NAME} 
    main.cpp
)

target_link_libraries(${SERVER_BIN_NAME}  
    fmt::fmt
    ${OpenCV_LIBS}
)