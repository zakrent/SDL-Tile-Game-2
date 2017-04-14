//
// Created by zakrent on 4/13/17.
//

#include "GameplayState.h"
namespace State {

    void GameplayState::update() {
        Entity::Entity tempEntity;
        Entity::PositionComponent *component;
        component = new Entity::PositionComponent(Vector2D(10, 0));
        tempEntity.addComponent(component);
        mainMap.entities.push_back(&tempEntity);
        for (Entity::System* system : systems){
            for (Entity::Entity* entity : mainMap.entities) {
                system->updateEntity(entity);
            }
        }
    }

    void GameplayState::render(SDL_Renderer *renderer) {
        mainMap.render(renderer);
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

    GameplayState::GameplayState(Map::Map mainMap, Program *mainProgram) : mainMap(mainMap), mainProgram(mainProgram) {
        systems.push_back(new Entity::PositionSystem());
    }

    GameplayState::~GameplayState() {}

}