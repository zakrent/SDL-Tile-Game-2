//
// Created by zakrent on 4/14/17.
//

#include "PositionComponent.h"

namespace Entity {

    PositionComponent::PositionComponent()
            : velocity(10,0), position(0,0) {
        Component::name = "Position";
    }

    PositionComponent::PositionComponent(Vector2D position)
            : velocity(10,0), position(position) {
        Component::name = "Position";
    }
}