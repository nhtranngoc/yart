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

Ray Ray::Transform(Matrix<4,4> &m) {
    return Ray(
        m * this->origin,
        m * this->direction
    );
}

Computations Ray::Precomp(Intersection const& i) {
    // Instantiate a data structure for storing some precomputed values
    Computations comps;

    // Copy the intersection's properties, for convenience
    comps.t = i.t;
    comps.object = i.object;

    // Precompute some useful values
    comps.point = this->Position(comps.t);
    comps.eyev = -this->direction;
    comps.normalv = i.object->NormalAt(comps.point);

    // Check if the hit occurs from the inside of the shape
    if(comps.normalv.Dot(comps.eyev) < 0) {
        comps.inside = true;
        comps.normalv = -comps.normalv;
    } else {
        comps.inside = false;
    }

    // Bump the point up a bit
    comps.over_point = comps.point + (comps.normalv * EPSILON);

    return comps;    
}