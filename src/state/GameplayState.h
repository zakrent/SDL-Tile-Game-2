//
// Created by zakrent on 4/13/17.
//

#ifndef SDL_TILE_2_GAMEPLAYSTATE_H
#define SDL_TILE_2_GAMEPLAYSTATE_H

#include <SDL_events.h>
#include <SDL_render.h>
#include "State.h"
#include "../map/Map.h"
#include "../Program.h"

namespace State {
    class GameplayState : public State{
    private:
        Map::Map mainMap;
        Program* mainProgram;
    public:
        void update();
        void render(SDL_Renderer* renderer);
        void handleEvent(SDL_Event& event);

        GameplayState(Map::Map mainMap, Program *mainProgram);
        ~GameplayState();
    };
}


#endif //SDL_TILE_2_GAMEPLAYSTATE_H
