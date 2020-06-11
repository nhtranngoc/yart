#include "material.h"

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
    if(this->pattern.a == Color::White() && this->pattern.b == Color::White()) {
        return this->color;
    }

    return this->pattern.StripeAt(object, point);
}