//
// Created by zakrent on 4/22/17.
//

#ifndef SDL_TILE_2_HEALTHSYSTEM_H
#define SDL_TILE_2_HEALTHSYSTEM_H


#include "System.h"

namespace Entity {
    class HealthSystem : public System{
    public:
        void updateEntity(Entity* entityPointer);

        HealthSystem() {
            System::name = "HealthSystem";
        };
        ~HealthSystem() {};
    };
}

#endif //SDL_TILE_2_HEALTHSYSTEM_H
