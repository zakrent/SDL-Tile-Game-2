//
// Created by zakrent on 4/13/17.
//

#ifndef SDL_TILE_2_TILE_H
#define SDL_TILE_2_TILE_H

#include "../misc/TextureWrapper.h"
#include "../misc/Vector2D.h"

namespace Map {

    const int TILE_HEIGHT = 32;
    const int TILE_WIDTH  = 32;

    class Tile {
    private:
        int state;
        Uint8 lightLevel;
        Vector2D position;
        TextureWrapper* tileSheet;
    public:
        int type;
        //std::map<direction, Tile*> neighbours;
        void render(SDL_Renderer* renderer, SDL_Rect& camera);

        Tile(int type, Vector2D position, TextureWrapper *tileSheet);
        ~Tile();
    };
}


#endif //SDL_TILE_2_TILE_H
