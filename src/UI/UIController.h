//
// Created by zakrent on 4/22/17.
//

#ifndef SDL_TILE_2_UICONTROLLER_H
#define SDL_TILE_2_UICONTROLLER_H

#include <vector>
#include <SDL_render.h>
#include "UIBaseElement.h"

namespace UI {
    class UIController {
    private:
        std::vector<UIBaseElement*> UIElements;

    public:
        void draw(SDL_Renderer* mainRenderer);

        UIController(Entity::Entity* Player);
        ~UIController() {};
    };
}

#endif //SDL_TILE_2_UICONTROLLER_H
