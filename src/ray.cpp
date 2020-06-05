#include "ray.h"

Ray::Ray(Tuple origin_, Tuple direction_) {
    this->origin = origin_;
    this->direction = direction_;
}

Tuple Ray::Position(float const &t) {
    return Point(
        this->origin.x + this->direction.x * t,
        this->origin.y + this->direction.y * t,
        this->origin.z + this->direction.z * t
    );
}