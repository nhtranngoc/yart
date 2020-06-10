#include "plane.h"

Tuple Plane::LocalNormalAt(Tuple const &p) {
    return Vector(0,1,0);
}

std::vector<Intersection> Plane::Intersect(Ray &r) {
    std::vector<Intersection> retVal;

    if(equal(0, r.direction.y)) {
        return retVal;
    }
    
    auto t = (float) (-r.origin.y / r.direction.y);
    retVal.push_back({Intersection(t, shared_from_this())});
    
    return retVal;
}