//
// Created by zakrent on 4/14/17.
//

#include "PositionSystem.h"

namespace Entity {
    void PositionSystem::updateEntity(Entity *entityPointer) {
        std::string name = "Position";
        PositionComponent* component = entityPointer->getComponent<PositionComponent>(name);
        if(component)
            component->position += component->velocity;
    }
}