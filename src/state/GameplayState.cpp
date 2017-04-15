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
        systems.push_back(new Entity::PositionSystem());
        systems.push_back(new Entity::VisualSystem(mainProgram->renderer, &camera));
    }

    GameplayState::GameplayState(Map::Map mainMap, Program *mainProgram) : mainMap(mainProgram), mainProgram(mainProgram) {
        camera = {0,0, SCREEN_WIDTH, SCREEN_HEIGHT};
        loadSystems();
    }

    GameplayState::~GameplayState() {}

}