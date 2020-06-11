#include "shape.h"

Tuple Shape::NormalAt(Tuple const &p) {
    auto localPoint = (this->transform).Inverse() * p;
    auto localNorm = this->LocalNormalAt(localPoint);
    auto worldNorm = (this->transform).Inverse().Transpose() * localNorm;
    worldNorm.w = 0;

    return worldNorm.Normalize();
}

bool Shape::operator== (Shape const &other) {
    return (
        this->material == other.material &&
        this->transform == other.transform
    );
}