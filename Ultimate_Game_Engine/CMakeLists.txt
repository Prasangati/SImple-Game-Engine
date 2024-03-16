


cmake_minimum_required(VERSION 3.27)
project(Ultimate_Game_Engine)

set(CMAKE_CXX_STANDARD 20) # Adjust as needed


# Add the SUN_EXPORTS definition for this library
#add_compile_definitions($<TARGET_PROPERTY:NAME>_EXPORTS)

# Define the dynamic library with all necessary source files
#add_library(Ultimate_Game_Engine SHARED
#   src/pch.cpp
#   src/UltimateGame.cpp # Add other source files here
#)

# Specify where to find the public headers
#target_include_directories(Ultimate_Game_Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Setup precompiled header
#target_precompile_headers(Ultimate_Game_Engine PRIVATE src/pch.h)







set(HEADER_FILES
    src/UltimateGame.h,
        src/Utility.h,
        include/Ultimate.h
)

set (SOURCE_FILES
    src/UltimateGame.cpp
)

add_library(Ultimate_Game_Engine SHARED ${HEADER_FILES} ${SOURCE_FILES})
target_compile_definitions(Ultimate_Game_Engine
        PUBLIC
            $<$<CONFIG:Debug>:ULTIMATE_DEBUG=2>
            $<$<CONFIG:RelWithDebInfo>:ULTIMATE_DEBUG=1>
        PRIVATE
            ULTIMATE_EXPORTS
)

target_precompile_headers(Ultimate_Game_Engine PRIVATE src/pch.h)




