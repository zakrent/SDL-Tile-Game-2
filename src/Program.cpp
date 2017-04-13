//
// Created by zakrent on 4/13/17.
//

#include "Program.h"
#include "misc/Renderer.cpp"
#include "state/GameplayState.h"

Program::Program() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    stateStack.push(new State::GameplayState);
}

Program::~Program() {
    SDL_Quit();
}

void Program::startMainLoop() {

    while(!stateStack.empty()) {

        SDL_Event event;
        while( SDL_PollEvent( &event) != 0 ) {
            stateStack.top()->handleEvent(event);
        }

        stateStack.top()->update();

        Render::beginRendering(renderer);
        stateStack.top()->render(renderer);
        Render::swapBuffers(renderer);

        if (!SDL_TICKS_PASSED(SDL_GetTicks() + 1, lastUpdate + MIN_UPDATE_TIME)) {
            SDL_Delay((lastUpdate + MIN_UPDATE_TIME) - SDL_GetTicks());
        }
    }
}
