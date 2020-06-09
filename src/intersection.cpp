#include "intersection.h"

Intersection::Intersection(float t_, std::shared_ptr<Sphere> object_) {
    this->t = t_;
    this->object = object_;
}

Intersection Hit(std::vector<Intersection> const &xs) {
    for (auto x : xs) {
        // Return first non-zero element.
        if(x.t > 0.f) {
            return x;
        }
    }

    return Intersection(0, nullptr);
}

bool Intersection::operator== (Intersection const &other) {
    if(equal(this->t, other.t) && (this->object == other.object)) {
        return true;
    } else return false;
}

bool Intersection::operator< (Intersection const &other) {
    return this->t < other.t;
}