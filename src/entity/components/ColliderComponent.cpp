//
// Created by zakrent on 4/14/17.
//

#include "ColliderComponent.h"

namespace Entity {
    ColliderComponent::ColliderComponent(const SDL_Rect &collider) : collider(collider) {
        Component::name = "Collider";
    }
}