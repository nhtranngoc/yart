#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "color.h"
#include "tuple.h"

class PointLight {
    public:
    Tuple position;
    Color intensity;
    PointLight(Tuple position_, Color intensity_) : 
        position(position_), 
        intensity(intensity_) {}
};

#endif // POINTLIGHT_H_