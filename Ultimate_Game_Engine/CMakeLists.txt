cmake_minimum_required(VERSION 3.27)
project(Ultimate_Game_Engine)

set(CMAKE_CXX_STANDARD 20) # Adjust as needed
set(HEADER_FILES
        include/Ultimate.h
    src/UltimateGame.h,
        src/Utility.h
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


if(MSVC)
    target_compile_definitions(Ultimate_Game_Engine PRIVATE ULTIMATE_EXPORTS)
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_definitions(Ultimate_Game_Engine PRIVATE ULTIMATE_EXPORTS)
endif()

target_precompile_headers(Ultimate_Game_Engine PRIVATE src/pch.h)

