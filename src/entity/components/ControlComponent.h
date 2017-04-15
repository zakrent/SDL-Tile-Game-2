//
// Created by zakrent on 4/15/17.
//

#ifndef SDL_TILE_2_CONTROLCOMPONENT_H
#define SDL_TILE_2_CONTROLCOMPONENT_H

#include "Component.h"

namespace Entity {
    class ControlComponent : public Component{
    public:
        int velMul;
        ControlComponent(){
            Component::name = "Control";
            velMul = 2;
        }d
        ~ControlComponent() {}
    };
}


#endif //SDL_TILE_2_CONTROLCOMPONENT_H
