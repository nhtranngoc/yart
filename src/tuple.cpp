#include "tuple.h"

Tuple::Tuple(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

bool operator == (Tuple const &t1, Tuple const &t2) {
    return (
        equal(t1.x, t2.x) && 
        equal(t1.y, t2.y) &&
        equal(t1.z, t2.z) &&
        equal(t1.w, t2.w));
}

Tuple operator + (Tuple const &t1, Tuple const &t2) {
    return Tuple(
        t1.x + t2.x,
        t1.y + t2.y,
        t1.z + t2.z,
        t1.w + t2.w);
}

Tuple operator - (Tuple const &t1, Tuple const &t2) {
    return Tuple(
        t1.x - t2.x,
        t1.y - t2.y,
        t1.z - t2.z,
        t1.w - t2.w        
    );
}

Tuple operator - (Tuple const &t) {
    return Tuple(
        -t.x,
        -t.y,
        -t.z,
        -t.w
    );
}

Tuple operator * (Tuple const &t, float const s) {
    return Tuple(
        t.x * s,
        t.y * s,
        t.z * s,
        t.w * s
    );
}

Tuple operator / (Tuple const &t, float const s) {
    return Tuple(
        t.x / s,
        t.y / s,
        t.z / s,
        t.w / s
    );
}

bool Tuple::isPoint() {
    return equal(this->w, 1.0);
}

bool Tuple::isVector() {
    return equal(this->w, 0.0);
}

float Tuple::magnitude() {
    return (sqrt(
        this->x * this->x +
        this->y * this->y +
        this->z * this->z +
        this->w * this->w
    ));
}

Tuple Tuple::normalize() {
    float m = this->magnitude();

    return Tuple(
        this->x / m,
        this->y / m,
        this->z / m,
        this->w / m
    );
}

float Tuple::dot(Tuple const &t) {
    return (
        this->x * t.x +
        this->y * t.y +
        this->z * t.z +
        this->w * t.w
    );
}

Tuple Tuple::cross(Tuple const &t) {
    return Vector(
        this->y * t.z - this->z * t.y,
        this->z * t.x - this->x * t.z,
        this->x * t.y - this->y * t.x        
    );
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