#ifndef SPHERE_H
#define SPHERE_H

#include "shape.h"
#include "ray.h"
#include "tuple.h"
#include "intersection.h"
#include "material.h"
#include <vector>
#include <memory>

class Intersection;
class Ray;
class Shape;

class Sphere : public Shape {
    public:
    std::vector<Intersection> Intersect(Ray &);
    Tuple LocalNormalAt(Tuple const&);
};

#endif // SPHERE_H_