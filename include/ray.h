#ifndef RAY_H
#define RAY_H

#include "tuple.h"
#include "matrix.h"
#include "transformation.h"
#include "intersection.h"

struct Computations;
class Intersection;

class Ray {
    public:
    Tuple origin, direction;
    Ray(Tuple, Tuple);

    Tuple Position(float const &);
    Ray Transform(Matrix<4,4> &);
    Computations Precomp(Intersection const&);
};


#endif // RAY_H_