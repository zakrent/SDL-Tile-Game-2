//
// Created by zakrent on 4/13/17.
//

#ifndef SDL_TILE_2_PROGRAM_H
#define SDL_TILE_2_PROGRAM_H

#include <SDL.h>
#include <stack>
#include "state/State.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT= 320;

class Program {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    Uint32 lastUpdate;
    const Uint32 MIN_UPDATE_TIME = 20;
    std::stack<State::State*> stateStack;
public:
    void startMainLoop();

    Program();
    ~Program();

};


#endif //SDL_TILE_2_PROGRAM_H
