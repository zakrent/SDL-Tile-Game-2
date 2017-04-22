//
// Created by zakrent on 4/22/17.
//

#include "HealthSystem.h"

namespace Entity {
    void HealthSystem::updateEntity(Entity *entityPointer) {
        std::string name = "Health";
        HealthComponent* healthComponent = entityPointer->getComponent<HealthComponent>(name);
        if(!healthComponent)
            return;

        if(healthComponent->health <= 0)
            entityPointer->shouldBeDestroyed=true;
    }
}
