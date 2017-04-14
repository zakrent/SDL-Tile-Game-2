//
// Created by zakrent on 4/14/17.
//

#ifndef SDL_TILE_2_COMPONENT_H
#define SDL_TILE_2_COMPONENT_H

#include <string>

namespace Entity {
    class Component {
    public:
        std::string name;

        Component() {};
        ~Component() {};
    };
}

#endif //SDL_TILE_2_COMPONENT_H
