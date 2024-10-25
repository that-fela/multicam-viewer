set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

function(find_cpp_files RESULT DIR)
    file(GLOB_RECURSE CPP_FILES 
        "${DIR}/*.cpp"
        "${DIR}/*.cxx"
        "${DIR}/*.cc"
    )
    set(${RESULT} ${CPP_FILES} PARENT_SCOPE)
endfunction()

# Server files
find_cpp_files(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/${SERVER_BIN_NAME} )
add_executable(${SERVER_BIN_NAME} ${SOURCE_FILES})
target_link_libraries(${SERVER_BIN_NAME} ${LIBRARIES})

# pis files
find_cpp_files(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PIS_BIN_NAME} )
add_executable(${PIS_BIN_NAME} ${SOURCE_FILES})
target_link_libraries(${PIS_BIN_NAME} ${LIBRARIES})