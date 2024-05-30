cmake_minimum_required(VERSION 3.27)
project(stbi CXX)

# Add the static library target
add_library(stbi STATIC src/stb_image.cpp)

# Include the `include` directory
target_include_directories(stbi PUBLIC include)
