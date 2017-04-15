//
// Created by zakrent on 4/13/17.
//

#include "Map.h"
#include "../Program.h"

namespace Map {
    Map::Map(Program *mainProgram) : mainProgram(mainProgram) {

        for (int x = 0; x < MAP_WIDTH; ++x) {
            std::vector<Tile *> currentRow;
            for (int y = 0; y < MAP_HEIGHT; ++y) {
                currentRow.push_back(new Tile(0, Vector2D(x*TILE_WIDTH, y*TILE_HEIGHT), &mainProgram->tileSheet));
            }
            tiles.push_back(currentRow);
        }
        tiles[4][2]->type = 1;

        //TODO:Remove debug
        entities.push_back(new Entity::Entity);
        entities.back()->addComponent(new Entity::PositionComponent());
        entities.back()->addComponent(new Entity::VisualComponent(&mainProgram->entitySheet,0));
        //
    }

    Map::~Map() {}

    void Map::render(SDL_Renderer *renderer, SDL_Rect camera) {
        for (std::vector<Tile *> row: tiles) {
            for (Tile *tile : row) {
                tile->render(renderer, camera);
            }
        }
    }

}