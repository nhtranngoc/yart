#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "matrix.h"
#include <cmath>
#include <math.h>

const double pi = 3.14159265358979323846;

Matrix<4,4> Translation(float, float, float);
Matrix<4,4> Scaling(float, float, float);
Matrix<4,4> RotationX(float);
Matrix<4,4> RotationY(float);
Matrix<4,4> RotationZ(float);
Matrix<4,4> Shearing(float, float, float, float, float, float);
Matrix<4,4> View(Tuple, Tuple, Tuple);

#endif // TRANSFORMATION_H_