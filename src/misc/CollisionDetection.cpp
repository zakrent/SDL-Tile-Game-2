//
// Created by zakrent on 4/13/17.
//
#include <SDL_rect.h>
#include <vector>
#include "../map/Tile.h"

namespace CollisionDetection{

    inline bool boundingBox(SDL_Rect collider1, SDL_Rect collider2){
        return (collider1.x+collider1.w > collider2.x &&
                collider1.x < collider2.x+collider2.w &&
                collider1.y+collider1.h > collider2.y &&
                collider1.y < collider2.y+collider2.h);
    }

    inline std::vector<Map::Tile*> getTilesToTest(Map::Tile* standingOn){
        std::vector<Map::Tile*> tilesToTest;
        if(standingOn) {
            tilesToTest.push_back(standingOn);
            tilesToTest.push_back(standingOn->neighbours[Map::Up]);
            tilesToTest.push_back(standingOn->neighbours[Map::Down]);
            tilesToTest.push_back(standingOn->neighbours[Map::Right]);
            tilesToTest.push_back(standingOn->neighbours[Map::Left]);
            if (standingOn->neighbours[Map::Up]) {
                tilesToTest.push_back(standingOn->neighbours[Map::Up]->neighbours[Map::Right]);
                tilesToTest.push_back(standingOn->neighbours[Map::Up]->neighbours[Map::Left]);
            }
            if (standingOn->neighbours[Map::Down]) {
                tilesToTest.push_back(standingOn->neighbours[Map::Down]->neighbours[Map::Right]);
                tilesToTest.push_back(standingOn->neighbours[Map::Down]->neighbours[Map::Left]);
            }
        }
        return tilesToTest;
    }

}
