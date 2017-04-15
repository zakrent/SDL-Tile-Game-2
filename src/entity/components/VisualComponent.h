//
// Created by zakrent on 4/15/17.
//

#ifndef SDL_TILE_2_VISUALCOMPONENT_H
#define SDL_TILE_2_VISUALCOMPONENT_H


#include <SDL_system.h>
#include "Component.h"
#include "../../misc/TextureWrapper.h"

namespace Entity {
    class VisualComponent : public Component{
    public:
        TextureWrapper* spriteSheet;
        int type;
        int state;
        int width = 24;
        int height = 24;

        VisualComponent(TextureWrapper* spriteSheet, int type) : spriteSheet(spriteSheet), type(type) {
            Component::name = "Visual";
            state = 0;
        }

        ~VisualComponent() {}
    };
}

#endif //SDL_TILE_2_VISUALCOMPONENT_H
