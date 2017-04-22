//
// Created by zakrent on 4/22/17.
//

#ifndef SDL_TILE_2_UIELEMENT_H
#define SDL_TILE_2_UIELEMENT_H

#include <SDL_rect.h>
#include "../entity/Entity.h"

namespace UI {
    class UIBaseElement {
    protected:
        Entity::Entity* player;
        UIBaseElement(Entity::Entity* player) : player(player) {};
    public:
        virtual void draw(SDL_Renderer *mainRenderer) {};
    };
}

#endif //SDL_TILE_2_UIELEMENT_H
