//
// Created by zakrent on 4/15/17.
//

#ifndef SDL_TILE_2_VISUALSYSTEM_H
#define SDL_TILE_2_VISUALSYSTEM_H


#include "System.h"
#include "../../Program.h"

namespace Entity {
    class VisualSystem : public System{
    public:
        SDL_Renderer* mainRenderer;
        SDL_Rect* camera;
        void updateEntity(Entity* entityPointer);

        VisualSystem(SDL_Renderer *mainRenderer, SDL_Rect *camera)
                : mainRenderer(mainRenderer), camera(camera) {
            System::name = "VisualSystem";};
        ~VisualSystem() {};
    };
}


#endif //SDL_TILE_2_VISUALSYSTEM_H
