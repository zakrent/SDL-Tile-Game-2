//
// Created by zakrent on 5/2/17.
//

#ifndef SDL_TILE_2_SHOOTINGCOMPONENT_H
#define SDL_TILE_2_SHOOTINGCOMPONENT_H

#include "Component.h"

namespace Entity {
    class ShootingComponent : public Component{
        //Only for player controlled shooting
    public:

        Uint32 lastShootTime = 0;
        const int shootingDelay;
        const int bulletDamage;
        const int bulletSpeed;
        const int bulletAliveTime;

        ShootingComponent(const int shootingDelay, const int speed, int damage, int range)
                : shootingDelay(shootingDelay), bulletSpeed(speed), bulletDamage(damage), bulletAliveTime(range) {
            Component::name = "Shooting";
        }
    };
}

#endif //SDL_TILE_2_SHOOTINGCOMPONENT_H
