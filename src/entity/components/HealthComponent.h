//
// Created by zakrent on 4/22/17.
//

#ifndef SDL_TILE_2_HEALTHCOMPONENT_H
#define SDL_TILE_2_HEALTHCOMPONENT_H

#include "Component.h"

namespace Entity {
    class HealthComponent : public Component{
    public:
        int health;
        HealthComponent(){
            Component::name = "Health";
            health = 100;
        }
        ~HealthComponent() {}
    };
}

#endif //SDL_TILE_2_HEALTHCOMPONENT_H
