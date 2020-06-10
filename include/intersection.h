#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <vector>
#include <algorithm>
#include <memory>
#include "shape.h"
#include "tuple.h"

class Shape;

struct Computations {
    float t;
    std::shared_ptr<Shape> object;
    Tuple point;
    Tuple eyev;
    Tuple normalv;
    bool inside;
    Tuple over_point;
};

class Intersection {
    public:
    Intersection(float, std::shared_ptr<Shape>);

    float t;
    std::shared_ptr<Shape> object;

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