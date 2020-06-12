#include "checkers.h"

Color CheckersPattern::PatternAtPoint(Tuple const &point) {
    float isEven = floor(point.x) + floor(point.y) + floor(point.z);

    if((int) isEven % 2) {
        return this->b;
    }

    return this->a;
}