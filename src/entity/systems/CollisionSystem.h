//
// Created by zakrent on 4/15/17.
//

#ifndef SDL_TILE_2_COLLISIONSYSTEM_H
#define SDL_TILE_2_COLLISIONSYSTEM_H

#include "System.h"
#include "../../map/Map.h"
#include "../../map/Tile.h"
#include "../../misc/CollisionDetection.cpp"

namespace Entity {
    class CollisionSystem : public System{
    public:
        void updateEntity(Entity* entityPointer);
        Map::Map* mainMap;
        CollisionSystem(Map::Map *mainMap) : mainMap(mainMap) {
            System::name = "CollisionSystem";
        };
        ~CollisionSystem() {};
    };
}


#endif //SDL_TILE_2_COLLISIONSYSTEM_H
