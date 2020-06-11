#pragma once 

#include "color.h"
#include "material.h"
#include "tuple.h"
#include "shape.h"

class Shape;

class PointLight {
    public:
    Tuple position;
    Color intensity;
    PointLight(Tuple position_, Color intensity_) : 
        position(position_), 
        intensity(intensity_) {}

    bool operator== (PointLight const &);
};

Color Lighting(Material &, std::shared_ptr<Shape>, PointLight const&, Tuple &, Tuple const&, Tuple const&, bool in_shadow = false);