//
// Created by zakrent on 4/13/17.
//
#ifndef SDL_TILE_2_MAP_H
#define SDL_TILE_2_MAP_H

#include <vector>
#include "Tile.h"
#include "../entity/Entity.h"
#include "../entity/components/Components.h"
#include "../Program.h"

namespace Map {

    const int MAP_HEIGHT = 50;
    const int MAP_WIDTH = 50;

    class Map {
    private:
        Program* mainProgram;
    public:
        std::vector< std::vector< Tile * > > tiles; //TODO : Remove debug
        std::vector<Entity::Entity*> entities;
        Tile* getTileAtPxPos(Vector2D position);
        void render(SDL_Renderer* renderer, SDL_Rect camera);
        void addEntity(std::vector<Entity::Component*> components);

        Map(Program *mainProgram);
        ~Map();
    };
}


#endif //SDL_TILE_2_MAP_H
