//
// Created by zakrent on 4/13/17.
//
#ifndef SDL_TILE_2_MAP_H
#define SDL_TILE_2_MAP_H

#include <vector>
#include "Tile.h"
#include "../entity/Entity.h"

namespace Map {

    const int MAP_HEIGHT = 20;
    const int MAP_WIDTH = 20;

    class Map {
    private:
        std::vector< std::vector< Tile * > > tiles;
        TextureWrapper* entitySheet;
        TextureWrapper* tileSheet;
        SDL_Rect camera;
    public:
        std::vector<Entity::Entity*> entities;
        void render(SDL_Renderer* renderer);

        Map(TextureWrapper *entitySheet, TextureWrapper *tileSheet);
        ~Map();
    };
}


#endif //SDL_TILE_2_MAP_H
