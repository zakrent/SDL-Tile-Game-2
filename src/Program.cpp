//
// Created by zakrent on 4/13/17.
//

#include "Program.h"
#include "misc/Renderer.cpp"

Program::Program() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

Program::~Program() {
    SDL_Quit();
}

void Program::render() {

    Render::beginRendering(renderer);
    Render::swapBuffers(renderer);
}
