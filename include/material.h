#pragma once 

#include "color.h"
#include "pattern.h"

class Material {
    public:
    Color color;
    Pattern pattern;
    float ambient, diffuse, specular, shininess;

    // Default material
    Material() :
        color(Color(1,1,1)),
        ambient(0.1f),
        diffuse(0.9f),
        specular(0.9f),
        shininess(200.f) {}

    bool operator== (Material const &);
    Color ColorAt(std::shared_ptr<Shape>, Tuple const &);
};
