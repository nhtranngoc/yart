#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <vector>
#include "sphere.h"

class Sphere;

class Intersection {
    public:
    Intersection(float, std::shared_ptr<Sphere>);

    float t;
    std::shared_ptr<Sphere> object;

};


template<typename... Args>
std::vector<Intersection> Intersections(Args const&... args) {
    return std::vector<Intersection> {args...};
}

#endif // INTERSECTION_H_