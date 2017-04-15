//
// Created by zakrent on 4/13/17.
//

#include "Map.h"
#include "../Program.h"

namespace Map {
    Map::Map(Program *mainProgram) : mainProgram(mainProgram) {
        entities.clear();
        for (int x = 0; x < MAP_WIDTH; ++x) {
            std::vector<Tile *> currentRow;
            for (int y = 0; y < MAP_HEIGHT; ++y) {
                currentRow.push_back(new Tile(0, Vector2D(x*TILE_WIDTH, y*TILE_HEIGHT), &mainProgram->tileSheet));
            }
            tiles.push_back(currentRow);
        }
        for (int x = 0; x < MAP_WIDTH; ++x) {
            for (int y = 0; y < MAP_HEIGHT; ++y) {
                if(y>0)
                    tiles[x][y]->neighbours[Up]=tiles[x][y-1];
                if(y<MAP_WIDTH-1)
                    tiles[x][y]->neighbours[Down]=tiles[x][y+1];
                if(x>0)
                    tiles[x][y]->neighbours[Left]=tiles[x-1][y];
                if(x<MAP_HEIGHT-1)
                    tiles[x][y]->neighbours[Right]=tiles[x+1][y];
            }
        }

        tiles[4][2]->type = 1;
        tiles[4][2]->neighbours[Right]->type = 1;
    }

    Map::~Map() {}

    void Map::render(SDL_Renderer *renderer, SDL_Rect camera) {
        for (std::vector<Tile *> row: tiles) {
            for (Tile *tile : row) {
                tile->render(renderer, camera);
            }
        }
    }

    void Map::addEntity(std::vector<Entity::Component*> components) {
        entities.push_back(new Entity::Entity);
        for(Entity::Component* component : components){
            entities.back()->addComponent(component);
        }
    }

    Tile *Map::getTileAtPxPos(Vector2D position) {
        int tilePosX = int((position.x - (int(position.x) % TILE_WIDTH))/TILE_WIDTH);
        if(tilePosX < 0 || tilePosX > MAP_WIDTH)
            return nullptr;
        int tilePosY = int((position.y - (int(position.y) % TILE_HEIGHT))/TILE_HEIGHT);
        if(tilePosY < 0 || tilePosY > MAP_HEIGHT)
            return nullptr;
        return tiles[tilePosX][tilePosY];
    }
}