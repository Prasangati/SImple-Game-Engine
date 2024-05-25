cmake_minimum_required(VERSION 3.27)
project(S24_Prasanga_Tiwari VERSION 1.0 DESCRIPTION "Application Using UltimateGame Library")

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the main executable
add_executable(S24_Prasanga_TiwariExecutable source.cpp Player.cpp)

# Include directories for Ultimate_Game_Engine
target_include_directories(S24_Prasanga_TiwariExecutable PRIVATE
        ${CMAKE_SOURCE_DIR}/Ultimate_Game_Engine/include
)

# Link the executable against the Ultimate_Game_Engine library
add_dependencies(S24_Prasanga_TiwariExecutable Ultimate_Game_Engine)
target_link_libraries(S24_Prasanga_TiwariExecutable PRIVATE Ultimate_Game_Engine)
