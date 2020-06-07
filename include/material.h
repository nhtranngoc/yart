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
        ambient(0.1),
        diffuse(0.9),
        specular(0.9),
        shininess(200) {}

    bool operator== (Material const &);
};

#endif // MATERIAL_H_