//
// Created by zakrent on 4/13/17.
//

#ifndef SDL_TILE_2_TEXTURE_H
#define SDL_TILE_2_TEXTURE_H


#include <SDL_render.h>

class TextureWrapper {
public:
    SDL_Texture* texturePointer;

    void loadFromFile(SDL_Renderer* renderer, char* filePath);

    TextureWrapper();
    ~TextureWrapper();
};


#endif //SDL_TILE_2_TEXTURE_H
