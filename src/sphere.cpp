#include "sphere.h"

Sphere::Sphere() {
    this->transform = Matrix<4,4>::Identity();
}

std::vector<Intersection> Sphere::Intersect(Ray r) {
    auto rayTransform = (this->transform).Inverse();
    auto r2 = r.Transform(rayTransform);

    // Vector from the sphere's center to ray origin
    // Unit sphere has a center of 0,0,0    
    Tuple sphere_to_ray = r2.origin - Point(0,0,0);

    float a = r2.direction.Dot(r2.direction);
    float b = 2 * r2.direction.Dot(sphere_to_ray);
    float c = sphere_to_ray.Dot(sphere_to_ray) - 1;

    float discriminant = pow(b, 2) - (4 * a * c);

    // IF there's no intersections
    if(discriminant < 0) {
        return std::vector<Intersection> {};
    }

    float t1 = (-b - sqrt(discriminant)) / (2 * a);
    float t2 = (-b + sqrt(discriminant)) / (2 * a);

    return Intersections(
        Intersection(t1, shared_from_this()),
        Intersection(t2, shared_from_this()));
}

void Sphere::SetTransform(Matrix<4,4> const &m) {
    this->transform = m;
}