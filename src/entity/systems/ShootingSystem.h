//
// Created by zakrent on 5/2/17.
//

#ifndef SDL_TILE_2_SHOOTINGSYSTEM_H
#define SDL_TILE_2_SHOOTINGSYSTEM_H

#include "System.h"
#include "../../map/Map.h"

namespace Entity {
    class ShootingSystem : public System{
    public:
        Map::Map* mainMap;
        void updateEntity(Entity* entityPointer);

        ShootingSystem(Map::Map* mainMap) : mainMap(mainMap) {
            System::name = "ShootingSystem";
        };
        ~ShootingSystem() {};
    };
}


#endif //SDL_TILE_2_SHOOTINGSYSTEM_H
