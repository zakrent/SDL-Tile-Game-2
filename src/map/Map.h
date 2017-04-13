//
// Created by zakrent on 4/13/17.
//
#ifndef SDL_TILE_2_MAP_H
#define SDL_TILE_2_MAP_H

#include <vector>
#include "Tile.h"

namespace Map {

    const int MAP_HEIGHT = 20;
    const int MAP_WIDTH = 20;

    class Map {
    private:
        TextureWrapper* entitySheet;
        TextureWrapper* tileSheet;
        std::vector< std::vector< Tile * > > tiles;
        //std::vector<Entity*>
        SDL_Rect camera;

    public:
        Map(TextureWrapper *entitySheet, TextureWrapper *tileSheet);

        void render(SDL_Renderer* renderer);
        ~Map();
    };
}


#endif //SDL_TILE_2_MAP_H
