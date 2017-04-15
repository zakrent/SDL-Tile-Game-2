//
// Created by zakrent on 4/15/17.
//

#ifndef SDL_TILE_2_CONTROLSYSTEM_H
#define SDL_TILE_2_CONTROLSYSTEM_H

#include "System.h"

namespace Entity {
    class ControlSystem : public System{
    public:
        void updateEntity(Entity* entityPointer);

        ControlSystem() {
            System::name = "ControlSystem";
        };
        ~ControlSystem() {};
    };
}


#endif //SDL_TILE_2_CONTROLSYSTEM_H
