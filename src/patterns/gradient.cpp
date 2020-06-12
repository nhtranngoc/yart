#include "gradient.h"

Color GradientPattern::PatternAtPoint(Tuple const &point) {
    auto retVal = (this->a + (this->b - this->a) * (point.x - floor(point.x)));

    return Color(retVal.x, retVal.y, retVal.z);
}