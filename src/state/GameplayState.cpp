//
// Created by zakrent on 4/13/17.
//

#include "GameplayState.h"
#include "../misc/Renderer.cpp"

namespace State {

    void GameplayState::update() {
        for (Entity::System* system : systems){
            if(system->name == "VisualSystem")
                continue;
            for (Entity::Entity* entity : mainMap.entities) {
                system->updateEntity(entity);
            }
        }
    }

    void GameplayState::render(SDL_Renderer *renderer) {
        mainMap.render(renderer, camera);
        Entity::VisualSystem system(mainProgram->renderer, &camera);
        for (Entity::System* system : systems){
            if(system->name != "VisualSystem")
                continue;
            for (Entity::Entity* entity : mainMap.entities) {
                system->updateEntity(entity);
            }
        }

    }

    void GameplayState::handleEvent(SDL_Event &event) {
        switch(event.type){
            case SDL_QUIT:
                mainProgram->stateStack.pop();
                break;
            default:
                break;
        }
    }

    void GameplayState::loadSystems(){
        systems.push_back(new Entity::ControlSystem());
        systems.push_back(new Entity::PathSystem(&mainMap));
        systems.push_back(new Entity::PositionSystem());
        systems.push_back(new Entity::CollisionSystem(&mainMap));
        systems.push_back(new Entity::CameraSystem());
        systems.push_back(new Entity::VisualSystem(mainProgram->renderer, &camera));
    }

    void GameplayState::loadEntities(){
        std::vector<Entity::Component*> components;
        components.push_back(new Entity::PositionComponent(Vector2D(32,32)));
        components.push_back(new Entity::VisualComponent(&mainProgram->entitySheet,0));
        components.push_back(new Entity::CameraComponent(&camera));
        components.push_back(new Entity::ControlComponent);
        components.push_back(new Entity::ColliderComponent({0,0,24,24}));
        mainMap.addEntity(components);

        std::vector<Entity::Component*> components2;
        components2.push_back(new Entity::PositionComponent(Vector2D(288,188)));
        components2.push_back(new Entity::VisualComponent(&mainProgram->entitySheet,0));
        components2.push_back(new Entity::PathComponent(mainMap.entities.back()));
        components2.push_back(new Entity::ColliderComponent({0,0,24,24}));
        mainMap.addEntity(components2);
    }

    GameplayState::GameplayState(Map::Map mainMap, Program *mainProgram) : mainMap(mainProgram), mainProgram(mainProgram) {
        camera = {0,0, SCREEN_WIDTH, SCREEN_HEIGHT};
        loadSystems();
        loadEntities();
    }

    GameplayState::~GameplayState() {}

}