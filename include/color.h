#ifndef COLOR_H
#define COLOR_H

#include "tuple.h"

class Color : public Tuple {
    public:
        Color(float r, float g, float b) : Tuple(r,g,b,0){}

        inline float r() {return this->x;}
        inline float g() {return this->y;}
        inline float b() {return this->z;}
        inline uint32_t toHex() {return (
            0xff000000 | 
            (((uint8_t) (this->x*255)) << 16) | 
            (((uint8_t) (this->y*255)) << 8) | 
            ((uint8_t) (this->z*255)));}
        friend inline Color operator * (Color const &c1, Color const c2) {return Color(c1.x * c2.x, c1.y * c2.y, c1.z * c2.z);}
};

#endif // COLOR_H_