//
// Created by zakrent on 4/14/17.
//

#include "Entity.h"
namespace Entity {
    Entity::Entity() {

    }

    Entity::~Entity() {

    }

    void Entity::addComponent(Component *componentPointer) {
        if(!components[componentPointer->name])
            components[componentPointer->name] = componentPointer;
    }
}
