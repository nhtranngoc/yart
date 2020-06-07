#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "color.h"
#include "material.h"
#include "tuple.h"

class PointLight {
    public:
    Tuple position;
    Color intensity;
    PointLight(Tuple position_, Color intensity_) : 
        position(position_), 
        intensity(intensity_) {}

    bool operator== (PointLight const &);
};

Color Lighting(Material const&, PointLight const&, Tuple const&, Tuple const&, Tuple const&);

#endif // POINTLIGHT_H_