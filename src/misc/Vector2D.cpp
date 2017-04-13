//
// Created by zakrent on 4/13/17.
//

#include "Vector2D.h"

Vector2D::Vector2D(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector2D::~Vector2D() {

}

Vector2D Vector2D::operator+(Vector2D SecVector) {
    return Vector2D(this->x+SecVector.x, this->y+SecVector.y);
}

Vector2D Vector2D::operator-(Vector2D SecVector) {
    return Vector2D(this->x-SecVector.x, this->y-SecVector.y);
}

bool Vector2D::operator==(Vector2D SecVector) {
    return this->x == SecVector.x && this->y == SecVector.y;
}

void Vector2D::operator+=(Vector2D SecVector) {
    this->x += SecVector.x;
    this->y += SecVector.y;
}

void Vector2D::operator-=(Vector2D SecVector) {
    this->x -= SecVector.x;
    this->y -= SecVector.y;
}
