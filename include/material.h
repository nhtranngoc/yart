#pragma once 

#include "color.h"
#include "pattern.h"
#include "stripe.h"

class Material {
    public:
    Color color;
    std::shared_ptr<Pattern> pattern;
    float ambient, diffuse, specular, shininess, reflective;

    // Default material
    Material();

    bool operator== (Material const &);
    std::shared_ptr<Pattern>& GetPattern() {return pattern;}
    Color ColorAt(std::shared_ptr<Shape>, Tuple const &);
};
