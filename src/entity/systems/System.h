//
// Created by zakrent on 4/14/17.
//

#ifndef SDL_TILE_2_SYSTEM_H
#define SDL_TILE_2_SYSTEM_H

#include "../Entity.h"
#include "../components/Components.h"

namespace Entity {
    class System {
    public:
        std::string name = "System";
        virtual void updateEntity(Entity* entityPointer) {};

        System() {};
        virtual ~System() {};
    };
}

#endif //SDL_TILE_2_SYSTEM_H
