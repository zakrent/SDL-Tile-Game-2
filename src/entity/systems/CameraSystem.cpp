//
// Created by zakrent on 4/15/17.
//

#include "CameraSystem.h"

namespace Entity {
    void CameraSystem::updateEntity(Entity *entityPointer) {
        std::string name = "Position";
        PositionComponent* positionComponent = entityPointer->getComponent<PositionComponent>(name);
        if(!positionComponent)
            return;
        name = "Camera";
        CameraComponent* cameraComponent = entityPointer->getComponent<CameraComponent>(name);
        if(!cameraComponent)
            return;
        cameraComponent->camera->x = int(positionComponent->position.x);
        cameraComponent->camera->y = int(positionComponent->position.y);
    }
}