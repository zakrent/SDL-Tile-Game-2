//
// Created by zakrent on 5/1/17.
//

#ifndef SDL_TILE_2_BULLETCOMPONENT_H
#define SDL_TILE_2_BULLETCOMPONENT_H

#include <SDL_rect.h>
#include "Component.h"

namespace Entity {
    class BulletComponent : public Component{
    public:
        const int damage;
        const int aliveTime;
        int timeCounter;

        BulletComponent(int damage, int range) : damage(damage), aliveTime(range), timeCounter(0){
            Component::name = "Bullet";
        }
    };
}


#endif //SDL_TILE_2_BULLETCOMPONENT_H
