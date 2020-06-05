#ifndef RAY_H
#define RAY_H

#include "tuple.h"
#include "matrix.h"
#include "transformation.h"

class Ray {
    public:
    Tuple origin, direction;
    Ray(Tuple, Tuple);

    Tuple Position(float const &);
    Ray Transform(Matrix<4,4> &);
};


#endif // RAY_H_