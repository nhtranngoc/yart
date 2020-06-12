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

    // Default pattern (none)
    Pattern() : 
        a(Color::White()), 
        b(Color::White()),
        transform(Matrix<4,4>::Identity()) {}
    
    // Subclass pattern constructor
    Pattern(Color a_, Color b_) :
        a(a_),
        b(b_),
        transform(Matrix<4,4>::Identity()) {}

    virtual Color PatternAtPoint(Tuple const &) = 0;
    Color PatternAt(std::shared_ptr<Shape>, Tuple const &);
};

class TestPattern : public Pattern {
    Color PatternAtPoint(Tuple const &p) {return Color(p.x, p.y, p.z);}
};