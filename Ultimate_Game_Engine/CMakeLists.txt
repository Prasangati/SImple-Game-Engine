cmake_minimum_required(VERSION 3.27)
project(Ultimate_Game_Engine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Assuming the GLFW source is directly included in your project under glfw directory
# This line should be in your top-level CMakeLists.txt, not inside this library-specific CMakeLists.txt
# add_subdirectory(glfw)

# Define source and header files for the Ultimate_Game_Engine
set(SOURCE_FILES
        src/UltimateGame.cpp
        src/UltimateWindow.cpp
        src/WindowImpl.cpp
        src/codeGLFW/WindowGLFW.cpp
        src/pch.cpp  # For precompiled headers
        # Add any additional .cpp files here
)

set(HEADER_FILES
        include/Ultimate.h
        src/UltimateGame.h
        src/Utility.h
        src/UltimateWindow.h
        src/WindowImpl.h
        src/codeGLFW/WindowGLFW.h
        src/pch.h  # For precompiled headers
        # Add any additional .h files here
)

# Define the Ultimate_Game_Engine as a shared library
add_library(Ultimate_Game_Engine SHARED ${SOURCE_FILES} ${HEADER_FILES})

# Set include directories
target_include_directories(Ultimate_Game_Engine
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        PRIVATE
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/glfw/include  # Explicitly including GLFW's include directory
)

# Precompiled header setup
target_precompile_headers(Ultimate_Game_Engine PRIVATE src/pch.h)

# Compiler definitions
target_compile_definitions(Ultimate_Game_Engine
        PUBLIC
        $<$<CONFIG:Debug>:ULTIMATE_DEBUG=2>
        $<$<CONFIG:RelWithDebInfo>:ULTIMATE_DEBUG=1>
        PRIVATE
        ULTIMATE_EXPORTS
)

# Link against GLFW and potentially other libraries
target_link_libraries(Ultimate_Game_Engine PRIVATE glfw)

# For MSVC specific options or definitions
if(MSVC)
    target_compile_options(Ultimate_Game_Engine PRIVATE /W4) # Example MSVC compiler flag
    # Additional MSVC-specific settings
endif()

# For GCC or Clang specific options or definitions
if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(Ultimate_Game_Engine PRIVATE -Wall -Wextra) # Example GCC/Clang flags
    # Additional GCC/Clang-specific settings
endif()
