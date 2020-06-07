#include "tuple.h"

Tuple::Tuple(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Tuple::Tuple() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 0;
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

bool Tuple::IsPoint() {
    return equal(this->w, 1.0);
}

bool Tuple::IsVector() {
    return equal(this->w, 0.0);
}

float Tuple::Magnitude() {
    return (sqrt(
        this->x * this->x +
        this->y * this->y +
        this->z * this->z +
        this->w * this->w
    ));
}

Tuple Tuple::Normalize() {
    float m = this->Magnitude();

    return Tuple(
        this->x / m,
        this->y / m,
        this->z / m,
        this->w / m
    );
}

float Tuple::Dot(Tuple const &t) {
    return (
        this->x * t.x +
        this->y * t.y +
        this->z * t.z +
        this->w * t.w
    );
}

Tuple Tuple::Cross(Tuple const &t) {
    return Vector(
        this->y * t.z - this->z * t.y,
        this->z * t.x - this->x * t.z,
        this->x * t.y - this->y * t.x        
    );
}

Tuple Tuple::Reflect(Tuple const &n) {
    return *(this) - n * 2 * this->Dot(n);
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