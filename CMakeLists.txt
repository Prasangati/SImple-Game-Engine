cmake_minimum_required(VERSION 3.27)
project(Prasanga_GAME VERSION 1.0 DESCRIPTION "Dynamic Library and Application")

# Set the C++ standard for the whole project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set a global output directory for all binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


# Include the glad library
add_subdirectory(glad)

# Include the stbi
add_subdirectory(stbi)

# Include the GLFW directory
add_subdirectory(glfw)

# Include the Ultimate Game Engine library
add_subdirectory(Ultimate_Game_Engine)

# Include the application that uses the library
add_subdirectory(S24_Prasanga_Tiwari)

# Optional: Set up the default startup project for Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT S24_Prasanga_Tiwari)

# Optional: Display a message with the GLFW include directory for debugging purposes
message(STATUS "GLFW include directory: ${PROJECT_SOURCE_DIR}/glfw/include")
message(STATUS "STB Image include directory: ${PROJECT_SOURCE_DIR}/stbi/include")
message(STATUS "GLAD include directory: ${PROJECT_SOURCE_DIR}/glad/include")
