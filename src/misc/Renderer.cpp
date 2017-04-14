//
// Created by zakrent on 4/13/17.
//
#ifndef SDL_TILE_2_RENDER
#define SDL_TILE_2_RENDER

#include <SDL_rect.h>
#include <SDL_render.h>
#include "TextureWrapper.h"
#include "Vector2D.h"

namespace Render {

    inline void beginRendering(SDL_Renderer* renderer){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
    }

    inline void renderTexture(SDL_Renderer* renderer, TextureWrapper* textureClass, SDL_Rect srcrect, SDL_Rect camera, Vector2D position, Uint8 lightLevel, float scalingFactor = 1){
        SDL_Rect dstrect = {int(position.x) - camera.x, int(position.y) - camera.y, srcrect.w, srcrect.h};
        dstrect.x = ceil(dstrect.x/scalingFactor);
        dstrect.y = ceil(dstrect.y/scalingFactor);
        dstrect.w = ceil(dstrect.w/scalingFactor);
        dstrect.h = ceil(dstrect.h/scalingFactor);
        SDL_SetTextureColorMod(textureClass->texturePointer, lightLevel, lightLevel, lightLevel);
        SDL_RenderCopyEx(renderer, textureClass->texturePointer, &srcrect, &dstrect, 0, NULL, SDL_FLIP_NONE);
    }

    inline void swapBuffers(SDL_Renderer* renderer){
        SDL_RenderPresent(renderer);
    }

}

#endif