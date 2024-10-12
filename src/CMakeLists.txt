# Set the executable output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Source files
add_executable(main_program 
    main.cpp
)

# Local libs
target_link_libraries(main_program 
    mylib
)

# CPM Packages
target_link_libraries(main_program 
    fmt::fmt
)