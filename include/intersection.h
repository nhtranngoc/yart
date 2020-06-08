#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <vector>
#include <algorithm>
#include <memory>
#include "sphere.h"
#include "tuple.h"

class Sphere;

struct Computations {
    float t;
    std::shared_ptr<Sphere> object;
    Tuple point;
    Tuple eyev;
    Tuple normalv;
    bool inside;
};

class Intersection {
    public:
    Intersection(float, std::shared_ptr<Sphere>);

    float t;
    std::shared_ptr<Sphere> object;

    bool operator== (const Intersection &);
    bool operator< (const Intersection &);
};

template<typename... Args>
std::vector<Intersection> Intersections(Args const&... args) {
    std::vector<Intersection> retVal{ args... };
    std::sort(retVal.begin(), retVal.end());

    return retVal;
}

Intersection Hit(std::vector<Intersection> const &);

#endif // INTERSECTION_H_