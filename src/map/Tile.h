//
// Created by zakrent on 4/13/17.
//

#ifndef SDL_TILE_2_TILE_H
#define SDL_TILE_2_TILE_H

#include <map>
#include "../misc/TextureWrapper.h"
#include "../misc/Vector2D.h"

namespace Map {

    enum direction{
        Up,
        Down,
        Right,
        Left
    };

    const int TILE_HEIGHT = 32;
    const int TILE_WIDTH  = 32;

    class Tile {
    private:
        int state;
         Vector2D position;
        TextureWrapper* tileSheet;
    public:
        Uint8 lightLevel;
        Vector2D getPosition();
        SDL_Rect getCollider();
        int type;
        std::map<direction, Tile*> neighbours;
        void render(SDL_Renderer* renderer, SDL_Rect& camera);
        bool isSolid();
        Tile(int type, Vector2D position, TextureWrapper *tileSheet);
        ~Tile();
    };
}


#endif //SDL_TILE_2_TILE_H
