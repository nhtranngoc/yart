#ifndef RAY_H
#define RAY_H

#include "tuple.h"

class Ray {
    public:
    Tuple origin, direction;
    Ray(Tuple, Tuple);

    Tuple Position(float const &);
};

#endif // RAY_H_