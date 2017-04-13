//
// Created by zakrent on 4/13/17.
//

#ifndef SDL_TILE_2_VECTOR2D_H
#define SDL_TILE_2_VECTOR2D_H


class Vector2D {
public:
    float x, y;
    Vector2D operator + (Vector2D SecVector);
    Vector2D operator - (Vector2D SecVector);
    void operator += (Vector2D SecVector);
    void operator -= (Vector2D SecVector);
    bool operator == (Vector2D SecVector);

    Vector2D(float x, float y);
    ~Vector2D();
};


#endif //SDL_TILE_2_VECTOR2D_H
