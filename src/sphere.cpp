#include "sphere.h"

Sphere::Sphere() {

}

std::vector<Intersection> Sphere::Intersect(Ray r) {
    // Vector from the sphere's center to ray origin
    // Unit sphere has a center of 0,0,0
    Tuple sphere_to_ray = r.origin - Point(0,0,0);

    float a = r.direction.Dot(r.direction);
    float b = 2 * r.direction.Dot(sphere_to_ray);
    float c = sphere_to_ray.Dot(sphere_to_ray) - 1;

    float discriminant = (b * b) - 4 * a * c;

    // IF there's no intersections
    if(discriminant < 0) {
        return std::vector<Intersection> {};
    }

    auto t1 = Intersection(((-b - sqrt(discriminant)) / 2 * a), shared_from_this());
    auto t2 = Intersection(((-b + sqrt(discriminant)) / 2 * a), shared_from_this());

    return Intersections(t1, t2);
}