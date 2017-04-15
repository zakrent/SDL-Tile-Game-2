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
    //TODO:Remove debug
        PositionComponent()
                : velocity(0,0), position(0,0) {
            Component::name = "Position";
        }

        PositionComponent(Vector2D position)
                : velocity(0,0), position(position) {
            Component::name = "Position";
        }

        PositionComponent(Vector2D position, Vector2D velocity)
                : velocity(velocity), position(position) {
            Component::name = "Position";
        }

        ~PositionComponent() {};
    };
}

#endif //SDL_TILE_2_POSITIONCOMPONENT_H
