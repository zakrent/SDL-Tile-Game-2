//
// Created by zakrent on 4/14/17.
//

#ifndef SDL_TILE_2_ENTITY_H
#define SDL_TILE_2_ENTITY_H

#include <map>
#include <vector>
#include "components/Components.h"

namespace Entity {
    class Entity {
    private:
        std::map<std::string, Component*> components;
    public:
        bool shouldBeDestroyed;
        void addComponent(Component* componentPointer);
        template<typename T> T* getComponent(std::string name) {
            if (components[name])
                return (T*)components[name];
            return nullptr;
        }
        Entity() {shouldBeDestroyed=false;};
        Entity(std::vector<Component*> components);
        ~Entity() {};
    };
}

#endif //SDL_TILE_2_ENTITY_H
