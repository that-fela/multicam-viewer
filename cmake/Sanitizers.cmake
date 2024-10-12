# Function to enable sanitizers for a target
function(enable_sanitizers target)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        # Enable AddressSanitizer (ASan)
        option(ENABLE_ASAN "Enable AddressSanitizer" ON)
        if(ENABLE_ASAN)
            target_compile_options(${target} PRIVATE -fsanitize=address)
            target_link_options(${target} PRIVATE -fsanitize=address)
        endif()

        # Enable UndefinedBehaviourSanitizer (UBSan)
        option(ENABLE_UBSAN "Enable UndefinedBehaviourSanitizer" ON)
        if(ENABLE_UBSAN)
            target_compile_options(${target} PRIVATE -fsanitize=undefined)
            target_link_options(${target} PRIVATE -fsanitize=undefined)
        endif()

        # Enable ThreadSanitizer (TSan)
        option(ENABLE_TSAN "Enable ThreadSanitizer" OFF) # Usually OFF by default as it's for multithreaded code
        if(ENABLE_TSAN)
            target_compile_options(${target} PRIVATE -fsanitize=thread)
            target_link_options(${target} PRIVATE -fsanitize=thread)
        endif()

        # Enable MemorySanitizer (MSan)
        option(ENABLE_MSAN "Enable MemorySanitizer" OFF) # Usually OFF by default as it's for memory issues
        if(ENABLE_MSAN)
            target_compile_options(${target} PRIVATE -fsanitize=memory)
            target_link_options(${target} PRIVATE -fsanitize=memory)
        endif()
    endif()
endfunction()
