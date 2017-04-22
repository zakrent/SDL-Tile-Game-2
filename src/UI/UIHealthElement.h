//
// Created by zakrent on 4/22/17.
//

#ifndef SDL_TILE_2_UIHEALTHELEMENT_H
#define SDL_TILE_2_UIHEALTHELEMENT_H

#include "../entity/Entity.h"
#include "UIBaseElement.h"

namespace UI {
    class UIHealthElement : public UIBaseElement{
    public:
        UIHealthElement(Entity::Entity* player) : UIBaseElement(player) {};
        void draw(SDL_Renderer *mainRenderer) {
            std::string name = "Health";
            Entity::HealthComponent* healthComponent = player->getComponent<Entity::HealthComponent>(name);
            if(!healthComponent)
                return;

            SDL_Rect fillRect = {10, 10, int(healthComponent->health*1.5), 16};
            SDL_SetRenderDrawColor(mainRenderer, 0xFF, 0x30, 0x30, 0xFF);
            SDL_RenderFillRect(mainRenderer, &fillRect);
        };
    };
}


#endif //SDL_TILE_2_UIHEALTHELEMENT_H
