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

std::vector<Intersection> World::Intersect(Ray const &r) {
    std::vector<Intersection> retVal;
    for (auto const& obj : this->objects) {
        auto xs = obj->Intersect(r);
        retVal.insert(retVal.end(), xs.begin(), xs.end());
    }

    std::sort(retVal.begin(), retVal.end());

    return retVal;
}

Color World::ShadeHit(Computations const &comps) {
    Color finalShade = Color(0,0,0);
    // Iterate through all light sources
    // This will slow the renderer down 
    for(const auto lightSource : this->lights) {
        finalShade = finalShade + Lighting(
            comps.object->material,
            lightSource,
            comps.point,
            comps.eyev,
            comps.normalv
        );
    }

    return finalShade;
}

Color World::ColorAt(Ray &r) {
    // Find the intersections of the ray with the world
    auto xs = this->Intersect(r);
    // Find the hit
    auto hit = Hit(xs);
    
    // If there's no intersections, return color black
    if(hit.object == nullptr) {
        return Color::Black();
    }

    // Otherwise, compute and return the color shade at the hit
    auto comps = r.Precomp(hit);

    return this->ShadeHit(comps);
}