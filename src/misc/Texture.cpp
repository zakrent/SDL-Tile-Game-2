//
// Created by zakrent on 4/13/17.
//

#include "Texture.h"

Texture::Texture() {
    texturePointer = NULL;
}

Texture::~Texture() {
    if(texturePointer){
        SDL_DestroyTexture(texturePointer);
    }
}

void Texture::loadFromFile(SDL_Renderer* renderer, char* filePath) {
    SDL_Surface* tempSurface = NULL;
    tempSurface = SDL_LoadBMP(filePath);
    texturePointer = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    tempSurface = NULL;
}
