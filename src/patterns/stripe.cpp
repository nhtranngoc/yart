#include "stripe.h"

Color StripePattern::PatternAtPoint(Tuple const &point) {
    // Even
    if(((int)floor(point.x) % 2) == 0) {
        return this->a;
    } else return this->b;
}