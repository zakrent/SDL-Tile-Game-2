//
// Created by zakrent on 4/13/17.
//

#include "GameplayState.h"
namespace State {

    void GameplayState::update() {}

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

    }

    GameplayState::~GameplayState() {

    }

}