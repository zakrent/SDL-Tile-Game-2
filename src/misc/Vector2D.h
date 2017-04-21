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
    Vector2D(float x, float y);

    ~Vector2D();
};

inline bool operator==(const Vector2D& first, const Vector2D& second){
    return first.x == second.x && first.y == second.y;
}

#endif //SDL_TILE_2_VECTOR2D_H
