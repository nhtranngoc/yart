#include "sphere.h"

std::vector<Intersection> Sphere::Intersect(Ray &r) {
    auto rayTransform = (this->transform).Inverse();
    auto r2 = r.Transform(rayTransform);

    // Vector from the sphere's center to ray origin
    // Unit sphere has a center of 0,0,0    
    Tuple sphere_to_ray = r2.origin - Point(0,0,0);

    float a = r2.direction.Dot(r2.direction);
    float b = 2.f * r2.direction.Dot(sphere_to_ray);
    float c = sphere_to_ray.Dot(sphere_to_ray) - 1.f;

    float discriminant = powf(b, 2) - (4.f * a * c);

    // IF there's no intersections
    if(discriminant < 0.f) {
        return std::vector<Intersection> {};
    }

    float t1 = (-b - sqrtf(discriminant)) / (2.f * a);
    float t2 = (-b + sqrtf(discriminant)) / (2.f * a);

    return Intersections(
        Intersection(t1, shared_from_this()),
        Intersection(t2, shared_from_this()));
}

Tuple Sphere::LocalNormalAt(Tuple const &p) {
    return p - Point(0,0,0);
}