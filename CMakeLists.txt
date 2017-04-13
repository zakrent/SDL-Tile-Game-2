cmake_minimum_required(VERSION 3.6)
project(SDL-Tile-2)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES src/main.cpp src/misc/Renderer.cpp src/misc/Vector2D.h src/misc/Vector2D.cpp src/misc/TextureWrapper.cpp src/misc/TextureWrapper.h src/Program.cpp src/Program.h src/state/State.cpp src/state/State.h src/state/GameplayState.cpp src/state/GameplayState.h src/map/Tile.cpp src/map/Tile.h src/map/Map.cpp src/map/Map.h)
add_executable(SDL-Tile-2 ${SOURCE_FILES} ${SOURCE_FILES})
target_link_libraries(SDL-Tile-2 ${SDL2_LIBRARY})
file(COPY textures/ DESTINATION textures/)