cmake_minimum_required(VERSION 3.27)
project(S24_Prasanga_Tiwari VERSION 1.0 DESCRIPTION "Application Using Sun Library")

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Add the main executable
add_executable(S24_Prasanga_Tiwari source.cpp)

# Assuming the Ultimate_Game_Engine library target is named "Ultimate_Game_Engine", link it with the executable
target_link_libraries(S24_Prasanga_Tiwari PRIVATE Ultimate_Game_Engine)
