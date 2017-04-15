//
// Created by zakrent on 4/15/17.
//

#include "VisualSystem.h"
#include "../../misc/Renderer.cpp"

namespace Entity{

    void VisualSystem::updateEntity(Entity *entityPointer) {

        std::string name = "Position";
        PositionComponent* positionComponent = entityPointer->getComponent<PositionComponent>(name);
        if(!positionComponent)
            return;
        name = "Visual";
        VisualComponent* visualComponent = entityPointer->getComponent<VisualComponent>(name);
        if(!visualComponent)
            return;

        SDL_Rect srcrect = {visualComponent->type * visualComponent->width, visualComponent->state * visualComponent->height, visualComponent->width, visualComponent->height};
        Render::renderTexture(mainRenderer, visualComponent->spriteSheet, srcrect, *camera, positionComponent->position, 0xFF);
    }

}