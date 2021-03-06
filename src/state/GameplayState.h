//
// Created by zakrent on 4/13/17.
//

#ifndef SDL_TILE_2_GAMEPLAYSTATE_H
#define SDL_TILE_2_GAMEPLAYSTATE_H

#include <SDL_events.h>
#include <SDL_render.h>
#include "State.h"
#include "../map/Map.h"
#include "../Program.h"
#include "../entity/systems/Systems.h"
#include "../entity/components/Components.h"
#include "../UI/UIController.h"

namespace State {
    class GameplayState : public State{
    private:
        Map::Map mainMap;
        Program* mainProgram;
        UI::UIController* mainUIController;
        std::vector<Entity::System*> systems;
        SDL_Rect camera;
        void loadSystems();
        void loadEntities();
        void loadUI();
    public:
        void update();
        void render(SDL_Renderer* renderer);
        void handleEvent(SDL_Event& event);

        GameplayState(Map::Map mainMap, Program *mainProgram);
        ~GameplayState();
    };
}


#endif //SDL_TILE_2_GAMEPLAYSTATE_H
