//
// Created by zakrent on 4/13/17.
//

#include "Tile.h"
#include "../misc/Renderer.cpp"
namespace Map {

    Tile::Tile(int type, Vector2D position, TextureWrapper *tileSheet)
            : type(type), position(position), tileSheet(tileSheet) {
        this->state = 0;
        this->lightLevel=0xFF;
    }

    Tile::~Tile() {

    }

    void Tile::render(SDL_Renderer *renderer, SDL_Rect &camera) {
        SDL_Rect srcrect = {type * TILE_WIDTH, state * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT};
        Render::renderTexture(renderer, tileSheet, srcrect, camera, position, lightLevel);
    }
}