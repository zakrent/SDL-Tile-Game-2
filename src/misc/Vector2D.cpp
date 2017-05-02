//
// Created by zakrent on 4/13/17.
//

#include <cmath>
#include "Vector2D.h"

Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

Vector2D::~Vector2D() {}

void Vector2D::normalize() {
    float length = float(sqrt(pow(x, 2)+pow(y, 2)));
    x /= length;
    y /= length;
}

Vector2D Vector2D::operator+(Vector2D SecVector) {
    return Vector2D(this->x + SecVector.x, 0);
}

Vector2D Vector2D::operator-(Vector2D SecVector) {
    return Vector2D(this->x - SecVector.x, 0);
}

void Vector2D::operator+=(Vector2D SecVector) {
    this->x += SecVector.x;
    this->y += SecVector.y;
}

void Vector2D::operator-=(Vector2D SecVector) {
    this->x -= SecVector.x;
    this->y -= SecVector.y;
}
