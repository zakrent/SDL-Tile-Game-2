//
// Created by zakrent on 4/13/17.
//

#include "TextureWrapper.h"

TextureWrapper::TextureWrapper() {
    texturePointer = NULL;
}

TextureWrapper::~TextureWrapper() {
    if(texturePointer){
        SDL_DestroyTexture(texturePointer);
    }
}

void TextureWrapper::loadFromFile(SDL_Renderer* renderer, char* filePath) {
    SDL_Surface* tempSurface = NULL;
    tempSurface = SDL_LoadBMP(filePath);
    texturePointer = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    tempSurface = NULL;
}
