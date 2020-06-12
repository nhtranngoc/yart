#include "pattern.h"
#include "shape.h"

Color Pattern::PatternAt(std::shared_ptr<Shape> object, Tuple const &point) {
    auto object_point = object->transform.Inverse() * point;
    auto pattern_point = this->transform.Inverse() * object_point;

    return PatternAtPoint(pattern_point); 
}