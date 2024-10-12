# Check if the compiler is GCC or Clang, and set the warning flags accordingly
function(enable_compiler_warnings target)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        # GCC-specific warnings
        target_compile_options(${target} PRIVATE
            -Wall        # All common warnings
            -Wextra      # Extra warnings
            -Wpedantic   # Strict ISO C++
            -Wshadow     # Warn when a variable shadows another
            -Wnon-virtual-dtor # Warn for classes with virtual methods and non-virtual destructors
            -Wold-style-cast    # Warn for old C-style casts
            -Wcast-align         # Warn on misaligned cast
            -Woverloaded-virtual # Warn when a base class method is hidden by another method
            -Wconversion         # Warn on type conversions
            -Wsign-conversion    # Warn on signed/unsigned conversions
            -Wnull-dereference   # Warn if a null pointer dereference is detected
        )
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        # Clang-specific warnings
        target_compile_options(${target} PRIVATE
            -Wall        # All common warnings
            -Wextra      # Extra warnings
            -Wpedantic   # Strict ISO C++
            -Wshadow     # Warn when a variable shadows another
            -Wnon-virtual-dtor # Warn for classes with virtual methods and non-virtual destructors
            -Wold-style-cast    # Warn for old C-style casts
            -Wcast-align         # Warn on misaligned cast
            -Woverloaded-virtual # Warn when a base class method is hidden by another method
            -Wconversion         # Warn on type conversions
            -Wsign-conversion    # Warn on signed/unsigned conversions
            -Wnull-dereference   # Warn if a null pointer dereference is detected
            -Wdouble-promotion   # Warn when a float is promoted to double
        )
    endif()
endfunction()
