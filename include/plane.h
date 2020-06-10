#ifndef PLANE_H
#define PLANE_H

#include "shape.h"
#include "intersection.h"
#include "tuple.h"
#include <vector>
#include "ray.h"

class Tuple;
class Shape;
class Intersection;
class Ray;

class Plane : public Shape {
    public:
    Tuple LocalNormalAt(Tuple const&);
    std::vector<Intersection> Intersect(Ray &);
};

#endif // PLANE_H_