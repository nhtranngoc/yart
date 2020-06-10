#ifndef SHAPE_H
#define SHAPE_H

#include "material.h"
#include "matrix.h"
#include "intersection.h"
#include "ray.h"
#include "tuple.h"
#include <memory>
#include <vector>

class Material;
class Intersection;
class Ray;
class Tuple;

class Shape : public enable_shared_from_this<Shape> {
    public:
    Material material;
    Matrix<4,4> transform;    

    Shape() : 
        material(Material()),
        transform(Matrix<4,4>::Identity()) {}

    void SetTransform(Matrix<4,4> const &m) {transform = m;}
    Tuple NormalAt(Tuple const& p);
    bool operator== (Shape const &);

    // Abstract functions, to be implemented by the appropriate shapes
    virtual std::vector<Intersection> Intersect(Ray &) = 0;
    virtual Tuple LocalNormalAt(Tuple const&) = 0;
};

class TestShape : public Shape {
    std::vector<Intersection> Intersect(Ray &r) {return std::vector<Intersection> {};}
    Tuple LocalNormalAt(Tuple const &p) {return Vector(p.x, p.y, p.z);}
};

#endif // SHAPE_H_