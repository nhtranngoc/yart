#include "pattern.h"
#include "shape.h"

Pattern StripePattern(Color const &a_, Color const &b_) {
    auto p = Pattern();

    p.a = a_;
    p.b = b_;

    return p;
}

Color Pattern::StripeAt(Tuple const &point) {
    // Even
    if(((int)floor(point.x) % 2) == 0) {
        return this->a;
    } else return this->b;
}

Color Pattern::StripeAt(std::shared_ptr<Shape> object, Tuple const &point) {
    auto object_point = object->transform.Inverse() * point;
    auto pattern_point = this->transform.Inverse() * object_point;

    return this->StripeAt(pattern_point);
}