#ifndef SPHERE_H
#define SPHERE_H

#include "ray.h"
#include "tuple.h"
#include "intersection.h"
#include "material.h"
#include <vector>
#include <memory>

class Intersection;

class Sphere : public enable_shared_from_this<Sphere> {
    public:
    Matrix<4,4> transform;
    Material material;

    Sphere() :
        transform(Matrix<4,4>::Identity()),
        material(Material()) {}

    std::vector<Intersection> Intersect(Ray);
    void SetTransform(Matrix<4,4> const &);
    Tuple NormalAt(Tuple const &);
};

#endif // SPHERE_H_