cmake_minimum_required(VERSION 3.6)
project(SDL-Tile-2)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES)
add_executable(SDL-Tile-2 ${SOURCE_FILES} src/main.cpp)
target_link_libraries(SDL-Tile-2 ${SDL2_LIBRARY})
file(COPY textures/ DESTINATION textures/)