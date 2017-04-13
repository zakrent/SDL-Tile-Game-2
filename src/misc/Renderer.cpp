//
// Created by zakrent on 4/13/17.
//

#include <SDL_rect.h>
#include <SDL_render.h>
#include "Texture.h"

namespace Render {

    void beginRendering(SDL_Renderer* renderer){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
    };

    void renderTexture(SDL_Renderer* renderer, Texture* textureClass, SDL_Rect srcrect, SDL_Rect camera, SDL_Rect position, float lightLevel){
        SDL_Rect dstrect = {position.x - camera.x, position.y - camera.y, position.w, position.h};
        SDL_SetTextureColorMod(textureClass->texturePointer, lightLevel, lightLevel, lightLevel);
        SDL_RenderCopyEx(renderer, textureClass->texturePointer, &srcrect, &dstrect, 0, NULL, SDL_FLIP_NONE);
    }

    void swapBuffers(SDL_Renderer* renderer){
        SDL_RenderPresent(renderer);
    };

}