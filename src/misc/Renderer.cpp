//
// Created by zakrent on 4/13/17.
//
#ifndef SDL_TILE_2_RENDER
#define SDL_TILE_2_RENDER

#include <SDL_rect.h>
#include <SDL_render.h>
#include "TextureWrapper.h"

namespace Render {

    inline void beginRendering(SDL_Renderer* renderer){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
    }

    inline void renderTexture(SDL_Renderer* renderer, TextureWrapper* textureClass, SDL_Rect srcrect, SDL_Rect camera, SDL_Rect position, float lightLevel){
        SDL_Rect dstrect = {position.x - camera.x, position.y - camera.y, position.w, position.h};
        SDL_SetTextureColorMod(textureClass->texturePointer, lightLevel, lightLevel, lightLevel);
        SDL_RenderCopyEx(renderer, textureClass->texturePointer, &srcrect, &dstrect, 0, NULL, SDL_FLIP_NONE);
    }

    inline void swapBuffers(SDL_Renderer* renderer){
        SDL_RenderPresent(renderer);
    }

}

#endif