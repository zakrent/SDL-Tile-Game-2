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
        bool isOnMove;
        Vector2D moveDestination;
        Entity* target;
        PathComponent(Entity *target) : target(target), moveDestination(0,0) {
            Component::name = "Path";
            isOnMove = false;
        }
        ~PathComponent() {}
    };
}

#endif //SDL_TILE_2_PATHCOMPONENT_H
