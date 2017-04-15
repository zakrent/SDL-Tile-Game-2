//
// Created by zakrent on 4/13/17.
//

#ifndef SDL_TILE_2_PROGRAM_H
#define SDL_TILE_2_PROGRAM_H

#include <SDL.h>
#include <stack>
#include "state/State.h"
#include "misc/TextureWrapper.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT= 320;

class Program {
private:
    const Uint32 MIN_UPDATE_TIME = 10;
    SDL_Window* window;
    Uint32 lastUpdate;
public:
    SDL_Renderer* renderer;
    TextureWrapper entitySheet;
    TextureWrapper tileSheet;
    std::stack<State::State*> stateStack;
    void startMainLoop();

    Program();
    ~Program();

};


#endif //SDL_TILE_2_PROGRAM_H
