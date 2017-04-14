//
// Created by zakrent on 4/14/17.
//

#ifndef SDL_TILE_2_POSITIONCOMPONENT_H
#define SDL_TILE_2_POSITIONCOMPONENT_H

#include "Component.h"
#include "../../misc/Vector2D.h"



namespace Entity {
    class PositionComponent : public Component{
    public:
        Vector2D position;
        Vector2D velocity;

        PositionComponent();
        PositionComponent(Vector2D position);
        ~PositionComponent() {};
    };
}

#endif //SDL_TILE_2_POSITIONCOMPONENT_H
