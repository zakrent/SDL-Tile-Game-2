cmake_minimum_required(VERSION 3.6)
project(SDL-Tile-2)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES src/main.cpp src/misc/Renderer.cpp src/misc/Vector2D.h src/misc/Vector2D.cpp src/misc/TextureWrapper.cpp src/misc/TextureWrapper.h src/Program.cpp src/Program.h src/state/State.cpp src/state/State.h src/state/GameplayState.cpp src/state/GameplayState.h src/map/Tile.cpp src/map/Tile.h src/map/Map.cpp src/map/Map.h src/misc/CollisionDetection.cpp src/entity/Entity.cpp src/entity/Entity.h src/entity/components/Component.h src/entity/components/PositionComponent.h src/entity/components/ColliderComponent.h src/entity/systems/System.cpp src/entity/systems/System.h src/entity/systems/PositionSystem.cpp src/entity/systems/PositionSystem.h src/entity/systems/Systems.h src/entity/components/Components.h src/entity/components/VisualComponent.h src/entity/systems/VisualSystem.cpp src/entity/systems/VisualSystem.h src/entity/components/CameraComponent.h src/entity/systems/CameraSystem.cpp src/entity/systems/CameraSystem.h src/entity/components/ControlComponent.h src/entity/systems/ControlSystem.cpp src/entity/systems/ControlSystem.h src/entity/systems/CollisionSystem.cpp src/entity/systems/CollisionSystem.h src/misc/Random.h src/entity/systems/PathSystem.cpp src/entity/systems/PathSystem.h src/entity/components/PathComponent.h src/UI/UIController.cpp src/UI/UIController.h src/UI/UIBaseElement.h src/UI/UIHealthElement.h src/entity/components/HealthComponent.h src/entity/systems/HealthSystem.cpp src/entity/systems/HealthSystem.h src/entity/components/BulletComponent.h src/entity/systems/BulletSystem.cpp src/entity/systems/BulletSystem.h src/entity/components/ShootingComponent.h src/entity/systems/ShootingSystem.cpp src/entity/systems/ShootingSystem.h)
add_executable(SDL-Tile-2 ${SOURCE_FILES} ${SOURCE_FILES})
target_link_libraries(SDL-Tile-2 ${SDL2_LIBRARY})
file(COPY textures/ DESTINATION textures/)