cmake_minimum_required(VERSION 3.27)
project(Ultimate_Game_Engine CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define source and header files for the Ultimate_Game_Engine
set(SOURCE_FILES
        src/UltimateGame.cpp
        src/UltimateWindow.cpp
        src/codeGLFW/WindowGLFW.cpp
        src/Image.cpp
        src/ShaderImplement.cpp
        src/ShaderImplement.h
)

set(HEADER_FILES
        include/Ultimate.h
        src/UltimateGame.h
        src/codeGLFW/WindowGLFW.h
        src/Utility.h
        src/UltimateWindow.h
        src/WindowImpl.h
        src/codeGLFW/WindowGLFW.h
        src/pch.h
        src/Image.h
        src/ImageImplement.h
        src/codeOpenGL/ImageOpenGL.cpp
        src/Shader.cpp
        src/Shader.h
        src/ShaderImplement.cpp
        src/ShaderImplement.h
        src/codeOpenGL/ShaderOpenGL.h
        src/codeOpenGL/ShaderOpenGL.cpp
)

# Define the Ultimate_Game_Engine as a shared library
add_library(Ultimate_Game_Engine SHARED ${SOURCE_FILES} ${HEADER_FILES})

# Specify the directories where the compiler should look for headers
target_include_directories(Ultimate_Game_Engine
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/../glfw/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../glad/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../stbi/include
)

# Enable precompiled headers
target_precompile_headers(Ultimate_Game_Engine PRIVATE src/pch.h)

# Definitions for controlling visibility and imports/exports
target_compile_definitions(Ultimate_Game_Engine PRIVATE
        ULTIMATE_OPENGL
        ULTIMATE_EXPORTS
        ULTIMATE_GLFW_WINDOW  # Define this to enable GLFW window implementation
        $<$<CONFIG:Debug>:ULTIMATE_DEBUG=2>
        $<$<CONFIG:RelWithDebInfo>:ULTIMATE_DEBUG=1>
)

# Link against GLFW and potentially other libraries
target_link_libraries(Ultimate_Game_Engine PRIVATE glfw glad stbi)

# Compiler-specific options
if(MSVC)
    target_compile_options(Ultimate_Game_Engine PRIVATE /W4)
else()
    target_compile_options(Ultimate_Game_Engine PRIVATE -Wall -Wextra)
endif()
