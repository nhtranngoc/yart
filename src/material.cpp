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