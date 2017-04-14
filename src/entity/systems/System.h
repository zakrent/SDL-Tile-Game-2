//
// Created by zakrent on 4/14/17.
//

#ifndef SDL_TILE_2_SYSTEM_H
#define SDL_TILE_2_SYSTEM_H

#include "../Entity.h"

namespace Entity {
    class System {
    public:
        virtual void updateEntity(Entity* entityPointer) {};

        System() {};
        virtual ~System() {};
    };
}

#endif //SDL_TILE_2_SYSTEM_H
