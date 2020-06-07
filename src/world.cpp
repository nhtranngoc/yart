#include "world.h"

World World::Default() {
    auto retVal = World();
    auto s1 = std::make_shared<Sphere>();
    auto s2 = std::make_shared<Sphere>();
    auto light = PointLight(Point(-10,10,-10), Color(1,1,1));

    s1->material.color = Color(0.8, 1.0, 0.6);
    s1->material.diffuse = 0.7;
    s1->material.specular = 0.2;

    s2->SetTransform(Scaling(0.5, 0.5, 0.5));

    retVal.lights.push_back(light);
    retVal.objects.push_back(s1);
    retVal.objects.push_back(s2);

    return retVal;
}