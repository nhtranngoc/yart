#include "intersection.h"

Intersection::Intersection(float t_, std::shared_ptr<Sphere> object_) {
    this->t = t_;
    this->object = object_;
}
