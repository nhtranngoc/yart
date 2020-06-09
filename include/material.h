#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"

class Material {
    public:
    Color color;
    float ambient, diffuse, specular, shininess;

    // Default material
    Material() :
        color(Color(1,1,1)),
        ambient(0.1f),
        diffuse(0.9f),
        specular(0.9f),
        shininess(200.f) {}

    bool operator== (Material const &);
};

#endif // MATERIAL_H_