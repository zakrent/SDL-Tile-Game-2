//
// Created by zakrent on 4/14/17.
//

#ifndef SDL_TILE_2_COLLIDERCOMPONENT_H
#define SDL_TILE_2_COLLIDERCOMPONENT_H


#include <SDL_rect.h>
#include "Component.h"

namespace Entity {
    class ColliderComponent : public Component{
    public:
        SDL_Rect collider;

        ColliderComponent(const SDL_Rect &collider);
    };
}


#endif //SDL_TILE_2_COLLIDERCOMPONENT_H
