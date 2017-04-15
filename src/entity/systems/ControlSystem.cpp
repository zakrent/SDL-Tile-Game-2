//
// Created by zakrent on 4/15/17.
//

#include "ControlSystem.h"

namespace Entity {

    void ControlSystem::updateEntity(Entity *entityPointer) {
        std::string name = "Position";
        PositionComponent* positionComponent = entityPointer->getComponent<PositionComponent>(name);
        if(!positionComponent)
            return;
        name = "Control";
        ControlComponent* controlComponent = entityPointer->getComponent<ControlComponent>(name);
        if(!controlComponent)
            return;

        const Uint8 *state = SDL_GetKeyboardState(NULL);
        float localVelMul = controlComponent->velMul;

        if ((state[SDL_SCANCODE_W] || state[SDL_SCANCODE_S]) && (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_D])) {
            localVelMul /= 1.4142135623731;
        }

        if (state[SDL_SCANCODE_W]) {
            positionComponent->velocity.y = -1 * localVelMul;
        } else if (state[SDL_SCANCODE_S]) {
            positionComponent->velocity.y = 1 * localVelMul;
        } else {
            positionComponent->velocity.y = 0;
        }
        if (state[SDL_SCANCODE_A]) {
            positionComponent->velocity.x = -1 * localVelMul;
        } else if (state[SDL_SCANCODE_D]) {
            positionComponent->velocity.x = 1 * localVelMul;
        } else {
            positionComponent->velocity.x = 0;
        }
    }

}