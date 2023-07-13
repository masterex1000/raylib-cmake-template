cmake_minimum_required(VERSION 3.1)

project(my_project)

# Raylib

set(SUPPORT_FILEFORMAT_JPG ON CACHE BOOL "" FORCE)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(libs/raylib)

# Game

add_executable( game
    src/main.cpp
)

target_include_directories(game PUBLIC include/ src/)
target_compile_options(game PRIVATE -Wall)
target_link_libraries(game raylib)