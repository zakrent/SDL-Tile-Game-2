//
// Created by zakrent on 5/2/17.
//

#include "ShootingSystem.h"

namespace Entity {
    void ShootingSystem::updateEntity(Entity *entityPointer) {
        std::string name = "Position";
        PositionComponent* positionComponent = entityPointer->getComponent<PositionComponent>(name);
        if(!positionComponent)
            return;
        name = "Shooting";
        ShootingComponent* shootingComponent = entityPointer->getComponent<ShootingComponent>(name);
        if(!shootingComponent)
            return;
        name = "Camera";
        CameraComponent* cameraComponent = entityPointer->getComponent<CameraComponent>(name);
        if(!cameraComponent)
            return;


        int mouseX;
        int mouseY;
        SDL_PumpEvents();
        if (SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT)) {

            Vector2D playerRelMousePos(
                    mouseX-cameraComponent->camera->w/2,
                    mouseY-cameraComponent->camera->h/2);

            playerRelMousePos.normalize();

            Vector2D bulletVel = Vector2D(playerRelMousePos.x*shootingComponent->bulletSpeed, playerRelMousePos.y*shootingComponent->bulletSpeed);

            if(shootingComponent->lastShootTime+shootingComponent->shootingDelay <= SDL_GetTicks()){
                std::vector<Component*> components;
                components.push_back(new PositionComponent(positionComponent->position, bulletVel));
                components.push_back(new BulletComponent(shootingComponent->bulletDamage, shootingComponent->bulletAliveTime));
                mainMap->addEntity(components);
            }
        }
    }
}