cmake_minimum_required(VERSION 3.27)
project(Ultimate_Game CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define source and header files for the Ultimate_Game
set(SOURCE_FILES
        src/UltimateGame.cpp
        src/UltimateWindow.cpp
        src/codeGLFW/WindowGLFW.cpp
        src/Image.cpp
        src/Shader.cpp
        src/codeOpenGL/ShaderOpenGL.cpp
        src/codeOpenGL/ImageOpenGL.cpp
        src/Renderer.cpp
        src/codeOpenGL/RendererOpenGL.cpp
        src/UltimateEvents.cpp
        src/Unit.cpp
)

set(HEADER_FILES
        include/Ultimate.h
        src/UltimateGame.h
        src/codeGLFW/WindowGLFW.h
        src/utility.h
        src/UltimateWindow.h
        src/WindowImpl.h
        src/pch.h
        src/Image.h
        src/ImageImplement.h
        src/Shader.h
        src/ShaderImplement.h
        src/codeOpenGL/ShaderOpenGL.h
        src/Renderer.h
        src/RendererImplement.h
        src/codeOpenGL/RendererOpenGL.h
        src/UltimateEvents.h
        src/UltimateKeys.h
        src/Unit.h
        src/codeOpenGL/ImageOpenGL.h
)

# Define the Ultimate_Game as a shared library
add_library(Ultimate_Game SHARED ${SOURCE_FILES} ${HEADER_FILES})


target_compile_definitions(Ultimate_Game PRIVATE
        PUBLIC
            $<$<CONFIG:Debug>:ULTIMATE_DEBUG=2>
            $<$<CONFIG:RelWithDebInfo>:ULTIMATE_DEBUG=1>

        PRIVATE
            ULTIMATE_OPENGL
            ULTIMATE_EXPORTS
            ULTIMATE_GLFW_WINDOW  # Define this to enable GLFW window implementation
            ULTIMATE_LIB
)

# Compiler-specific options
if(MSVC)
    target_compile_options(Ultimate_Game PRIVATE /W4)
else()
    target_compile_options(Ultimate_Game PRIVATE -Wall -Wextra)
endif()


# Specify the directories where the compiler should look for headers
target_include_directories(Ultimate_Game
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/../glfw/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../glad/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../stbi/include
)

# Enable precompiled headers
target_precompile_headers(Ultimate_Game PRIVATE src/pch.h)



# Link against GLFW and potentially other libraries
target_link_libraries(Ultimate_Game PRIVATE glfw glad stbi)



