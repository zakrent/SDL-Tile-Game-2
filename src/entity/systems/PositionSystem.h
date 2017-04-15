//
// Created by zakrent on 4/14/17.
//

#ifndef SDL_TILE_2_POSITIONSYSTEM_H
#define SDL_TILE_2_POSITIONSYSTEM_H

#include "System.h"

namespace Entity {
    class PositionSystem : public System{
    public:
        void updateEntity(Entity* entityPointer);

        PositionSystem() {
            System::name = "PositionSystem";
        };
        ~PositionSystem() {};
    };
}


#endif //SDL_TILE_2_POSITIONSYSTEM_H
