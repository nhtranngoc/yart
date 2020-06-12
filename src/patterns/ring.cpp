#include "ring.h"

Color RingPattern::PatternAtPoint(Tuple const &point) {
    float x2 = point.x * point.x;
    float z2 = point.z * point.z;

    float square = floor(sqrtf(x2 + z2));

    if((int) square % 2) {
        return this->b;
    }

    return this->a;
}