cmake_minimum_required(VERSION 3.27)
project(Prasanga_GAME VERSION 1.0 DESCRIPTION "Dynamic Library and Application")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(glad)
add_subdirectory(stbi)
add_subdirectory(glfw)
add_subdirectory(Ultimate_Game_Engine)
add_subdirectory(S24_Prasanga_Tiwari)


message(STATUS "GLFW include directory: ${PROJECT_SOURCE_DIR}/glfw/include")
message(STATUS "STB Image include directory: ${PROJECT_SOURCE_DIR}/stbi/include")
message(STATUS "GLAD include directory: ${PROJECT_SOURCE_DIR}/glad/include")

add_custom_target(copy_assets ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Assets ${CMAKE_BINARY_DIR}/Assets
)
add_dependencies(Ultimate_Game_Engine copy_assets)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT S24_Prasanga_Tiwari)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR})
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)
