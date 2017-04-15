//
// Created by zakrent on 4/13/17.
//
#include <SDL_rect.h>

namespace CollisionDetection{

    inline bool boundingBox(SDL_Rect collider1, SDL_Rect collider2){
        return (collider1.x+collider1.w > collider2.x &&
                collider1.x < collider2.x+collider2.w &&
                collider1.y+collider1.h > collider2.y &&
                collider1.y < collider2.y+collider2.h);
    }
}
