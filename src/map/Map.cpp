//
// Created by zakrent on 4/13/17.
//

#include "Map.h"
namespace Map {
    Map::Map(TextureWrapper *entitySheet, TextureWrapper *tileSheet) : entitySheet(entitySheet), tileSheet(tileSheet) {
        camera = {0,0,320, 640};

        for (int x = 0; x < MAP_WIDTH; ++x) {
            std::vector<Tile *> currentRow;
            for (int y = 0; y < MAP_HEIGHT; ++y) {
                currentRow.push_back(new Tile(0, Vector2D(x*TILE_WIDTH, y*TILE_HEIGHT), tileSheet));
            }
            tiles.push_back(currentRow);
        }
    }

    Map::~Map() {}

    void Map::render(SDL_Renderer *renderer) {
        for (std::vector<Tile *> row: tiles) {
            for (Tile *tile : row) {
                tile->render(renderer, camera);
            }
        }
    }

}