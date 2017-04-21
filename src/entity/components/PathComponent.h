//
// Created by zakrent on 4/21/17.
//

#ifndef SDL_TILE_2_PATHCOMPONENT_H
#define SDL_TILE_2_PATHCOMPONENT_H

#include "Component.h"

namespace Entity {

    class Entity;

    class PathComponent : public Component{
    public:
        Entity* target;
        PathComponent(Entity *target) : target(target) {
            Component::name = "Path";
        }
        ~PathComponent() {}
    };
}

#endif //SDL_TILE_2_PATHCOMPONENT_H
