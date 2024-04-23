cmake_minimum_required(VERSION 3.27)
project(S24_Prasanga_Tiwari VERSION 1.0 DESCRIPTION "Application Using UltimateGame Library")

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the main executable
add_executable(S24_Prasanga_Tiwari source.cpp)

# Assuming the Ultimate_Game_Engine library is in a sibling directory
# Adjust the path according to your project structure
target_include_directories(S24_Prasanga_Tiwari PRIVATE
        ${CMAKE_SOURCE_DIR}/Ultimate_Game_Engine/include
)

# Link the executable against the Ultimate_Game_Engine library
# Ensure that Ultimate_Game_Engine is built before S24_Prasanga_Tiwari
add_dependencies(S24_Prasanga_Tiwari Ultimate_Game_Engine)
target_link_libraries(S24_Prasanga_Tiwari PRIVATE Ultimate_Game_Engine)
