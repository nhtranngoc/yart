#ifndef SPHERE_H
#define SPHERE_H

#include "ray.h"
#include "tuple.h"
#include "Intersection.h"
#include <vector>

class Intersection;

class Sphere : public enable_shared_from_this<Sphere> {
    public:
    Sphere();
    Matrix<4,4> transform;
    std::vector<Intersection> Intersect(Ray);
    void SetTransform(Matrix<4,4> const &);
};

#endif // SPHERE_H_