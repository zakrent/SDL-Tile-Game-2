//
// Created by zakrent on 4/14/17.
//

#include "Entity.h"
namespace Entity {
    void Entity::addComponent(Component *componentPointer) {
        if(!components[componentPointer->name])
            components[componentPointer->name] = componentPointer;
    }

    Entity::Entity(std::vector<Component*> components) {
        for(Component* component : components){
            addComponent(component);
        }
        shouldBeDestroyed=false;
    }
}
