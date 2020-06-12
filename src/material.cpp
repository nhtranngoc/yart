#include "material.h"

Material::Material() :
        color(Color(1,1,1)),
        ambient(0.1f),
        diffuse(0.9f),
        specular(0.9f),
        shininess(200.f),
        reflective(0.0f),
        pattern(std::make_shared<StripePattern>(Color::White(), Color::White())) {}


bool Material::operator== (Material const &other) {
    return (
        this->color == other.color &&
        equal(this->ambient, other.ambient) &&
        equal(this->diffuse, other.diffuse) &&
        equal(this->specular, other.specular) &&
        equal(this->shininess, other.shininess)
    );
}

Color Material::ColorAt(std::shared_ptr<Shape> object, Tuple const &point) {
    // If default pattern (ie no pattern)
    if(pattern->a == Color::White() && pattern->b == Color::White()) {
        return this->color;
    }

    return this->pattern->PatternAt(object, point);
}