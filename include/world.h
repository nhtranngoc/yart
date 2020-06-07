#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "sphere.h"
#include "pointlight.h"
#include "color.h"

class World {
    public:
    std::vector<std::shared_ptr<Sphere> > objects;
    std::vector<PointLight> lights;

    World() :
        objects(std::vector<std::shared_ptr<Sphere> > {}),
        lights(std::vector<PointLight> {}) {}

    static World Default();
};

#endif // WORLD_H_