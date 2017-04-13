//
// Created by zakrent on 4/13/17.
//

#ifndef SDL_TILE_2_BASESTATE_H
#define SDL_TILE_2_BASESTATE_H

#include <SDL_render.h>
#include <SDL_events.h>

namespace State {
    class State {
    public:
        virtual void update() {};
        virtual void render(SDL_Renderer* renderer) {};
        virtual void handleEvent(SDL_Event& event) {};
    };
}

#endif //SDL_TILE_2_BASESTATE_H
