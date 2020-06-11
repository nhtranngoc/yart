#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "shape.h"
#include "sphere.h"
#include "pointlight.h"
#include "color.h"
#include "intersection.h"
#include "ray.h"

class Intersection;
class Shape;
class Sphere;
class Ray;
class Color;
struct Computations;

class World {
    public:
    std::vector<std::shared_ptr<Shape> > objects;
    std::vector<PointLight> lights;

    World() :
        objects(std::vector<std::shared_ptr<Shape> > {}),
        lights(std::vector<PointLight> {}) {}

    static World Default();

    std::vector<Intersection> Intersect(Ray &);
    Color ShadeHit(Computations &);
    Color ColorAt(Ray &);
    bool IsShadowed(Tuple const &);
};

#endif // WORLD_H_