#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "sphere.h"
#include "pointlight.h"
#include "color.h"
#include "intersection.h"
#include "ray.h"

class Intersection;
class Sphere;
class Ray;
class Color;
struct Computations;

class World {
    public:
    std::vector<std::shared_ptr<Sphere> > objects;
    std::vector<PointLight> lights;

    World() :
        objects(std::vector<std::shared_ptr<Sphere> > {}),
        lights(std::vector<PointLight> {}) {}

    static World Default();

    std::vector<Intersection> Intersect(Ray const &);
    Color ShadeHit(Computations const &);
    Color ColorAt(Ray &);
    bool IsShadowed(Tuple const &);
};

#endif // WORLD_H_