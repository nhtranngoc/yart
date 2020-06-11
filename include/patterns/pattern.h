#pragma once 

#include "color.h"
#include "tuple.h"
#include "matrix.h"
#include <memory>

class Point;
class Color;
class Shape;

class Pattern {
    public:
    Color a;
    Color b;
    Matrix<4,4> transform;

    Pattern() : 
        a(Color::White()), 
        b(Color::White()),
        transform(Matrix<4,4>::Identity()) {}
    
    void SetTransform(Matrix<4,4> const& m) {this->transform = m;}
    Color StripeAt(Tuple const &);
    Color StripeAt(std::shared_ptr<Shape>, Tuple const &);
};

Pattern StripePattern(Color const &, Color const &);