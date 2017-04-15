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
        name = "Visual";
        VisualComponent* visualComponent = entityPointer->getComponent<VisualComponent>(name);
        if(!visualComponent)
            return;

        cameraComponent->camera->x = int((visualComponent->width/2)+positionComponent->position.x-cameraComponent->camera->w/2);
        cameraComponent->camera->y = int((visualComponent->height/2)+positionComponent->position.y-cameraComponent->camera->h/2);
    }
}