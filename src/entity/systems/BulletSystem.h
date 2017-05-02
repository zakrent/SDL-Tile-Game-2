//
// Created by zakrent on 5/1/17.
//

#ifndef SDL_TILE_2_BULLETSYSTEM_H
#define SDL_TILE_2_BULLETSYSTEM_H

#include "../Entity.h"
#include "../../map/Map.h"
#include "System.h"

namespace Entity {
    class BulletSystem : public System{
    public:
        void updateEntity(Entity* entityPointer);
        Map::Map* mainMap;
        BulletSystem(Map::Map *mainMap) : mainMap(mainMap) {
            System::name = "BulletSystem";
        };
        ~BulletSystem() {};
    };
}

#endif //SDL_TILE_2_BULLETSYSTEM_H
