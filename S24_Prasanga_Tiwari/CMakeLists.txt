cmake_minimum_required(VERSION 3.27)
project(S24_Prasanga_Tiwari VERSION 1.0 DESCRIPTION "Application Using Sun Library")

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Add the main executable
add_executable(S24_Prasanga_Tiwari source.cpp)

# Assuming the Sun library target is named "Sun", link it with the executable
target_link_libraries(S24_Prasanga_Tiwari PRIVATE Sun)
