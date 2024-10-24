set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})
include_directories(shared)


# Server files
add_executable(${SERVER_BIN_NAME} 
    server/main_server.cpp
    shared/net_comm.cpp
)
target_link_libraries(${SERVER_BIN_NAME}  
    fmt::fmt
    ${OpenCV_LIBS}
    ${Boost_LIBRARIES}
)


# pis files
add_executable(${PIS_BIN_NAME}
    pis/main_pi.cpp
    shared/net_comm.cpp
)
target_link_libraries(${PIS_BIN_NAME}
    fmt::fmt
    ${OpenCV_LIBS}
    ${Boost_LIBRARIES}
)