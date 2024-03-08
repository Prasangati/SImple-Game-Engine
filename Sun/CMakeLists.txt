cmake_minimum_required(VERSION 3.27)
project(Sun)

set(CMAKE_CXX_STANDARD 20) # Adjust as needed


# Add the SUN_EXPORTS definition for this library
add_compile_definitions($<TARGET_PROPERTY:NAME>_EXPORTS)

# Define the dynamic library with all necessary source files
add_library(Sun SHARED
        src/pch.cpp
        src/SunApplication.cpp # Add other source files here
)

# Specify where to find the public headers
target_include_directories(Sun PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Setup precompiled header
target_precompile_headers(Sun PRIVATE src/pch.h)






