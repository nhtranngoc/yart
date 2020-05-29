#include "tuple.h"

Tuple::Tuple(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

bool Tuple::isPoint() {
    return equal(this->w, 1.0);
}

bool Tuple::isVector() {
    return equal(this->w, 0.0);
}

Tuple Point(float x, float y, float z) {
    Tuple tmp(x,y,z,1.0);
    return tmp;
}

Tuple Vector(float x, float y, float z) {
    Tuple tmp(x,y,z,0.0);
    return tmp;
}

bool equal(float x, float y) {
    return (std::abs(x -y) < EPSILON);
}