//
// Created by zakrent on 4/15/17.
//

#ifndef SDL_TILE_2_CAMERASYSTEM_H
#define SDL_TILE_2_CAMERASYSTEM_H

#include "System.h"

namespace Entity {
    class CameraSystem : public System{
    public:
        void updateEntity(Entity* entityPointer);

        CameraSystem() {
            System::name = "CameraSystem";
        };
        ~CameraSystem() {};
    };
}


#endif //SDL_TILE_2_CAMERASYSTEM_H
