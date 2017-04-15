//
// Created by zakrent on 4/15/17.
//

#ifndef SDL_TILE_2_CAMERACOMPONENT_H
#define SDL_TILE_2_CAMERACOMPONENT_H


#include <SDL_rect.h>
#include "Component.h"

namespace Entity {
    class CameraComponent : public Component{
    public:
        SDL_Rect* camera;

        CameraComponent(SDL_Rect* camera) : camera(camera) {
            Component::name = "Camera";
        }
    };
}


#endif //SDL_TILE_2_CAMERACOMPONENT_H
