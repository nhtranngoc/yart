#include "pointlight.h"

Color Lighting(Material & material, std::shared_ptr<Shape> object, PointLight const& light, Tuple & point, Tuple const& eyev, Tuple const& normalv, bool in_shadow) {
    // Combine surface color with light's intensity/color
    Color effective_color = material.ColorAt(object, point) * light.intensity;

    // Find direction to the light source
    auto lightv = (light.position - point).Normalize();

    // Compute the ambient contribution
    Color ambient = effective_color * material.ambient;

    // light_dot_normal represents the cosine of the angle between the
    // light vector and the normal vector. A negative number means the 
    // light is on the other side of the surface.
    auto light_dot_normal = lightv.Dot(normalv);
    auto diffuse = Color::Black();
    auto specular = Color::Black();

    if(light_dot_normal >= 0) {
        // Compute the diffuse contribution
        diffuse = (in_shadow) ? Color::Black() : effective_color * (material.diffuse * light_dot_normal);

        // reflect_dot_eye represents the cosine of the angle between the
        // reflection vector and the eye vector. A negative number means the 
        // light reflects away from the eye
        auto reflectv = (-lightv).Reflect(normalv);
        auto reflect_dot_eye = reflectv.Dot(eyev);

        if(reflect_dot_eye > 0) {
            auto factor = pow(reflect_dot_eye, material.shininess);
            specular = (in_shadow) ? Color::Black() : light.intensity * material.specular * factor;
        }
    }

    return ambient + diffuse + specular;
}

bool PointLight::operator== (PointLight const &other) {
    return (
        this->intensity == other.intensity &&
        this->position == other.position
    );
}