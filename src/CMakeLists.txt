# Set the executable output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Source files
add_executable(${BIN_NAME} 
    main.cpp
)

target_link_libraries(${BIN_NAME}  
    mylib
    fmt::fmt
)
